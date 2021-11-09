#include <stdio.h>
#include "../models/gadget.h"
#include "../modules/core/globals.h"
#include "../modules/io/machines/charmachine.h"
#include "../modules/io/machines/wordmachine.h"
#include "../modules/io/word_utils.h"

void buy()
{
    if (gameState.cash == 0)
    {
        printf("Anda tidak mempunyai uang!\n");
    }
    else if (isGadgetListFull(gameState.inventory))
    {
        printf("Inventory penuh!");
    }
    else if (symbol(gameState.currentLocation) != '8')
    {
        printf("Anda sedang tidak berada di Headquarters!\n");
    }
    else
    {
        printf("Uang anda sekarang: %d Yen\n", gameState.cash);
        printf("Gadget yang tersedia: \n");
        printf("1. Kain Pembungkus Waktu (800 Yen) \n");
        printf("2. Senter Pembesar (1200 Yen) \n");
        printf("3. Pintu Kemana Saja (1500 Yen) \n");
        printf("4. Mesin Waktu (3000 Yen) \n");
        printf("5. Senter Pengecil (800 Yen) \n");
        printf("Gadget mana yang ingin kau beli? \n");
        printf("(Ketik 0 jika ingin kembali)\n\n");

        int option;
        if (isGadgetListFull(gameState.inventory))
        {
            printf("Inventory sudah penuh!\n");
            printf("Gunakan command 'INVENTORY' untuk mengecek");
        }
        else
        {
            printf("ENTER OPTION: ");
            readConsoleInput();
            readWord();
            option = parseInt(stringify(currentWord));
            if (option > 0 && option < 6)
            {
                Gadget gadget = GADGETS[option - 1];
                int price = price(gadget);
                if (gameState.cash >= price)
                {
                    gameState.cash -= price;
                    insertGadget(gameState.inventory, gadget);
                    printf("Gadget '%s' berhasil dibeli!\n", name(gadget));
                }
                else
                {
                    printf("Uang tidak cukup untuk membeli gadget!\n");
                }
            }
            else
            {
                printf("Tidak ada gadget yang dipilih.\n");
                printf("Mengembalikan ke main menu...\n\n");
            }
        }
    }
}