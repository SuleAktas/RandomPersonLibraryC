#include "Kisi.h"
#include"RastgeleKisi.h"
#include"IMEINo.h"
#include"stdlib.h"
#include"stdio.h"
#include"KimlikNo.h"
#include"Rastgele.h"

kisi kisi_olustur()
{
	kisi this;
	this = (kisi)malloc(sizeof(struct Kisi));
	int rastgele;
	Rastgele_Kisi rastgelekisi;
	rastgelekisi =(Rastgele_Kisi)malloc(sizeof(struct RastgeleKisi));
	rastgelekisi = rastgele_kisi();
	
	
	int i = 0;
	while (rastgelekisi->rastgele_isim[i] != ' ')//Bosluga gelene kadar olan karakterler isim degiskenine atandi.
	{
		this->isim[i] = rastgelekisi->rastgele_isim[i];
		i++;
	}
	this->isim_uzunlugu = i;
	i++;
	int b=0;
	for (int j = i; j < rastgelekisi->isim_uzunlugu; j++)//Bosluktan sonraki karakterler soyisime atandi.
	{
		this->soyisim[b] = rastgelekisi->rastgele_isim[j];
		b++;
	}
	this->soyisim_uzunlugu = b;
	
	this->telefon_no=telefon_no_olustur();
	this->kimlik_num = kimlik_no_olustur();
	this->yas = random_sayi(100);
	this->Dosya_Yaz = &dosyaya_kisi_yazdir;
	this->KisiYokEt = &KYokEt;
	return this;
	
}

void dosyaya_kisi_yazdir(const kisi this)
{
	
	

	FILE *dosya_yazma;
	dosya_yazma = fopen("Kisiler.txt", "a");//olusturulan kisiler eklenmek uzere dosya acildi ve karakter karakter yazildi.
	fprintf(dosya_yazma, "\n");
	for (int i = 0; i < 11; i++)
	{
		fprintf(dosya_yazma, "%d", this->kimlik_num->kimlik_no[i]);
		
	}
	fprintf(dosya_yazma, "%c", ' ');
	for (int i = 0; i < this->isim_uzunlugu; i++)
	{
		fprintf(dosya_yazma, "%c", this->isim[i]);
	   
	}
	fprintf(dosya_yazma," ");
	for (int i = 0; i < this->soyisim_uzunlugu; i++)
	{
		fprintf(dosya_yazma, "%c", this->soyisim[i]);

	}

	fprintf(dosya_yazma, " %d ", this->yas);
	
	for (int i = 0; i < 11; i++)
	{
		fprintf(dosya_yazma, "%d", this->telefon_no->telefon_numarasi[i]);
	   
	}
	
	fprintf(dosya_yazma, " %c",'(');
	for (int i = 0; i < 15; i++)
	{

		fprintf(dosya_yazma, "%d", this->telefon_no->imei_no2[i]);
	   
	}
	
	fprintf(dosya_yazma, "%c", ')');
	fclose(dosya_yazma);
}
void KYokEt(kisi this)
{
	if (this == NULL) return;
	if (this->kimlik_num != NULL) this->kimlik_num->KimlikYokEt;
	if (this->telefon_no != NULL) this->telefon_no->TelefonYokEt;

}
