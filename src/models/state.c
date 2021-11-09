/**
 * @file state.c
 * @brief Implementasi State pada game.
 */

#include <stdlib.h>
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
 * @brief Constructor untuk membuat state
 * boolean untuk ability
 */

AbilityStruct newAbilityStruct()
{
    AbilityStruct abs;
    abs.SpeedBoost = false;
    abs.SpeedBoostCount = 0;
    abs.SpeedBoostStack = 0;
    abs.IsSenterPengecilOn = false;
    abs.IsHeavyItemOn = false;
    abs.HeavyItemStack = 0;
    abs.IsVIPItemOn = false;
    abs.PintuKemanaSaja = false;
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
    // Tambah waktu saat ini
    state->time += diffTime;

    // Pindahkan order yang masuk
    // ke todo list
    Item item;
    ItemQueue order = state->order;
    ItemList todo = state->todoList;
    while (peekHeadTime(order) <= state->time && !isEmpty(order))
    {
        item = dequeue(order);
        insertItemLast(todo, item);
        setAsPickUpPlace(pickUpLoc(item));
        setAsDropOffPlace(dropOffLoc(item));
    }

    // Decrement perishTime perishable item atau
    // hapus jika durasi habis.
    // 1. Pada In Progress list
    ItemList inProgressList = state->inProgressList;
    int len = itemListLength(inProgressList);
    int i = 0;
    while (i < len)
    {
        Item item = getItem(inProgressList, i);
        Item garbage;
        if (itemType(item) == PERISHABLE)
        {
            perishTime(item) -= diffTime;
            if (perishTime(item) <= 0)
            {
                deleteItemAt(inProgressList, i);
            }
            else
            {
                setItem(inProgressList, i, item);
            }
        }
        i++;
    }

    // 2. Pada tas
    ItemStack bag = state->bag;
    ItemStack reversedBag = newItemStack(capacity(bag));
    while (!isStackEmpty(bag))
    {
        item = pop(bag);
        if (isPerishableItem(item))
        {
            if (perishTime(item) > diffTime)
            {
                perishTime(item) -= diffTime;
                push(reversedBag, item);
            }
        }
        else
        {
            push(reversedBag, item);
        }
    }
    while (!isStackEmpty(reversedBag))
    {
        item = pop(reversedBag);
        push(bag, item);
    }
    free(reversedBag);

    /**
     * @todo Hapus efek speedboost jika
     * waktunya telah habis.
     */
}