#ifndef TELEFON_H
#define TELEFON_H
#include"stdio.h"
#include"stdlib.h"

struct Telefon
{
	int telefon_numarasi[11];
	int imei_no2[15];
	void(*TelefonYokEt)(struct Telefon*);
	
};
typedef struct Telefon* telefon;
telefon telefon_no_olustur();
void TYokEt(telefon);


#endif
