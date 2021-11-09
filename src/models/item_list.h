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
typedef struct node *ItemListNode;

/**
 * @struct ItemListNode
 * @brief Node dari tipe data linked list ItemList.
 */
struct node
{
    /**
     * @brief Nilai Item pada ItemListNode ini.
     */
    Item value;
    /**
     * @brief Pointer ke ItemListNode selanjutnya.
     */
    ItemListNode next;
};

typedef ItemListNode *ItemList;

/**
 * @brief Mengambil value dari sebuah ItemListNode.
 * @param node ItemListNode instance.
 */
#define value(node) (node)->value
/**
 * @brief Mengambil pointer ke next node dari sebuah ItemListNode.
 * @param node ItemListNode instance.
 */
#define next(node) (node)->next

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
ItemListNode newItemListNode(Item item);

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
void setItem(ItemList iList, int index, Item item);

/**
 * @brief Insert Item di awal list iList.
 * 
 * @param iList ItemList instance.
 * @param item Item instance.
 */
void insertItemFirst(ItemList iList, Item item);

/**
 * @brief Insert Item di indeks tertentu list iList.
 * 
 * @param iList ItemList instance.
 * @param index Indeks yang akan dimasukkan Item.
 * @param item Item instance.
 */
void insertItemAt(ItemList iList, int index, Item item);

/**
 * @brief Insert Item di akhir list iList.
 * 
 * @param iList ItemList instance.
 * @param item Item instance.
 */
void insertItemLast(ItemList iList, Item item);

/**
 * @brief Mengambil & mengapus Item pertama pada iList.
 * 
 * @param iList ItemList yang akan dihapus nilai pertamanya.
 * @return Item di posisi pertama iList.
 */
Item deleteItemFirst(ItemList iList);

/**
 * @brief Mengambil & menghapus Item pada indeks index iList.
 * 
 * @param iList ItemList yang akan dilakukan penghapusan.
 * @param index Indeks Item yang akan dihapus.
 * @return Item pada indeks index.
 */
Item deleteItemAt(ItemList iList, int index);

/**
 * @brief Mengambil & menghapus Item terakhir iList.
 * 
 * @param iList ItemList instance.
 * @return Item di posisi terakhir iList.
 */
Item deleteItemLast(ItemList iList);

#endif