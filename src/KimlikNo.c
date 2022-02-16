#include"KimlikNo.h"
#include"stdlib.h"
#include"stdio.h"
#include"Rastgele.h"
Kimlik_No kimlik_no_olustur()
{
	Kimlik_No this;
	this = (Kimlik_No)malloc(sizeof(struct KimlikNo));

	int ilk_toplam=0;
	int son_toplam=0;
	int islem1;
	int islem2;

	do
	{
		this->kimlik_no[0] = random_sayi(10);
	} while (this->kimlik_no[0] == 0);

	for (int i = 1; i<9; i++)//kimlik numarasina rastgele rakamlar atandi.
	{
		this->kimlik_no[i] = random_sayi(10);
	}
	for (int j = 0; j<9; j = j + 2)//kimlik numarasi algoritmasina gore son iki basamaga deger verildi.
	{
		ilk_toplam += this->kimlik_no[j];
	}
	for (int i = 1; i<8; i = i + 2)
	{
		son_toplam += this->kimlik_no[i];
	}

	islem1 = ((7 * ilk_toplam) - son_toplam) % 10;
	this->kimlik_no[9] = islem1;
	islem2 = (ilk_toplam + son_toplam + islem1) % 10;
	this->kimlik_no[10] = islem2;
	this->KimlikKontrol = &kimlik_no_kontrol;
	this->KimlikYokEt = &Kimlik_YokEt;
	return this;

}
void kimlik_no_kontrol()
{
	
	int tc_num[3000][11];
	char line[3000][100];
	char fname[30];
	FILE *fptr = NULL;
	int i = 0;
	int tot = 0;
	
	
	fptr = fopen("Kisiler.txt", "r");
	while (fgets(line[i],"/n", fptr))//Dosyadan tum satirlardaki veriler okundu.
	{
		line[i][strlen(line[i]) - 1] = '\0';
		i++;
	}
	fclose(fptr);
	tot = i;
	

	for (int i = 0; i < tot; i++)
	{
		for (int j = 0; j < 11; j++)//Olusturulan tc_num dizisine teker teker atildi.
		{
			
			tc_num[i][j] = (line[i][j]-'0');
		}
		
		
	}

	int kimlik_gecerli = 0;
	int kimlik_gecersiz = 0;

	for(int a=0;a<tot;a++)//Kimlik numarasi algoritmasina gore okunan degerler kontrol edilip gecerli ve gecersiz kimlik sayisi yazildi.
	{

		int kontrol_ilk_toplam = 0;
		int kontrol_son_toplam = 0;
		int kontrol_islem1;
		int kontrol_islem2;


		for (int j = 0; j<10; j = j + 2)
		{
			kontrol_ilk_toplam += tc_num[a][j];
			
		}
		
		for (int i = 1; i<9; i = i + 2)
		{
			kontrol_son_toplam += tc_num[a][i];
		}
	

		kontrol_islem1 = ((7 * kontrol_ilk_toplam) - kontrol_son_toplam) % 10;
		kontrol_islem2 = (kontrol_ilk_toplam + kontrol_son_toplam + kontrol_islem1) % 10;
		

		if (kontrol_islem1 == tc_num[a][9] && kontrol_islem2 == tc_num[a][10])
		{
			kimlik_gecerli++;

		}

		else
		{
			kimlik_gecersiz++;

		}
	}
	printf("Kimlik Numarasi:\n");
	printf("gecerli: %d\n", kimlik_gecerli);
	printf("gecersiz: %d\n", kimlik_gecersiz);

}
void Kimlik_YokEt(Kimlik_No this)
{
	if (this == NULL) return;
	free(this);
}

