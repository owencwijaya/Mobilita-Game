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
    ItemList list;
    list = (ItemList)malloc(sizeof(ItemListNode));
    list = NULL;
}

/**
 * @brief Constructor untuk membuat ItemListNode baru.
 * 
 * @param item Value yang di-hold oleh node ini.
 * @return ItemListNode instance berisi item.
 */
ItemListNode newItemListNode(Item item)
{
    ItemListNode node;
    value(node) = item;
    next(node) = NULL;
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
    ItemList list;
    list = iList;
    int count = 0;
    while (list != NULL)
    {
        list = next(*list);
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
    ItemList list;
    list = iList;
    int index = 0;
    boolean found = false;
    while (list != NULL && !found)
    {
        if (isItemIdentical(value(*list), item))
        {
            found = true;
        }
        else
        {
            index++;
            list = next(*list);
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
    // if (isItemListIndexValid(iList, index))
    // {
    ItemList list;
    list = iList;
    int i = 0;
    while (i < index)
    {
        list = next(*list);
        i++;
    }
    return value(*list);
    // }
    // else
    // {
    //     return newItem(NULL_LOCATION, NULL_LOCATION, -1, -1);
    // }
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
    ItemList list;
    list = *iList;
    int i = 0;
    while (i < index)
    {
        list = next(*list);
        i++;
    }
    value(*list) = item;
}

/**
 * @brief Insert Item di awal list iList.
 * 
 * @param iList ItemList instance.
 * @param item Item instance.
 */
void insertItemFirst(ItemList *iList, Item item)
{
    ItemList list = *iList;
    ItemListNode node = newItemListNode(item);
    **iList = node;
    next(**iList) = list;
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
    ItemList list, nextList;
    list = *iList;
    ItemListNode node = newItemListNode(item);
    int i = 0;
    while (i < index)
    {
        list = next(*list);
        i++;
    }
    nextList = list;
    next(node) = nextList;
    next(*list) = &node;
}

/**
 * @brief Insert Item di akhir list iList.
 * 
 * @param iList ItemList instance.
 * @param item Item instance.
 */
void insertItemLast(ItemList *iList, Item item)
{
    ItemList list, nextList;
    list = *iList;
    ItemListNode node = newItemListNode(item);
    while (list != NULL)
    {
        list = next(*list);
    }
    next(*list) = &node;
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
    *item = value(*list);
    *iList = next(*list);
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
    ItemList list = *iList;
    ItemList nextList;
    int i = 0;
    while (i < index - 1)
    {
        list = next(*list);
        i++;
    }
    nextList = next(*list);
    *item = value(*nextList);
    next(*list) = next(*nextList);
    free(nextList);
}

/**
 * @brief Mengambil & menghapus Item terakhir iList.
 * 
 * @param iList ItemList instance.
 * @param item Item di posisi terakhir iList.
 */
void deleteItemLast(ItemList *iList, Item *item)
{
    ItemList list = *iList;
    if (next(*list) == NULL)
    {
        *item = value(*list);
        *iList = NULL;
        free(list);
    }
    else
    {
        ItemList nextList;
        nextList = next(*list);
        while (next(*nextList) != NULL)
        {
            list = nextList;
            nextList = next(*nextList);
        }
        *item = value(*nextList);
        next(*list) = NULL;
        free(nextList);
    }
}
