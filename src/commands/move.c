#include <stdio.h>
#include "../models/state.h"
#include "../models/macros.h"
#include "../modules/core/globals.h"
#include "../modules/io/word_utils.h"
#include "../modules/colorizer/colorizer.h"

void move()
{   
    printf("Lokasi-lokasi yang dapat diakses: \n");
    // terimalokasi awal
    unsetAsPlayerPlace(&gameState.gameMap._locationMatrix.contents[gameState.currentLocation.coordinate.x][gameState.currentLocation.coordinate.y]);
    LocationList adjlocation = getAdjacentLocations(locList(gameState.gameMap), gameState.currentLocation, adjMatrix(gameState.gameMap));
    displayAdjacentLocation(gameState.gameMap, gameState.currentLocation);

    
    for (int i = 0; i < length(adjlocation); i++){
        unsetAsReachable(&gameState.gameMap._locationMatrix.contents[adjlocation.buffer[i].coordinate.x][adjlocation.buffer[i].coordinate.y]);
    }

    // terima input dan cek kevalidan input
    int ChoiceNumber;
    int time = 0;
    boolean ChoiceValid = false;
    while (!ChoiceValid)
    {
        printf("Posisi yang dipilih? (ketik 0 jika ingin kembali)\n");
        if (gameState.abs.PintuKemanaSaja){
            printf("Gadget 'Pintu Kemana Saja' akan digunakan!\n\n");
        }
        if (gameState.abs.SpeedBoost){
            printf("Speedboost aktif!\n");
            printf("Berlaku untuk %d kali pemakaian.\n\n", gameState.abs.SpeedBoostStack);
        }
        printf("ENTER COMMAND: ");
        readConsoleInput();
        readWord();
        char *str = stringify(currentWord);
        ChoiceNumber = parseInt(str);
        
        if ((ChoiceNumber <= length(adjlocation)) && (ChoiceNumber > 0))
        {
            gameState.currentLocation = lElem(adjlocation, (ChoiceNumber - 1));
             if (gameState.abs.PintuKemanaSaja){
                time = 0;
                gameState.abs.PintuKemanaSaja = false;
            } else if (gameState.abs.SpeedBoost) {
                if (gameState.abs.SpeedBoostCount == 0){
                    time = 0;
                    gameState.abs.SpeedBoostCount++;
                } else if (gameState.abs.SpeedBoostCount == 1){
                    time = 1;
                    gameState.abs.SpeedBoostCount--;
                    gameState.abs.SpeedBoostStack--;
                    if (gameState.abs.SpeedBoostStack == 0){
                        gameState.abs.SpeedBoost = false;
                    }
                } 
            }else if (gameState.abs.IsHeavyItemOn && gameState.abs.HeavyItemStack > 0){
                time = 1 + gameState.abs.HeavyItemStack;
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
            printf("Opsi input salah!\n");
        }
    }

    // tampilin hasil
    printf("\n");
    printf("Mobita sekarang berada di titik ");
    changeToOrangeColor();
    printf("%c", symbol(gameState.currentLocation));
    displayPoint(coord(gameState.currentLocation));
    resetColor();
    setAsPlayerPlace(&gameState.gameMap._locationMatrix.contents[gameState.currentLocation.coordinate.x][gameState.currentLocation.coordinate.y]);
    printf("!\n");
    changeToGreenColor();
    printf("Waktu : %d (+%d)", gameState.time, time);
    resetColor();
    
    LocationList newAdjLoc = getAdjacentLocations(locList(gameState.gameMap), gameState.currentLocation, adjMatrix(gameState.gameMap));
    for (int i = 0; i < length(newAdjLoc); i++){
        setAsReachable(&gameState.gameMap._locationMatrix.contents[newAdjLoc.buffer[i].coordinate.x][newAdjLoc.buffer[i].coordinate.y]);
    }
}