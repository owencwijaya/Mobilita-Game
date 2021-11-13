#include <stdio.h>
#include "../modules/core/globals.h"
#include "../modules/io/machines/charmachine.h"
#include "../models/macros.h"

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
            //cari perishable item teratas, ini buat inprogress?
            /*
            ItemStack tempStack = newItemStack(capacity(gameState.bag));
            // untuk penyimpanan sementara
            Item temp;
            int i = 0;
            boolean found = false;
            
            while (!isStackEmpty(gameState.bag) && !found)
            {
                pop(&gameState.bag, &temp);
                if (itemType(temp) == PERISHABLE)
                {
                    found = true;
                    temp.perishTime = perishTimeReference(temp);
                    setItem(&gameState.inProgressList, i, temp);
                }
                push(&tempStack, temp);
                i++;
            }

            while (!isStackEmpty(tempStack))
            {
                pop(&tempStack, &temp);
                push(&gameState.bag, temp);
            }
            */

           if (itemType(top(gameState.bag)) == PERISHABLE)
                {
                    top(gameState.bag).perishTime = perishTimeReference(top(gameState.bag));
                    setItem(&gameState.inProgressList, topIndex(gameState.bag), top(gameState.bag));
                }
            printf("Gadget 'Kain Pembungkus Waktu' berhasil digunakan!\n");
            setGadget(&gameState.inventory, (int)(option - '0') - 1, NULL_GADGET);
        }
        else if (isGadgetIdentical(tempGadget, SENTER_PEMBESAR))
        {
            //algo buat senter pembesar
            //Senter pembesar dapat digunakan untuk meningkatkan kapasitas tas
            //sebesar dua kali lipat, namun tidak melebihi batas maksimum kapasitas tas.
            doubleCapacity(&gameState.bag);
            printf("Gadget 'Pintu Kemana Saja' berhasil digunakan!\n");
            printf("Kapasitas tas Mobita membesar menjadi dua kali lipat...\n");
            setGadget(&gameState.inventory, (int)(option - '0') - 1, NULL_GADGET);
        }
        else if (isGadgetIdentical(tempGadget, PINTU_KEMANA_SAJA))
        {
            //algo buat pintu kemana saja
            //Pintu Kemana Saja dapat digunakan sekali untuk berpindah ke lokasi yang
            //diinginkan tanpa menambahkan unit waktu.
            gameState.abs.PintuKemanaSaja = true;
            printf("Gadget 'Pintu Kemana Saja' berhasil digunakan!\n");
            printf("Gunakan perintah 'MOVE' untuk berpindah tanpa menambah waktu!\n");
            setGadget(&gameState.inventory, (int)(option - '0') - 1, NULL_GADGET);
            //nanti pake fungsi move, tapi ga nambahin waktu
        }
        else if (isGadgetIdentical(tempGadget, MESIN_WAKTU))
        {
            //algo buat mesin waktu
            //Mesin waktu dapat digunakan untuk mengurangi waktu sebanyak 50 unit.
            //(jika waktu kurang dari 50 unit, maka waktu menjadi 0 unit).
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
            if (top(gameState.bag).type == HEAVY){
                gameState.abs.HeavyItemStack -= 1;
                if (gameState.abs.HeavyItemStack == 0){
                    gameState.abs.IsHeavyItemOn = false;
                }
            gameState.abs.IsSenterPengecilOn = true;
            printf("Gadget 'Senter Pengecil' berhasil digunakan!\n");
            printf("Beban dari satu heavy item berhasil dikurangi.\n");
            setGadget(&gameState.inventory, (int)(option - '0') - 1, NULL_GADGET);
            }
            //algo buat senter pengecil
            //Senter pengecil dapat digunakan untuk menghilangkan efek dari satu heavy
            //item jika terdapat pada tumpukan teratas tas. Efek dari senter pengecil ini
            //akan berlangsung sampai melakukan drop off / return pertama kali setelah
            //penggunaan gadget ini.
        }
        else
        {
            printf("Tidak ada gadget yang dipilih.\n");
            printf("Mengembalikan ke main menu...\n\n");
        }
    }
}