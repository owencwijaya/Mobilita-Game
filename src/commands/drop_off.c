#include "../modules/core/globals.h"
#include "../modules/io/machines/charmachine.h"

void drop_off(){
    if (isStackEmpty(gameState.bag) || gameState.currentLocation != gameState.bag.buffer[gameState.bag.topIndex].dropOffLocation){
        printf("Tidak dapat pesanan yang dapat diantarkan!\n");
    } else {

        deleteItemFirst(&gameState.inProgressList);

        Item temp;
        pop(&gameState.bag, &temp);

        if (isNormalItem(temp)){
            printf("Pesanan Normal Item berhasil diantarka!\n");
            gameState.cash += 200;
            printf("Uang yang didapatkan: 200 Yen\n");

        } else if (isHeavyItem(temp)){
            printf("Pesanan Heavy Item berhasil diantarkan!\n");
            gameState.cash += 400;
            printf("Uang yang didapatkan: 400 Yen\n");
            gameState.abs.HeavyItemStack--;

            // Jika tidak membawa HeavyItem lain, Speed Boost akan aktif
            if (gameState.abs.HeavyItemStack == 0){
                printf("Speed Boost activated!\n");
                gameState.abs.IsHeavyItemOn = false;
                gameState.abs.SpeedBoostCount++; // Bener gak ini +1 doang Speed Boost countnya? wkwkwk
                gameState.abs.SpeedBoost = true;
            }

        } else if (isPerishableItem(temp)){
            printf("Pesanan Perishable Item berhasil diantarkan!\n");
            gameState.cash += 400;
            printf("Uang yang didapatkan: 400 Yen\n");
            printf("Kapasitas tas bertambah 1!\n")
            incrementCapacity(&gameState.bag);

        } else { // Kalau gak jadi pake bonus VIP item, hapus aja ini (Algoritmanya juga WIP)
            printf("Pesanan VIP Item berhasil diantarkan!\n");
            gameState.cash += 600;
            printf("Uang yang didapatkan: 600 Yen\n");
        }
    }
}