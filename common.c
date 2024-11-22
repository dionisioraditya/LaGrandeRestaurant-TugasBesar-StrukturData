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
    item = makeDataLinkedlist(1, "Nasi Goreng", "makanan", 0, 13000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist(2, "Fuyung Hay", "makanan", 0, 12000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist(3, "Mie Goreng", "makanan", 0, 15000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist(4, "Karee", "makanan", 0, 20000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist(5, "Cap Cay", "makanan", 0, 22000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    // minuman
    item = makeDataLinkedlist(1, "Es Teh", "minuman", 0, 4000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist(2, "Lemon Tea", "minuman", 0, 5000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist(3, "Pink Lava", "minuman", 0, 15000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist(4, "Orange Water", "minuman", 0, 7000, 0);
    P = alokasiLinkedList(item);
    insertLastLinkedList(L, P);

    item = makeDataLinkedlist(5, "Air Mineral", "minuman", 0, 3000, 0);
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
    paper->totalMakananTerbanyak += totalMakananTerbanyak;
    paper->totalMinumanTerbanyak += totalMinumanTerbanyak;
    paper->totalKeseluruhanMakanan += totalKeseluruhanMakanan;
    paper->totalKeseluruhanMinuman += totalKeseluruhanMinuman;
    paper->totalKeseluruhanItem += totalKeseluruhanItem;
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
