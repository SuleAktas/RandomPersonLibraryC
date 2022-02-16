#ifndef KISI_H
#define KISI_H
#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
#include"Telefon.h"
#include"KimlikNo.h"
struct Kisi
{
	char isim[20];
	char soyisim[20];
	int yas;
	telefon telefon_no;
	Kimlik_No kimlik_num;
	int isim_uzunlugu;
	int soyisim_uzunlugu;
	void(*Dosya_Yaz)(struct Kisi*);
	void(*KisiYokEt)(struct Kisi*);

};
typedef struct Kisi* kisi;
kisi kisi_olustur();
void dosyaya_kisi_yazdir(const kisi);
void KYokEt(kisi);

#endif
