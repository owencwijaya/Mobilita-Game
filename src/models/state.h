/**
 * @file state.h
 * @brief Header file untuk State game.
 */

#ifndef STATE_H
#define STATE_H

#include "game_map.h"
#include "item_list.h"
#include "item_queue.h"
#include "item_stack.h"
#include "gadget_list.h"

/**
 * @brief Game state & life cycle.
 */
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
} State;

/**
 * @todo Implementasi State, termasuk fungsi-fungsi
 * yang mengubah State game, save State, dan
 * reevaluasi State setiap player menjalankan command.
 */

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
 * @brief Memindahkan Item dalam Todo List ke
 * In Progress List. Hanya dipanggil ketika
 * player melakukan pick up Item.
 * 
 * @param state State saat ini.
 * @param indexTodo Indeks item pada todo yang akan
 *                  dipindahkan.
 */
void moveItemToProgressList(State *state, int indexTodo);

/**
 * @brief Reevaluasi state setelah player menjalankan
 * suatu command atau setelah waktu bertambah.
 * 
 * @param state State saat ini.
 */
void reevaluate(State *state);

#endif