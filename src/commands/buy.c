#include <stdio.h>
#include "../modules/core/globals.h"
#include "../modules/io/machines/charmachine.h"
#include "../models/macros.h"

void buy()
{
    gameState.cash = 99999;
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
            option = currentChar;
            adv();
            if (option == '1')
            {
                if (gameState.cash >= 800)
                {
                    gameState.cash -= 800;
                    setGadget(&gameState.inventory, gListLength(gameState.inventory), KAIN_PEMBUNGKUS_WAKTU);
                    printf("Gadget 'Kain Pembungkus Waktu' berhasil dibeli!\n");
                }
                else
                {
                    printf("Uang tidak cukup untuk membeli gadget!\n");
                }
            }
            else if (option == '2')
            {
                if (gameState.cash >= 1200)
                {
                    gameState.cash -= 1200;
                    setGadget(&gameState.inventory, gListLength(gameState.inventory), SENTER_PEMBESAR);
                    printf("Gadget 'Senter Pembesar' berhasil dibeli!\n");
                }
                else
                {
                    printf("Uang tidak cukup untuk membeli gadget!\n");
                }
            }
            else if (option == '3')
            {
                if (gameState.cash >= 1500)
                {
                    gameState.cash -= 1500;
                    setGadget(&gameState.inventory, gListLength(gameState.inventory), PINTU_KEMANA_SAJA);
                    printf("Gadget 'Pintu Kemana Saja' berhasil dibeli!\n");
                }
                else
                {
                    printf("Uang tidak cukup untuk membeli gadget!\n");
                }
            }
            else if (option == '4')
            {
                if (gameState.cash >= 3000)
                {
                    gameState.cash -= 3000;
                    setGadget(&gameState.inventory, gListLength(gameState.inventory), MESIN_WAKTU);
                    printf("Gadget 'Mesin Waktu' berhasil dibeli!\n");
                }
                else
                {
                    printf("Uang tidak cukup untuk membeli gadget!\n");
                }
            }
            else if (option == '5')
            {
                if (gameState.cash >= 800)
                {
                    gameState.cash -= 800;
                    setGadget(&gameState.inventory, gListLength(gameState.inventory), SENTER_PENGECIL);
                    printf("Gadget 'Senter Pengecil' berhasil dibeli!\n");
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