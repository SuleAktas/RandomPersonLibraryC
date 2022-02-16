#include "RastgeleKisi.h"
#include"Rastgele.h"
#include"stdio.h"
#include"stdlib.h"
#include "errno.h"

Rastgele_Kisi rastgele_kisi()
{
	Rastgele_Kisi this;
	this = (Rastgele_Kisi)malloc(sizeof(struct RastgeleKisi));
	
	char rastgele_isimler[3000][40];
	
	FILE *fptr = NULL;
	int i = 0;
	int tot = 0;


	fptr = fopen("random_isimler.txt", "r");//dosya okumak icin acildi.
	while (fgets(rastgele_isimler[i], "/n", fptr))//tum satirlar okunup rastgele_isimler dizisine atandi.
	{
		i++;
	}
	int kelime_uzunlugu[3000];
	for (int i = 0; i < 3000; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			if (rastgele_isimler[i][j] == '\n')//Her satirin uzunlugu bulundu.
			{
				kelime_uzunlugu[i] = j;
			}
		}

	}
	fclose(fptr);
	tot = i;
	int randomsayi;
	randomsayi = random_sayi(3000);;
	
	for (int j = 0; j < kelime_uzunlugu[randomsayi]; j++)//gelen random sayiyla istenilen isim degiskene atandi.
	{
		
		this->rastgele_isim[j] = rastgele_isimler[randomsayi][j];

	}
	this->isim_uzunlugu = kelime_uzunlugu[randomsayi];
	this->RastKisiYokEt = &RYokEt;
	return this;
}
void RYokEt(Rastgele_Kisi this)
{
	if (this == NULL) return;
	free(this);
}
