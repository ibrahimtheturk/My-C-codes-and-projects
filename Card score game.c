#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int kart(){
	srand(time(NULL));
	int i,kartlar[5];
	int sum=0;
		for(i=0;i<5;i++){
		printf("\n\e[0;35m%d. Kart\e[0m:",i+1);
		kartlar[i]=rand()%52+1;
		printf("\e[0;34m");
		switch(kartlar[i]){
			case 1:printf("Sinek as(1)");sum=sum+1;break;
			case 2:printf("Sinek 2(2)");sum=sum+2;break;
			case 3:printf("Sinek 3(3)");sum=sum+3;break;
			case 4:printf("Sinek 4(4)"); sum=sum+4;break;
			case 5:printf("Sinek 5(5)"); sum=sum+5;break;
			case 6:printf("Sinek 6(6)");sum=sum+6;break;
			case 7:printf("Sinek 7(7)");sum=sum+7;break;
			case 8:printf("Sinek 8(8)");sum=sum+8;break;
			case 9:printf("Sinek 9(9)");sum=sum+9;break;
			case 10:printf("Sinek 10(10)");sum=sum+10;break;
			case 11:printf("Sinek J(11)");  sum=sum+11;break;
			case 12:printf("Sinek Q(12)");  sum=sum+12;break;
			case 13:printf("Sinek K(13)");  sum=sum+13;break;
			case 14:printf("Karo as(2)");  sum=sum+2;break;
			case 15:printf("Karo 2(4)");sum=sum+4;   break;
			case 16:printf("Karo 3(6)");sum=sum+6;  break;
			case 17:printf("Karo 4(8)");sum=sum+8;  break;
			case 18: printf("Karo 5(10)");sum=sum+10;break;
			case 19:printf("Karo 6(12)");sum=sum+12; break;
			case 20:printf("Karo 7(14)");sum=sum+14;break;
			case 21:printf("Karo 8(16)");sum=sum+16;break;
			case 22:printf("Karo 9(18)");sum=sum+18;break;
			case 23:printf("Karo 10(20)");sum=sum+20;break;
			case 24:printf("Karo J(22)"); sum=sum+22;break;
			case 25:printf("Karo Q(24)");sum=sum+24;break;
			case 26:printf("Karo K(26)");sum=sum+26;break;
			case 27:printf("Vale as(3)");sum=sum+3;break;
			case 28:printf("Vale 2(6)");sum=sum+6; break;
			case 29:printf("Vale 3(9)");sum=sum+9; break;
			case 30:printf("Vale 4(12)");sum=sum+12;break;
			case 31:printf("Vale 5(15)");sum=sum+15;break;
			case 32:printf("Vale 6(18)");sum=sum+18;break;
			case 33:printf("Vale 7(21)");sum=sum+21;break;
			case 34:printf("Vale 8(24)");sum=sum+24;break;
			case 35:printf("Vale 9(27)");sum=sum+27;break;
			case 36:printf("Vale 10(30)");sum=sum+30;break;
			case 37:printf("Vale J(33)");sum=sum+33; break;
			case 38:printf("Vale Q(36)");sum=sum+36; break;
			case 39:printf("Vale K(39)");sum=sum+39; break;
			case 40:printf("Kupa as(4)");sum=sum+4; break;
			case 41:printf("Kupa 2(8)");sum=sum+8;  break;
			case 42:printf("Kupa 3(12)");sum=sum+12; break;
			case 43:printf("Kupa 4(16)");sum=sum+16; break;
			case 44:printf("Kupa 5(20)"); sum=sum+20;break;
			case 45:printf("Kupa 6(24)");sum=sum+24; break;
			case 46:printf("Kupa 7(28)");sum=sum+28;  break;
			case 47:printf("Kupa 8(32)");sum=sum+32;  break;
			case 48:printf("Kupa 9(36)");sum=sum+36;  break;
			case 49:printf("Kupa 10(40)");sum=sum+40; break;
			case 50:printf("Kupa J(44)"); sum=sum+44; break;
			case 51:printf("Kupa Q(48)"); sum=sum+48; break;
			case 52:printf("Kupa K(52)"); sum=sum+52; break;
		}	
	}
	printf("\e[0m");
	return sum;
}
int main(){
	srand(time(NULL));
	int money=100;
	int highscore=0;
	printf("Kart oyununa hosgeldiniz.\nKartlarin deger siralamasi:\n1.Kupa\n2.Vale\n3.Karo\n4.Sinek\n");
	printf("\nDagitilan 5 kart'in toplami 90'dan buyuk oldugu durumda kazanirsiniz.\n");
	int bet;
	int a=0;
	do{
				printf("\nBakiyeniz:%d",money);
				printf("\nBahsinizi girin:");scanf("%d",&bet);
		if(money<bet){
			while(money<bet){
					printf("Paraniz yetersiz. ");
					printf("Bahsinizi girin:");scanf("%d",&bet);
			}
		}
		printf("\e[1;1H\e[2J");
		money=money-bet;
	printf("\e[0mKartlar Dagitiliyor..");
	int el;
	el=kart();
	printf("\n\nSkorunuz:%d\n",el);
	if(el<=90){
		printf("\e[0;31mKaybettiniz.\e[0m\n");
		if(money==0){
			printf("PARANIZ BITTI.\n");
			return 0;
		}
	}		
	if(el>90){
		printf("\e[0;32mKAZANDINIZ!\e[0m");
		if(el>highscore){
			highscore=el;
		}
		if(highscore!=0){
			printf("\nEn yuksek skor:%d",highscore);
		}
		money=money+(bet*2);
	}
	a++;
	}while(a<60);
}
