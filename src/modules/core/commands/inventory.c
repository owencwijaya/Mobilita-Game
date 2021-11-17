#include <stdio.h>
#include "../../io/machines/charmachine.h"
#include "../../models/shared/macros.h"
#include "../globals.h"

void inventory()
{
    displayGadget(gameState.inventory);
    if (gListLength(gameState.inventory) == 0)
    {
        printf("Inventory kosong!\n");
    }
    else
    {
        printf("Gadget mana yang ingin digunakan? \n");
        printf("(Ketik 0 jika ingin kembali)\n\n");
        printf("ENTER OPTION: ");
        int option;
        readConsoleInput();
        option = currentChar;
        adv();
        Gadget tempGadget = getGadget(gameState.inventory, (int)(option - '0') - 1);

        if (isGadgetIdentical(tempGadget, KAIN_PEMBUNGKUS_WAKTU))
        {
            if (itemType(top(gameState.bag)) == PERISHABLE)
            {
                top(gameState.bag).perishTime = perishTimeReference(top(gameState.bag));
                setItem(&gameState.inProgressList, topIndex(gameState.bag), top(gameState.bag));
            }
            printf("Gadget 'Kain Pembungkus Waktu' berhasil digunakan!\n");
            printf("Waktu perishable dari item teratas di tas diubah menjadi default...\n");
            setGadget(&gameState.inventory, (int)(option - '0') - 1, NULL_GADGET);
        }
        else if (isGadgetIdentical(tempGadget, SENTER_PEMBESAR))
        {
            doubleCapacity(&gameState.bag);
            printf("Gadget 'Senter Pembesar' berhasil digunakan!\n");
            printf("Kapasitas tas Mobita membesar menjadi dua kali lipat...\n");
            setGadget(&gameState.inventory, (int)(option - '0') - 1, NULL_GADGET);
        }
        else if (isGadgetIdentical(tempGadget, PINTU_KEMANA_SAJA))
        {
            gameState.abs.PintuKemanaSaja = true;
            printf("Gadget 'Pintu Kemana Saja' berhasil digunakan!\n");
            printf("Gunakan perintah 'MOVE' untuk berpindah tanpa menambah waktu!\n");
            setGadget(&gameState.inventory, (int)(option - '0') - 1, NULL_GADGET);
        }
        else if (isGadgetIdentical(tempGadget, MESIN_WAKTU))
        {
            if (gameState.time < 50)
            {
                gameState.time = 0;
            }
            else
            {
                gameState.time -= 50;
            }
            printf("Gadget 'Mesin Waktu' berhasil dipakai!\n");
            printf("Waktu berkurang sebanyak 50...\n");
            setGadget(&gameState.inventory, (int)(option - '0') - 1, NULL_GADGET);
        }
        else if (isGadgetIdentical(tempGadget, SENTER_PENGECIL))
        {
            if (gameState.abs.IsSenterPengecilOn == false)
            {
                if (top(gameState.bag).type == HEAVY)
                {
                    gameState.abs.HeavyItemStack -= 1;
                    if (gameState.abs.HeavyItemStack == 0)
                    {
                        gameState.abs.IsHeavyItemOn = false;
                    }
                    gameState.abs.IsSenterPengecilOn = true;
                    printf("Gadget 'Senter Pengecil' berhasil digunakan!\n");
                    printf("Beban dari satu heavy item berhasil dikurangi.\n");
                    setGadget(&gameState.inventory, (int)(option - '0') - 1, NULL_GADGET);
                }
            }
            else
            {
                printf("Gadget 'Senter Pengecil' sedang digunakan!");
            }
        }
        else
        {
            printf("Tidak ada gadget yang dipilih.\n");
            printf("Mengembalikan ke main menu...\n");
        }
        printf("\n");
    }
}