//this code simply takes the informations of the book which you want to save and prints to .txt file named 'book.txt'
//enter the date input like '13/12/2004'.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *txt = fopen("book.txt","a");
typedef struct book{
	char name[100];
	char author[100];
	int paper;
	int day,month,year;
	book *next;	
}book;
book *next,*prev,*index,*head,*newbook,*temp;
int addBook(){
	book *newbook=(book *)malloc(sizeof(book));
	if(head==NULL){
		head= (book *)malloc(sizeof(book));
		temp=head;
	}
	else{
		temp->next=(book *)malloc(sizeof(book));
		temp=temp->next;
	}  
	printf("\e[0;94mEnter book's name.\n");
	fflush(stdin);
	gets(temp->name); 
	printf("\e[1;95mEnter author's name.\n");
	fflush(stdin);
	gets(temp->author);
	printf("\e[0;94mEnter book lenght.\n");
	scanf("%d",&temp->paper);
	printf("\e[1;95mEnter date (dd/mm/yy): ");
    	scanf("%d/%d/%d", &temp->day,&temp->month,&temp->year);
	fprintf(txt,"******************\n");
	fprintf(txt,"Name: %s\n",temp->name);
	fprintf(txt,"Author Name: %s\n",temp->author);
	fprintf(txt,"Lenght: %d\n",temp->paper);
	fprintf(txt,"Date: %02d/%02d/%04d\n",temp->day,temp->month,temp->year);
	printf("\e[1;1H\e[2J");
	return 0;
}
int main(){ 
	int i=0;
	int choice;
	printf("\e[0;94mWelcome to the book recorder. Please select what you want.\n\e[0m");
do {
	printf("\e[1;95m1.Add Book\n2.Exit\e[0m\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:addBook();break;
		case 2:return 0;break;
	}
}while (i<1000);			
}
