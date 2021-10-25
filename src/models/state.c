/**
 * @file state.c
 * @brief Implementasi State pada game.
 */

#include "game_map.h"
#include "item_list.h"
#include "item_queue.h"
#include "item_stack.h"
#include "gadget_list.h"
#include "state.h"

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
State newState(GameMap m, ItemList todo, ItemList inProgress, ItemStack bag, ItemQueue order)
{
    State state;
    state.gameMap = m;
    state.todoList = todo;
    state.inProgressList = inProgress;
    state.bag = bag;
    state.order = order;
    state.time = 0;
    state.cash = 0;
    state.inventory = newGadgetList();
    state.currentLocation = getLocationById(m, 0);
    return state;
}

/**
 * @brief Reevaluasi state setelah player menjalankan
 * suatu command atau setelah waktu bertambah.
 * 
 * @param state State saat ini.
 */
void reevaluate(State *state)
{
}