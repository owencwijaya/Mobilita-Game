/**
 * @file item_list.h
 * @brief Header file untuk tipe data ItemList.
 */

#ifndef ITEM_DYNAMIC_LIST_H
#define ITEM_DYNAMIC_LIST_H

#include "boolean.h"
#include "item.h"

/**
 * @brief Alias untuk tipe data ItemListNode.
 */
typedef struct node *ItemList;

/**
 * @struct ItemListNode
 * @brief Node dari tipe data linked list ItemList.
 */
typedef struct node
{
    /**
     * @brief Nilai Item pada ItemListNode ini.
     */
    Item value;
    /**
     * @brief Pointer ke ItemListNode selanjutnya.
     */
    ItemList next;
} ItemListNode;

/**
 * @brief Constructor untuk membuat ItemList baru.
 * 
 * @return ItemList kosong.
 */
ItemList newItemList();

/**
 * @brief Constructor untuk membuat ItemListNode baru.
 * 
 * @param item Value yang di-hold oleh node ini.
 * @return ItemListNode instance berisi item.
 */
ItemList newItemListNode(Item item);

/**
 * @brief Mengecek apakah suatu ItemList kosong atau tidak. 
 * 
 * @param iList ItemList instance.
 * @return true jika iList kosong, false selainnya.
 */
boolean isItemListEmpty(ItemList iList);

/**
 * @brief Mengecek apakah suatu bilangan adalah indeks yang valid
 *        untuk iList.
 * 
 * @param iList ItemList instance. 
 * @param index Indeks yang akan dicek validitasnya.
 * @return true jika indeks index adalah valid, false selainnya.
 */
boolean isItemListIndexValid(ItemList iList, int index);

/**
 * @brief Mengembalikan panjang suatu ItemList.
 * 
 * @param iList ItemList instance.
 * @return Panjang dari iList.
 */
int itemListLength(ItemList iList);

/**
 * @brief Mencari indeks pertama kemunculan item pada ItemList.
 * 
 * @param iList ItemList instance.
 * @param item Item yang akan dicari.
 * @return Index pertama kemunculan item atau -1 jika item tidak
 *         ditemukan.
 */
int indexOfItem(ItemList iList, Item item);

/**
 * @brief Mengambil item pada indeks ke index di iList.
 * 
 * @param iList ItemList instance.
 * @param index Indeks yang akan diambil nilainya.
 * @return Item pada indeks ke index di iList.
 */
Item getItem(ItemList iList, int index);

/**
 * @brief Set elemen iList pada indeks index menjadi Item item.
 * 
 * @param iList ItemList instance.
 * @param index Indeks iList yang akan di-set.
 * @param item Item instance.
 */
void setItem(ItemList *iList, int index, Item item);

/**
 * @brief Insert Item di awal list iList.
 * 
 * @param iList ItemList instance.
 * @param item Item instance.
 */
void insertItemFirst(ItemList *iList, Item item);

/**
 * @brief Insert Item di indeks tertentu list iList.
 * 
 * @param iList ItemList instance.
 * @param index Indeks yang akan dimasukkan Item.
 * @param item Item instance.
 */
void insertItemAt(ItemList *iList, int index, Item item);

/**
 * @brief Insert Item di akhir list iList.
 * 
 * @param iList ItemList instance.
 * @param item Item instance.
 */
void insertItemLast(ItemList *iList, Item item);

/**
 * @brief Mengambil & mengapus Item pertama pada iList.
 * 
 * @param iList ItemList yang akan dihapus nilai pertamanya.
 * @param[out] item Item di posisi pertama iList.
 */
void deleteItemFirst(ItemList *iList, Item *item);

/**
 * @brief Mengambil & menghapus Item pada indeks index iList.
 * 
 * @param iList ItemList yang akan dilakukan penghapusan.
 * @param index Indeks Item yang akan dihapus.
 * @param[out] item Item pada indeks index.
 */
void deleteItemAt(ItemList *iList, int index, Item *item);

/**
 * @brief Mengambil & menghapus Item terakhir iList.
 * 
 * @param iList ItemList instance.
 * @param item Item di posisi terakhir iList.
 */
void deleteItemLast(ItemList *iList, Item *item);

#endif