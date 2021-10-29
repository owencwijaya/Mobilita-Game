#include<stdio.h>
#include "../modules/core/globals.h"
#include "macros.h"


int idxVIPintodo(ItemList todo){
/*Mengembalikan idx VIP item di To Do list, jika tidak ada mengembalikan -1
Jika idx =/= -1, maka VIP item ada di ToDoList*/
    ItemList l;
    l = todo;
    int idx = 0;
    boolean found = false;
    while (l != NULL && !found){
        if(isVIPItem(value(l))){
            found = true;
        }else{
            idx ++;
            l = next(l);
        }
    }
   return found ? idx : -1;
}

int idxItemInTodo(ItemList todo){
    ItemList l;
    l = gameState.todoList;
    int idx = 0; //Mencari index item pada todolist yang sesuai
    boolean found = false;
    while (l != NULL && !found){
        if(isLocationIdentical(gameState.currentLocation, value(l).pickUpLocation)){
            found = true;
        }else{
            idx ++;
            l = next(l);
        }
    }
    return idx;
}

int countItemInLocation(ItemList todo){
// Banyaknya Item yang dapat diambil di Pick Up Place. 
    ItemList l;
    l = todo;
    int count = 0;
    while(l != NULL){
        if(isLocationIdentical(gameState.currentLocation, value(l).pickUpLocation)){
            count +=1;
        }else{
            l = next(l);
        }
    }
}

void insertItem(ItemList *inProg, Item item){
// Menambahkan Item ke In Progress terurut dari pesanan yang terakhir kali masuk agar lebih mudah ditampilkan (command inProgress)
    if (isItemListEmpty(*inProg)){
        insertItemFirst(inProg, item);
    }else{
        ItemList node = newItemListNode(item);
        if(node != NULL){
            ItemList loc = *inProg;
            ItemList prevLoc = NULL;
            while (loc != NULL && value(loc).orderTime > value(node).orderTime){
                prevLoc = loc;
                loc = next(loc);
            }
            if (prevLoc == NULL){
                insertItemFirst(inProg, item);
            }else{
                next(node) = loc;
                next(prevLoc) = node;
            }
        }
    }
}

void pick_up(){
    if(idxVIPintodo(gameState.todoList) != -1){
    //Ada VIP Item di To Do list, sehingga Harus diutamakan terlebih dahulu.
        int idx = idxVIPintodo(gameState.todoList);
        if(isLocationIdentical(gameState.currentLocation, getItem(gameState.todoList, idx).pickUpLocation)){
            insertItem(&gameState.inProgressList, getItem(gameState.todoList, idx));
            push(&gameState.bag, getItem(gameState.todoList, idx));
            printf("Pesanan berupa VIP Item berhasil diambil!\n");
            printf("Tujuan Pesanan : %c\n\n", getItem(gameState.todoList, idx).dropOffLocation.symbol);
            gameState.abs.IsVIPItemOn = true;
            Item temp;
            deleteItemAt(&gameState.todoList, idx, &temp); //Menghapus VIP item dari ToDo List
        }else{
            printf("Pesanan berupa VIP item tidak ditemukan\n\n");
        }
    }else{
        if(gameState.currentLocation.isPickUpPlace){
            int countItem = countItemInLocation(gameState.todoList);
            int i;
            for(i = 0; i<countItem; i++){//Loop Untuk Mengambil Beberapa Item pada Pick Up Place
                int idx = idxItemInTodo(gameState.todoList);
                if(!isStackFull(gameState.bag)){
                    if(isNormalItem(getItem(gameState.todoList, idx))){
                        insertItem(&gameState.inProgressList, getItem(gameState.todoList, idx));
                        push(&gameState.bag, getItem(gameState.todoList, idx));
                        printf("Pesanan berupa Normal Item berhasil diambil!\n");
                        printf("Tujuan Pesanan : %c\n\n", getItem(gameState.todoList, idx).dropOffLocation.symbol);
                        Item temp;
                        deleteItemAt(&gameState.todoList, idx, &temp); //Menghapus item yang di Pick_UP dari To Do
                    }else if (isHeavyItem(getItem(gameState.todoList, idx))){
                        insertItem(&gameState.inProgressList, getItem(gameState.todoList, idx));
                        push(&gameState.bag, getItem(gameState.todoList, idx));
                        printf("Pesanan berupa Heavy Item berhasil diambil!\n");
                        printf("Tujuan Pesanan : %c\n\n", getItem(gameState.todoList, idx).dropOffLocation.symbol);
                        Item temp;
                        deleteItemAt(&gameState.todoList, idx, &temp);
                        gameState.abs.IsHeavyItemOn = true;
                        gameState.abs.HeavyItemStack++;
                    }else if(isPerishableItem(getItem(gameState.todoList, idx))){
                        insertItem(&gameState.inProgressList, getItem(gameState.todoList, idx));
                        push(&gameState.bag, getItem(gameState.todoList, idx));
                        printf("Pesanan berupa Perishable Item berhasil diambil!\n");
                        printf("Tujuan Pesanan : %c\n\n", getItem(gameState.todoList, idx).dropOffLocation.symbol);
                        Item temp;
                        deleteItemAt(&gameState.todoList, idx, &temp);
                    }
                }else{
                    printf("Tas telah penuh\n\n");
                }
            }
        }else{
            printf("Tidak ada pesanan yang dapat diambil\n\n");
        }
    }
}