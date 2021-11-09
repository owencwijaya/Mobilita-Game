#include <stdio.h>
#include "../modules/core/globals.h"

void drop_off()
{
    printf("%c", symbol(dropOffLoc(top(gameState.bag))));
    if (isStackEmpty(gameState.bag) || gameState.currentLocation != dropOffLoc(top(gameState.bag)))
    {
        printf("Tidak dapat pesanan yang dapat diantarkan!\n");
    }
    else
    {
        deleteItemFirst(gameState.inProgressList);

        Item item = pop(gameState.bag);
        // unsetColors(temp);
        unsetAsDropOffPlace(dropOffLoc(item));
        unsetAsPickUpPlace(pickUpLoc(item));
        if (!isStackEmpty(gameState.bag))
        {
            Item topItem = top(gameState.bag);
            // setColors(top(gameState.bag));
            setAsDropOffPlace(dropOffLoc(topItem));
            setAsPickUpPlace(pickUpLoc(topItem));
        }

        if (isNormalItem(item))
        {
            printf("Pesanan Normal Item berhasil diantarkan!\n");
            gameState.cash += 200;
            printf("Uang yang didapatkan: 200 Yen\n");
        }
        else if (isHeavyItem(item))
        {
            printf("Pesanan Heavy Item berhasil diantarkan!\n");
            gameState.cash += 400;
            printf("Uang yang didapatkan: 400 Yen\n");
            gameState.abs.HeavyItemStack--;

            // Jika tidak membawa HeavyItem lain, Speed Boost akan aktif

            printf("Speed Boost activated!\n");
            gameState.abs.IsHeavyItemOn = false;
            gameState.abs.SpeedBoostStack = 5;
            gameState.abs.SpeedBoost = true;
        }
        else if (isPerishableItem(item))
        {
            printf("Pesanan Perishable Item berhasil diantarkan!\n");
            gameState.cash += 400;
            printf("Uang yang didapatkan: 400 Yen\n");
            printf("Kapasitas tas bertambah 1!\n");
            incrementCapacity(gameState.bag);
        }
        else
        { // Kalau gak jadi pake bonus VIP item, hapus aja ini (WIP)
            printf("Pesanan VIP Item berhasil diantarkan!\n");
            gameState.cash += 600;
            printf("Uang yang didapatkan: 600 Yen\n");
        }
    }
}