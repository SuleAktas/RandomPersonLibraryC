#include "IMEINo.h"
#include"Rastgele.h"
#include"stdio.h"
#include"stdlib.h"
#include "errno.h"
#include"Rastgele.h"



Imei_No imei_no_olustur()
{
	Imei_No this;
	this = malloc(sizeof(struct IMEINo));
	int toplam=0;
	for (int i = 0; i < 14; i++)
	{
		
		this->imei_numarasi[i] = random_sayi(10);//imei numarasina rastgele rakamlar atandi.
	}
	for (int i = 0; i < 14; i++)
	{
		if (i % 2 != 0)//Imei numarasi algoritmasina gore gerekli islemler yapildi.
		{
			int basamaklar[2];
			if (2 * this->imei_numarasi[i]>9)
			{
				basamaklar[1] = (2 * this->imei_numarasi[i]) % 10;
				basamaklar[0] = (2 * this->imei_numarasi[i]) / 10;
				toplam += basamaklar[0] + basamaklar[1];
			}
			else
			{
				toplam += (2 * this->imei_numarasi[i]);
			}

		}
		else
		{
			toplam += this->imei_numarasi[i];
		}

		
	}
	toplam = 10 - (toplam % 10);
	
	if (toplam == 10)
	{
		toplam = 0;

	}
	this->imei_numarasi[14] = toplam;//Yapilan islemlere gore son basamaga deger atandi.
	this->Kontrol = &imei_no_kontrol;
	this->ImeiYokEt = &Imei_YokEt;
	return this;

	
}

void imei_no_kontrol()
{


	int imei[3000][15];
	char line[3000][100];
	
	FILE *fptr = NULL;
	int i = 0;
	int tot = 0;


	fptr = fopen("Kisiler.txt", "r");
	while (fgets(line[i], "/n", fptr))//Dosyadaki tum satirlar okunup line dizisine atandi.
	{
		
		i++;
	}
	fclose(fptr);
	tot = i;


	for (int i = 0; i < tot; i++)
	{
		for (int j = 0; j < strlen(line[i]); j++)
		{
			if (line[i][j] == '(')//Paranteze gelindiginde olusturulan imei dizisine dosyadan okunan degerler atandi.
			{
				j++;
				for (int a = 0; a < 15; a++)
				{
					imei[i][a] = line[i][a + j] - '0';
				}

			}
		}
		
	}

	int gecerli_imei = 0;
	int gecersiz_imei = 0;

	for (int i = 0; i < tot; i++)//Imei numarasi algoritmasina gore kontroller yapildi ve gecerli,gecersiz imeiler sayildi.
	{
		int kontrol_toplam = 0;
		
		for (int j = 0; j<14; j++)
		{
			if (j % 2 != 0)
			{
				int basamaklar[2];
				if (2 * imei[i][j]>9)
				{
					basamaklar[1] = (2 * imei[i][j]) % 10;
					basamaklar[0] = (2 * imei[i][j]) / 10;
					kontrol_toplam += basamaklar[0] + basamaklar[1];
				}
				else
				{
					kontrol_toplam += 2 * imei[i][j];
				}

			}
			else
			{
				kontrol_toplam += imei[i][j];
			}

		}
		kontrol_toplam = 10 - (kontrol_toplam % 10);
		if (kontrol_toplam == 10)
		{
			kontrol_toplam = 0;
		}


		if (imei[i][14] == kontrol_toplam)
		{
			gecerli_imei++;

		}
		else
		{
			gecersiz_imei++;

		}
	}
	printf("Imei No:\n");
	printf("Gecerli: %d\n",gecerli_imei);
	printf("Gecersiz: %d\n",gecersiz_imei);

}
void Imei_YokEt(Imei_No this)
{
	if (this == NULL)return;
	free(this);
}

