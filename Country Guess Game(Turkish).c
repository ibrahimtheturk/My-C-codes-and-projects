#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> 
#include <locale.h>

const char* getword(){
	int cnt1 = 0,cntn2 = 0;
	int randomizer = rand()%50+1;
	switch(randomizer){
		case 1:printf("Avrasya\n");return "turkiye";
		case 2:printf("Balkanlar\n");return "yunanistan";
		case 3:printf("Balkanlar\n");return "bulgaristan";
		case 4:printf("Amerika\n");return "kanada";
		case 5:printf("Avrupa\n");return "fransa";
		case 6:printf("Avrupa\n");return "almanya";
		case 7:printf("Balkanlar\n");return "arnavutluk";
		case 8:printf("Afrika\n");return "fas";
		case 9:printf("Orta Dogu\n");return "irak";
		case 10:printf("Orta Dogu\n");return "iran";
		case 11:printf("Afrika\n");return "senegal";
		case 12:printf("Afrika\n");return "cibuti";
		case 13:printf("Latin Amerika\n");return "ekvador";
		case 14:printf("Latin Amerika\n");return "arjantin";
		case 15:printf("Avrasya\n");return "gurcistan";
		case 16:printf("Avrasya\n");return "ermenistan";
		case 17:printf("Balkanlar\n");return "makedonya";
		case 18:printf("Avrasya\n");return "azerbaycan";
		case 19:printf("Orta Dogu\n");return "suriye";
		case 20:printf("Orta Dogu\n");return "israil";
		case 21:printf("Orta Dogu\n");return "filistin";
		case 22:printf("Orta Dogu\n");return "kuveyt";
		case 23:printf("Avrasya\n");return "rusya";
		case 24:printf("Avrupa\n");return "ukrayna";
		case 25:printf("Avrupa\n");return "ingiltere";
		case 26:printf("Avrupa\n");return "galler";
		case 27:printf("Avrasya\n");return "afganistan";
		case 28:printf("Adriyatik\n");return "avustralya";
		case 29:printf("Avrupa\n");return "avusturya";
		case 30:printf("Avrupa\n");return "belcika";
		case 31:printf("Latin Amerika\n");return "brezilya";
		case 32:printf("Avrupa\n");return "finlandiya";
		case 33:printf("Avrupa\n");return "norvec";
		case 34:printf("Avrupa\n");return "isvec";
		case 35:printf("Avrupa\n");return "letonya";
		case 36:printf("Avrupa\n");return "litvanya";
		case 37:printf("Asya\n");return "japonya";
		case 38:printf("Asya\n");return "hindistan";
		case 39:printf("Latin Amerika\n");return "peru";
		case 40:printf("Balkanlar\n");return "hirvatistan";
		case 41:printf("Balkanlar\n");return "bosnahersek";
		case 42:printf("Balkanlar\n");return "sirbistan";
		case 43:printf("Balkanlar\n");return "slovenya";
		case 44:printf("Avrupa\n");return "italya";
		case 45:printf("Avrupa\n");return "danimarka";
		case 46:printf("Avrupa\n");return "isvicre";
		case 47:printf("Avrupa\n");return "polonya";
		case 48:printf("Avrupa\n");return "portekiz";
		case 49:printf("Avrupa\n");return "hollanda";
		case 50:printf("Afrika\n");return "somali";
	}
}

int main(){
	srand(time(NULL));
	printf("\e[0;107m\e[1;30m");
	printf("\e[1;1H\e[2J");
	printf("\e[0;107m\e[1;30mUlke tahmin oyununa hos geldiniz. Turkce harf girilemedigini unutmayin. \nHer ulke icin toplam 5 yanlis harf hakkiniz var.\n");
	int resume = 1;
	int win = 0;
	int lose = 0;
	do{
	srand(time(NULL));
	const char* word = getword();
	int length = strlen(word);
	char guessed[length+1];
	memset(guessed, '_',length);
	guessed[length] = '\0';
	 int cnt = 0;
	 int hak = 0;
	do{
		printf("\e[0;107m\e[1;30m%s\n",guessed);
		char guess[2];
		printf("Harf:");scanf("%s",guess);
		int correct = 0,i;
		for(i = 0;i<length;i++){
			if(word[i] == guess[0]){
				guessed[i] = guess[0];
				correct = 1;
			}
		}
		if(!correct){
			printf("\e[0;101mYanlis tahmin,tekrar deneyin.\e[0m\n");
			cnt++;
			hak++;
			if(hak == 5){
				printf("\e[0;101mUlkeyi tahmin edemediniz..\e[0m\n");
				lose++;
				break;
			}
		}
		if(strcmp(guessed, word) == 0){
			printf("\e[0;104mTebrikler, %s ulkesini %d hata ile tahmin ettiniz.\e[0m\n",word,cnt);
			win++;
			break;
		}
	}while(1);
	printf("\e[0;107m\e[1;30mBulunan ulke:%d Bulunamayan ulke:%d\nDevam etmek icin 1, cikis icin 0 girin:",win,lose);
	scanf("%d",&resume);
	printf("\e[1;1H\e[2J");
		
	}while(resume == 1);
}
