#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct record
{
 	char name[30];
 	char dept[4];
 	char usn[5];
	char ph[11];
	char email[30];
};
typedef struct record Rec;

struct node{
	Rec student;
	struct node* next;
	struct node* prev;
};
typedef struct node Node;

Rec getdata(){
	Rec rec;
	printf("Name:");
	scanf("%s",rec.name);
	printf("Dept:");
	scanf("%s",rec.dept);
	printf("USN:");
	scanf("%s",rec.usn);
	printf("PH:");
	scanf("%s",rec.ph);
	printf("Email:");
	scanf("%s",rec.email);
	return rec;
}

void listToFile()
{
	   FILE *fp;
	   char ch;
	   Rec Stu;
	   int i;

	   fp = fopen("Student.dat","w");            //Statement   1

	   if(fp == NULL)
	   {
			  printf("\nCan't open file or file doesn't exist.");
			  exit(0);
	   }

	   for(i=0;i<3;i++){
		   Stu=getdata();
		   fwrite(&Stu,sizeof(Stu),1,fp);
	   }

	   printf("\nData written successfully...");

	   fclose(fp);
}

void fileToList()
{
	   FILE *fp;
	   char ch;
	   Rec Stu;

	   fp = fopen("Student.dat","r");            //Statement   1

	   if(fp == NULL)
	   {
			  printf("\nCan't open file or file doesn't exist.");
			  exit(0);
	   }


	   while(fread(&Stu,sizeof(Stu),1,fp)>0)
		   printf("\n%s\t%s\t%s\t%s\t%s",Stu.name,Stu.dept,Stu.usn,Stu.ph,Stu.email);

	   fclose(fp);
}

void main(){
	//listToFile();
	fileToList();
}
