/**
 * @file item_list.c
 * @brief Implementasi tipe data ItemList.
 * Digunakan untuk Todo List dan In Progress List.
 */

#include <stdlib.h>
#include "boolean.h"
#include "item.h"
#include "item_list.h"

/**
 * @brief Constructor untuk membuat ItemList baru.
 * 
 * @return ItemList kosong.
 */
ItemList newItemList()
{
    ItemList list = (ItemList)malloc(sizeof(ItemListNode));
    *list = NULL;
    return list;
}

/**
 * @brief Constructor untuk membuat ItemListNode baru.
 * 
 * @param item Value yang di-hold oleh node ini.
 * @return ItemListNode instance berisi item.
 */
ItemListNode newItemListNode(Item item)
{
    ItemListNode node = (ItemListNode)malloc(sizeof(struct node));
    if (node != NULL)
    {
        value(node) = item;
        next(node) = NULL;
    }
    return node;
}

/**
 * @brief Mengecek apakah suatu ItemList kosong atau tidak. 
 * 
 * @param iList ItemList instance.
 * @return true jika iList kosong, false selainnya.
 */
boolean isItemListEmpty(ItemList iList)
{
    ItemListNode node = *iList;
    return node == NULL;
}

/**
 * @brief Mengecek apakah suatu bilangan adalah indeks yang valid
 *        untuk iList.
 * 
 * @param iList ItemList instance. 
 * @param index Indeks yang akan dicek validitasnya.
 * @return true jika indeks index adalah valid, false selainnya.
 */
boolean isItemListIndexValid(ItemList iList, int index)
{
    return index >= 0 && index < itemListLength(iList);
}

/**
 * @brief Mengembalikan panjang suatu ItemList.
 * 
 * @param iList ItemList instance.
 * @return Panjang dari iList.
 */
int itemListLength(ItemList iList)
{
    ItemListNode node = *iList;
    int count = 0;
    while (node != NULL)
    {
        node = next(node);
        count++;
    }
    return count;
}

/**
 * @brief Mencari indeks pertama kemunculan item pada ItemList.
 * 
 * @param iList ItemList instance.
 * @param item Item yang akan dicari.
 * @return Index pertama kemunculan item atau -1 jika item tidak
 *         ditemukan.
 */
int indexOfItem(ItemList iList, Item item)
{
    ItemListNode node = *iList;
    int index = 0;
    boolean found = false;
    while (node != NULL && !found)
    {
        if (value(node) == item)
        {
            found = true;
        }
        else
        {
            index++;
            node = next(node);
        }
    }
    return found ? index : -1;
}

/**
 * @brief Mengambil item pada indeks ke index di iList.
 * 
 * @param iList ItemList instance.
 * @param index Indeks yang akan diambil nilainya.
 * @return Item pada indeks ke index di iList.
 */
Item getItem(ItemList iList, int index)
{
    ItemListNode node = *iList;
    int i = 0;
    while (i < index)
    {
        node = next(node);
        i++;
    }
    return value(node);
}

/**
 * @brief Set elemen iList pada indeks index menjadi Item item.
 * 
 * @param iList ItemList instance.
 * @param index Indeks iList yang akan di-set.
 * @param item Item instance.
 */
void setItem(ItemList iList, int index, Item item)
{
    ItemListNode node = *iList;
    int i = 0;
    while (i < index)
    {
        node = next(node);
        i++;
    }
    value(node) = item;
}

/**
 * @brief Insert Item di awal list iList.
 * 
 * @param iList ItemList instance.
 * @param item Item instance.
 */
void insertItemFirst(ItemList iList, Item item)
{
    ItemListNode node = newItemListNode(item);
    if (node != NULL)
    {
        next(node) = *iList;
        *iList = node;
    }
}

/**
 * @brief Insert Item di indeks tertentu list iList.
 * 
 * @param iList ItemList instance.
 * @param index Indeks yang akan dimasukkan Item.
 * @param item Item instance.
 */
void insertItemAt(ItemList iList, int index, Item item)
{
    if (index == 0)
    {
        insertItemFirst(iList, item);
    }
    else
    {
        ItemListNode node = newItemListNode(item);
        if (node != NULL)
        {
            int i = 0;
            ItemListNode subList = *iList;
            while (i < index - 1)
            {
                i++;
                subList = next(subList);
            }
            next(node) = next(subList);
            next(subList) = node;
        }
    }
}

/**
 * @brief Insert Item di akhir list iList.
 * 
 * @param iList ItemList instance.
 * @param item Item instance.
 */
void insertItemLast(ItemList iList, Item item)
{
    if (isItemListEmpty(iList))
    {
        insertItemFirst(iList, item);
    }
    else
    {
        ItemListNode node = newItemListNode(item);
        if (node != NULL)
        {
            ItemListNode list = *iList;
            while (next(list) != NULL)
            {
                list = next(list);
            }
            next(list) = node;
        }
    }
}

/**
 * @brief Mengambil & mengapus Item pertama pada iList.
 * 
 * @param iList ItemList yang akan dihapus nilai pertamanya.
 * @return Item di posisi pertama iList.
 */
Item deleteItemFirst(ItemList iList)
{
    Item item;
    ItemListNode node = *iList;
    item = value(node);
    *iList = next(node);
    free(node);
    return item;
}

/**
 * @brief Mengambil & menghapus Item pada indeks index iList.
 * 
 * @param iList ItemList yang akan dilakukan penghapusan.
 * @param index Indeks Item yang akan dihapus.
 * @return Item pada indeks index.
 */
Item deleteItemAt(ItemList iList, int index)
{
    Item item;
    if (index == 0)
    {
        item = deleteItemFirst(iList);
    }
    else
    {
        ItemListNode node = *iList;
        int i = 0;
        while (i < index - 1)
        {
            node = next(node);
            i++;
        }
        ItemListNode nextNode = next(node);
        item = value(nextNode);
        next(node) = next(nextNode);
        free(nextNode);
    }
    return item;
}

/**
 * @brief Mengambil & menghapus Item terakhir iList.
 * 
 * @param iList ItemList instance.
 * @return Item di posisi terakhir iList.
 */
Item deleteItemLast(ItemList iList)
{
    Item item;
    ItemListNode lastList = *iList;
    ItemListNode beforeLastList = NULL;
    while (next(lastList) != NULL)
    {
        beforeLastList = lastList;
        lastList = next(lastList);
    }
    if (beforeLastList == NULL)
    {
        *iList = NULL;
    }
    else
    {
        next(beforeLastList) = NULL;
    }
    item = value(lastList);
    free(lastList);
    return item;
}
