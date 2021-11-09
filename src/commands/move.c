#include <stdio.h>
#include "../models/state.h"
#include "../modules/core/globals.h"
#include "../modules/io/word_utils.h"

void move()
{
    Location currentLocation = gameState.currentLocation;
    LocationList lList = locList(gameState.gameMap);

    printf("Lokasi-lokasi yang dapat diakses: \n");
    // terimalokasi awal
    LocationList adjlocation = getAdjacentLocations(lList, currentLocation, adjMatrix(gameState.gameMap));

    int l = length(adjlocation);

    for (int i = 0; i < l; i++)
    {
        unsetAsReachable(lElem(adjlocation, i));
    }

    displayAdjacentLocation(gameState.gameMap, currentLocation);

    // for (int i = 0; i < length(adjlocation); i++)
    // {
    //     unsetAsReachable(&gameState.gameMap._locationMatrix.contents[adjlocation.buffer[i].coordinate.x][adjlocation.buffer[i].coordinate.y]);
    // }

    // terima input dan cek kevalidan input
    int ChoiceNumber;
    boolean ChoiceValid = false;
    while (!ChoiceValid)
    {
        printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
        if (gameState.abs.SpeedBoost)
        {
            printf("Speedboost aktif!\n");
            printf("Berlaku untuk %d kali pemakaian.\n\n", gameState.abs.SpeedBoostStack);
        }
        printf("ENTER COMMAND: ");
        readConsoleInput();
        readWord();
        char *str = stringify(currentWord);
        ChoiceNumber = parseInt(str);
        int time = 1;
        if ((ChoiceNumber <= length(adjlocation)) && (ChoiceNumber > 0))
        {
            gameState.currentLocation = lElem(adjlocation, (ChoiceNumber - 1));
            if (gameState.abs.IsHeavyItemOn && gameState.abs.HeavyItemStack > 0)
            {
                time += gameState.abs.HeavyItemStack;
            }
            else if (gameState.abs.SpeedBoost)
            {
                if (gameState.abs.SpeedBoostCount == 0)
                {
                    time = 0;
                    gameState.abs.SpeedBoostCount++;
                }
                else if (gameState.abs.SpeedBoostCount == 1)
                {
                    time = 1;
                    gameState.abs.SpeedBoostCount--;
                    gameState.abs.SpeedBoostStack--;
                    if (gameState.abs.SpeedBoostStack == 0)
                    {
                        gameState.abs.SpeedBoost = false;
                    }
                }
            }
            incrementTime(&gameState, time);
            ChoiceValid = true;
        }
        else if (ChoiceNumber == 0)
        {
            ChoiceValid = true;
        }
        else
        {
            printf("masukan salah!\n");
        }
    }

    // tampilin hasil
    printf("\n");
    printf("Mobita sekarang berada di titik %c ", symbol(gameState.currentLocation));
    displayPoint(coord(gameState.currentLocation));
    setAsPlayerPlace(gameState.currentLocation);
    printf("!\n");
    printf("Waktu : %d", gameState.time);

    adjlocation = getAdjacentLocations(lList, currentLocation, adjMatrix(gameState.gameMap));
    for (int i = 0; i < l; i++)
    {
        setAsReachable(lElem(adjlocation, i));
    }
}