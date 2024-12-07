#include "header.h"

void gotoxy(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void hide_cur() {
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(consoleHandle, &info);
}
void get_current_date(str *date_str) {
    time_t t = time(NULL);
    struct tm *local_time = localtime(&t); // Konversi ke waktu lokal
    
    // Formatkan tanggal "YYYY-MM-DD"
    sprintf(*date_str, "%04d-%02d-%02d",
            local_time->tm_year + 1900,  // Tahun
            local_time->tm_mon + 1,     // Bulan
            local_time->tm_mday);       // Hari
}


int generateDateforNotaId() {
    time_t t = time(NULL);
    struct tm *local_time = localtime(&t);
    int year = local_time->tm_year + 1900;
    int month = local_time->tm_mon + 1;
    int day = local_time->tm_mday;
    int date = year*10000 + month*100 + day;
    return date;
}

void logicInputMenuKasir(char kb, int *value) {
    if (kb == 'w')
    {   
        if ((*value) == 0)
        {
            (*value) = 6;
        } else {
            (*value)--;
        }
    } 
    if (kb == 's')
    {   
        if ((*value) == 6)
        {
            (*value) = 0;
        } else {
            (*value)++;
        }
    }
}
void initDefaultMakananMinuman(LinkedList *L) {
    createEmptyLinkedList(L);
    DataItem item;
    AddressLinkedList P;
    // Makanan
    item = makeDataLinkedlist("Nasi Goreng", "makanan", 0, 13000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist("Fuyung Hay", "makanan", 0, 12000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist("Mie Goreng", "makanan", 0, 15000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist("Karee", "makanan", 0, 20000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist("Cap Cay", "makanan", 0, 22000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    // minuman
    item = makeDataLinkedlist("Es Teh", "minuman", 0, 4000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist("Lemon Tea", "minuman", 0, 5000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist("Pink Lava", "minuman", 0, 15000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist("Orange Water", "minuman", 0, 7000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist("Air Mineral", "minuman", 0, 3000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);
    
}
void initPaper (
    ReportPaper *paper, 
    float pemasukkan, 
    str tanggal, 
    str makananTerbanyak, 
    str minumanTerbanyak,
    int totalMakananTerbanyak,
    int totalMinumanTerbanyak,
    int totalKeseluruhanMakanan,
    int totalKeseluruhanMinuman,
    int totalKeseluruhanItem
) {
    paper->penghasilan = pemasukkan;
    strcpy(paper->tanggal, tanggal);
    strcpy(paper->makananTerbanyak, makananTerbanyak);
    strcpy(paper->minumanTerbanyak, minumanTerbanyak);
    paper->totalMakananTerbanyak = totalMakananTerbanyak;
    paper->totalMinumanTerbanyak = totalMinumanTerbanyak;
    paper->totalKeseluruhanMakanan = totalKeseluruhanMakanan;
    paper->totalKeseluruhanMinuman = totalKeseluruhanMinuman;
    paper->totalKeseluruhanItem = totalKeseluruhanItem;
}
void inputPaper (
    ReportPaper *paper, 
    float pemasukkan, 
    str tanggal, 
    str makananTerbanyak, 
    str minumanTerbanyak,
    int totalMakananTerbanyak,
    int totalMinumanTerbanyak,
    int totalKeseluruhanMakanan,
    int totalKeseluruhanMinuman,
    int totalKeseluruhanItem
) {
    paper->penghasilan += pemasukkan;
    strcpy(paper->tanggal, tanggal);
    strcpy(paper->makananTerbanyak, makananTerbanyak);
    strcpy(paper->minumanTerbanyak, minumanTerbanyak);
    paper->totalMakananTerbanyak = totalMakananTerbanyak;
    paper->totalMinumanTerbanyak = totalMinumanTerbanyak;
    paper->totalKeseluruhanMakanan = totalKeseluruhanMakanan;
    paper->totalKeseluruhanMinuman = totalKeseluruhanMinuman;
    paper->totalKeseluruhanItem = totalKeseluruhanItem;
}
void cetakPaper(ReportPaper paper, int x, int y) {
    gotoxy(x+4, y);
    printf("Omzet Hari ini");

    y+=2;
    gotoxy(x, y);
    printf("Tanggal             : %s", paper.tanggal);
    y+=1;
    gotoxy(x, y);
    printf("Penghasilan         : Rp %.2f", paper.penghasilan);
    y+=1;
    gotoxy(x, y);
    printf("Makanan Terlaris    : %s sebanyak %d buah", paper.makananTerbanyak, paper.totalMakananTerbanyak);
    y+=1;
    gotoxy(x, y);
    printf("Minuman Terlaris    : %s sebanyak %d buah", paper.minumanTerbanyak, paper.totalMinumanTerbanyak);
    y+=1;
    gotoxy(x, y);
    printf("Total makanan terjual    : %d", paper.totalKeseluruhanMakanan);
    y+=1;
    gotoxy(x, y);
    printf("Total minuman terjual    : %d", paper.totalKeseluruhanMinuman);
    y+=1;
    gotoxy(x, y);
    printf("Total keseluruhan        : %d", paper.totalKeseluruhanItem);
    
    

    
}

// fungsi menyimpan total makanan minuman terjual
void sumItemSold(LinkedList * linklist, AddressParent p) {
    int makanan=0, minuman=0;
    AddressLinkedList temp;
    AddressChild ch = p->firstChild;
    while (ch!=NULL)
    {
        temp = findLinkList(*linklist, ch->dataChild.namaItem);
        if (temp!= NULL)
        {
            temp->data.jumlah++;
        }
        ch = ch->next;
    }
    
}
// Fungsi untuk menyimpan data multilist ke file
void saveDataToFile(MultiList L, LinkedList itemList, ReportPaper paper, const char * filename) {
    FILE *fp = fopen(filename, "w");
    if(fp == NULL) {
        printf("Error: Tidak dapat membuka file untuk menyimpan data\n");
        return;
    }

    // Menyimpan data ReportPaper
    fprintf(fp, "REPORT_PAPER\n");
    fprintf(fp, "%.2f\n", paper.penghasilan);
    fprintf(fp, "%s\n", paper.tanggal);
    fprintf(fp, "%s\n", paper.makananTerbanyak);
    fprintf(fp, "%s\n", paper.minumanTerbanyak);
    fprintf(fp, "%d\n", paper.totalMakananTerbanyak);
    fprintf(fp, "%d\n", paper.totalMinumanTerbanyak);
    fprintf(fp, "%d\n", paper.totalKeseluruhanMakanan);
    fprintf(fp, "%d\n", paper.totalKeseluruhanMinuman);
    fprintf(fp, "%d\n", paper.totalKeseluruhanItem);

    // Menyimpan data LinkedList (item resto)
    fprintf(fp, "ITEM_LIST\n");
    AddressLinkedList curr = itemList.first;
    while(curr != NULL) {
        fprintf(fp, "%s,%s,%d,%.2f,%.2f\n", 
            curr->data.itemName,
            curr->data.kategori,
            curr->data.jumlah,
            curr->data.harga,
            curr->data.totalPenjualan);
        curr = curr->next;
    }

    // Menyimpan data MultiList (nota dan item)
    fprintf(fp, "MULTILIST\n");
    AddressParent currParent = L.firstParent;
    while(currParent != NULL) {
        // Simpan data parent
        fprintf(fp, "PARENT\n");
        fprintf(fp, "%d,%s,%d,%.2f,%d,%d,%d\n",
            currParent->dataParent.nomorNota,
            currParent->dataParent.tanggalNota,
            currParent->dataParent.nomorMeja,
            currParent->dataParent.totalHarga,
            currParent->dataParent.totalItem,
            currParent->dataParent.statusProduksi,
            currParent->dataParent.paymentState);

        // Simpan data child
        AddressChild currChild = currParent->firstChild;
        while(currChild != NULL) {
            fprintf(fp, "CHILD\n");
            fprintf(fp, "%s,%s,%.2f\n",
                currChild->dataChild.namaItem,
                currChild->dataChild.tipeItem,
                currChild->dataChild.hargaItem);
            currChild = currChild->next;
        }
        currParent = currParent->next;
    }

    fprintf(fp, "END\n");
    fclose(fp);
}

// Fungsi untuk memuat data dari file ke multilist
void loadDataFromFile(MultiList *L, LinkedList *itemList, ReportPaper *paper, const char * filename) {
    FILE *fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Info: File data tidak ditemukan, memulai dengan data kosong\n");
        return;
    }

    char line[256];
    char section[20] = "";

    // Reset struktur data
    createEmpty(L);
    createEmptyLinkedList(itemList);

    while(fgets(line, sizeof(line), fp)) {
        // Hapus newline di akhir string
        line[strcspn(line, "\n")] = 0;

        if(strcmp(line, "REPORT_PAPER") == 0) {
            strcpy(section, "REPORT_PAPER");
            fgets(line, sizeof(line), fp);
            paper->penghasilan = atof(line);
            
            fgets(line, sizeof(line), fp);
            line[strcspn(line, "\n")] = 0;
            strcpy(paper->tanggal, line);
            
            fgets(line, sizeof(line), fp);
            line[strcspn(line, "\n")] = 0;
            strcpy(paper->makananTerbanyak, line);
            
            fgets(line, sizeof(line), fp);
            line[strcspn(line, "\n")] = 0;
            strcpy(paper->minumanTerbanyak, line);
            
            fgets(line, sizeof(line), fp);
            paper->totalMakananTerbanyak = atoi(line);
            
            fgets(line, sizeof(line), fp);
            paper->totalMinumanTerbanyak = atoi(line);
            
            fgets(line, sizeof(line), fp);
            paper->totalKeseluruhanMakanan = atoi(line);
            
            fgets(line, sizeof(line), fp);
            paper->totalKeseluruhanMinuman = atoi(line);
            
            fgets(line, sizeof(line), fp);
            paper->totalKeseluruhanItem = atoi(line);
        }
        else if(strcmp(line, "ITEM_LIST") == 0) {
            strcpy(section, "ITEM_LIST");
            continue;
        }
        else if(strcmp(line, "MULTILIST") == 0) {
            strcpy(section, "MULTILIST");
            continue;
        }
        else if(strcmp(line, "PARENT") == 0) {
            strcpy(section, "PARENT");
            continue;
        }
        else if(strcmp(line, "CHILD") == 0) {
            strcpy(section, "CHILD");
            continue;
        }
        else if(strcmp(line, "END") == 0) {
            break;
        }

        if(strcmp(section, "ITEM_LIST") == 0 && strlen(line) > 0) {
            str itemName, kategori;
            int jumlah;
            float harga, totalPenjualan;
            sscanf(line, "%[^,],%[^,],%d,%f,%f", 
                itemName, kategori, &jumlah, &harga, &totalPenjualan);
            
            DataItem item = makeDataLinkedlist(itemName, kategori, jumlah, harga, totalPenjualan);
            AddressLinkedList newNode = alokasiLinkedList(item);
            insertLastLinkedList(itemList, newNode);
        }
        else if(strcmp(section, "PARENT") == 0 && strlen(line) > 0) {
            int nomorNota, nomorMeja, totalItem, statusProduksi, paymentState;
            str tanggalNota;
            float totalHarga;
            sscanf(line, "%d,%[^,],%d,%f,%d,%d,%d",
                &nomorNota, tanggalNota, &nomorMeja, &totalHarga,
                &totalItem, &statusProduksi, &paymentState);
            
            DataParent parent = makeDataParent(nomorNota, tanggalNota, nomorMeja,
                totalHarga, totalItem, statusProduksi, paymentState);
            insertLastParent(L, parent);
        }
        else if(strcmp(section, "CHILD") == 0 && strlen(line) > 0) {
            str namaItem, tipeItem;
            float hargaItem;
            sscanf(line, "%[^,],%[^,],%f",
                namaItem, tipeItem, &hargaItem);
            
            DataChild child = makeDataChild(namaItem, tipeItem, hargaItem);
            AddressParent lastParent = getLastParent(*L);
            insertLastChild(*L, lastParent->dataParent.nomorNota, child);
        }
    }

    fclose(fp);
}

