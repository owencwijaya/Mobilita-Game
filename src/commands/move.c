#include <stdio.h>
#include "../models/state.h"
#include "../models/macros.h"
#include "../modules/core/globals.h"
#include "../modules/io/word_utils.h"

void move()
{   
    printf("Lokasi-lokasi yang dapat diakses: \n");
    // terimalokasi awal
    LocationList adjlocation = getAdjacentLocations(locList(gameState.gameMap), gameState.currentLocation, adjMatrix(gameState.gameMap));
    displayAdjacentLocation(gameState.gameMap, gameState.currentLocation);

    // terima input dan cek kevalidan input
    int ChoiceNumber;
    boolean ChoiceValid = false;
    while (!ChoiceValid)
    {
        printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
        if (gameState.abs.PintuKemanaSaja){
            printf("Gadget 'Pintu Kemana Saja' akan digunakan!\n\n");
        }
        if (gameState.abs.SpeedBoost){
            printf("SPEEDBOOST aktif!\n");
            printf("Berlaku untuk %d kali pemakaian.", gameState.abs.SpeedBoostStack);
        }
        printf("ENTER COMMAND: ");
        readConsoleInput();
        readWord();
        char *str = stringify(currentWord);
        ChoiceNumber = parseInt(str);
        int time = 0;
        if ((ChoiceNumber <= length(adjlocation)) && (ChoiceNumber > 0))
        {
            gameState.currentLocation = lElem(adjlocation, (ChoiceNumber - 1));
            if (gameState.abs.IsHeavyItemOn && gameState.abs.HeavyItemStack > 0){
                time = 2 * gameState.abs.HeavyItemStack;
            } else if (gameState.abs.PintuKemanaSaja){
                time = 0;
                gameState.abs.PintuKemanaSaja = false;
            } else {
                time = 1;
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
    printf("Mobita sekarang berada di titk %c ", symbol(gameState.currentLocation));
    displayPoint(coord(gameState.currentLocation));
    setAsPlayerPlace(&gameState.gameMap._locationMatrix.contents[gameState.currentLocation.coordinate.x][gameState.currentLocation.coordinate.y]);
    printf("!\n");
    printf("Waktu : %d", gameState.time);
}