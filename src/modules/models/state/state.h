/**
 * @file state.h
 * @brief Header file untuk State game.
 */

#ifndef STATE_H
#define STATE_H

#include "../map/game_map.h"
#include "../item/item_list.h"
#include "../item/item_queue.h"
#include "../item/item_stack.h"
#include "../inventory/gadget_list.h"
#include "../shared/boolean.h"
/**
 * @brief Game state & life cycle.
 */

typedef struct
{
    /**
     * @brief Apakah speedboost aktif
     */
    boolean SpeedBoost;
    /**
     * @brief Menghitung jumlah langkah speedboost
     */
    int SpeedBoostCount;
    /**
     * @brief Menghitung berapa kali speedboost digunakan
     */
    int SpeedBoostStack;
    /**
     * @brief Mengecek apakah senter pengecil digunakan
     */
    boolean IsSenterPengecilOn;
    /**
     * @brief Mengecek apakah Mobita mempunyai efek heavy item
     */
    boolean IsHeavyItemOn;
    /**
     * @brief Jumlah heavy item di to do list
     */
    int HeavyItemStack;
    /**
     * @brief Mengecek apakah Mobita mempunyai efek VIP item
     */
    boolean IsVIPItemOn;
    /** 
     * @brief Mengecek jumlah VIP item
     */
    int VIPItemStack;
    /**
     * @brief Mengecek jumlah vip item di todo
     * 
     */
    int TodoVIP;
    /**
     * @brief Mengecek apakah Mobita mempunyai efek pintu kemana saja
     */

    boolean PintuKemanaSaja;
    /**
     * @brief Mengecek apakah item bisa dikembalikan ke 
     * sender
     */
    boolean IsReturnOn;
    /**
     * @brief Mengecek banyaknya efek
     * return to sender
     */
    int ReturnStack;
} AbilityStruct;

typedef struct
{
    /**
     * @brief Map dari game yang berjalan.
     */
    GameMap gameMap;
    /**
     * @brief ToDo List dari game yang berjalan.
     */
    ItemList todoList;
    /**
     * @brief In Progress List dari game yang berjalan.
     */
    ItemList inProgressList;
    /**
     * @brief Tas player.
     */
    ItemStack bag;
    /**
     * @brief Daftar pesanan dari game yang berjalan.
     */
    ItemQueue order;
    /**
     * @brief Inventory player.
     */
    GadgetList inventory;
    /**
     * @brief Uang player.
     */
    int cash;
    /**
     * @brief Lokasi player saat ini.
     */
    Location currentLocation;
    /**
     * @brief Waktu saat ini.
     */
    int time;
    /**
     * @brief Ability struct.
     */
    AbilityStruct abs;

} State;

/**
 * @brief Constructor untuk membuat state
 * boolean untuk ability
 */
AbilityStruct newAbilityStruct();

/**
 * @brief Constructor untuk membuat instance
 * (termasuk State) game yang baru.
 * 
 * @param m GameMap instance dari game instance ini.
 * @param todo Todo List dari game instance ini.
 * @param inProgress In Progress List dari game instance ini.
 * @param bag Tas player pada game instance  ini.
 * @param order Daftar pesanan pada game instance ini.
 * @return State 
 */
State newState(GameMap m, ItemList todo, ItemList inProgress, ItemStack bag, ItemQueue order);

/**
 * @brief Reevaluasi state setelah waktu bertambah.
 * 
 * @param state State saat ini.
 * @param diffTime Waktu yang bertambah.
 */
void incrementTime(State *state, int diffTime);

#endif