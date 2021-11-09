#include <stdio.h>
#include "../models/location.h"
#include "../models/item.h"
#include "../modules/core/globals.h"
#include "../models/boolean.h"

// void setColors(Item item)
// {
//     setAsMarkedPickUp(&gameState.gameMap._locationMatrix.contents[item.pickUpLocation.coordinate.x][item.pickUpLocation.coordinate.y]);
//     setAsMarkedDropOff(&gameState.gameMap._locationMatrix.contents[item.dropOffLocation.coordinate.x][item.dropOffLocation.coordinate.y]);
// }

// void unsetColors(Item item)
// {
//     unsetAsMarkedPickUp(&gameState.gameMap._locationMatrix.contents[item.pickUpLocation.coordinate.x][item.pickUpLocation.coordinate.y]);
//     unsetAsMarkedDropOff(&gameState.gameMap._locationMatrix.contents[item.dropOffLocation.coordinate.x][item.dropOffLocation.coordinate.y]);
// }

boolean isVIPintodo(ItemList todo)
{
    /*Mengembalikan True Jika VIP item ada di TO_DO*/
    ItemListNode node = *todo;
    boolean found = false;
    while (node != NULL && !found)
    {
        if (isVIPItem(value(node)))
        {
            found = true;
        }
        else
        {
            node = next(node);
        }
    }
    return found;
}

int idxVIPItem(ItemList todo, Location location)
{
    ItemListNode node = *todo;
    int idx = 0;
    boolean found = false;
    while (node != NULL && !found)
    {
        if (isVIPItem(value(node)) && location == pickUpLoc(value(node)))
        {
            found = true;
        }
        else
        {
            idx += 1;
            node = next(node);
        }
    }
    return found ? idx : -1;
}

int idxItemInTodo(ItemList todo)
{
    ItemListNode node = *todo;
    int idx = 0; //Mencari index item pada todolist yang sesuai
    boolean found = false;
    while (node != NULL && !found)
    {
        if (gameState.currentLocation == pickUpLoc(value(node)))
        {
            found = true;
        }
        else
        {
            idx++;
            node = next(node);
        }
    }
    return idx;
}

void insertItem(ItemList inProg, Item item)
{
    // Menambahkan Item ke In Progress terurut dari pesanan yang terakhir kali masuk agar lebih mudah ditampilkan (command inProgress)
    if (isItemListEmpty(inProg))
    {
        insertItemFirst(inProg, item);
    }
    else
    {
        ItemListNode node = newItemListNode(item);
        if (node != NULL)
        {
            ItemListNode loc = *inProg;
            ItemListNode prevLoc = NULL;
            while (loc != NULL && orderTime(value(node)) > orderTime(value(node)))
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
    if (isVIPintodo(gameState.todoList))
    {
        //Ada VIP Item di To Do list, sehingga Harus diutamakan terlebih dahulu.
        if (!isStackFull(gameState.bag))
        {
            int idx = idxVIPItem(gameState.todoList, gameState.currentLocation);
            if (idx != -1)
            {
                insertItem(gameState.inProgressList, getItem(gameState.todoList, idx));
                push(gameState.bag, getItem(gameState.todoList, idx));
                printf("Pesanan berupa VIP Item berhasil diambil!\n");
                printf("Tujuan Pesanan : %c\n\n", symbol(dropOffLoc(getItem(gameState.todoList, idx))));
                gameState.abs.IsVIPItemOn = true;
                deleteItemAt(gameState.todoList, idx); //Menghapus VIP item dari ToDo List
            }
            else
            {
                printf("Pesanan berupa VIP Item tidak ada di lokasi ini!\n(Pesanan VIP di TO_DO harus didahulukan! Gue  bucin!)\n\n");
            }
        }
        else
        {
            printf("Tas telah penuh\n\n");
        }
    }
    else
    {
        if (gameState.currentLocation->isPickUpPlace)
        {
            int idx = idxItemInTodo(gameState.todoList);
            if (!isStackFull(gameState.bag))
            {
                if (isNormalItem(getItem(gameState.todoList, idx)))
                {
                    insertItem(gameState.inProgressList, getItem(gameState.todoList, idx));
                    // unsetColors(top(gameState.bag));
                    push(gameState.bag, getItem(gameState.todoList, idx));
                    // setColors(top(gameState.bag));
                    printf("Pesanan berupa Normal Item berhasil diambil!\n");
                    printf("Tujuan Pesanan : %c\n\n", symbol(dropOffLoc(getItem(gameState.todoList, idx))));
                    deleteItemAt(gameState.todoList, idx); //Menghapus item yang di Pick_UP dari To Do
                }
                else if (isHeavyItem(getItem(gameState.todoList, idx)))
                {
                    insertItem(gameState.inProgressList, getItem(gameState.todoList, idx));
                    // unsetColors(top(gameState.bag));
                    push(gameState.bag, getItem(gameState.todoList, idx));
                    // setColors(top(gameState.bag));
                    printf("Pesanan berupa Heavy Item berhasil diambil!\n");
                    printf("Tujuan Pesanan : %c\n\n", symbol(dropOffLoc(getItem(gameState.todoList, idx))));
                    deleteItemAt(gameState.todoList, idx);
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
                    insertItem(gameState.inProgressList, getItem(gameState.todoList, idx));
                    // unsetColors(top(gameState.bag));
                    push(gameState.bag, getItem(gameState.todoList, idx));
                    // setColors(top(gameState.bag));
                    printf("Pesanan berupa Perishable Item berhasil diambil!\n");
                    printf("Tujuan Pesanan : %c\n\n", symbol(dropOffLoc(getItem(gameState.todoList, idx))));
                    deleteItemAt(gameState.todoList, idx);
                }
            }
            else
            {
                printf("Tas telah penuh\n\n");
            }
        }
        else
        {
            printf("Tidak ada pesanan yang dapat diambil\n\n");
        }
    }
}