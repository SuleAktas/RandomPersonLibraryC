#include "Telefon.h"
#include"stdio.h"
#include"stdlib.h"
#include"IMEINo.h"
#include"Rastgele.h"
telefon telefon_no_olustur()
{

	telefon this;
	Imei_No imei_icin;
	this = (telefon)malloc(sizeof(struct Telefon));
	imei_icin = (Imei_No)malloc(sizeof(struct IMEINo));
	this->telefon_numarasi[0] = 0;
	this->telefon_numarasi[1] = 5;
	imei_icin = imei_no_olustur();
	for (int i = 0; i < 15; i++)
	{
		this->imei_no2[i] = imei_icin->imei_numarasi[i];//imei numarasi icine imei yapisinda olusturulan degerler atandi.
	}


	for (int i = 2; i<11; i++)
	{
	
		this->telefon_numarasi[i] = random_sayi(10);//telefon numarasinin icine rastgele rakamlar atandi.


	}
	this->TelefonYokEt = &TYokEt;
	return this;
}
void TYokEt(telefon this)
{
	if (this == NULL) return;
	free(this);
}