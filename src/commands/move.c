#include <stdio.h>
#include "../models/state.h"
#include "../models/macros.h"
#include "../modules/core/globals.h"
#include "../modules/io/word_utils.h"

void move()
{
    // terimalokasi awal
    LocationList adjlocation = getAdjacentLocations(locList(gameState.gameMap), gameState.currentLocation, adjMatrix(gameState.gameMap));
    displayAdjacentLocation(gameState.gameMap, gameState.currentLocation);

    // terima input dan cek kevalidan input
    int ChoiceNumber;
    boolean ChoiceValid = false;
    while (!ChoiceValid)
    {
        printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n\n");
        printf("ENTER COMMAND: ");
        readConsoleInput();
        readWord();
        char *str = stringify(currentWord);
        ChoiceNumber = parseInt(str);
        if ((ChoiceNumber <= length(adjlocation)) && (ChoiceNumber > 0))
        {
            gameState.currentLocation = lElem(adjlocation, (ChoiceNumber - 1));
            incrementTime(&gameState, 1 + gameState.abs.HeavyItemStack - gameState.abs.IsSenterPengecilOn);
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
    printf("Mobita sekarang berada di titk %c ", symbol(gameState.currentLocation));
    displayPoint(coord(gameState.currentLocation));
    printf("!\n");
    printf("Waktu : %d", gameState.time);
}