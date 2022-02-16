#ifndef KIMLIKNO_H
#define KIMLIKNO_H
#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
struct KimlikNo
{
	int kimlik_no[11];
	void(*KimlikKontrol)(struct KimlikNo*);
	void(*KimlikYokEt)(struct KimlikNo*);
};
typedef struct KimlikNo* Kimlik_No;
Kimlik_No kimlik_no_olustur();
void kimlik_no_kontrol();
void Kimlik_YokEt(Kimlik_No);


#endif