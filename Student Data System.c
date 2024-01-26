#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	int no;
	char name[50];
	int age;
	char bolum[50];
	int grade;
	struct node *next,*head;
}node;
node *head,*newstudent,*next,*t,*new;

//Counting the students in the list.
int count(){
	int c=0;
	node *index=head;
		if (index==NULL){
		printf("\e[0;101mYour list is empty.\n\e[0m");
		sleep(2);
		printf("\e[1;1H\e[2J");
		return 1;
	}
	while(index!=NULL){
		c++;
		index=index->next;
	} 
	printf("\e[0;92mThere is %d students in your list.\n",c);
	sleep(2);
	printf("\e[1;1H\e[2J");
	return 1;
}
//Printing students' informations to screen.
int print(){
	printf("\e[1;1H\e[2J");
	node *index=head;
	if (index==NULL){
		printf("\e[0;101mYour list is empty.\n\e[0m");
		sleep(2);
		printf("\e[1;1H\e[2J");
		return 1;
	}
	while (index!=NULL){
		printf("\e[1;95m-*****STUDENT*****-\n\e[0m");
		printf("\e[0;94mName:\e[0m\e[0;96m%s\n\e[0m",index->name);
		printf("\e[0;94mNo:\e[0m\e[0;96m%d\n",index->no);
		printf("\e[0;94mAge:\e[0m\e[0;96m%d\n",index->age);
		printf("\e[0;94mProgram:\e[0m\e[0;96m%s\n",index->bolum);
		printf("\e[0;94mGrade:\e[0m\e[0;96m%d\n\n\n",index->grade);
		index=index->next;
	}
	return 1;
}
//Deleting selected student.
int delete(no){
	node *prev=NULL;
	node *index=head;
	if (head==NULL){
		printf("List is empty.\n");
		sleep(2);
		printf("\e[1;1H\e[2J");
		return 1;
	}
	if(head->no==no){
		node *temp=head;
		head=head->next;
		free(temp);
		printf("\e[0;92mBasariyla kayit silindi");
		sleep(2);
		printf("\e[1;1H\e[2J");
		return 1;
	}
	while (index!=NULL && index->no!=no){
		prev=index;
		index=index->next;
	}
	if(index==NULL){
		printf("The student you are looking for is not found.\n");
		sleep(2);
		printf("\e[1;1H\e[2J");
		return 1;
	}
	prev->next=index->next;
	return 1;
}
//Adding a new student
int addNode(){
	node *new=(node *)malloc(sizeof(node));
	if(head==NULL){
		head=(node *)malloc(sizeof(node));
		t=head;}
	else{
		t->next=(node *)malloc(sizeof(node));
		t=t->next;
	}
	printf("\e[0;96mEnter student's number's first 5 digits.\n\e[0m");
		scanf("%d",&t->no);
		printf("\e[0;96mEnter student's name.\n\e[0m");
		scanf("%s",t->name);
		printf("\e[0;96mEnter student's age. \n\e[0m");
		scanf("%d",&t->age);
		printf("\e[0;96mEnter student's program.\n\e[0m");
		scanf("%s",t->bolum);
		printf("\e[0;96mEnter student's grade.\n\e[0m");
		scanf("%d",&t->grade);
		printf("\e[0;92mentering the student's informations is completed.");
		sleep(2);
		printf("\e[1;1H\e[2J");
}
// Calculating the average of student's grades
int average(){
	int i=0,sum=0;
	node *index=head;
		if (index==NULL){
		printf("\e[0;101mYour list is empty.\n\e[0m");
		sleep(2);
		printf("\e[1;1H\e[2J");
		return 1;
	}
	while (index!=NULL){
			printf("\e[0;92m%s's grade:\e[0;96m%d\n\e[0m",index->name,index->grade);
			sum=sum+index->grade;
			i++;
			index=index->next;
		}                           
	sum=sum/i;
	printf("\e[0;96mThe average is: %d",sum);
	sleep(2);
	printf("\n\n\n");
	return 1;
	}
//Printing students' grades.	
int grade(int pass){
	node *index=head;
		if (index==NULL){
		printf("\e[0;101mYour list is empty.\n\e[0m");
		sleep(2);
		printf("\e[1;1H\e[2J");
		return 1;
	}
	while (index!=NULL){
		if(index->grade>=pass){
			printf("\e[0;102m%s's grade is: %d\n\e[0m",index->name,index->grade);
		}
		else{
			printf("\e[0;101m%s's grade is: %d\n\e[0m",index->name,index->grade);
		}
		index=index->next;
	}
	printf("\n\n\n");
	return 1;
}
//Creating a student list (for adding too many students)
int createList(){
	printf("\e[0;96mHow many students will you enter?\n\e[0m");
	int k=0,n;
	scanf("%d",&n);
	for(k=0;k<n;k++){
		if (head==NULL){
			head=(node *)malloc(sizeof(node));
			t=head;	}
		else{
			t->next=(node *)malloc(sizeof(node));
			t=t->next;	}
		
		printf("\e[0;96mEnter %d. student's number's first 5 digits.\n\e[0m",k+1);
		scanf("%d",&t->no);
		printf("\e[0;96mEnter %d. student's name.\n\e[0m",k+1);
		scanf("%s",t->name);
		printf("\e[0;96mEnter %d. student's age. \n\e[0m",k+1);
		scanf("%d",&t->age);
		printf("\e[0;96mEnter student's program.\n\e[0m");
		scanf("%s",t->bolum);
		printf("\e[0;96mEnter %d. student's grade. \n\e[0m",k+1);
		scanf("%d",&t->grade);
		printf("\e[0;92mentering the %d. student's informations is completed.\n\n",k+1);
		sleep(2);
		printf("\e[1;1H\e[2J");
	}
	t->next=NULL;
}
//Saving students' informations to txt file for other executions.
int text(){
	FILE *text = fopen("student.txt","w");
		node *index=head;
	if (index==NULL){
		printf("\e[0;101mYour list is empty.\n\e[0m");
		sleep(2);
		printf("\e[1;1H\e[2J");
		return 1;
	}
	while (index!=NULL){
		fprintf(text,"%s ",index->name);
		fprintf(text,"%d ",index->no);
		fprintf(text,"%d ",index->age);
		fprintf(text,"%s ",index->bolum);
		fprintf(text,"%d ",index->grade);
		index=index->next;
	}
	return 1;
}
//Finding a student by searching via name. 
int ara(char *str){
	node *prev=NULL;
	node *index=head;
	if (head==NULL){
		printf("List is empty.\n");
		sleep(2);
		printf("\e[1;1H\e[2J");
		return 1;
	}
	if(strcmp(head->name,str)==0){
		printf("\e[0;92mName:%s\nStudent Number:%d\nAge:%d\nProgram:%s\nGrade:%d\n",head->name,head->no,head->age,head->bolum,head->grade);
		return 1;
	}
	while (index!=NULL && strcmp(index->name,str)!=0){
		prev=index;
		index=index->next;
		if(strcmp(index->name,str)==0){
		printf("\e[0;92mName:%s\nStudent Number:%d\nAge:%d\nProgram:%s\nGrade:%d\n",index->name,index->no,index->age,index->bolum,index->grade);
		return 1;
	}
	}
	if(index==NULL){
		printf("The student you are looking for is not found.\n");
		sleep(2);
		printf("\e[1;1H\e[2J");
		return 1;
	}
	prev->next=index->next;
	return 1;
}
 void readFromFile(const char *txt) {
    FILE *file = fopen("student.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    while (!feof(file)) {
        node *newNode = (node *)malloc(sizeof(node));
        if (fscanf(file, "%s %d %d %s %d", newNode->name, &newNode->no, &newNode->age, newNode->bolum, &newNode->grade) == 5) {
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
                t = newNode;
            } else {
                t->next = newNode;
                t = t->next;
            }
        }
    }

    fclose(file);
}
//main function
int main(){ 
	int choice;
	char str[50];
	int g=0;
	readFromFile("student.txt");
do{
	printf("\e[1;94m1.Create Student List\n2.Add Student\n3.Delete Student\n4.Print Student List\n5.List the student's grades\n6.Count the students\n7.Calculate the average\n8.Save Students\n9.Search Student with name\n10.Exit\n");
	printf("\e[0;92mChoose What you want to do.\n\e[0m");
	scanf("%d",&choice);
	printf("\e[1;1H\e[2J");
	switch(choice){
		case 1:createList();break;
		case 2:addNode();break;
		case 3:{
			int d;
			printf("\e[0;92mEnter the student's number you want to delete.\n");
			scanf("%d",&d);
			delete(d);
			break;
		}
		case 4:print();break;
		case 5:printf("\e[0;92mEnter the pass grade.\n");int pass;scanf("%d",&pass);grade(pass);break;
		case 6:count();break;
		case 7:average();break;
		case 10:printf("\e[0;92mGoodbye.");return 0;break;
		case 8:text();break;
		case 9:printf("Enter name:");fflush(stdin);gets(str);ara(str);break;
		g++;	}	
}while(g<100);
	return 1;}

