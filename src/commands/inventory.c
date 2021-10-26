#include "../modules/core/globals.h"
#include "../modules/io/machines/charmachine.h"

void inventory(){
    displayGadget(gameState.inventory);
    if (gListLength(gameState.inventory) == 0){
        printf("Inventory kosong!\n");
    } else {
        printf("Gadget mana yang ingin digunakan? \n");
        printf("(Ketik 0 jika ingin kembali)\n\n");
        printf("ENTER OPTION: ");
        int option;
        readConsoleInput();
        option = currentChar;
        adv();
        Gadget tempGadget = getGadget(gameState.inventory, (int)(option - '0') - 1);
        

        if (isGadgetIdentical(tempGadget, KAIN_PEMBUNGKUS_WAKTU)){
            //cari perishable item teratas
            ItemStack tempStack = newItemStack(topIndex(gameState.bag));; // untuk penyimpanan sementara
            Item temp;
            boolean found = false;
            while (!isStackEmpty(gameState.bag) && !found){
                pop(&gameState.bag, &temp);
                if (itemType(temp) == PERISHABLE){
                    found = true;
                    perishTime(temp) = perishTimeReference(temp);
                    push(&tempStack, temp);
                } else {
                    push(&tempStack, temp);
                }
            }

            while (!isStackEmpty(tempStack)){
                pop(&tempStack, &temp);
                push(&gameState.bag, temp);
            }

            if (found){
                printf("Gadget 'Kain Pembungkus Waktu' berhasil digunakan!\n");
                setGadget(&gameState.inventory, (int)(option - '0') - 1, NULL_GADGET);
            } else {
                printf("Perishable item tidak ditemukan!\n");
            }
        } else if (isGadgetIdentical(tempGadget, SENTER_PEMBESAR)){
            //algo buat senter pembesar
            //Senter pembesar dapat digunakan untuk meningkatkan kapasitas tas
            //sebesar dua kali lipat, namun tidak melebihi batas maksimum kapasitas tas.
            doubleCapacity(&gameState.bag);
            printf("Gadget 'Pintu Kemana Saja' berhasil digunakan!\n");
            printf("Kapasitas tas Mobita membesar menjadi dua kali lipat...\n");
            setGadget(&gameState.inventory, (int)(option - '0') - 1, NULL_GADGET);
        } else if (isGadgetIdentical(tempGadget, PINTU_KEMANA_SAJA)){
            //algo buat pintu kemana saja
            //Pintu Kemana Saja dapat digunakan sekali untuk berpindah ke lokasi yang
            //diinginkan tanpa menambahkan unit waktu.

            //nanti pake fungsi move, tapi ga nambahin waktu
        } else if (isGadgetIdentical(tempGadget, MESIN_WAKTU)){
            //algo buat mesin waktu
            //Mesin waktu dapat digunakan untuk mengurangi waktu sebanyak 50 unit.
            //(jika waktu kurang dari 50 unit, maka waktu menjadi 0 unit).
            if (gameState.time < 50){
                gameState.time = 0;
            } else {
                gameState.time -= 50;
            }
            printf("Gadget 'Mesin Waktu' berhasil dipakai!\n");
            printf("Waktu berkurang sebanyak 50...\n");
            setGadget(&gameState.inventory, (int)(option - '0') - 1, NULL_GADGET);
        } else if (isGadgetIdentical(tempGadget, SENTER_PENGECIL)){
            gameState.abs.IsSenterPengecilOn = true;
            //algo buat senter pengecil
            //Senter pengecil dapat digunakan untuk menghilangkan efek dari satu heavy
            //item jika terdapat pada tumpukan teratas tas. Efek dari senter pengecil ini
            //akan berlangsung sampai melakukan drop off / return pertama kali setelah
            //penggunaan gadget ini.

        } else {
            printf("Tidak ada gadget yang dipilih.\n");
            printf("Mengembalikan ke main menu...\n\n");
        }
    }
}