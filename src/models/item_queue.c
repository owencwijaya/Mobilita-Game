/**
 * @file item_queue.c
 * @brief Implementasi tipe data ItemQueue.
 * Hanya digunakan untuk antrian pesanan masuk. 
 */

#include "item.h"
#include "item_queue.h"
#include "macros.h"

/**
 * @brief Constructor untuk membuat ItemQueue baru.
 * 
 * @return ItemQueue instance baru yang kosong.
 */
ItemQueue newItemQueue()
{
    ItemQueue q;
    headIndex(q) = -1;
    tailIndex(q) = -1;
    return q;
}

/**
 * @brief Melihat nilai pesanan masuk (orderTime)
 * dari Item terdepan pada q.
 * @see Item
 * 
 * @param q ItemQueue instance.
 * @return Nilai pesanan Item terdepan q.
 */
int peekHeadTime(ItemQueue q)
{
    return head(q).orderTime;
}

/**
 * @brief Mengecek apakah queue q kosong atau tidak.
 * 
 * @param q ItemQueue instance yang akan dicek.
 * @return true jika q kosong, false selainnya.
 */
boolean isEmpty(ItemQueue q)
{
    return headIndex(q) == -1 && tailIndex(q) == -1;
}

/**
 * @brief Menambah Item item pada antrian q.
 * 
 * @param q ItemQueue instance.
 * @param item Item instance.
 */
void enqueue(ItemQueue *q, Item item)
{
    if (isEmpty(*q))
    {
        headIndex(*q) = 0;
        tailIndex(*q) = 0;
        tail(*q) = item;
    }
    else
    {
        // * Insert
        tailIndex(*q)++;
        tail(*q) = item;
        // * Sort
        for (int i = 0; i < tailIndex(*q); i++)
        {
            int priorityIndex = i;
            for (int j = i + 1; j <= tailIndex(*q); j++)
            {
                if ((*q).buffer[j].orderTime < (*q).buffer[priorityIndex].orderTime)
                {
                    priorityIndex = j;
                }
            }
            Item temp = (*q).buffer[priorityIndex];
            (*q).buffer[priorityIndex] = (*q).buffer[i];
            (*q).buffer[i] = temp;
        }
    }
}

/**
 * @brief Mengambil Item terdepan pada antrian q.
 * 
 * @param q ItemQueue instance.
 * @param item Item terdepan pada antrian q.
 */
void dequeue(ItemQueue *q, Item *item)
{
    *item = head(*q);
    if (headIndex(*q) != tailIndex(*q))
    {
        headIndex(*q)++;
    }
    else
    {
        headIndex(*q) = -1;
        tailIndex(*q) = -1;
    }
}