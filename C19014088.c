#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ogrenci
{
	char ogrID[9];
	char ad[30];
	char soyad[30];
	int puan;
	struct Ogrenci *next;
	struct Ogrenci *prev;
}Ogrenci;

typedef struct Yazar
{
	int yazarID;
	char yazarAd[30];
	char yazarSoyad[30];
	struct Yazar *next;
}Yazar;

typedef struct KitapOrnek
{
	char EtiketNo[20];
	char Durum[8];
	struct KitapOrnek *next;
}KitapOrnek;

typedef struct Kitap
{
	char kitapAd[30];
	char ISBN[14];
	int kitapAdet;
	struct Kitap *next;
	struct KitapOrnek *head;
}Kitap;

typedef struct KitapYazar{
	char ISBN[14];
	int yazarID;
}KitapYazar;

typedef struct Tarih
{
	int gun;
	int ay;
	int yil;
}Tarih;

typedef struct KitapOdunc
{
	char EtiketNo[20];
	char ogrID[9];
	int IslemTipi;
	struct KitapOdunc *next;
	struct Tarih *islemTarihi;
}KitapOdunc;

int OgrenciEkle(Ogrenci **head);
void OgrenciOku(Ogrenci **head);
void OgrenciYaz(Ogrenci **head);
int OgrenciSil(Ogrenci **head);
void OgrenciGuncelle(Ogrenci **head);
Ogrenci* OgrenciGorutuleme(Ogrenci **head);
void OgrenciListele(Ogrenci *head);
void CezaliOgrenciListele(Ogrenci *head);
void KTEOgrenciList(KitapOdunc *headKOdunc,Ogrenci *headOgrenci);
void YazarOku(Yazar **headYazar);
void YazarListele(Yazar *headYazar);
int YazarEkle(Yazar **headYazar);
int YazarSil(Yazar **headYazar,KitapYazar ***dizi);
void YazarGuncelle(Yazar **headYazar);
int YazarGoruntuleme(Yazar **headYazar,KitapYazar **dizi,Kitap *headKitap);
void KitapOku(Kitap **headKitap);
void KitapListele(Kitap *headKitap);
int KitapEkle(Kitap **headKitap);
int KitapSilme(Kitap **headKitap);
void KitapYaz(Kitap *headKitap);
void KitapOrnekEkle(KitapOrnek **headKitapOrnek,Kitap *KitapInfo);
void KitapGuncelle(Kitap **headKitap);
void KitapOrnekOku(Kitap **headKitap);
void KitapOrnekYaz(Kitap *headKitap);
int KitapYazarOkuma(KitapYazar ***dizi);
void KitapYazarYaz(KitapYazar **dizi,int count);
void KitapYazarEslestir(Yazar *headYazar,KitapYazar ***dizi,Kitap *headKitap);
int KitapYazarGuncelleme(Yazar *headYazar,KitapYazar ***dizi,Kitap *headKitap);
void YazarSilmeGuncelle(KitapYazar ***dizi,int yazarid);
int filelinecount(char *filename);
void KitapOduncOku(KitapOdunc **head);
void KitapOduncListele(KitapOdunc *headKodunc);
int KitapOduncEkle(KitapOdunc **headKodunc,char *ogrID,char *etiket,Tarih *tarih,int feature);
int KitapOduncAl(KitapOdunc **headKodunc,Ogrenci *headOgrenci,Kitap *headKitap);
Kitap* KitapGoruntule(Kitap *headKitap);
int KitapTeslimEtme(KitapOdunc **headKodunc,Ogrenci **headOgrenci,Kitap *headKitap);
void RaftakiKitapList(Kitap *head);
void ZTEKitapList(KitapOdunc *head);
int ArtikYil(Tarih *d);
int TarihFark(Tarih *dt1, Tarih *dt2);
void freeOgrenci(Ogrenci **head);
void freeKitap(Kitap **head);
void freeKitapOdunc(KitapOdunc **head);
void freeYazar(Yazar **head);
void YazarYaz(Yazar **headYazar);

int main(){
	int exitcontrol =1;
	int anamenu;
	int choice,res;
	
	
	int count =0;
	Ogrenci *head = (Ogrenci*) malloc(sizeof(Ogrenci));
	if(head == NULL){
		printf("Alan ayrilamadi.");
	}
	Yazar *headYazar = (Yazar*) malloc(sizeof(Yazar));
	if(headYazar == NULL){
		printf("Alan ayrilamadi. ");
	}
	Kitap *headKitap = (Kitap*) malloc(sizeof(Kitap));
	if(headKitap == NULL){
		printf("Alan ayrilamadi. ");
	}
	KitapOdunc *headKodunc = (KitapOdunc*) malloc(sizeof(KitapOdunc));
	if(headKodunc == NULL){
		printf("Alan aytilamadi. ");
	}
	head->prev = NULL;
	head->next = NULL;
	headKodunc->next = NULL;
	Ogrenci *temp;
	KitapYazar **dizi;
	int kyazarcount = KitapYazarOkuma(&dizi);
	OgrenciOku(&head);
	YazarOku(&headYazar);
	KitapOku(&headKitap);
	KitapOrnekOku(&headKitap);
	KitapOduncOku(&headKodunc);
	while(exitcontrol){
		printf("Islem Seciniz:\n");
		printf("1 - Ogranci Islemleri \n");
		printf("2 - Kitap Islemleri  \n");
		printf("3 - Yazar Islemleri \n");
		printf("4 - Cikis\n");
		scanf("%d",&anamenu);
		if(anamenu == 1){
			printf("Ogranci Islemleri \n");
			printf("1-Ogrenci Ekle\n");
			printf("2-Ogrenci Sil\n");
			printf("3-Ogrenci Guncelle\n");
			printf("4-Ogrenci Bilgisi Goruntuleme\n");
			printf("5-Kitap Teslim Etmemis Ogrencileri Listele\n");
			printf("6-Cezali Ogrencileri Listele\n");
			printf("7-Tum Ogrencileri Listele\n");
			printf("8-Kitap Odunc Al\n");
			printf("9-Kitap Teslim Et\n");
			printf("10-Cikis\n");
			scanf("%d",&choice);
			switch (choice){
			case 1:
				res = OgrenciEkle(&head);
				if(res == 0){
					printf("Basarili.");
				}
				break;
			case 2:
				res = OgrenciSil(&head);
				if(res == 1){
					printf("Basarili.");
				}
				break;
			case 3:
				OgrenciGuncelle(&head);
				break;
			case 4:
				temp = OgrenciGorutuleme(&head);
				if(temp == NULL){
					printf("Bulunamadi. ");				}
				break;
			case 5:
				KTEOgrenciList(headKodunc,head);
				break;
			case 6:
				CezaliOgrenciListele(head);
				break;
			case 7:
				OgrenciListele(head);
				break;
			case 8:
				res = KitapOduncAl(&headKodunc,head,headKitap);
				if(res == 0){
					printf("Basarili");
				}else{
					printf("Basarisiz.");
				}
				break;
			case 9:
				res = KitapTeslimEtme(&headKodunc,&head,headKitap);
				if(res == 0){
					printf("Basarili");
				}else{
					printf("Basarisiz.");
				}
				break;
			case 10:
				exitcontrol=0;
				break;
			default:
				printf("Yanlis Secim\n");
				break;
			}
		}
		else if (anamenu==2){
			printf("Kitap Islemleri\n");
			printf("1-Kitap Ekle\n");
			printf("2-Kitap Sil\n");
			printf("3-Kitap Guncelleme\n");
			printf("4-Kitap Bilgisi Goruntuleme\n");
			printf("5-Raftaki Kitaplari Listele\n");
			printf("6-Zamaninda Teslim Edilmeyen Kitaplari Listele\n");
			printf("7-Kitap yazar eslestir\n");
			printf("8-Kitabin Yazarini Guncelleme \n");
			printf("9-Cikis\n");
			scanf("%d",&choice);
			switch (choice){
			case 1:
				res = KitapEkle(&headKitap);
				if(res == 0){
					printf("Basarili. \n");
				}
				break;
			case 2:
				res = KitapSilme(&headKitap);
				if(res == 1){
					printf("Basarili. \n");
				}
				break;
			case 3:
				KitapGuncelle(&headKitap);
				break;
			case 4:
				KitapGoruntule(headKitap);
				break;
			case 5:
				RaftakiKitapList(headKitap);
				break;
			case 6:
				ZTEKitapList(headKodunc);
				break;
			case 7:
				KitapYazarEslestir(headYazar,&dizi,headKitap);
				break;
			case 8:
				res = KitapYazarGuncelleme(headYazar,&dizi,headKitap);
				if(res == 0){
					printf("Basarili. ");
				}else{
					printf("Hata. ");
				}				
				break;
			case 9:
				exitcontrol = 0;
				break;
			default:
				printf("Yanlis Secim\n");
				break;
			}
			
		}
		else if (anamenu == 3){
			printf("Yazar Islemleri \n");
			printf("1-Yazar Ekle\n");
			printf("2-Yazar Sil\n");
			printf("3-Yazar Guncelle\n");
			printf("4-Yazar Bilgisi Goruntuleme\n");
			printf("5-Cikis\n");
			scanf("%d",&choice);
			switch (choice)
			{
			case 1:
				res = YazarEkle(&headYazar);
				if(res == 0){
					printf("Basarili. \n");
				}
				break;
			case 2:
				res = YazarSil(&headYazar,&dizi);
				if(res == 1){
					printf("Basarili. \n");
				}
				break;
			case 3:
				YazarGuncelle(&headYazar);
				break;
			case 4:
				YazarGoruntuleme(&headYazar,dizi,headKitap); 
				break;
			case 5:
				exitcontrol = 0;
				break;			
			default:
				printf("Yanlis Secim\n");
				break;
			}
		}else if(anamenu == 4){
			exitcontrol = 0;
		}else{
			printf("Lutfen dogru secim yapiniz ...");
		}
	}


	freeOgrenci(&head);
	freeKitap(&headKitap);
	freeKitapOdunc(&headKodunc);
	freeYazar(&headYazar);


}

void OgrenciOku(Ogrenci **head){
	FILE *fptr2;
	Ogrenci *tmp2;
	fptr2 = fopen("Ogrenciler.csv","r");
	if(fptr2==NULL){
		printf("Dosya acilamadi.");
	}
	tmp2 = *head;
	while(!feof(fptr2)){	
		fscanf(fptr2,"%[^,], %[^,], %[^,], %d ",tmp2->ogrID,tmp2->ad,tmp2->soyad,&tmp2->puan);
		if(!feof(fptr2)){
			tmp2->next = (Ogrenci*) malloc(sizeof(Ogrenci));
			if(tmp2->next == NULL){
				printf("Hata");
			}
			tmp2->next->prev = tmp2;
			tmp2->next->next = NULL;
			tmp2 = tmp2->next;
		}
	}
	fclose(fptr2);
}

void OgrenciYaz(Ogrenci **head){
	FILE *fptr;
	fptr = fopen("Ogrenciler.csv","w");
	if(fptr == NULL){
		printf("Dosya acilmadi..");
	}
	Ogrenci *tmp;
	tmp = *head;
	while(tmp != NULL){	
		fprintf(fptr,"%s, %s, %s, %d\n",tmp->ogrID,tmp->ad,tmp->soyad,tmp->puan);
		tmp = tmp->next;
	}
	fclose(fptr);
}


int OgrenciEkle(Ogrenci **head){
	Ogrenci *tmp;
	Ogrenci *iter;
	iter = *head;
	tmp = (Ogrenci*) malloc(sizeof(Ogrenci));
	if(tmp == NULL){
		return -1;
	}
	printf("Sirasiyla Ad , Soyad, ogrId giriniz.. ");
	scanf("%s %s %s",tmp->ad,tmp->soyad,tmp->ogrID);
	tmp->puan = 100;
	while(iter->next != NULL){
		iter = iter->next;
	}
	iter->next = tmp;
	iter->next->prev = iter;
	iter->next->next = NULL;
	OgrenciYaz(head);
	return 0;
}

int OgrenciSil(Ogrenci **head){
	int found = 0;
	Ogrenci *iter;
	Ogrenci *tmp;
	iter = *head;
	char id[9];
	printf("Ogrenci Numaranizi Giriniz: ");
	scanf("%s",id);
	if(strcmp((*head)->ogrID,id)==0){//basta ise
		found=1;
		tmp = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(tmp);
	}else{
		while(iter->next!=NULL && strcmp(iter->next->ogrID,id)!=0){
			iter = iter->next;
		}
		if(iter->next != NULL){
			if(iter->next->next == NULL){//sonda ise
				found= 1;
				free(iter->next);
				iter->next=NULL;
			}else{//arada ise
				found = 1;
				tmp = iter->next;
				iter->next = iter->next->next;
				iter->next->prev = iter;
				free(tmp);
			}
		}else{
			printf("Numara Bulunamadi. \n");
		}
		
	}
	OgrenciYaz(head);
	return found;
}


void OgrenciGuncelle(Ogrenci **head){
	Ogrenci *iter;
	char id[9];
	printf("Ogrencinin OgrIdsini giriniz: ");
	scanf("%s",id);
	iter = *head;
	int found = 0;
	while(iter != NULL && strcmp(iter->ogrID,id)!=0){
		iter = iter->next;
	}
	if(iter != NULL){
		found = 1;
		printf("Sirasiyla Ad , Soyad, ogrId , Puan giriniz.. ");
		scanf("%s %s %s %d",iter->ad,iter->soyad,iter->ogrID,&iter->puan);
		OgrenciYaz(head);
		printf("Basarili.");
	}else{
		printf("Numara Bulunamadi.\n");

	}
}

Ogrenci* OgrenciGorutuleme(Ogrenci **head){
	Ogrenci *iter;
	char id[9];
	printf("Ogrencinin OgrIdsini giriniz: ");
	scanf("%s",id);
	iter = *head;
	int found = 0;
	while(iter != NULL && strcmp(iter->ogrID,id)!=0){
		iter = iter->next;
	}
	if(iter != NULL){
		found = 1;
		printf("Ad : %s , Soyad : %s , ogrId : %s , Puan : %d\n",iter->ad,iter->soyad,iter->ogrID,iter->puan);
		return iter;
	}else{
		printf("Numara Bulunamadi.\n");
		return NULL;
	}
}

void OgrenciListele(Ogrenci *head){
	Ogrenci *iter;
	iter = head;
	while(iter != NULL){
    	printf("ad : %s, soyad: %s, id: %s, puan: %d \n",iter->ad,iter->soyad,iter->ogrID,iter->puan);
        iter = iter->next;
    }
}

void KTEOgrenciList(KitapOdunc *headKOdunc,Ogrenci *headOgrenci){
	KitapOdunc *iter;
	iter = headKOdunc;
	KitapOdunc *iter2;
	Ogrenci *iter3;
	Ogrenci *iter4;
	int flag=0;
	char* ogrId;
	while(iter != NULL){
		if(iter->IslemTipi != 1){
			flag = 0;
			iter2 = iter->next;
			while(iter2 != NULL && flag != 1){
				if(strcmp(iter->EtiketNo,iter2->EtiketNo) == 0){
					flag = iter2->IslemTipi;
				}
				iter2 = iter2->next;
			}
			if(flag == 0){
				iter3 = headOgrenci;
				while(iter3 != NULL){
					if(strcmp(iter->ogrID,iter3->ogrID)==0){
						iter4 = iter3;
					}
					iter3 = iter3->next;
				}
				printf("ad : %s, soyad: %s, id: %s, puan: %d, Etiket: %s \n",iter4->ad,iter4->soyad,iter4->ogrID,iter4->puan,iter->EtiketNo);
			}
		}
		iter = iter->next;
	}


}

void CezaliOgrenciListele(Ogrenci *head){
	Ogrenci *iter;
	iter = head;
	int flag = 0;
	while(iter != NULL){
		if(iter->puan<0){
			printf("ad : %s, soyad: %s, id: %s, puan: %d \n",iter->ad,iter->soyad,iter->ogrID,iter->puan);
			flag++;
		}
        iter = iter->next;
    }
	if(flag==0){
		printf("Cezali ogrenci yok. \n");
	}
}


void YazarOku(Yazar **headYazar){
	FILE *fptr;
	Yazar *tmp;
	fptr = fopen("Yazarlar.csv","r");
	if(fptr==NULL){
		printf("Dosya acilamadi.");
	}
	tmp = *(headYazar);
	while(!feof(fptr)){
		fscanf(fptr,"%d, %[^,], %s ",&tmp->yazarID,tmp->yazarAd,tmp->yazarSoyad);
		if(!feof(fptr)){
			tmp->next = (Yazar*) malloc(sizeof(Yazar));
			if(tmp->next == NULL){
				printf("Hata");
			}
			tmp->next->next = NULL;
			tmp = tmp->next;
		}
	}
	fclose(fptr);
}

void YazarListele(Yazar *headYazar){
	Yazar *iter;
	iter = headYazar;
	while(iter != NULL){
    	printf("id: %d ad : %s, soyad: %s \n",iter->yazarID,iter->yazarAd,iter->yazarSoyad);
        iter = iter->next;
    }
}

int YazarEkle(Yazar **headYazar){
	Yazar *tmp;
	Yazar *iter;
	iter = *headYazar;
	tmp = (Yazar*) malloc(sizeof(Yazar));
	if(tmp == NULL){
		return -1;
	}
	printf("Sirasiyla Ad , Soyad Giriniz: ");
	scanf("%s %s",tmp->yazarAd,tmp->yazarSoyad);
	while(iter->next != NULL){
		iter = iter->next;
	}
	tmp->yazarID = iter->yazarID +1;
	iter->next = tmp;
	iter->next->next = NULL;
	YazarYaz(headYazar);
	return 0;
}

void YazarYaz(Yazar **headYazar){
	FILE *fptr;
	fptr = fopen("Yazarlar.csv","w");
	if(fptr == NULL){
		printf("Dosya acilmadi..");
	}
	Yazar *tmp;
	tmp = *headYazar;
	while(tmp != NULL){	
		fprintf(fptr,"%d, %s, %s\n",tmp->yazarID,tmp->yazarAd,tmp->yazarSoyad);
		tmp = tmp->next;
	}
	fclose(fptr);
	YazarOku(headYazar);
}

int YazarSil(Yazar **headYazar,KitapYazar ***dizi){
	int found = 0;
	Yazar *iter;
	Yazar *tmp;
	iter = *headYazar;
	int id;
	printf("Yazar Id Giriniz: ");
	scanf("%d",&id);
	if((*headYazar)->yazarID == id){//basta ise
		found=1;
		tmp = *headYazar;
		*headYazar = (*headYazar)->next;
		free(tmp);
		YazarSilmeGuncelle(dizi,id);
	}else{
		while(iter->next!=NULL && iter->next->yazarID != id){
			iter = iter->next;
		}
		if(iter->next != NULL){
			if(iter->next->next == NULL){//sonda ise
				found= 1;
				free(iter->next);
				iter->next=NULL;
				YazarSilmeGuncelle(dizi,id);
			}else{//arada ise
				found = 1;
				tmp = iter->next;
				iter->next = iter->next->next;
				free(tmp);
				YazarSilmeGuncelle(dizi,id);
			}
		}else{
			printf("Numara Bulunamadi. \n");
		}
		
	}
	YazarYaz(headYazar);
	return found;
}

void YazarGuncelle(Yazar **headYazar){
	Yazar *iter;
	int id;
	printf("Yazar Idsini giriniz: ");
	scanf("%d",&id);
	iter = *headYazar;
	int found = 0;
	while(iter != NULL && iter->yazarID != id){
		iter = iter->next;
	}
	if(iter != NULL){
		found = 1;
		printf("Sirasiyla Ad , Soyad Giriniz : ");
		scanf("%s %s",iter->yazarAd,iter->yazarSoyad);
		YazarYaz(headYazar);
	}else{
		printf("Numara Bulunamadi.\n");

	}
}

int YazarGoruntuleme(Yazar **headYazar,KitapYazar **dizi,Kitap *headKitap){
	Yazar *iter;
	Kitap *iter2;
	iter2 = headKitap;
	int i;
	char yazarad[30];
	char yazarsoyad[30];
	printf("Yazarin Adini ve Soyadini Giriniz: ");
	scanf("%s %s",yazarad,yazarsoyad);
	iter = *headYazar;
	int found = 0;
	while(iter != NULL && strcmp(iter->yazarAd,yazarad)!= 0 && strcmp(iter->yazarSoyad,yazarsoyad) != 0){
		iter = iter->next;
	}
	if(iter != NULL){
		found = 1;
		printf("Yazar ID: %d Ad : %s , Soyad : %s\n",iter->yazarID,iter->yazarAd,iter->yazarSoyad);
		int count = filelinecount("KitapYazar.csv");
		printf("Kitaplari : \n");
		for(i=0;i<count;i++){
			if(dizi[i]->yazarID==iter->yazarID){
				while(iter2 != NULL && strcmp(iter2->ISBN,dizi[i]->ISBN)!= 0){
					iter2 = iter2->next;
				}
				if(iter2 != NULL){
					printf("Kitabin Adi : %s , Kitabin ISBNsi: %s, Kitabin Adeti: %d\n",iter2->kitapAd,iter2->ISBN,iter2->kitapAdet);
				}else{
					printf("Hata. ");
				}
			}
		}
		return iter->yazarID;
	}else{
		printf("Yazar Bulunamadi.\n");
		return -1;
	}
}

void KitapOku(Kitap **headKitap){
	FILE *fptr;
	Kitap *tmp;
	fptr = fopen("Kitaplar.csv","r");
	if(fptr==NULL){
		printf("Dosya acilamadi.");
	}
	tmp = *(headKitap);
	while(!feof(fptr)){
		fscanf(fptr,"%[^,], %[^,], %d ",tmp->kitapAd,tmp->ISBN,&tmp->kitapAdet);
		if(!feof(fptr)){
			tmp->next = (Kitap*) malloc(sizeof(Kitap));
			if(tmp->next == NULL){
				printf("Hata");
			}
			tmp->next->next = NULL;
			tmp = tmp->next;
		}
	}
	fclose(fptr);
}

void KitapListele(Kitap *headKitap){
	Kitap *iter;
	iter = headKitap;
	while(iter != NULL){
    	printf("ad : %s, ISBN: %s adet: %d \n",iter->kitapAd,iter->ISBN,iter->kitapAdet);
        iter = iter->next;
    }
}

void RaftakiKitapList(Kitap *head){
	Kitap *iter;
	KitapOrnek *iter2;
	iter = head;
	int i;
	while(iter != NULL){
		iter2 = iter->head;
		for(i=0;i<iter->kitapAdet;i++){
			if(strcmp(iter2->Durum,"Rafta")==0){
				printf("EtiketNo: %s\n",iter2->EtiketNo);
			}
			iter2 = iter2->next;
		}
		iter = iter->next;
	}

}

void ZTEKitapList(KitapOdunc *head){
	Tarih *temp = (Tarih*) malloc(sizeof(Tarih));
	printf("Bu gunun tarihini giriniz(G.A.Y) : ");
	scanf("%d.%d.%d",&temp->gun,&temp->ay,&temp->yil);
	KitapOdunc *iter;
	KitapOdunc *iter2;
	KitapOdunc *iter3;
	iter = head;
	int count=0;
	int veri1;
	int veri2;
	while(iter != NULL){
		if(iter->IslemTipi != 1){
			iter2 = iter->next;
			count=0;
			while(iter2 != NULL){
				if(strcmp(iter->EtiketNo,iter2->EtiketNo)== 0 && iter2->IslemTipi == 1){
					count++;
					iter3 = iter2;
				}
				iter2 = iter2->next;
			}	
			if(count>0){
				veri1 = TarihFark(iter->islemTarihi,iter3->islemTarihi);
				if((veri1)>15){
					printf("Etiket No: %s OgrId : %s IslemTarihi: %d.%d.%d \n",iter3->EtiketNo,iter3->ogrID,iter3->islemTarihi->gun,iter3->islemTarihi->ay,iter3->islemTarihi->yil);
				}
			}else{
				veri2 = TarihFark(iter->islemTarihi,temp);
				if(veri2>15){
					printf("Etiket No: %s OgrId : %s IslemTarihi: %d.%d.%d \n",iter->EtiketNo,iter->ogrID,iter->islemTarihi->gun,iter->islemTarihi->ay,iter->islemTarihi->yil);
				}
			}
		}
		iter = iter->next;
	}
}

int KitapEkle(Kitap **headKitap){
	int i;
	Kitap *tmp;
	Kitap *iter;
	iter = *headKitap;
	tmp = (Kitap*) malloc(sizeof(Kitap));
	if(tmp == NULL){
		return -1;
	}
	printf("Kitabin Adini giriniz : ");
	scanf(" %[^\n]",tmp->kitapAd);
	printf("Kitabin ISBN , Adetini Giriniz: ");
	scanf("%s %d",tmp->ISBN,&tmp->kitapAdet);
	KitapOrnek *tmp2 = (KitapOrnek*) malloc(sizeof(KitapOrnek));
	tmp->head = tmp2;
	KitapOrnekEkle(&(tmp->head),tmp);
	if (iter == NULL){
		iter = tmp;
		iter->next = NULL;
	}else{
		while(iter->next != NULL){
			iter = iter->next;
		}
		iter->next = tmp;
		iter->next->next = NULL;
	}
	KitapYaz(*headKitap);
	KitapOrnekYaz(*headKitap);
	return 0;
}


void KitapOrnekListele(KitapOrnek *headKitapOrnek){
	KitapOrnek *iter;
	iter = headKitapOrnek;
	while(iter != NULL){
    	printf("EtiketNo: %s Durum: %s \n",iter->EtiketNo,iter->Durum);
        iter = iter->next;
    }
}
void KitapOrnekOku(Kitap **headKitap){
	int i;
	FILE *fptr;
	KitapOrnek *tmp;
	Kitap *iter;
	iter = *headKitap;
	fptr = fopen("KitapOrnek.csv","r");
	if(fptr==NULL){
		printf("Dosya acilamadi.");
	}
	
	while(iter != NULL && !feof(fptr)){
		iter->head = (KitapOrnek*) malloc(sizeof(KitapOrnek));
		tmp = iter->head;
		for(i=0;i<iter->kitapAdet;i++){
			fscanf(fptr,"%[^,], %s ",tmp->EtiketNo,tmp->Durum);
			if(!feof(fptr)){
				tmp->next = (KitapOrnek*) malloc(sizeof(KitapOrnek));
				if(tmp->next == NULL){
					printf("Hata");
				}
				tmp->next->next = NULL;
				tmp = tmp->next;
			}
		}
		iter = iter->next;
	}
	fclose(fptr);
}


void KitapOrnekEkle(KitapOrnek **headKitapOrnek,Kitap *KitapInfo){
	int i;
	KitapOrnek *tmp;
	KitapOrnek *iter;
	iter = *headKitapOrnek;
	for(i=0;i<KitapInfo->kitapAdet;i++){
		sprintf(iter->EtiketNo,"%s_%d",KitapInfo->ISBN,i+1);
		strcpy(iter->Durum,"Rafta");
		iter->next = NULL;
		if(i!=(KitapInfo->kitapAdet)-1){
			iter->next = (KitapOrnek*) malloc(sizeof(KitapOrnek));
		}
		iter = iter->next;
	}
}

void KitapOrnekYaz(Kitap *headKitap){
	FILE *fptr;
	fptr = fopen("KitapOrnek.csv","w");
	if(fptr == NULL){
		printf("Dosya acilmadi..");
	}
	KitapOrnek *iter; 
	Kitap *tmp;
	tmp = headKitap;
	int i;
	while(tmp != NULL){	
		iter = tmp->head;
		for(i=0;i<tmp->kitapAdet;i++){
			fprintf(fptr,"%s, %s\n",iter->EtiketNo,iter->Durum);
			iter = iter->next;
		}
		tmp = tmp->next;
	}
	fclose(fptr);		 
}

void KitapYaz(Kitap *headKitap){
	FILE *fptr;
	fptr = fopen("Kitaplar.csv","w");
	if(fptr == NULL){
		printf("Dosya acilmadi..");
	}
	Kitap *tmp;
	tmp = headKitap;
	while(tmp != NULL){	
		fprintf(fptr,"%s, %s, %d\n",tmp->kitapAd,tmp->ISBN,tmp->kitapAdet);
		tmp = tmp->next;
	}
	fclose(fptr);
}

int KitapSilme(Kitap **headKitap){
	int found = 0;
	Kitap *iter;
	Kitap *tmp;
	iter = *headKitap;
	char isbnid[14];
	printf("Kitap ISBNsini Giriniz: ");
	scanf("%s",isbnid);
	if(strcmp((*headKitap)->ISBN,isbnid) == 0){//basta ise
		found=1;
		tmp = *headKitap;
		*headKitap = (*headKitap)->next;
		free(tmp);
	}else{
		while(iter->next!=NULL && strcmp(iter->next->ISBN,isbnid)){
			iter = iter->next;
		}
		if(iter->next != NULL){
			if(iter->next->next == NULL){//sonda ise
				found= 1;
				free(iter->next);
				iter->next=NULL;
			}else{//arada ise
				found = 1;
				tmp = iter->next;
				iter->next = iter->next->next;
				free(tmp);
			}
		}else{
			printf("Numara Bulunamadi. \n");
		}
		
	}
	KitapYaz(*headKitap);
	KitapOrnekYaz(*headKitap);
	return found;
}

void KitapGuncelle(Kitap **headKitap){
	int i;
	int size;
	Kitap *iter;
	KitapOrnek *tmp;
	KitapOrnek *iter2;
	char isbnid[14];
	printf("Kitap ISBNsini Giriniz: ");
	scanf("%s",isbnid);
	iter = *headKitap;
	int found = 0;
	while(iter != NULL && strcmp(iter->ISBN,isbnid)!=0){
		iter = iter->next;
	}
	if(iter != NULL){
		found = 1;
		size = iter->kitapAdet;
		printf("Kitabin Adini giriniz : ");
		scanf(" %[^\n]",iter->kitapAd);
		printf("Kitabin ISBN , Adetini Giriniz: ");
		scanf("%s %d",iter->ISBN,&iter->kitapAdet);
		iter2 = iter->head;
		for(i=0;i<size;i++){
			tmp = iter2;
			iter2 = iter2->next;
			free(tmp);
		}
		iter->head = (KitapOrnek*) malloc(sizeof(KitapOrnek));
		KitapOrnekEkle(&(iter->head),iter);
		KitapYaz(*headKitap);
		KitapOrnekYaz(*headKitap);
	}else{
		printf("Numara Bulunamadi.\n");

	}
}

int filelinecount(char *filename){
	FILE *fptr;
	fptr = fopen(filename,"r");
	if(!fptr){
		printf("Dosya Acilamadi . ");
	}
	int count = 1;
    char temp;
    while(fscanf(fptr,"%c",&temp) != -1){
        if(temp == 10) count++;
    }
    fclose(fptr);
    return count;
}

int KitapYazarOkuma(KitapYazar ***dizi){
	char *file = "KitapYazar.csv";
	int count = filelinecount(file);
	FILE *fptr;
	fptr = fopen("KitapYazar.csv","r");
	if(!fptr){
		printf("Dosya Acilamadi . ");
	}
	int i;
	*dizi = (KitapYazar**) malloc(count*sizeof(KitapOrnek*));
	for(i=0;i<count;i++){
		(*dizi)[i] = (KitapYazar*) malloc(sizeof(KitapOrnek));
	}
	i=0;
	while(!feof(fptr)){
		fscanf(fptr,"%[^,], %d ",(*dizi)[i]->ISBN,&(*dizi)[i]->yazarID);
		i++;
	}
	fclose(fptr);
	return count;
}

int KitapYazarGuncelleme(Yazar *headYazar,KitapYazar ***dizi,Kitap *headKitap){
	char isbn[14];
	printf("Kitabin ISBNsini giriniz: ");
	scanf("%s",isbn);
	int i;
	int yazarid;
	int choice;
	int count = filelinecount("KitapYazar.csv");
	for(i=0;i<count;i++){
		if(strcmp((*dizi)[i]->ISBN,isbn)==0 && ((*dizi)[i]->yazarID) != -1){
			printf("ISBN: %s YazarId: %d\n",(*dizi)[i]->ISBN,(*dizi)[i]->yazarID);
			yazarid = YazarGoruntuleme(&headYazar,*dizi,headKitap);
			if(yazarid == -1){
				printf("Hata. ");
			}
			printf("Guncellemek istiyormusunuz E:1 H:0: ");
			scanf("%d",&choice);
			if(choice == 1){
				(*dizi)[i]->yazarID = yazarid;
				KitapYazarYaz(*dizi,count);
			}else{
				printf("Hata. ");
				return -1;
			}
		}
	}
	return 0;
}

void KitapYazarYaz(KitapYazar **dizi,int count){
	FILE *fptr;
	fptr = fopen("KitapYazar.csv","w");
	if(fptr == NULL){
		printf("Dosya acilmadi..");
	}
	int i;
	for(i=0;i<count;i++){
		if(i==(count-1)){
			fprintf(fptr,"%s, %d",dizi[i]->ISBN,dizi[i]->yazarID);
		}else{
			fprintf(fptr,"%s, %d\n",dizi[i]->ISBN,dizi[i]->yazarID);
		}
	}
	fclose(fptr);
}

void KitapYazarEkle(KitapYazar ***dizi,int yazarId,char *ISBN){
	FILE *fptr;
	fptr = fopen("KitapYazar.csv","a");
	fprintf(fptr,"\n%s, %d",ISBN,yazarId);
	fclose(fptr);
	int count = filelinecount("KitapYazar.csv");
	KitapYazarOkuma(dizi);
}

void KitapYazarEslestir(Yazar *headYazar,KitapYazar ***dizi,Kitap *headKitap){
	char *isbn;
	int yazarid = YazarGoruntuleme(&headYazar,*dizi,headKitap);
	if(yazarid == -1){
		printf("Hata. ");
	}
	printf("Eslestireceginiz kitabin ISBNsini Giriniz : ");
	scanf("%s",isbn);
	KitapYazarEkle(dizi,yazarid,isbn);
}

void YazarSilmeGuncelle(KitapYazar ***dizi,int yazarid){
	int i;
	int count = filelinecount("KitapYazar.csv");
	for(i=0;i<count;i++){
		if((*dizi)[i]->yazarID == yazarid){
			(*dizi)[i]->yazarID = -1;
		}
	}
	KitapYazarYaz(*dizi,count);
	KitapYazarOkuma(dizi);
}

void KitapOduncOku(KitapOdunc **head){
	FILE *fptr;
	KitapOdunc *tmp;
	fptr = fopen("KitapOdunc.csv","r");
	if(fptr==NULL){
		printf("Dosya acilamadi.");
	}
	tmp = *head;
	tmp->islemTarihi = (Tarih*) malloc(sizeof(Tarih));
	while(!feof(fptr)){	
		fscanf(fptr,"%[^,],%[^,],%d,%d.%d.%d ",tmp->EtiketNo,tmp->ogrID,&tmp->IslemTipi,&tmp->islemTarihi->gun,&tmp->islemTarihi->ay,&tmp->islemTarihi->yil);
		if(!feof(fptr)){
			tmp->next = (KitapOdunc*) malloc(sizeof(KitapOdunc));
			tmp->next->islemTarihi = (Tarih*) malloc(sizeof(Tarih));
			if(tmp->next == NULL){
				printf("Hata");
			}
			tmp->next->next = NULL;
			tmp = tmp->next;
		}
	}
	//KitapOduncListele(*head);
	fclose(fptr);	
}

void KitapOduncListele(KitapOdunc *headKodunc){
	KitapOdunc *iter;
	iter = headKodunc;
	while(iter != NULL){
    	printf("Etiket No: %s Ogrenci No: %s Durum: %d Tarih: %d.%d.%d\n",iter->EtiketNo,iter->ogrID,iter->IslemTipi,iter->islemTarihi->gun,iter->islemTarihi->ay,iter->islemTarihi->yil);
        iter = iter->next;
    }
}

int KitapOduncEkle(KitapOdunc **headKodunc,char *ogrID,char *etiket,Tarih *tarih,int feature){
	KitapOdunc *tmp;
	KitapOdunc *iter;
	iter = *headKodunc;
	tmp = (KitapOdunc*) malloc(sizeof(KitapOdunc));
	if(tmp == NULL){
		return -1;
	}
	
	if(feature == 1){
		tmp->islemTarihi = tarih;
		strcpy(tmp->EtiketNo,etiket);
		strcpy(tmp->ogrID,ogrID);
		tmp->IslemTipi = 1;		
	}else if(feature == 0){
		tmp->islemTarihi = tarih;
		strcpy(tmp->EtiketNo,etiket);
		strcpy(tmp->ogrID,ogrID);
		tmp->IslemTipi = 0;	
	}else{
		tmp->islemTarihi = (Tarih*) malloc(sizeof(Tarih));
		printf("Sirasiyla EtiketNo , ogrId, Durum , Tarih(G.A.Y) giriniz.. ");
		scanf("%s %s %d %d.%d.%d",tmp->EtiketNo,tmp->ogrID,&tmp->IslemTipi,&tmp->islemTarihi->gun,&tmp->islemTarihi->ay,&tmp->islemTarihi->yil);
	}
	
	if((*headKodunc)->next == NULL){
		tmp->next = NULL;
		*headKodunc = tmp;
	}else{
		iter = *headKodunc;
		while(iter->next != NULL){
			iter = iter->next;
		}
		iter->next = tmp;
		iter->next->next = NULL;
	}
	FILE *fptr;
	fptr = fopen("KitapOdunc.csv","a");
	if(fptr==NULL){
		printf("Dosya acilamadi.");
	}
	fseek(fptr,0,SEEK_END);
	if(ftell(fptr) == 0){
		fprintf(fptr,"%s,%s,%d,%d.%d.%d",tmp->EtiketNo,tmp->ogrID,tmp->IslemTipi,tmp->islemTarihi->gun,tmp->islemTarihi->ay,tmp->islemTarihi->yil);
	}else{
		fprintf(fptr,"\n%s,%s,%d,%d.%d.%d",tmp->EtiketNo,tmp->ogrID,tmp->IslemTipi,tmp->islemTarihi->gun,tmp->islemTarihi->ay,tmp->islemTarihi->yil);
	}
	fclose(fptr);
	return 0;
		
}

Kitap* KitapGoruntule(Kitap *headKitap){
	Kitap *iter;
	char id[14];
	printf("Kitabin ISBNsini giriniz: ");
	scanf("%s",id);
	iter = headKitap;
	while(iter != NULL && strcmp(iter->ISBN,id)!=0){
		iter = iter->next;
	}
	if(iter != NULL){
		printf("Ad : %s , ISBN: %s , Adet : %d\n",iter->kitapAd,iter->ISBN,iter->kitapAdet);
		return iter;
	}else{
		printf("Numara Bulunamadi.\n");
		return NULL;
	}

}

int KitapOduncAl(KitapOdunc **headKodunc,Ogrenci *headOgrenci,Kitap *headKitap){
	Ogrenci *tmp = OgrenciGorutuleme(&headOgrenci);
	if(tmp == NULL){
		return -1;
	}else if((tmp->puan)<0){
		printf("Ogrenci Cezali.");
		return -1;
	}
	Kitap *tmp2 = KitapGoruntule(headKitap);
	if(tmp2 == NULL){
		return -1;
	}
	KitapOrnek *iter2 = tmp2->head;
	int b=0;
	while(iter2 != NULL){
		if(strcmp(iter2->Durum,"Rafta") == 0){
			b++;
		}
		iter2 = iter2->next;
	}
	if(b == 0){
		return -1;
		printf("Islem Basarisiz. Bos Kitap Yok.");
	}
	char etiket[21];
	printf("Lutfen Kitabin Etiket Numarasini giriniz. ");
	scanf("%s",etiket);
	Tarih *temp = (Tarih*) malloc(sizeof(Tarih));
	printf("Kitabin Odunc Alinma Tarihini giriniz(G.A.Y): ");
	scanf("%d.%d.%d",&temp->gun,&temp->ay,&temp->yil);
	/*char *ISBN;
	sscanf(etiket,"%[^_]",ISBN);
	printf("%s",ISBN);*/
	KitapOdunc *iter;
	KitapOrnek *iter3 = tmp2->head;
	iter = *headKodunc;
	if(iter->next == NULL){
		printf("Kitap Odunc Verilebilir..");
		return KitapOduncEkle(headKodunc,tmp->ogrID,etiket,temp,0);
	}
	int i;
	int count = filelinecount("KitapOdunc.csv");
	int flag;
	int flag2 = 0;
	for (i = 0; i < count && iter != NULL; i++)
	{
		if(strcmp(iter->EtiketNo,etiket)==0){
			flag = iter->IslemTipi;
			flag2++;
		}
		iter = iter->next;
	}
	if(flag == 1 || flag2 == 0){
		printf("Kitap Odunc Verilebilir..");
		while(iter3 != NULL){
			if(strcmp(iter3->EtiketNo,etiket) == 0){
				strcpy(iter3->Durum,tmp->ogrID);
			}
			iter3 = iter3->next;
		}
		KitapOrnekYaz(headKitap);
		return KitapOduncEkle(headKodunc,tmp->ogrID,etiket,temp,0);
	}else{
		printf("Kitap Odunc Verilemez. ");
		return -1;
	}
}

int KitapTeslimEtme(KitapOdunc **headKodunc,Ogrenci **headOgrenci,Kitap *headKitap){
	Ogrenci *tmp = OgrenciGorutuleme(headOgrenci);
	if(tmp == NULL){
		return -1;
	}else if((tmp->puan)<0){
		printf("Ogrenci Cezali.");
		return -1;
	}
	Kitap *tmp2 = KitapGoruntule(headKitap);
	if(tmp2 == NULL){
		return -1;
	}
	char etiket[21];
	printf("Lutfen Kitabin Etiket Numarasini giriniz. ");
	scanf("%s",etiket);
	KitapOdunc *tmp3 = NULL;
	Tarih *temp = (Tarih*) malloc(sizeof(Tarih));
	printf("Kitabin Teslim Tarihini giriniz(G.A.Y): ");
	scanf("%d.%d.%d",&temp->gun,&temp->ay,&temp->yil);
	KitapOdunc *iter;
	iter = *headKodunc;
	KitapOrnek *iter3;
	iter3 = tmp2->head;
	if(iter->next == NULL){
		return KitapOduncEkle(headKodunc,tmp->ogrID,etiket,temp,1);
	}
	int i;
	int count = filelinecount("KitapOdunc.csv");
	int flag;
	for (i = 0; i < count && iter != NULL; i++)
	{
		if(strcmp(iter->EtiketNo,etiket)==0 && strcmp(iter->ogrID,tmp->ogrID)==0){
			flag = iter->IslemTipi;
			tmp3 = iter;
		}
		iter = iter->next;
	}
	int fark;

	if(flag == 0 && tmp3 !=NULL){		
		printf("Kitap Teslim Edilebilir..");
		fark = TarihFark(tmp3->islemTarihi,temp);
		if(fark <0){
			printf("Teslim Tarihi Yanlis Girildi .");
			return -1;		
		}else if(fark > 15){
			printf("Gec Teslim Edildi Ogrenciye -10 puan yansitildi.");
			tmp->puan -= 10;
			OgrenciYaz(headOgrenci);
		}		
		while(iter3 != NULL){
			if(strcmp(iter3->EtiketNo,etiket) == 0){
				strcpy(iter3->Durum,"Rafta");
			}
			iter3 = iter3->next;
		}
		KitapOrnekYaz(headKitap);
		return KitapOduncEkle(headKodunc,tmp->ogrID,etiket,temp,1);
	}else{
		printf("Kitap Odunc Verilmemis. ");
		return -1;
	}

}

//Tarih arasındaki fark
int ArtikYil(Tarih *d){
    int years = d->yil;
    if (d->ay <= 2)
        years--;
    return years / 4 - years / 100 + years / 400;
}

int TarihFark(Tarih *dt1, Tarih *dt2){
	int i;
	int monthDays[12]= { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    long int n1 = dt1->yil * 365 + dt1->gun;
    for (i = 0; i < dt1->ay - 1; i++)
        n1 += monthDays[i];
    n1 += ArtikYil(dt1);
    long int n2 = dt2->yil * 365 + dt2->gun;
    for (i = 0; i < dt2->ay - 1; i++)
        n2 += monthDays[i];
    n2 += ArtikYil(dt2);
    return (n2 - n1);
}

void freeOgrenci(Ogrenci **head){
	Ogrenci *iter;
	iter = *head;
	while(*head != NULL){
		iter = *head;
		*head = (*(head))->next;
		free(iter);
	}
	printf("Ogrenci Linked Listi Bosaltildi. \n");
}

void freeKitapOdunc(KitapOdunc **head){
	KitapOdunc *iter;
	iter = *head;
	while(*head != NULL){
		iter = *head;
		*head = (*(head))->next;
		free(iter);
	}
	printf("KitapOdunc Linked Listi Bosaltildi. \n");
}

void freeKitap(Kitap **head){
	Kitap *iter;
	KitapOrnek *iter2;
	KitapOrnek *tmp;
	iter = *head;
	int i;
	while(*head != NULL){
		iter = *head;
		iter2 = iter->head;
		for(i=0;i<iter->kitapAdet;i++){
			tmp = iter2;
			iter2 = iter2->next;
			free(tmp);
		}
		*head = (*(head))->next;
		free(iter);
	}
	printf("Kitap Linked Listi Bosaltildi. \n");
}

void freeYazar(Yazar **head){
	Yazar *iter;
	iter = *head;
	while(*head != NULL){
		iter = *head;
		*head = (*(head))->next;
		free(iter);
	}
	printf("Yazar Linked Listi Bosaltildi. \n");
}


