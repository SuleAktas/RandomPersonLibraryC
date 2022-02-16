#include"Rastgele.h"


int random_sayi(int x)
{
	rastgele this;
	this = malloc(sizeof(struct Rastgele));
	static int i = 24;	
	this->t = time(NULL);
	int s1 = (int)(this->t / 3600);
	if(s1<0)
	{
		s1=s1*(-1);
	}
	
	long s2 = (int)(this->t * 1000);
	if(s2<0)
	{
		s2=s2*(-1);
	}
	i += 5;
	return (int)((s1 + s2) % i + 1000) % x;

}

