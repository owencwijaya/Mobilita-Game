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
#include "macros.h"

/**
 * @todo Implementasi State, termasuk fungsi-fungsi
 * yang mengubah State game, save State, dan
 * reevaluasi State setiap player menjalankan command.
 */

/**
 * @brief Constructor untuk membuat state
 * boolean untuk ability
 */

AbilityStruct newAbilityStruct(){
    AbilityStruct abs;
    abs.SpeedBoost = false;
    abs.SpeedBoostCount = 0;
    abs.IsSenterPengecilOn = false;
    abs.IsHeavyItemOn = false;
    abs.HeavyItemStack = 0;
    abs.IsVIPItemOn = false;
    return abs;
}
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
    state.abs = newAbilityStruct();
    return state;
}

/**
 * @brief Reevaluasi state setelah waktu bertambah.
 * 
 * @param state State saat ini.
 * @param diffTime Waktu yang bertambah.
 */
void incrementTime(State *state, int diffTime)
{
    // Pindahkan order yang masuk
    // ke todo list
    ItemQueue orders = state->order;
    Item item;
    while (peekHeadTime(orders) <= diffTime && !isEmpty(orders))
    {
        dequeue(&orders, &item);
        insertItemLast(&(state->todoList), item);
    }

    // Decrement perishTime perishable item atau
    // hapus jika durasi habis.
    ItemStack bag = state->bag;
    ItemStack reversedBag = newItemStack(capacity(bag));
    while (!isStackEmpty(bag))
    {
        pop(&bag, &item);
        if (isPerishableItem(item))
        {
            if (perishTime(item) > diffTime)
            {
                perishTime(item) -= diffTime;
                push(&reversedBag, item);
            }
        }
        else
        {
            push(&reversedBag, item);
        }
    }
    while (!isStackEmpty(reversedBag))
    {
        pop(&reversedBag, &item);
        push(&bag, item);
    }
    state->bag = bag;

    /**
     * @todo Hapus efek speedboost jika
     * waktunya telah habis.
     */

    // Tambah waktu saat ini
    state->time += diffTime;
}