#include "header.h"

bool LinkedListIsEmpty(LinkedList L) {
  return L.first == NULL;
}
bool LinkedListIsOneElement(LinkedList L) {
  return !LinkedListIsEmpty(L) && L.first->next == NULL;
}
AddressLinkedList alokasiLinkedList(DataItem X) {
  AddressLinkedList temp;
  temp = (Tnode*)malloc(sizeof(Tnode));
  temp->data = X;
  temp->next = NULL;
  return temp; 
}
DataItem makeDataLinkedlist(str itemName, str kategori, int jumlah, 
float harga, float totalPenjualan) {
  DataItem temp;
  strcpy(temp.itemName, itemName);
  strcpy(temp.kategori, kategori);
  temp.jumlah = jumlah;
  temp.harga = harga;
  temp.totalPenjualan = totalPenjualan;
  return temp;
}
void createEmptyLinkedList(LinkedList *L) {
  L->first = NULL;
}
void insertFirstLinkedList(LinkedList *L, AddressLinkedList newNode) {
  newNode->next = L->first;
  L->first = newNode;
}
void insertLastLinkedList(LinkedList *L, AddressLinkedList newNode) {
  AddressLinkedList temp = L->first;
  if (LinkedListIsEmpty(*L))
  {
    insertFirstLinkedList(&(*L), newNode);
  } else {
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}
void deleteFirstLinkedList(LinkedList *L) {
  if (!LinkedListIsEmpty(*L))
  {
    AddressLinkedList del = L->first;
    L->first = L->first->next;
    free(del);
  } 
}
void deleteAtLinkedList(LinkedList *L, AddressLinkedList del) {
  AddressLinkedList p;
  if (!LinkedListIsEmpty(*L))
  {
    if (L->first == del)
    {
      deleteFirstLinkedList(L);
    } else {
      p = L->first;
      while (p->next != del)
      {
        p = p->next;
      }
      p->next = del->next;
      free(del);
    }
  }
}
void deleteLastLinkedList(LinkedList *L){
  AddressLinkedList P;
  if (!LinkedListIsEmpty(*L))
  {
    if (LinkedListIsOneElement(*L))
    {
      deleteFirstLinkedList(L);
    } else {
      for(P = L->first; P->next->next != NULL; P = P->next)
        ;
      free(P->next);
      P->next = NULL;
    }
  }
}
void printDataLinkedList(LinkedList L, int x, int y, str kategori) {
  int i = 0;
  AddressLinkedList temp = L.first;
  while (temp != NULL)
  {
    if (strcmpi(temp->data.kategori, kategori)==0)
    {
      y+2;
      gotoxy(x, y);
      printf("========================");
      y++;
      gotoxy(x, y);
      printf("Nama Item : %s", temp->data.itemName);
      y++;
      gotoxy(x, y);
      printf("Harga     : Rp %.2f", temp->data.harga);
      y++;
      gotoxy(x, y);
      printf("========================");
    }
    temp = temp->next;
  }
}
AddressLinkedList findLinkList(LinkedList L, str namaItem) {
  AddressLinkedList P = L.first;
  while (P != NULL) {
    if (strcmpi(P->data.itemName, namaItem) == 0) {
      return P;
    }
    P = P->next;
  }
  return P;
}
AddressLinkedList findKategoriTerbanyak(LinkedList L, str kategori) {
  AddressLinkedList P = L.first, index = NULL;
  int max = 0;
  while (P!=NULL)
  {
    if (strcmpi(P->data.kategori, kategori)==0 && P->data.jumlah > max)
    {
      max = P->data.jumlah;
      index = P;
    }
    P = P->next;
  }
  return index;
}
int countTotaItemlLinkListByKategori(LinkedList L, str kategori) {
  AddressLinkedList P = L.first;
  int count = 0;
  while (P!= NULL)
  {
    if (strcmpi(P->data.kategori, kategori)==0)
    {
      count +=P->data.jumlah;
    }
    P = P->next;
  }
  return count;
}
int countTotalItemLinkList(LinkedList L) {
  AddressLinkedList P = L.first;
  int count = 0;
  while (P!= NULL)
  {
    count +=P->data.jumlah;
    P = P->next;
  }
  return count;
}