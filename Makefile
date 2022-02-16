hepsi: nesne derle calistir
 
nesne:
	
	gcc -I ./include/ -o ./lib/IMEINo.o -c ./src/IMEINo.c
	
	gcc -I ./include/ -o ./lib/KimlikNo.o -c ./src/KimlikNo.c
	
	gcc -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.c
	
	gcc -I./include/ -o./lib/Rastgele.o -c ./src/Rastgele.c
	gcc -I ./include/ -o ./lib/RastgeleKisi.o -c ./src/RastgeleKisi.c
	
	gcc -I ./include/ -o ./lib/Telefon.o -c ./src/Telefon.c

derle:	
	
	gcc -I ./include/ -o ./bin/Test ./lib/IMEINo.o ./lib/KimlikNo.o ./lib/Kisi.o ./lib/Rastgele.o ./lib/RastgeleKisi.o ./lib/Telefon.o ./src/test.c
	

calistir:
	
	./bin/Test