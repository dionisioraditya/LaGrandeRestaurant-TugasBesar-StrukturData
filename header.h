#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include <windows.h>
typedef char str [50];
// ADT LinkedList
typedef struct Node * AddressLinkedList;
typedef struct
{
	str itemName;
	str kategori;
	int jumlah;
	float harga;
	float totalPenjualan;
}DataItem;

typedef struct Node {
	DataItem data;
	AddressLinkedList next;
}Tnode;
typedef struct {
	AddressLinkedList first;
}LinkedList;

// ADT MultiList
typedef struct Child* AddressChild;
typedef struct Parent*  AddressParent;

typedef struct DataChild{
	str namaItem;
	str tipeItem;
	float hargaItem;
}DataChild;

typedef struct DataParent{
	int nomorNota;
	str tanggalNota;
	int nomorMeja;
	float totalHarga;
	int totalItem;
	bool statusProduksi;
	bool paymentState;
}DataParent;

typedef struct Child {
	DataChild dataChild;
	AddressChild next;
}NodeChild;

typedef struct Parent
{
	DataParent dataParent;
	AddressParent next;
	AddressChild firstChild;
}NodeParent;

typedef struct {
  AddressParent firstParent;
} MultiList;

typedef struct {
	float penghasilan;
	str tanggal;
	str makananTerbanyak;
	int totalMakananTerbanyak;
	int totalMinumanTerbanyak;
	int totalKeseluruhanMakanan;
	int totalKeseluruhanMinuman;
	int totalKeseluruhanItem;
	str minumanTerbanyak;
}ReportPaper;
//view
void laGrandeSign();
void loadingAnimation();
void resetColor();
void red();
void blue();
void green();
void purple();
void gotoxy(int x, int y);
void hide_cur();
void keyGuide(int x, int y);
void printMainMenuKasir(int x, int y, int input);
void menuPertama(int menu);
void errorMessageParentNULL(int x, int y);
void printPaperDapur(MultiList L, AddressParent target);
void menuUpdateItemResto(int value, int x, int y);
void keyLogicMenuUpdateItem(char kb, int *value);
// common header
void get_current_date(str *date_str);
int generateDateforNotaId();
void logicInputMenuKasir(char kb, int *value);
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
);
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
);
void cetakPaper(ReportPaper paper, int x, int y);
void saveDataToFile(MultiList L, LinkedList itemList, ReportPaper paper, const char * filename);
void loadDataFromFile(MultiList *L, LinkedList *itemList, ReportPaper *paper, const char * filename);
void sumItemSold(LinkedList * linklist, AddressParent p);
// LinkedList
bool LinkedListIsEmpty(LinkedList L);
bool LinkedListIsOneElement(LinkedList L);
AddressLinkedList alokasiLinkedList(DataItem X);
void createEmptyLinkedList(LinkedList *L);
void insertFirstLinkedList(LinkedList *L, AddressLinkedList newNode);
void insertLastLinkedList(LinkedList *L, AddressLinkedList newNode);
void deleteFirstLinkedList(LinkedList *L);
void deleteAtLinkedList(LinkedList *L, AddressLinkedList del);
void deleteLastLinkedList(LinkedList *L);
DataItem makeDataLinkedlist(str itemName, str kategori, int jumlah, float harga, float totalPenjualan);
void initDefaultMakananMinuman(LinkedList *L);
void printDataLinkedList(LinkedList L, int x, int y, str kategori);
AddressLinkedList findLinkList(LinkedList L, str namaItem);
AddressLinkedList findKategoriTerbanyak(LinkedList L, str kategori);
int countTotaItemlLinkListByKategori(LinkedList L, str kategori);
int countTotalItemLinkList(LinkedList L);

// parent header MultiList
void createEmpty(MultiList *L);
bool isEmpty(MultiList L);
bool haveChild(AddressParent addresParent);
DataParent makeDataParent(int nomorNota, str tanggalNota, int nomorMeja, float totalHarga, int totalItem, bool status, bool paymentState);
AddressParent alokasiParent(DataParent data);
AddressParent findParent(MultiList L, int data);
AddressParent getLastParent(MultiList L);
AddressParent getBeforeParentCircular(MultiList L, AddressParent target);
void insertFirstParent(MultiList *L, DataParent data);
void insertAfterParent(MultiList *L, int kodeParent, DataParent data);
void insertLastParent(MultiList *L, DataParent data);
void deleteFirstParent(MultiList *L);
void deleteAtParent(MultiList *L, int nomorNota);
void deleteLastParent(MultiList *L);
void deleteAllChild(AddressParent parent);
void printParent(AddressParent parent);
void printAllParent(MultiList L);
void printAllParentWithPaymentCheck(MultiList L, bool paymentCheck);
void Backup_DeleteParent(MultiList *L, int hapus, int backup);
void printAll(MultiList L);
void printAllWithPaymentCheck(MultiList L, bool checkPayment);
AddressParent getNextWithProductionFalse(AddressParent target);
AddressParent getBeforeWithProductionFalse(MultiList L, AddressParent target);
// child header MultiList
bool isOneChild(AddressParent P);
DataChild makeDataChild(str namaItem, str tipeItem, float hargaItem);
AddressChild alokasiChild(DataChild data);
void insertFirstChild(MultiList L, int kodeParent, DataChild data);
void insertLastChild(MultiList L, int kodeParent, DataChild data);
void deleteFirstChild(MultiList L, int kodeParent);
void deleteLastChild(MultiList L, int kodeParent);
void printChild(AddressChild child);
void printAllChild(AddressParent parent);
AddressParent getBefore(MultiList L, AddressParent target);
int countChild(AddressParent target);
void deleteAtChild(MultiList l , AddressParent p, str itemName);
bool dataisExist(AddressParent p, str namaItem);
DataChild popDataItem(MultiList l, AddressParent P, str item);
bool isLastChild(AddressParent p, str namaItem);