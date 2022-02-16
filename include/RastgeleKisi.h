#ifndef RASTGELEKÝSÝ_H
#define RASTGELEKÝSÝ_H
#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
struct RastgeleKisi
{
	char rastgele_isim[40];
	int isim_uzunlugu;
	void(*RastKisiYokEt)(struct RastgeleKisi*);
	
};
typedef struct RastgeleKisi *Rastgele_Kisi;
Rastgele_Kisi rastgele_kisi();
void RYokEt(Rastgele_Kisi);

#endif
