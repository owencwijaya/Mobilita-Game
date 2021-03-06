#include <stdio.h>
#include "../../models/shared/macros.h"
#include "../globals.h"

void drop_off()
{
    if (isStackEmpty(gameState.bag) || !isLocationIdentical(gameState.currentLocation, top(gameState.bag).dropOffLocation))
    {
        printf("Tidak ada pesanan yang dapat diantarkan!\n");
    }
    else
    {

        Item dump;
        deleteItemLast(&gameState.inProgressList, &dump);

        Item temp;
        pop(&gameState.bag, &temp);
        unsetAsDropOffPlace(&gameState.gameMap._locationMatrix.contents[temp.dropOffLocation.coordinate.x][temp.dropOffLocation.coordinate.y]);
        if (!isStackEmpty(gameState.bag))
        {
            setAsDropOffPlace(&gameState.gameMap._locationMatrix.contents[top(gameState.bag).dropOffLocation.coordinate.x][top(gameState.bag).dropOffLocation.coordinate.y]);
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
            if (gameState.abs.IsSenterPengecilOn)
            {
                gameState.abs.IsSenterPengecilOn = false;
            }
            else
            {
                gameState.abs.HeavyItemStack--;
            }

            if (gameState.abs.HeavyItemStack == 0)
            {
                gameState.abs.IsHeavyItemOn = false;
            }

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
        {
            printf("Pesanan VIP Item berhasil diantarkan!\n");
            gameState.cash += 600;
            printf("Uang yang didapatkan: 600 Yen\n");
            gameState.abs.IsReturnOn = true;
            gameState.abs.ReturnStack++;

            gameState.abs.VIPItemStack--;
            if (gameState.abs.VIPItemStack == 0)
            {
                gameState.abs.IsVIPItemOn = false;
            }

            printf("Efek 'Return to Sender' bertambah menjadi %d.\n", gameState.abs.ReturnStack);
        }
    }
    printf("\n");
}