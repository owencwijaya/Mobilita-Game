/**
 * @file item_queue.h
 * @brief Header file untuk tipe data ItemQueue. 
 */

#ifndef ITEM_QUEUE_H
#define ITEM_QUEUE_H

#include "boolean.h"
#include "item.h"

/**
 * @struct ItemQueue
 * @brief Antrian Item terurut berdasarkan waktu
 * pesanan masuk.
 */
typedef struct
{
    /**
     * @brief Indeks terdepan antrian.
     */
    int headIndex;
    /**
     * @brief Indeks terakhir antrian.
     */
    int tailIndex;
    /**
     * @brief Array tempat menyimpan elemen
     *        antrian.
     */
    Item buffer[30];
} ItemQueue;

/**
 * @brief Constructor untuk membuat ItemQueue baru.
 * 
 * @return ItemQueue instance baru yang kosong.
 */
ItemQueue newItemQueue();

/**
 * @brief Melihat nilai pesanan masuk (orderTime)
 * dari Item terdepan pada q.
 * @see Item
 * 
 * @param q ItemQueue instance.
 * @return Nilai pesanan Item terdepan q.
 */
int peekHeadTime(ItemQueue q);

/**
 * @brief Mengecek apakah queue q kosong atau tidak.
 * 
 * @param q ItemQueue instance yang akan dicek.
 * @return true jika q kosong, false selainnya.
 */
boolean isEmpty(ItemQueue q);

/**
 * @brief Menambah Item item pada antrian q.
 * 
 * @param q ItemQueue instance.
 * @param item Item instance.
 */
void enqueue(ItemQueue *q, Item item);

/**
 * @brief Mengambil Item terdepan pada antrian q.
 * 
 * @param q ItemQueue instance.
 * @param item Item terdepan pada antrian q.
 */
void dequeue(ItemQueue *q, Item *item);

#endif