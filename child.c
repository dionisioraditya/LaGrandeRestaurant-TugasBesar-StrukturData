#include "header.h"

// source child
bool isOneChild(AddressParent P) {
  if (P->firstChild->next ==  NULL)
  {
    return true;
  } else {
    return false;
  }
  
}
DataChild makeDataChild(str namaItem, str tipeItem, float hargaItem) {
    DataChild data;
    strcpy(data.namaItem, namaItem);
    strcpy(data.tipeItem, tipeItem);
    data.hargaItem = hargaItem;
    return data;
}
AddressChild alokasiChild(DataChild data) {
    AddressChild ac;
    ac = (AddressChild) malloc(sizeof(NodeChild));
    ac->next = NULL;
    ac->dataChild = data;
    return ac;
}
void insertFirstChild(MultiList L, int kodeParent, DataChild data) {
  AddressParent parent = findParent(L, kodeParent);
  if (parent != NULL)
  {
    AddressChild dataBaru = alokasiChild(data);
    dataBaru->next = parent->firstChild;
    parent->firstChild = dataBaru;
  }
}
void insertLastChild(MultiList L, int kodeParent, DataChild data) {
  AddressParent parent = findParent(L, kodeParent);
  if (parent != NULL) {}
  {
    if (!haveChild(parent))
    {
      insertFirstChild(L, kodeParent, data);
    } else {
      AddressChild temp = parent->firstChild;
      AddressChild dataBaru = alokasiChild(data);

      while (temp->next != NULL)
      {
        temp = temp->next;
      }
      temp->next = dataBaru;
    }
  }
}
void deleteFirstChild(MultiList L, int kodeParent) {
  AddressParent parent = findParent(L, kodeParent);
  if (parent != NULL)
  {
    if (haveChild(parent))
    {
      AddressChild temp = parent->firstChild;
      parent->firstChild = parent->firstChild->next;
      temp->next = NULL;
      free(temp);
    }
  }
}
void deleteLastChild(MultiList L, int kodeParent) {
  AddressParent parent = findParent(L, kodeParent);

  if (parent != NULL)
  {
    if (haveChild(parent))
    {
      if (parent->firstChild->next == NULL)
      {
        deleteFirstChild(L, kodeParent);
      } else {
        AddressChild temp = parent->firstChild;
        while (temp->next->next != NULL)
        {
          temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
      }
    }
  }
}
void printChild(AddressChild child) {
  printf("\n\n\t=== Item ===");
  printf("\n\t[+] Nama Item : %s", child->dataChild.namaItem);
  printf("\n\t[+] Tipe Item : %s", child->dataChild.tipeItem);
  printf("\n\t[+] Harga Item: Rp %.2f", child->dataChild.hargaItem);
}
void printAllChild(AddressParent parent) {
  AddressChild temp = parent->firstChild;
  while (temp != NULL)
  {
    printChild(temp);
    temp = temp->next;
  }
}
int countChild(AddressParent target) {
  AddressChild support = target->firstChild;
  int count = 0;
  while (support== NULL) {
    count++;
    support = support->next;
  }
  return count;
}
void deleteAtChild(MultiList l , AddressParent p, str itemName) {
  AddressChild ch = p->firstChild;
  if (ch != NULL) {
    // If it's the first node
    if (strcmpi(ch->dataChild.namaItem, itemName) == 0) {
      p->firstChild = ch->next;
      free(ch);
      return;  // Important: Return after deletion
    }
    
    // For other nodes
    while (ch->next != NULL) {
      if (strcmpi(ch->next->dataChild.namaItem, itemName) == 0) {
        AddressChild del = ch->next;
        ch->next = ch->next->next;
        free(del);
        return;  // Important: Return after deletion
      }
      ch = ch->next;
    }
  }
}
DataChild popDataItem(MultiList l, AddressParent P, str item) {
  DataChild data;
  AddressChild CH = P->firstChild;
  while(CH != NULL) {
    if(strcmpi(CH->dataChild.namaItem, item)==0) {
      data = CH->dataChild;
      //deleteAtChild(l, P, item);
      return data;
    }
    CH =CH->next;
  }
}
bool dataisExist(AddressParent p, str namaItem) {
  AddressChild ch = p->firstChild;
  while (ch!= NULL)
  {
    if (strcmpi(ch->dataChild.namaItem, namaItem)==0)
    {
      return true;
    }
    
    ch = ch->next;
  }
  return false;
}
bool isLastChild(AddressParent p, str namaItem) {
  AddressChild ch = p->firstChild;
  
  // Handle empty list
  if (ch == NULL) {
    return false;
  }
  
  // Handle single node
  if (ch->next == NULL) {
    return strcmpi(ch->dataChild.namaItem, namaItem) == 0;
  }
  
  // Handle first node
  if (strcmpi(ch->dataChild.namaItem, namaItem) == 0) {
    return false;
  }
  
  // Find the node
  while (ch != NULL) {
    if (ch->next != NULL && strcmpi(ch->next->dataChild.namaItem, namaItem) == 0) {
      // Found the item - it's last if there's nothing after it
      return ch->next->next == NULL;
    }
    ch = ch->next;
  }
  
  return false;  // Item not found
  
}