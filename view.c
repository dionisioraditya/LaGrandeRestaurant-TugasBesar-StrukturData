#include "header.h"
void printMainMenuKasir(int x, int y, int input) {
    blue();
    gotoxy(x, y);
    printf("=== [ Menu Utama Kasir] ===");
    resetColor();
    if (input==0) green(); else resetColor();
    y++;
    gotoxy(x, y);
    printf("[+] Input Pesanan Nota Baru");

    if (input==1) green(); else resetColor();
    y++;
    gotoxy(x, y);
    printf("[++] Tambah Pesanan ");

    if (input==2) green(); else resetColor();
    y++;
    gotoxy(x, y);
    printf("[X?->Y?] Gabung Nota");

    if (input==3) green(); else resetColor();
    y++;
    gotoxy(x, y);
    printf("[$] Bayar Pesanan");

    if (input==4) green(); else resetColor();
    y++;
    gotoxy(x, y);
    printf("[%%] Lihat Omzet hari ini");

    if (input==5) green(); else resetColor();
    y++;
    gotoxy(x, y);
    printf("[<->] Split Nota");

    if (input==6) green(); else resetColor();
    y++;
    gotoxy(x, y);
    printf("[>>] Update Data Item Resto");

    resetColor();
    y++;
    gotoxy(x+3, y);
    printf("[ESC] Kembali");
}
void laGrandeSign() {
    green();
    printf(" __                  ____                             __                        \n");
    printf("/\\ \\                /\\  _`\\                          /\\ \\                       \n");
    printf("\\ \\ \\        __     \\ \\ \\L\\_\\  _ __   __      ___    \\_\\ \\     __               \n");
    printf(" \\ \\ \\  __ /'__`\\    \\ \\ \\L_L /\\`'__/'__`\\  /' _ `\\  /'_` \\  /'__`\\             \n");
    printf("  \\ \\ \\L\\ /\\ \\L\\.\\_   \\ \\ \\/, \\ \\ \\/\\ \\L\\.\\_/\\ \\/\\ \\/\\ \\L\\ \\/\\  __/             \n");
    printf("   \\ \\____\\ \\__/.\\_\\   \\ \\____/\\ \\_\\ \\__/.\\_\\ \\_\\ \\_\\ \\___,_\\ \\____\\            \n");
    printf("    \\/___/ \\/__/\\/_/    \\/___/  \\/_/\\/__/\\/_/\\/_/\\/_/\\/__,_ /\\/____/_           \n");
    purple();
    printf(" ___                    __                                         __            \n");
    printf("/\\  _`\\                /\\ \\__                                     /\\ \\__        \n");
    printf("\\ \\ \\L\\ \\     __    ___\\ \\ ,_\\    __    __  __  _ __   __      ___\\ \\ ,_\\       \n");
    printf(" \\ \\ ,  /   /'__`\\ /',__\\ \\ \\/  /'__`\\ /\\ \\/\\ \\/\\`'__/'__`\\  /' _ `\\ \\ \\/       \n");
    printf("  \\ \\ \\\\ \\ /\\  __//\\__, `\\ \\ \\_/\\ \\L\\.\\  \\ \\_\\ \\ \\ \\/\\ \\L\\.\\_/\\ \\/\\ \\ \\ \\_      \n");
    printf("   \\ \\_\\ \\_\\ \\____\\/\\____/\\ \\__\\ \\__/.\\_\\ \\____/\\ \\_\\ \\__/.\\_\\ \\_\\ \\_\\ \\__\\     \n");
    printf("    \\/_/\\/ /\\/____/\\/___/  \\/__/\\/__/\\/_/\\/___/  \\/_/\\/__/\\/_/\\/_/\\/_/\\/__/     \n");
    resetColor();
    printf("\n============================= [PRESS ESC FOR QUIT] =============================");
}
void loadingAnimation() {
    int i, j;
    for(i=0; i<100; i++) {
        system("cls");
        printf("\n\n\n\n\n\n\t\t\t\t\t\tLoading... %d%%\n", i);
        for (j=0; j<=i; j++) {
            printf("=");
            
        }
        //Sleep(0);
    }
}
void menuPertama(int menu) {
    if (menu == 1)
    {
        green();
        printf("\n #    #   ##    ####  # #####  ");
        printf("\n #   #   #  #  #      # #    # ");
        printf("\n ####   #    #  ####  # #    # ");
        printf("\n #  #   ######      # # #####  ");
        printf("\n #   #  #    # #    # # #   #  ");
        printf("\n #    # #    #  ####  # #    # ");
        resetColor();
        printf("\n ######     #    ######  #     # ######  ");
        printf("\n #     #   # #   #     # #     # #     # ");
        printf("\n #     #  #   #  #     # #     # #     # ");
        printf("\n #     # #     # ######  #     # ######  ");
        printf("\n #     # ####### #       #     # #   #  ");
        printf("\n #     # #     # #       #     # #    #  ");
        printf("\n ######  #     # #        #####  #     # ");
    }
    if(menu == 2) {
        resetColor();
        printf("\n #    #   ##    ####  # ##### ");
        printf("\n #   #   #  #  #      # #    # ");
        printf("\n ####   #    #  ####  # #    # ");
        printf("\n #  #   ######      # # #####  ");
        printf("\n #   #  #    # #    # # #   #  ");
        printf("\n #    # #    #  ####  # #    # ");
        green();
        printf("\n ######     #    ######  #     # ######  ");
        printf("\n #     #   # #   #     # #     # #     # ");
        printf("\n #     #  #   #  #     # #     # #     # ");
        printf("\n #     # #     # ######  #     # ######  ");
        printf("\n #     # ####### #       #     # #   #  ");
        printf("\n #     # #     # #       #     # #    #  ");
        printf("\n ######  #     # #        #####  #     # ");
        resetColor();
    }
}
void keyGuide(int x, int y) {
    gotoxy(x, y);
    printf("Press 'W' up and 'S' down");
    y++;
    gotoxy(x, y);
    printf("Press 'Enter' to choose");
    y++;
    gotoxy(x, y);
    printf("developed by: Dionisio Raditya (230712370)");
}
void errorMessageParentNULL(int x, int y) {
    gotoxy(x, y);
    printf("Data tidak ada");
    y++;
    gotoxy(x, y);
    printf("\033[1;34mPress Space...");
    resetColor();
}
void resetColor() {
  printf("\033[1;37m");
}
void red() {
  printf("\033[1;31m");
}
void blue() {
  printf("\033[1;34m");
}
void green() {
  printf("\033[1;32m");
}
void purple() {
  printf("\033[1;35m");
}
void printPaperDapur(MultiList L, AddressParent target) {
  AddressParent P = L.firstParent;
  while (P !=NULL)
  {
    if(P->dataParent.statusProduksi == false) {
      if (P == target)
      { 
          blue();
          printf("\n\t === Nota ===");
          printf("\n\t[-] Nomor Nota            : %d", P->dataParent.nomorNota);
          printf("\n\t[-] Nomor Meja            : %d", P->dataParent.nomorMeja);
          if(P->dataParent.statusProduksi== false)printf("\n\t[-] Status Produksi       : Proses");
          else printf("\n\t[-] Status Produksi       : Selesai");
          printf("\n\t[-] Total Item            : %d", P->dataParent.totalItem);
          AddressChild temp = P->firstChild;
          while (temp != NULL)
          {
            printf("\n\n\t\t[+] Nama Item : %s", temp->dataChild.namaItem);
            printf("\n\t\t[+] Tipe Item : %s", temp->dataChild.tipeItem);
            temp = temp->next;
          }
          resetColor();
      } else {
          printf("\n\t === Nota ===");
          printf("\n\t[-] Nomor Nota            : %d", P->dataParent.nomorNota);
          printf("\n\t[-] Nomor Meja            : %d", P->dataParent.nomorMeja);
          if(P->dataParent.statusProduksi== false)printf("\n\t[-] Status Produksi       : Proses");
          else printf("\n\t[-] Status Produksi       : Selesai");
          printf("\n\t[-] Total Item            : %d", P->dataParent.totalItem);
          AddressChild temp = P->firstChild;
          while (temp != NULL)
          {
            printf("\n\n\t\t[+] Nama Item : %s", temp->dataChild.namaItem);
            printf("\n\t\t[+] Tipe Item : %s", temp->dataChild.tipeItem);
            temp = temp->next;
          }
      }
      printf("\n");
    }
      
    P = P->next;
  }    
}
void menuUpdateItemResto(int value, int x, int y) {
  if (value==1)
  {
    green();
    gotoxy(x, y);
    printf("[+] Tambah Item");
    resetColor();
    y++;
    gotoxy(x, y);
    printf("[+] Hapus Item");
  } else if(value == 2) {
    gotoxy(x, y);
    printf("[+] Tambah Item");
    green();
    y++;
    gotoxy(x, y);
    printf("[+] Hapus Item");
    resetColor();
  }
  
}
void keyLogicMenuUpdateItem(char kb, int *value) {
  if (kb == 'w')
  {
    *value = 1;
  } 
  if (kb == 's')
  {
    *value = 2;
  }
}