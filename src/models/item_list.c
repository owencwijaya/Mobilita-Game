/**
 * @file item_list.c
 * @brief Implementasi tipe data ItemList.
 * Digunakan untuk Todo List dan In Progress List.
 */

#include <stdlib.h>
#include "boolean.h"
#include "item.h"
#include "item_list.h"
#include "macros.h"

/**
 * @brief Constructor untuk membuat ItemList baru.
 * 
 * @return ItemList kosong.
 */
ItemList newItemList()
{
    return (ItemList)NULL;
}

/**
 * @brief Constructor untuk membuat ItemListNode baru.
 * 
 * @param item Value yang di-hold oleh node ini.
 * @return ItemListNode instance berisi item.
 */
ItemList newItemListNode(Item item)
{
    ItemList node = (ItemList)malloc(sizeof(ItemListNode));
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
    return iList == NULL;
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
    ItemList list = iList;
    int count = 0;
    while (list != NULL)
    {
        list = next(list);
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
    ItemList list = iList;
    int index = 0;
    boolean found = false;
    while (list != NULL && !found)
    {
        if (isItemIdentical(value(list), item))
        {
            found = true;
        }
        else
        {
            index++;
            list = next(list);
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
    ItemList list = iList;
    int i = 0;
    while (i < index)
    {
        list = next(list);
        i++;
    }
    return value(list);
}

/**
 * @brief Set elemen iList pada indeks index menjadi Item item.
 * 
 * @param iList ItemList instance.
 * @param index Indeks iList yang akan di-set.
 * @param item Item instance.
 */
void setItem(ItemList *iList, int index, Item item)
{
    ItemList list = *iList;
    int i = 0;
    while (i < index)
    {
        list = next(list);
        i++;
    }
    value(list) = item;
}

/**
 * @brief Insert Item di awal list iList.
 * 
 * @param iList ItemList instance.
 * @param item Item instance.
 */
void insertItemFirst(ItemList *iList, Item item)
{
    ItemList node = newItemListNode(item);
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
void insertItemAt(ItemList *iList, int index, Item item)
{
    if (index == 0)
    {
        insertItemFirst(iList, item);
    }
    else
    {
        ItemList node = newItemListNode(item);
        if (node != NULL)
        {
            int i = 0;
            ItemList subList = *iList;
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
void insertItemLast(ItemList *iList, Item item)
{
    if (isItemListEmpty(*iList))
    {
        insertItemFirst(iList, item);
    }
    else
    {
        ItemList node = newItemListNode(item);
        if (node != NULL)
        {
            ItemList list = *iList;
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
 * @param[out] item Item di posisi pertama iList.
 */
void deleteItemFirst(ItemList *iList, Item *item)
{
    ItemList list = *iList;
    *item = value(list);
    *iList = next(list);
    free(list);
}

/**
 * @brief Mengambil & menghapus Item pada indeks index iList.
 * 
 * @param iList ItemList yang akan dilakukan penghapusan.
 * @param index Indeks Item yang akan dihapus.
 * @param[out] item Item pada indeks index.
 */
void deleteItemAt(ItemList *iList, int index, Item *item)
{
    if (index == 0)
    {
        deleteItemFirst(iList, item);
    }
    else
    {
        ItemList node = *iList;
        int i = 0;
        while (i < index - 1)
        {
            node = next(node);
            i++;
        }
        ItemList nextNode = next(node);
        *item = value(nextNode);
        next(node) = next(nextNode);
        free(nextNode);
    }
}

/**
 * @brief Mengambil & menghapus Item terakhir iList.
 * 
 * @param iList ItemList instance.
 * @param item Item di posisi terakhir iList.
 */
void deleteItemLast(ItemList *iList, Item *item)
{
    ItemList lastList = *iList;
    ItemList beforeLastList = NULL;
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
    *item = value(lastList);
    free(lastList);
}
