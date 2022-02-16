#ifndef IMEINO_H
#define IMEINO_H
#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include"stdlib.h"
struct IMEINo
{
	int imei_numarasi[15];
	void(*Kontrol)(struct IMEINo*);
	void(*ImeiYokEt)(struct IMEINo*);
};
typedef struct IMEINo* Imei_No;
Imei_No imei_no_olustur();
void imei_no_kontrol();
void Imei_YokEt(Imei_No);


#endif
