/**
 * @file item_stack.h
 * @brief Header file untuk tipe data ItemStack.
 */

#ifndef ITEM_STACK_H
#define ITEM_STACK_H

#include "../shared/boolean.h"
#include "item.h"

/**
 * @struct ItemStack
 * @brief Tumpukan Item pada tas.
 */
typedef struct
{
    /**
     * @brief Indeks teratas stack.
     */
    int topIndex;
    /**
     * @brief Kapasitas stack.
     */
    int capacity;
    /**
     * @brief Array tempat menyimpan elemen stack.
     */
    Item buffer[100];
} ItemStack;

/**
 * @brief Constructor untuk membuat ItemStack baru.
 * 
 * @param capacity Kapasitas stack.
 * @return ItemStack instace baru yang kosong.
 */
ItemStack newItemStack(int capacity);

/**
 * @brief Mengecek apakah stack kosong atau tidak.
 * 
 * @param stack ItemStack instance.
 * @return true jika stack kosong, false selainnya.
 */
boolean isStackEmpty(ItemStack stack);

/**
 * @brief Mengecek apakah stack penuh atau tidak.
 * 
 * @param stack ItemStack instance.
 * @return true jika stack penuh, false selainnya.
 */
boolean isStackFull(ItemStack stack);

/**
 * @brief Memasukkan item ke atas stack.
 * 
 * @param stack ItemStack instance.
 * @param item Item yang akan dimasukkan ke atas stack.
 */
void push(ItemStack *stack, Item item);

/**
 * @brief Mengambil item dari atas stack.
 * 
 * @param stack ItemStack instance.
 * @param[out] item Item yang diambil dari atas stack.
 */
void pop(ItemStack *stack, Item *item);

/**
 * @brief Menambah kapasitas stack sebanyak 1.
 * Kapasitas tidak bertambah jika telah mencapai
 * kapasitas maksimum (100).
 * 
 * @param stack ItemStack instance. 
 */
void incrementCapacity(ItemStack *stack);

/**
 * @brief Menggandakan kapasitas stack.
 * Kapasitas tidak bertambah hingga melebihi
 * kapasitas maksimum (100).
 * 
 * @param stack ItemStack instance. 
 */
void doubleCapacity(ItemStack *stack);

/**
 * @brief Membatasi kapasitas stack jika
 * kapasitas melebihi batas.
 * 
 * @param stack ItemStack instance.
 */
void _clampCapacity(ItemStack *stack);

#endif