#include <stdio.h>
#include "../modules/core/globals.h"
#include "../models/macros.h"
#include "../models/boolean.h"

boolean isVIPintodo(ItemList todo)
{
    /*Mengembalikan True Jika VIP item ada di TO_DO*/
    ItemList l;
    l = todo;
    boolean found = false;
    while (l != NULL && !found)
    {
        if (isVIPItem(value(l)))
        {
            found = true;
        }
        else
        {
            l = next(l);
        }
    }
    return found;
}

int idxVIPItem(ItemList todo, Location location)
{
    ItemList l;
    l = todo;
    int idx = 0;
    boolean found = false;
    while (l != NULL && !found)
    {
        if (isVIPItem(value(l)) && isLocationIdentical(location, value(l).pickUpLocation))
        {
            found = true;
        }
        else
        {
            idx += 1;
            l = next(l);
        }
    }
    return found ? idx : -1;
}

int idxItemInTodo(ItemList todo)
{
    ItemList l;
    l = gameState.todoList;
    int idx = 0; //Mencari index item pada todolist yang sesuai
    boolean found = false;
    while (l != NULL && !found)
    {
        if (isLocationIdentical(gameState.currentLocation, value(l).pickUpLocation))
        {
            found = true;
        }
        else
        {
            idx++;
            l = next(l);
        }
    }
    return idx;
}

void insertItem(ItemList *inProg, Item item)
{
    // Menambahkan Item ke In Progress terurut dari pesanan yang terakhir kali masuk agar lebih mudah ditampilkan (command inProgress)
    if (isItemListEmpty(*inProg))
    {
        insertItemFirst(inProg, item);
    }
    else
    {
        ItemList node = newItemListNode(item);
        if (node != NULL)
        {
            ItemList loc = *inProg;
            ItemList prevLoc = NULL;
            while (loc != NULL && value(loc).orderTime > value(node).orderTime)
            {
                prevLoc = loc;
                loc = next(loc);
            }
            if (prevLoc == NULL)
            {
                insertItemFirst(inProg, item);
            }
            else
            {
                next(node) = loc;
                next(prevLoc) = node;
            }
        }
    }
}

void pick_up()
{
    if(gameState.abs.VIPItemStack != 0){
        printf("Sedang ada VIP Item di in-progress list, harus diantarkan terlebih dahulu!\n");
    } else {
        if (isVIPintodo(gameState.todoList))
        {
            //Ada VIP Item di To Do list, sehingga Harus diutamakan terlebih dahulu.
            if (!isStackFull(gameState.bag))
            {
                
                int idx = idxVIPItem(gameState.todoList, gameState.currentLocation);
                if (idx != -1)
                {
                    if (!isStackEmpty(gameState.bag)){
                        unsetAsDropOffPlace(&gameState.gameMap._locationMatrix.contents[top(gameState.bag).dropOffLocation.coordinate.x][top(gameState.bag).dropOffLocation.coordinate.y]);
                    }
                    Item item = getItem(gameState.todoList, idx);
                    insertItemLast(&gameState.inProgressList, item);
                    push(&gameState.bag, getItem(gameState.todoList, idx));
                    gameState.abs.TodoVIP--;
                    printf("Pesanan berupa VIP Item berhasil diambil!\n");
                    printf("Tujuan Pesanan : %c\n\n", item.dropOffLocation.symbol);
                    gameState.abs.IsVIPItemOn = true;
                    gameState.abs.VIPItemStack++;
                    Location dropOffLocation = dropOffLoc(item);
                    Point coordinate = coord(dropOffLocation);
                    setAsDropOffPlace(&gameState.gameMap._locationMatrix.contents[x(coordinate)][y(coordinate)]);
                    Item temp;
                    deleteItemAt(&gameState.todoList, idx, &temp); //Menghapus VIP item dari ToDo List
                    setAsDropOffPlace(&gameState.gameMap._locationMatrix.contents[top(gameState.bag).dropOffLocation.coordinate.x][top(gameState.bag).dropOffLocation.coordinate.y]);
                    boolean similarLocation = false;
                    int i = 0;
                    while (i < itemListLength(gameState.todoList) && !similarLocation)
                    {
                        if (isLocationIdentical(top(gameState.bag).pickUpLocation, getItem(gameState.todoList, i).pickUpLocation))
                        {
                            similarLocation = true;
                        }
                        i++;
                    }
                    //kalo gada lokasi yang sama lagi, unset as pickup, unset warna pickup
                    if (similarLocation == false)
                    {
                        unsetAsPickUpPlace(&gameState.gameMap._locationMatrix.contents[top(gameState.bag).pickUpLocation.coordinate.x][top(gameState.bag).pickUpLocation.coordinate.y]);
                    }
                }
                else
                {
                    printf("Pesanan berupa VIP Item tidak ada di lokasi ini!\n(Pesanan VIP di to-do list (TO_DO) harus didahulukan!)\n\n");
                }
            }
            else
            {
                printf("Tas telah penuh!\n");
            }
        }
        else
        {
            if (gameState.gameMap._locationMatrix.contents[gameState.currentLocation.coordinate.x][gameState.currentLocation.coordinate.y].isPickUpPlace)
            {
                int idx = idxItemInTodo(gameState.todoList);
                if (!isStackFull(gameState.bag))
                {   
                    if (!isStackEmpty(gameState.bag)){
                        unsetAsDropOffPlace(&gameState.gameMap._locationMatrix.contents[top(gameState.bag).dropOffLocation.coordinate.x][top(gameState.bag).dropOffLocation.coordinate.y]);
                    }
            
                    if (isNormalItem(getItem(gameState.todoList, idx)))
                    {
                        insertItemLast(&gameState.inProgressList, getItem(gameState.todoList, idx));
                        push(&gameState.bag, getItem(gameState.todoList, idx));
                        printf("Pesanan berupa Normal Item berhasil diambil!\n");
                        printf("Tujuan Pesanan : %c\n\n", getItem(gameState.todoList, idx).dropOffLocation.symbol);
                        Item temp;
                        deleteItemAt(&gameState.todoList, idx, &temp); //Menghapus item yang di Pick_UP dari To Do
                    }
                    else if (isHeavyItem(getItem(gameState.todoList, idx)))
                    {
                        insertItemLast(&gameState.inProgressList, getItem(gameState.todoList, idx));
                        push(&gameState.bag, getItem(gameState.todoList, idx));
                        printf("Pesanan berupa Heavy Item berhasil diambil!\n");
                        printf("Tujuan Pesanan : %c\n\n", getItem(gameState.todoList, idx).dropOffLocation.symbol);
                        Item temp;
                        deleteItemAt(&gameState.todoList, idx, &temp);
                        gameState.abs.IsHeavyItemOn = true;
                        gameState.abs.HeavyItemStack++;
                        if (gameState.abs.SpeedBoost)
                        {
                            gameState.abs.SpeedBoost = false;
                            gameState.abs.SpeedBoostCount = 0;
                            gameState.abs.SpeedBoostStack = 0;
                            printf("Speed Boost yang didapatkan dimatikan!");
                        }
                    }
                    else if (isPerishableItem(getItem(gameState.todoList, idx)))
                    {
                        insertItemLast(&gameState.inProgressList, getItem(gameState.todoList, idx));
                        push(&gameState.bag, getItem(gameState.todoList, idx));
                        printf("Pesanan berupa Perishable Item berhasil diambil!\n");
                        printf("Tujuan Pesanan : %c\n\n", getItem(gameState.todoList, idx).dropOffLocation.symbol);
                        Item temp;
                        deleteItemAt(&gameState.todoList, idx, &temp);
                    }
                    setAsDropOffPlace(&gameState.gameMap._locationMatrix.contents[top(gameState.bag).dropOffLocation.coordinate.x][top(gameState.bag).dropOffLocation.coordinate.y]);
                    boolean similarLocation = false;
                    int i = 0;
                    while (i < itemListLength(gameState.todoList) && !similarLocation)
                    {
                        if (isLocationIdentical(top(gameState.bag).pickUpLocation, getItem(gameState.todoList, i).pickUpLocation))
                        {
                            similarLocation = true;
                        }
                        i++;
                    }

                    if (similarLocation == false)
                    {
                        unsetAsPickUpPlace(&gameState.gameMap._locationMatrix.contents[top(gameState.bag).pickUpLocation.coordinate.x][top(gameState.bag).pickUpLocation.coordinate.y]);
                    }
                }
                else
                {
                    printf("Tas telah penuh!\n\n");
                }
            }
            else
            {
                printf("Tidak ada pesanan yang dapat diambil!\n\n");
            }
        }
    }
}