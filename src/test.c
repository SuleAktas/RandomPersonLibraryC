#define _CRT_SECURE_NO_WARNINGS
#include"stdio.h"
#include"stdlib.h"
#include"IMEINo.h"
#include"KimlikNo.h"
#include"Kisi.h"
#include"Rastgele.h"
#include"locale.h"


int main()
{
	setlocale(LC_ALL, "Turkish");
	int secim=0;
	int kisi_sayisi=0;
	//kisi kisiler[200];
	kisi kisi1;
	 kisi1=(kisi)malloc(sizeof(struct Kisi));
	
	
	do {
		printf("1- Rastgele Kiþi Üret\n");
		printf("2- Üretilmiþ Dosya Kontrol Et\n");
		printf("3- Çýkýþ\n");
		scanf("%d", &secim);
		switch (secim)
		{

		case 1:
            
	       
			printf("Kaç adet kiþi üretmek istiyorsunuz:\n");
			scanf("%d", &kisi_sayisi);
			
			for (int i = 0; i < kisi_sayisi; i++)//Kullanicinin istedigi kisi sayisi kadar kisiler dosyaya yazildi.
			{
				
				kisi1=kisi_olustur();
				dosyaya_kisi_yazdir(kisi1);
				
			}
			printf("Dosyaya yazma baþarýlý. \n");
			kisi1->KisiYokEt(kisi1);

			break;
		case 2:
			imei_no_kontrol();
			kimlik_no_kontrol();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("Yanlýþ bir deðer girdiniz.\n");
			break;

		}
	} while (secim != 3);//Secim 3 olana kadar tekrar donduruldu.

	
    
	getchar();
	return 0;
}