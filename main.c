#include "header.h"

int main(int argc, char *argv[]) {
	hide_cur();
	LinkedList ListItemResto;
	AddressLinkedList tempLinkList, tempLinkList2;
	MultiList nota;
	AddressParent tempParent, tempParent2;
	DataChild DC;
	DataParent DP;
	ReportPaper paper;
	initPaper(&paper, 0, "-", "-", "-", 0, 0, 0, 0, 0);
	createEmpty(&nota);
	initDefaultMakananMinuman(&ListItemResto);
	int menu, nomorNt=0, i;
	int nomor_Nota = 0, nomor_nota2 = 0, nomor_meja = 0, totalItem= 0;

	float total_harga = 0, harga_item = 0;
	float saldoToko = 0, uang;
	int inValue=1;
	str tanggal_Nota, nama_item, tipe_item;
	char kb, confirm;
	int xTemp, yTemp;
	int count_item = 0, count_nota = 0;
	int jumlah1, jumlah2;
	str name1, name2;
	//loadingAnimation();
	menuPertama(inValue);
	do
	{
		system("cls");
		laGrandeSign();
		
		switch (kb)
		{
			case 'w':
				inValue = 1;

				break;
			case 's':
				inValue = 2;
				
				break;
			default:
				break;
		}

		menuPertama(inValue);
		keyGuide(90, 8);
		//printf("\n%d", value);

		kb = getch();
		
		if (kb == 13 && inValue == 1)
		{
			kb = 'w';
			do
			{
				system("cls");
				logicInputMenuKasir(kb, &inValue);
				//printAllParent(nota);
				printAll(nota);
				keyGuide(90, 1);
				printDataLinkedList(ListItemResto, 82, 5, "makanan");
				printDataLinkedList(ListItemResto, 108, 5, "minuman");
				printMainMenuKasir(50, 5, inValue);
				if (inValue == 0 && kb == 13) // menu kasir 1, buat nota pesanan baru
				{
					system("cls");
					xTemp = 45;
					yTemp = 5;
					total_harga = 0;
					count_item = 0;
					count_nota++;
					while (1)
					{ 
						gotoxy(xTemp, yTemp);
						printf("Masukkan nomor meja: ");scanf("%d", &nomor_meja);
						if (nomor_meja>0)
						{
							yTemp++;
							gotoxy(xTemp, yTemp);
							printf("[*] Berhasil memasukkan nomor meja");
							yTemp++;
							break;
						}
						yTemp++;
						gotoxy(xTemp, yTemp);
						printf("[!] Nomor meja harus lebih dari 0");
						yTemp++;
					}
					get_current_date(&tanggal_Nota);
					DP = makeDataParent(generateDateforNotaId()*100+count_nota, tanggal_Nota, nomor_meja, total_harga, count_item, false);
					insertLastParent(&nota, DP);
					tempParent = findParent(nota, DP.nomorNota);
					
					do
					{
						total_harga = 0;
						harga_item = 0;
						while (1)
						{ 
							xTemp = 41;
							yTemp = 5;
							system("cls");
							printParent(tempParent);
							printAllChild(tempParent);
							printDataLinkedList(ListItemResto, 82, 5, "makanan");
							printDataLinkedList(ListItemResto, 108, 5, "minuman");
							gotoxy(xTemp, yTemp);
							printf("Masukkan nama item: ");
							yTemp++;
							gotoxy(xTemp, yTemp);
							fflush(stdin);gets(nama_item);
							tempLinkList = findLinkList(ListItemResto, nama_item);
							if (tempLinkList!= NULL)
							{
								yTemp++;
								gotoxy(xTemp, yTemp);
								printf("[*] Berhasil menambahkan item");
								yTemp++;
								break;
							}
							yTemp++;
							gotoxy(xTemp, yTemp);
							printf("[!] Nama item tidak ditemukan");
							yTemp++;
							getch();
						}
						while (1)
						{ 
							yTemp++;
							gotoxy(xTemp, yTemp);
							printf("Masukkan Jumlah item: ");
							yTemp++;
							gotoxy(xTemp, yTemp);
							scanf("%d", &count_item);
							if (count_item>0)
							{
								yTemp++;
								gotoxy(xTemp, yTemp);
								printf("[*] Berhasil menambahkan item");
								yTemp++;
								break;
							}
							yTemp++;
							gotoxy(xTemp, yTemp);
							printf("[!] jumlah item harus lebih dari 0");
						}
						total_harga = tempLinkList->data.harga * count_item;
						harga_item = tempLinkList->data.harga;
						strcpy(tipe_item, tempLinkList->data.kategori);
						DC = makeDataChild(nama_item, tipe_item, harga_item);
						for(i=0; i<count_item; i++) {
							insertLastChild(nota, DP.nomorNota, DC);

						}
						tempParent->dataParent.totalHarga += total_harga;
						tempParent->dataParent.totalItem += count_item;
						tempLinkList->data.jumlah +=count_item;
						tempLinkList->data.totalPenjualan += total_harga;
						yTemp++;
						gotoxy(xTemp, yTemp);
						printf("[?] Ingin menambahkan item lagi? y/n : "); 
						yTemp++;
						gotoxy(xTemp, yTemp);
						scanf(" %c", &confirm);
						if (confirm=='n') {
							kb = 'w';
							yTemp++;
							gotoxy(xTemp, yTemp);
							printf("[*] Berhasil menambahkan item");
							blue();
							yTemp+=2;
							gotoxy(xTemp, yTemp);
							printf("[*] Press space...");
							resetColor();
						} else {
							yTemp++;
						}
					} while (confirm != 'n');
				} else if (inValue == 1 && kb == 13) {// menu kasir 2, tambah pesanan berdasarkan nota yang sudah ada
					if (isEmpty(nota))
					{
						system("cls");
						errorMessageParentNULL(50, 5);
						resetColor();
					} else {
						system("cls");
						printAllParent(nota);
						xTemp = 50;
						yTemp = 5;
						count_item = 0;
						total_harga = 0;
						gotoxy(xTemp, yTemp);
						printf("[?] Masukkan nomor nota yang ingin ditambahkan pesanan: ");scanf("%d", &nomor_Nota);
						tempParent = findParent(nota, nomor_Nota);
						if (tempParent == NULL)
						{
							yTemp++;
							gotoxy(xTemp, yTemp);
							printf("[!] Nomor nota tidak ditemukan");
						} else {
							do
							{
								system("cls");
								total_harga = 0;
								harga_item = 0;
								printParent(tempParent);
								printAllChild(tempParent);
								printDataLinkedList(ListItemResto, 82, 5, "makanan");
								printDataLinkedList(ListItemResto, 108, 5, "minuman");
								while (1)
								{ 
									xTemp = 41;
									yTemp = 5;
									gotoxy(xTemp, yTemp);
									printf("Masukkan nama item: ");
									yTemp++;
									gotoxy(xTemp, yTemp);
									fflush(stdin);gets(nama_item);
									tempLinkList = findLinkList(ListItemResto, nama_item);
									if (tempLinkList!= NULL)
									{
										yTemp++;
										gotoxy(xTemp, yTemp);
										printf("[*] Berhasil menambahkan item");
										yTemp++;
										break;
									}
									yTemp++;
									gotoxy(xTemp, yTemp);
									printf("[!] Nama item tidak ditemukan");
									yTemp++;
									getch();
								}
								while (1)
								{ 
									yTemp++;
									gotoxy(xTemp, yTemp);
									printf("Masukkan Jumlah item: ");
									yTemp++;
									gotoxy(xTemp, yTemp);
									scanf("%d", &count_item);
									if (count_item>0)
									{
										yTemp++;
										gotoxy(xTemp, yTemp);
										printf("[*] Berhasil menambahkan item");
										yTemp++;
										break;
									}
									yTemp++;
									gotoxy(xTemp, yTemp);
									printf("[!] jumlah item harus lebih dari 0");
								}
								total_harga = tempLinkList->data.harga * count_item;
								harga_item = tempLinkList->data.harga;
								strcpy(tipe_item, tempLinkList->data.kategori);
								DC = makeDataChild(nama_item, tipe_item, harga_item);
								for(i=0; i<count_item; i++) {
									insertLastChild(nota, DP.nomorNota, DC);

								}
								
								tempParent->dataParent.totalHarga += total_harga;
								tempParent->dataParent.totalItem += count_item;
								tempLinkList->data.jumlah +=count_item;
								tempLinkList->data.totalPenjualan += total_harga;
								yTemp++;
								gotoxy(xTemp, yTemp);
								printf("[?] Ingin menambahkan item lagi? y/n : "); 
								yTemp++;
								gotoxy(xTemp, yTemp);
								scanf(" %c", &confirm);
								if (confirm=='n') {
									kb = 'w';
									yTemp++;
									gotoxy(xTemp, yTemp);
									printf("[*] Berhasil menambahkan item");
									blue();
									yTemp+=2;
									gotoxy(xTemp, yTemp);
									printf("[*] Press space...");
									resetColor();
								} else {
									yTemp++;
								}
							} while (confirm != 'n');
						}
						
					}
				} else if (inValue == 2 && kb == 13) {// menu kasir 3, pindah nota yang sudah ada X? -> N?
					if (isEmpty(nota))
					{
						system("cls");
						errorMessageParentNULL(50, 6);
					} else {
						system("cls");
						xTemp = 50;
						yTemp = 5;
						printAllParent(nota);
						gotoxy(xTemp, yTemp);
						printf("[?] Masukkan nota yang ingin dipindahkan: ");scanf("%d", &nomor_Nota);
						
						if (findParent(nota, nomor_Nota)== NULL)
						{
							yTemp+=2;
							gotoxy(xTemp, yTemp);
							printf("[!] Nomor nota tidak ditemukan");
						} else {
							yTemp+=2;
							gotoxy(xTemp, yTemp);
							printf("[?] Masukkan nota tujuan: ");scanf("%d", &nomor_nota2);
							if (findParent(nota, nomor_nota2) == NULL || nomor_Nota == nomor_nota2)
							{
								yTemp+=2;
								gotoxy(xTemp, yTemp);
								printf("[!] Nomor nota tidak ditemukan atau nota tidak boleh sama");
								blue();
								yTemp+=2;
								gotoxy(xTemp, yTemp);
								printf("[*] Press space...");
								resetColor();
							} else {
								tempParent = findParent(nota, nomor_Nota);
								totalItem = tempParent->dataParent.totalItem;
								total_harga = tempParent->dataParent.totalHarga;
								if (nomor_Nota > nomor_nota2)
								{
									Backup_DeleteParent(&nota, nomor_Nota, nomor_nota2);
									tempParent2 = findParent(nota, nomor_nota2);
									tempParent2->dataParent.totalItem += totalItem;
									tempParent2->dataParent.totalHarga += total_harga;
								} else {
									Backup_DeleteParent(&nota, nomor_nota2, nomor_Nota);
									tempParent2 = findParent(nota, nomor_Nota);
									tempParent2->dataParent.totalItem += totalItem;
									tempParent2->dataParent.totalHarga += total_harga;
								}
								
								
								
								yTemp+=2;
								gotoxy(xTemp, yTemp);
								printf("[!] Berhasil memindahkan item nota %d -> %d", nomor_Nota, nomor_nota2);
								blue();
								yTemp+=2;
								gotoxy(xTemp, yTemp);
								printf("[*] Press space...");
								resetColor();
							}
							
						}
						
					}
					
				}
				else if(inValue == 3 && kb == 13 ) { // menu kasir 4, pembayaran
					if (isEmpty(nota))
					{
						system("cls");
						errorMessageParentNULL(50, 6);
					} else {
						system("cls");
						xTemp = 50;
						yTemp = 5;
						printAllParent(nota);
						gotoxy(xTemp, yTemp);
						printf("[?] Masukkan nomor nota yang ingin dibayarkan: ");scanf("%d", &nomor_Nota);
						tempParent = findParent(nota, nomor_Nota);
						if (tempParent == NULL) {
							yTemp+=2;
							errorMessageParentNULL(xTemp, yTemp);
						} else {
							system("cls");
							printParent(tempParent);
							printAllChild(tempParent);
							gotoxy(xTemp, yTemp);
							printf("[INFO] Total Harga: Rp %.2f", tempParent->dataParent.totalHarga);
							yTemp+=3;
							gotoxy(xTemp, yTemp);
							printf("[PAY] Masukkan uang pembayaran: ");scanf("%f", &uang);
							if (uang < tempParent->dataParent.totalHarga) {
								yTemp+=2;
								gotoxy(xTemp, yTemp);
								printf("[FAILED] Gagal melakukan transaksi karena uang kurang dari nominal transaksi");
								blue();
								yTemp+=2;
								gotoxy(xTemp, yTemp);
								printf("[*] Press space...");
								resetColor();
							} else {
								yTemp+=2;
								gotoxy(xTemp, yTemp);
								printf("[SUCCESS] Berhasil melakukan transaksi untuk nota %d", tempParent->dataParent.nomorNota);
								saldoToko += tempParent->dataParent.totalHarga;
								get_current_date(&tanggal_Nota);
								tempLinkList = findKategoriTerbanyak(ListItemResto, "makanan");
								tempLinkList2 = findKategoriTerbanyak(ListItemResto, "minuman");
								if (tempLinkList == NULL)
								{
									strcpy(name1, "-");
									jumlah1 = 0;
									
								}else {
									jumlah1 = tempLinkList->data.jumlah;
									strcpy(name1, tempLinkList->data.itemName);
								}
								if (tempLinkList2 == NULL)
								{
									strcpy(name2, "-");
									jumlah2 = 0;
								}else {
									jumlah2 = tempLinkList2->data.jumlah;
									strcpy(name1, tempLinkList->data.itemName);
								}
								
								inputPaper(	
									&paper, 
									saldoToko, 
									tanggal_Nota, 
									name1, 
									name2,
									jumlah1,
									jumlah2, 
									countTotaItemlLinkListByKategori(ListItemResto,"makanan"), 
									countTotaItemlLinkListByKategori(ListItemResto,"minuman"),
									countTotalItemLinkList(ListItemResto)
								);
								deleteAtParent(&nota, nomor_Nota);
								blue();
								yTemp+=2;
								gotoxy(xTemp, yTemp);
								printf("[*] Press space...");
								resetColor();
							}
						}
					}
				}
				else if(inValue == 4 && kb == 13 ) {

					//if (paper.totalKeseluruhanItem>0)
					//{
						xTemp = 50;
						yTemp = 5;
						system("cls");
						gotoxy(xTemp, yTemp);
						cetakPaper(paper, xTemp, yTemp);
						getch();
					//}
					
				} else if(inValue == 5 && kb == 13 ) { // menu kasir 5, Split Nota
						if (isEmpty(nota))
						{
							system("cls");
							errorMessageParentNULL(50, 9);
						}else {
								system("cls");
							xTemp = 50;
							yTemp = 5;
							printAll(nota);
							gotoxy(xTemp, yTemp);
							printf("Split Nota");
							yTemp++;
							gotoxy(xTemp, yTemp);
							printf("Masukkan nomor nota yang ingin dipecah: ");
							yTemp++;
							gotoxy(xTemp, yTemp);
							scanf("%d", &nomor_Nota);
							if (findParent(nota, nomor_Nota) != NULL)
							{
								tempParent = findParent(nota, nomor_Nota);
								yTemp++;
								gotoxy(xTemp, yTemp);
								printf("Berapa jumlah nota yang ingin dipisah? (maksimal %d):", tempParent->dataParent.totalItem-1);
								yTemp++;
								gotoxy(xTemp, yTemp);
								scanf("%d", &jumlah1);
								if (jumlah1 < tempParent->dataParent.totalItem) {
									for(i = 0; i<jumlah1; i++) {
										count_nota++;
										system("cls");
										xTemp = 50;
										yTemp = 5;
										printAllChild(tempParent);
										if (isOneChild(tempParent))
										{
											gotoxy(xTemp, yTemp);
											printf("Data item sudah habis");
											getch;
											break;
										} else {
											get_current_date(&tanggal_Nota);
											nomor_nota2 = generateDateforNotaId()*100+count_nota;
											DP = makeDataParent(nomor_nota2, tempParent->dataParent.tanggalNota, tempParent->dataParent.nomorMeja, 0, 0, tempParent->dataParent.statusProduksi);
											insertLastParent(&nota, DP);
											tempParent2 = findParent(nota, nomor_nota2);
											do{
												jumlah2=0;
												system("cls");
												xTemp = 50;
												yTemp = 5;
												printAllChild(tempParent);
												gotoxy(xTemp, yTemp-2);
												printf("Nota baru: %d | Jumlah item: %d", tempParent2->dataParent.nomorNota, tempParent2->dataParent.totalItem);
												gotoxy(xTemp, yTemp);
												printf("Masukkan nama item: ");
												
												yTemp++;
												gotoxy(xTemp, yTemp);
												fflush(stdin);gets(nama_item);
												if (dataisExist(tempParent, nama_item))
												{
													jumlah2++;
													DC = popDataItem(nota, tempParent, nama_item);
													printf("\n LOG: %s", DC.namaItem);	
													insertLastChild(nota, nomor_nota2, DC);
													tempParent2->dataParent.totalItem += jumlah2;
													tempParent2->dataParent.totalHarga += DC.hargaItem;
													tempParent->dataParent.totalHarga -= DC.hargaItem;
													tempParent->dataParent.totalItem -= jumlah2;
													yTemp++;
													gotoxy(xTemp, yTemp);
													printf("Apakah ingin menambah item lain? (y/n):");
													yTemp++;
													gotoxy(xTemp, yTemp);
													confirm = getch();
													if (confirm == 'n')
													{
														yTemp+=2;
														gotoxy(xTemp, yTemp);
														printf("Berhasil melakukan split bill");
														getch;
														break;
													}
													if (isOneChild(tempParent))
													{
														break;
													}
													
												} else {
													yTemp++;
													red();
													gotoxy(xTemp, yTemp);
													printf("Item tidak ada");
													resetColor();
													getch();
												}
												
											}while(1);

										}
										
									}
								} else {
									yTemp+=2;
									gotoxy(xTemp, yTemp);
									printf("[*] Jumlah nota tidak boleh lebih dari %d", tempParent->dataParent.totalItem);
								}
							} else {
								system("cls");
								errorMessageParentNULL(50, 9);
							}
						}
						
						
						
				}
				kb = getch();

			} while (kb!=27);
			kb = 'w';
		} if (kb == 13 && inValue == 2) // akses ke menu dapur
		{
			if (isEmpty(nota))
			{
				system("cls");
				errorMessageParentNULL(50, 10);
			} else {
				AddressParent  pointer = nota.firstParent;
				kb = 'w';
				inValue = 1;
				do
				{
					system("cls");
						
					switch (kb)
					{
						case 'w':
							if (nota.firstParent->next== NULL)
							{
									
							} else {
								if(pointer != nota.firstParent) {
									pointer = getBeforeWithProductionFalse(nota, pointer);
								}
								
							} 
							
							break;
						case 's':
							if (nota.firstParent->next== NULL)
							{
								
							} else {
								if (pointer->next != NULL) {
										//pointer = pointer->next;
									pointer = getNextWithProductionFalse(pointer);
									
								}
								
							}
							break;
						default:
							break;
					}
					printPaperDapur(nota, pointer);
					keyGuide(90, 8);
					if (kb == 13) // event listener ketika user memilih salah satu data
					{
						kb = 'w';
						confirm = 'w';
						xTemp = 50;
						yTemp = 5;
						gotoxy(xTemp, yTemp);
						printf("Pesanan selesai dimasak? (yes 'y' /no 'n')");
						confirm = getch();
						if (confirm == 'y')
						{
							pointer->dataParent.statusProduksi = true;
							pointer = nota.firstParent;
							yTemp++;
							gotoxy(xTemp, yTemp);
							printf("Berhasil mengubah status pesanan");
							blue();
							yTemp++;
							gotoxy(xTemp, yTemp);
							printf("Tekan 'space'");
							resetColor();
						} else {
							yTemp++;
							gotoxy(xTemp, yTemp);
							printf("Batal mengubah status pesanan");
							blue();
							yTemp++;
							gotoxy(xTemp, yTemp);
							printf("Tekan 'space'");
							resetColor();
						}
						
					}
					
					kb = getch();
				} while (kb != 27);
				kb = 'w';
			}
			
			getch();
		}
	} while (kb!=27);
	system("cls");
	return 0;
}
