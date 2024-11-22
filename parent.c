#include "header.h"
void createEmpty(MultiList *L) {
  L->firstParent = NULL;
}

bool isEmpty(MultiList L) {
  return L.firstParent == NULL;
}

bool haveChild(AddressParent addresParent) {
  return addresParent->firstChild != NULL;
}
DataParent makeDataParent(int nomorNota, str tanggalNota, int nomorMeja, float totalHarga, int totalIten, bool status) {
    DataParent data;
    data.nomorNota = nomorNota;
    strcpy(data.tanggalNota, tanggalNota);
    data.nomorMeja = nomorMeja;
    data.totalHarga = totalHarga;
    data.totalItem = totalIten;
    data.statusProduksi = status;
  return data;
}
AddressParent alokasiParent(DataParent data) {
  AddressParent ap;
  ap  = (AddressParent)malloc(sizeof(NodeParent));
  ap->next = NULL;
  ap->firstChild = NULL;
  ap->dataParent = data;

  return ap;
}
AddressParent findParent(MultiList L, int data) {
  AddressParent temp = NULL;
  temp = L.firstParent;
  while (temp != NULL)
  {
    while (temp !=NULL)
    {
      if (temp->dataParent.nomorNota == data)
      {
        return temp;
      }
      temp = temp->next;
    }
    return NULL;
  }
  
}
void insertFirstParent(MultiList *L, DataParent data) {
  AddressParent temp = alokasiParent(data);
  temp->next = L->firstParent;
  L->firstParent = temp;
}
void insertAfterParent(MultiList *L, int kodeParent, DataParent data) {
  AddressParent dataBaru = alokasiParent(data);
  if (!isEmpty(*L))
  {
    AddressParent temp = findParent(*L, kodeParent);
    if (temp != NULL)
    {
      dataBaru->next = temp->next;
      temp->next = dataBaru;
    }
  }
}
void insertLastParent(MultiList *L, DataParent data) {
  AddressParent dataBaru = alokasiParent(data);
  if (isEmpty(*L))
  {
    insertFirstParent(L, data);
  } else {
    AddressParent temp = L->firstParent;
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = dataBaru;
  }  
}
void deleteFirstParent(MultiList *L) {
  AddressParent temp = L->firstParent;
  if(!isEmpty(*L)) {
    deleteAllChild(temp);
    L->firstParent = L->firstParent->next;
    free(temp);
  }
}
void deleteAtParent(MultiList *L, int nomorNota) {
  AddressParent temp = L->firstParent;
  AddressParent hapus;
  if (!isEmpty(*L))
  {
    if (temp->dataParent.nomorNota == nomorNota)
    {
      deleteFirstParent(L);
    } else {
      while (temp->next != NULL) {
        if (temp->next->dataParent.nomorNota == nomorNota)
        {
          hapus = temp->next;
          temp->next = temp->next->next;
          deleteAllChild(hapus);
          free(hapus);
          hapus = NULL;
          break;
        }
        temp = temp->next;
      }
    } 
  }
}
void deleteLastParent(MultiList *L) {
  AddressParent  temp = L->firstParent;
  if (!isEmpty(*L)) {
    if (temp->next == NULL) {
      deleteFirstParent(L);
    } else {
      while (temp->next->next != NULL) {
        temp = temp->next;
      }
      deleteAllChild(temp->next);
      free(temp->next);
      temp->next = NULL;
    }
  }
}
void deleteAllChild(AddressParent parent) {
  AddressChild temp;
  while (haveChild(parent))
  {
    temp = parent->firstChild;
    parent->firstChild = parent->firstChild->next;
    free(temp);
  }
}
void printParent(AddressParent parent) {
    printf("\n  === Nota ===");
    printf("\n [-] Nomor Nota            : %d", parent->dataParent.nomorNota);
    printf("\n [-] Tanggal Pesanan       : %s", parent->dataParent.tanggalNota);
    printf("\n [-] Nomor Meja            : %d", parent->dataParent.nomorMeja);
    if(parent->dataParent.statusProduksi== false)printf("\n [-] Status Produksi       : Proses");
    else printf("\n [-] Status Produksi       : \033[1;32mSelesai"); resetColor();
    printf("\n [-] Total Item            : %d", parent->dataParent.totalItem);
    printf("\n [-] Total Harga           : Rp %.2f", parent->dataParent.totalHarga);
}
void printAllParent(MultiList L) {
  AddressParent temp = L.firstParent;
  while (temp != NULL)
  {
    printParent(temp);
    printf("\n");
    temp = temp->next;
  }
}

AddressParent getLastParent(MultiList L) {
  AddressParent P = L.firstParent;
  if (P->next== NULL)
  {
    return P;
  }
  
  while (P->next != NULL)
  {
    P = P->next;
  }
  return P;
}
AddressParent getBeforeParentCircular(MultiList L, AddressParent target) {
  AddressParent support = L.firstParent;
  if (target == L.firstParent)
  {
    return getLastParent(L);
  }
  
  while (support != NULL)
  {
    if (support->next == target)
    {
      return support;
    }
    support = support->next;
  }
  return NULL;
}
void Backup_DeleteParent(MultiList *L, int hapus, int backup) {
  AddressParent delete = findParent(*L, hapus);
  AddressChild C = delete->firstChild;
  if (haveChild(delete))
  {
    while (C!=NULL)
    {
      insertLastChild(*L, backup, C->dataChild);
      C = C->next;
    }
    deleteAtParent(L, hapus);
  } else {
    deleteAtParent(L, hapus);
  }
}
void printAll(MultiList L) {
  AddressParent temp = L.firstParent;
  while (temp !=NULL)
  {
    printParent(temp);
    printAllChild(temp);
    printf("\n");
    temp = temp->next;
  }
}
AddressParent getBefore(MultiList L, AddressParent target) {
	AddressParent P = L.firstParent;
	while(P->next != target) {
		P = P->next;
	}
	return P;
}
AddressParent getNextWithProductionFalse( AddressParent target) {
  AddressParent P = target;
  while(P->next!= NULL) {
    P = P->next;
    if(P->dataParent.statusProduksi == false) {
      return P;
    }
  }
  return P = target;
}
AddressParent getBeforeWithProductionFalse(MultiList L, AddressParent target) {
  AddressParent P = target;
  while(P != L.firstParent ) {
    P = getBefore(L, P);
    if (P->dataParent.statusProduksi == false)
    {
      return P;
    }
    
  }
  return target;
}