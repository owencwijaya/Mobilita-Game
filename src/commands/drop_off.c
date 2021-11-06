#include <stdio.h>
#include "../modules/core/globals.h"
#include "../models/macros.h"

void drop_off()
{
    printf("%c", top(gameState.bag).dropOffLocation.symbol);
    if (isStackEmpty(gameState.bag) || !isLocationIdentical(gameState.currentLocation, top(gameState.bag).dropOffLocation))
    {
        printf("Tidak dapat pesanan yang dapat diantarkan!\n");
    }
    else
    {
        Item dump;
        deleteItemFirst(&gameState.inProgressList, &dump);

        Item temp;
        pop(&gameState.bag, &temp);
        unsetColors(temp);
        unsetAsDropOffPlace(&gameState.gameMap._locationMatrix.contents[temp.dropOffLocation.coordinate.x][temp.dropOffLocation.coordinate.y]);
        unsetAsPickUpPlace(&gameState.gameMap._locationMatrix.contents[temp.pickUpLocation.coordinate.x][temp.pickUpLocation.coordinate.y]);
        if (!isStackEmpty(gameState.bag)){
            setColors(top(gameState.bag));
            setAsDropOffPlace(&gameState.gameMap._locationMatrix.contents[top(gameState.bag).dropOffLocation.coordinate.x][temp.dropOffLocation.coordinate.y]);
            setAsPickUpPlace(&gameState.gameMap._locationMatrix.contents[top(gameState.bag).pickUpLocation.coordinate.x][temp.pickUpLocation.coordinate.y]);
        }

        if (isNormalItem(temp))
        {
            printf("Pesanan Normal Item berhasil diantarkan!\n");
            gameState.cash += 200;
            printf("Uang yang didapatkan: 200 Yen\n");
        }
        else if (isHeavyItem(temp))
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
        else if (isPerishableItem(temp))
        {
            printf("Pesanan Perishable Item berhasil diantarkan!\n");
            gameState.cash += 400;
            printf("Uang yang didapatkan: 400 Yen\n");
            printf("Kapasitas tas bertambah 1!\n");
            incrementCapacity(&gameState.bag);
        }
        else
        { // Kalau gak jadi pake bonus VIP item, hapus aja ini (WIP)
            printf("Pesanan VIP Item berhasil diantarkan!\n");
            gameState.cash += 600;
            printf("Uang yang didapatkan: 600 Yen\n");
        }
    }
}