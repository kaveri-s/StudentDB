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

Node *head,*temp;
Rec Stu;

void listToFile();
void fileToList();
int getrec();
void insert(int);
void update();
void delete(int);
void search();
void display();

//File <----> List

void listToFile(){
	FILE *fw;
	temp=head;

	fw = fopen("Student.dat","w");

	if(fw == NULL){
		printf("\nCan't open file or file doesn't exist.");
		exit(0);
	}

	else{
		while(temp!=NULL){
		Stu=temp->student;
		fwrite(&Stu,sizeof(Rec),1,fw);
		temp=temp->next;
		}
	}

	printf("\nData saved successfully...\n\n");

	fclose(fw);
}

void fileToList(){
	FILE* fr;
	fr = fopen("Student.dat","r");
	Node* new;

	if(fr == NULL)
	{
		printf("\nCan't open file or file doesn't exist.");
		exit(0);
	}

	while(fread(&Stu,sizeof(Rec),1,fr)>0){
		new=(Node *)malloc(sizeof(Node));
		new->next=new->prev=NULL;
		new->student=Stu;
		if(head==NULL){
			head=new;
			temp=new;
		}
		else{
			temp->next=new;
			new->prev=temp;
			temp=temp->next;
		}
	}

	fclose(fr);
}

//List operations

int getrec(){
	char sn[15];
	printf("Enter USN:\n");
	scanf("%s",sn);
	temp=head;
	while((strcmp(temp->student.usn,sn)!=0) && temp->next!=NULL){
		temp=temp->next;
	}
	if(strcmp(temp->student.usn,sn)!=0){
		printf("\nStudent record of usn %s not found\n",sn);
		return 0;
	}
	return 1;
}

void insert(int flag)
{
	Node *new;
	new=(Node *)malloc(sizeof(Node));
	if(flag==0){
		printf("\nEnter the details.....\n");
		printf("Name: ");
		scanf("%s",Stu.name);
		printf("Department: ");
		scanf("%s",Stu.dept);
		printf("USN: ");
		scanf("%s",Stu.usn);
		printf("Phone No: ");
		scanf("%s",Stu.ph);
		printf("Email: ");
		scanf("%s",Stu.email);
	}
	new->student=Stu;
	new->next=new->prev=NULL;

	if (head==NULL)
		head=new;
	else if(strcmp(head->student.name,new->student.name)>0)
	{
		new->next=head;
		head->prev=new;
		head=new;
	}
	else
	{
		temp=head;
		while((strcmp(temp->student.name,new->student.name)<0) && temp->next!=NULL)
		{
			temp=temp->next;
		}
		if(strcmp(temp->student.name,new->student.name)>0)
		{
			temp->prev->next=new;
			new->prev=temp->prev;
			new->next=temp;
			temp->prev=new;

		}
		else
		{
			temp->next=new;
			new->prev=temp;
		}
	}
	if(flag==0){
		printf("\nName\t\t\tDepartment\tUSN\tPhone No\tEmail");
		printf("\n%-24s%s\t\t%s\t%s\t%s\n\n",Stu.name, Stu.dept, Stu.usn, Stu.ph, Stu.email);
		printf("\nRecord Inserted Successfully.\n");
	}
}

void update()
{
	int ch;
	int flag=0;
	if(getrec()==1)
	{
		Stu=temp->student;
		printf("\nEnter corresponding Column Number to Edit and 0 when done.");
		printf("\n1.Name\t2.Department\t4.Phone No\t5.Email");
		do{
			printf("\nEnter Choice: ");
			scanf("%d",&ch);
			switch(ch){
				case 0:break;
				case 1:
					printf("\nName: ");
					scanf("%s",Stu.name);
					flag=1;
					break;
				case 2:
					printf("\nDepartment: ");
					scanf("%s",Stu.dept);
					break;
				case 3:
					printf("\nUSN cannot be changed");
					break;
				case 4:
					printf("\nPhone No: ");
					scanf("%s",Stu.ph);
					break;
				case 5:
					printf("\nEmail: ");
					scanf("%s",Stu.email);
					break;
				default:
					printf("\nInvalid Entry");
			}
			printf("\nName\t\t\tDepartment\tUSN\tPhone No\tEmail");
			printf("\n%-24s%s\t\t%s\t%s\t%s\n\n",Stu.name, Stu.dept, Stu.usn, Stu.ph, Stu.email);
		}while(ch!=0);
		if(flag==1){
			delete(1);
			insert(1);
		}
		else{
			temp->student=Stu;
		}
		printf("\nRecord Updated Successfully.\n");
	}
}

void delete(int flag)
{
	if(flag==1 || getrec()==1)
	{
		if(temp==head)
		{
			head=temp->next;
			free(temp);
		}
		else if(temp->next==NULL)
		{
			temp->prev->next=NULL;
			free(temp);
		}
		else
		{
			temp->prev->next=temp->next;
			temp->next->prev=temp->prev;
			free(temp);
		}
	}
	if(flag==0)
		printf("\nRecord Deleted Successfully.\n");
}

void search(){
	if(getrec()==1)
	{
		Stu=temp->student;
		printf("\nName\t\t\tDepartment\tUSN\tPhone No\tEmail");
		printf("\n%-24s%s\t\t%s\t%s\t%s\n\n",Stu.name, Stu.dept, Stu.usn, Stu.ph, Stu.email);
	}
}

//Display Query

void display(){
	int row_check[]={0,0,0,0,0};
	int i,pos;
	char ch[6];
	char department[5];
	int flag=0;
	printf("\n1.Name\t2.Department\t3.USN\t4.Phone No.\t5.Email");
	printf("\nEnter the corresponding numbers of the columns you wish to view in sucession(e.g. 123 or 125) or type * to select all.\nEnter Choice: ");
	scanf("%s",ch);
	if(ch[0]=='*'){
		for(i=0;i<5;i++)
			row_check[i]=i+1;
	}
	else{
		for(i=0;i<strlen(ch);i++){
			pos=ch[i]-'0';
			if(pos<=5 && pos>0)
				row_check[pos-1]=pos;
		}
	}
	temp=head;
	printf("\nEnter the name of the department you wish to view or type * to view all.\nEnter Choice: ");
	scanf("%s",department);
	printf("\n\n");
	for(i=0;i<5;i++){
		switch(row_check[i]){
			case 1: printf("NAME\t\t\t"); break;
			case 2: printf("DEPARTMENT\t"); break;
			case 3: printf("USN\t"); break;
			case 4: printf("PHONE\t\t"); break;
			case 5: printf("EMAIL"); break;
		}
	}
	printf("\n");
	while(temp!=NULL){
		Stu=temp->student;
		for(i=0;i<5;i++){
			if(department[0]=='*' || (strcmp(Stu.dept,department)==0)){
				flag=1;
				switch(row_check[i]){
					case 1: printf("%-24s",Stu.name); break;
					case 2: printf("%s\t\t",Stu.dept); break;
					case 3: printf("%s\t",Stu.usn); break;
					case 4: printf("%s\t",Stu.ph); break;
					case 5: printf("%s\t",Stu.email); break;
				}
			}
		}
		if(flag==1){
			printf("\n");
			flag=0;
		}
		temp=temp->next;
	}
	printf("\n\n");
}

int main()
{
	int ch=0;
	fileToList();
	printf("\n---------------------------------------------------------------------------");
	printf("\n\t\t\t\tStudent Record System.");
	printf("\n---------------------------------------------------------------------------");
	while(ch<=5)
	{
		printf("\n1:Insert Record\n2:Update Record\n3:Delete Record\n4:View Record\n5:Display Records\n6:Exit\n");
		printf("Enter ur choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:	insert(0);
				   	break;
			case 2:	update();
			       	break;
			case 3:	delete(0);
				   	break;
			case 4: search();
					break;
			case 5: display();
					break;
			case 6: break;
			default: printf("\nInvalid Option.");
		}
	}
	listToFile();
}
