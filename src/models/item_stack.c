/**
 * @file item_stack.c
 * @brief Implementasi tipe data ItemStack.
 * Hanya digunakan untuk INVENTORY.
 */

#include "boolean.h"
#include "item.h"
#include "item_stack.h"

/**
 * @brief Constructor untuk membuat ItemStack baru.
 * 
 * @param capacity Kapasitas stack.
 * @return ItemStack instace baru yang kosong.
 */
ItemStack newItemStack(int capacity)
{
    ItemStack s;
    topIndex(s) = -1;
    capacity(s) = capacity;
    return s;
}

/**
 * @brief Mengecek apakah stack kosong atau tidak.
 * 
 * @param stack ItemStack instance.
 * @return true jika stack kosong, false selainnya.
 */
boolean isStackEmpty(ItemStack stack)
{
    return topIndex(stack) == -1;
}

/**
 * @brief Mengecek apakah stack penuh atau tidak.
 * 
 * @param stack ItemStack instance.
 * @return true jika stack penuh, false selainnya.
 */
boolean isStackFull(ItemStack stack)
{
    return topIndex(stack) == capacity(stack) - 1;
}

/**
 * @brief Memasukkan item ke atas stack.
 * 
 * @param stack ItemStack instance.
 * @param item Item yang akan dimasukkan ke atas stack.
 */
void push(ItemStack *stack, Item item)
{
    topIndex(*stack)++;
    top(*stack) = item;
}

/**
 * @brief Mengambil item dari atas stack.
 * 
 * @param stack ItemStack instance.
 * @param[out] item Item yang diambil dari atas stack.
 */
void pop(ItemStack *stack, Item *item)
{
    *item = top(*stack);
    topIndex(*stack)--;
}

/**
 * @brief Menambah kapasitas stack sebanyak 1.
 * Kapasitas tidak bertambah jika telah mencapai
 * kapasitas maksimum (100).
 * 
 * @param stack ItemStack instance. 
 */
void incrementCapacity(ItemStack *stack)
{
    capacity(*stack)++;
    _clampCapacity(stack);
}

/**
 * @brief Menggandakan kapasitas stack.
 * Kapasitas tidak bertambah hingga melebihi
 * kapasitas maksimum (100).
 * 
 * @param stack ItemStack instance. 
 */
void doubleCapacity(ItemStack *stack)
{
    capacity(*stack) *= 2;
    _clampCapacity(stack);
}

/**
 * @brief Membatasi kapasitas stack jika
 * kapasitas melebihi batas.
 * 
 * @param stack ItemStack instance.
 */
void _clampCapacity(ItemStack *stack)
{
    if (capacity(*stack) > ITEM_STACK_MAX_CAPACITY)
    {
        capacity(*stack) = ITEM_STACK_MAX_CAPACITY;
    }
}