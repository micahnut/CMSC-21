#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define MAX 10
#define BUFSIZE 1000

typedef struct{
    int yearLevel;
    char firstName[30],middleName[30],lastName[30],studentnumber[11], program[30];
}student;

typedef struct elem{
    student record;
	struct elem *next;
}node;

typedef struct{
	node *head, *tail;
	int size;
}list;


void init(list*);
void enroll(list*, student);
int withdraw(list*,char*);
void display(list, FILE *);
int search(list ,char*);
void searchyearl(list,int, FILE *);
void searchC(list,char *, FILE *);
void searchfamily(list,char*, FILE *);
void searchSN(list,char*, FILE *);
int check(list ,char*);

int main() {
    int t,inputtype,c;
	student s;
    char buff[BUFSIZE],line[80];
	list l;
    int x;
    
    FILE *input = fopen("mpa9.in", "r");
	FILE *ofp = fopen("studentdatabase.out", "w");
	init(&l);
	
	
    if( input == NULL )
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    
    	fgets(buff,BUFSIZE,input);
    		t=atoi(buff);
    		
	  	//fscanf(input, "%d", &t);
		
    do{
        fscanf(input, "%d",&inputtype);

        if(inputtype==1){
            fscanf(input, " %[^\n]s", &s.studentnumber);
			fscanf(input, " %[^\n]s", &s.firstName);
			fscanf(input, " %[^\n]s", &s.middleName);
			fscanf(input, " %[^\n]s", &s.lastName);
			fscanf(input, " %[^\n]s", &s.program);
			fscanf(input, "%d", &s.yearLevel);
			
			c=check(l,s.studentnumber);

			if(c!=1)
            enroll(&l,s);

			else
			fprintf(ofp,"THE STUDENT NUMBER %s ALREADY EXISTS.\n\n",s.studentnumber);

        display(l,ofp);
        }

        if(inputtype==2){
             fscanf(input, " %[^\n]s", &s.studentnumber);
             withdraw(&l,s.studentnumber);

             display(l, ofp);
        }

        else if(inputtype==3){
            display(l, ofp);
        }
        else if(inputtype==4){
            //search all students based on yearlevel
            fscanf(input, "%d",&s.yearLevel);
            searchyearl(l,s.yearLevel,ofp);
        }
        else if(inputtype==5){
            //search based on course
            fscanf(input, " %[^\n]s",&s.program);
     		searchC(l,s.program, ofp);
        }
        else if(inputtype==6){
        	//search all students based on the family name
        	fscanf(input, " %[^\n]s",&s.lastName);
     		searchfamily(l,s.lastName,ofp);
		}
		else if(inputtype==7){
			//search a student based on the student number
			fscanf(input, " %[^\n]s",&s.studentnumber);
			searchSN(l,s.studentnumber,ofp);
		}
        t--;
    }while(t>0);
//}	

	fclose(input);
	fclose(ofp);
    return 0;
}


void init(list* l){
	l->size = 0;
	l->head =l->tail =NULL;
}

void enroll(list* l,student s){
	node *n = malloc(sizeof(node));

	n->record = s;
	n->next =NULL;
	
	if(l->size<=MAX){
	
	if(l->size==0){
		l->head = l->tail =n;
	}
	else{
		l->tail->next=n;
		l->tail=n;

	}
	/*printf("%s, %s %s\n",n->record.lastName,n->record.firstName,n->record.middleName);
	printf("%s \n",n->record.program);
	printf("%s\n",n->record.studentnumber);
	printf("%d\n",n->record.yearLevel);
	*/
	l->size++;
	}
}

void display(list l, FILE * ofp){
	node *tmp = l.head;
	int i=0;

	while(tmp!=NULL){
		if(i>0)
        fprintf(ofp,"\n");

		fprintf(ofp,"Student Number: %s\n",tmp->record.studentnumber);
        fprintf(ofp,"Name: %s, %s %s\n",tmp->record.lastName,tmp->record.firstName,tmp->record.middleName);
        fprintf(ofp,"Program: %s\n",tmp->record.program);
        fprintf(ofp,"Year Level: %d\n",tmp->record.yearLevel);
        i++;
		tmp =tmp->next;
	}
	fprintf(ofp,"\n");
}


int withdraw(list *l, char *t){
	node *n = l->head, *tmp;
	int flag=0;

	if(l->size == 0)
		return 0;

	else if( strcmp(n->record.studentnumber, t)==0)	{
		tmp=l->head;
		l->head = tmp->next;
		tmp->next=NULL;
		l->size--;
		return 1;
	}
	else{
		while(n->next!=NULL){
			if(strcmp(n->next->record.studentnumber,t)==0){
				flag=1;
				break;
			}
			n= n->next;
		}
		if(flag==1){
			if(n->next->next == NULL)
				l->tail = n;
			tmp = n->next;
			n->next = tmp->next;
			tmp->next = NULL;
			l->size--;
			free(tmp);
			return 1;

		}
		else{
			return 0;
		}

	}
}


void searchyearl(list l,int y,FILE * ofp){
	node *n = l.head;

	int i,flag=0;
    while(n!=NULL){
        if(n->record.yearLevel==y){
       		if(i>0)
			 fprintf(ofp,"\n");

			fprintf(ofp,"Student Number: %s\n",n->record.studentnumber);
        	fprintf(ofp,"Name: %s, %s %s\n",n->record.lastName,n->record.firstName,n->record.middleName);
        	fprintf(ofp,"Program: %s\n",n->record.program);
        	fprintf(ofp,"Year Level: %d\n",n->record.yearLevel);

		flag=1;
		i++;
	}
	n=n->next;

	}
	//printf("\n");

		if(flag==0){
		fprintf(ofp,"NO STUDENT WITH YEAR LEVEL %d EXISTS.\n",y);
		fprintf(ofp,"\n");
		}
}

void searchC(list l,char* t, FILE * ofp){
	node *n = l.head;

	int i=0,flag=0;
    while(n!=NULL){
        if(strcmp(n->record.program,t)==0){
       		if(i>0)
			 fprintf(ofp,"\n");

			fprintf(ofp,"Student Number: %s\n",n->record.studentnumber);
        	fprintf(ofp,"Name: %s, %s %s\n",n->record.lastName,n->record.firstName,n->record.middleName);
        	fprintf(ofp,"Program: %s\n",n->record.program);
        	fprintf(ofp,"Year Level: %d\n",n->record.yearLevel);
			
		flag=1;
		i++;
	}
	n=n->next;

	}
	//printf("\n");
		if(flag==0)
		fprintf(ofp,"NO STUDENT WITH THE COURSE %s EXISTS.\n",t);
}

void searchfamily(list l,char* t, FILE * ofp){
node *n = l.head;

	int i=0,flag=0;
    while(n!=NULL){
        if(strcmp(n->record.lastName,t)==0){
       		if(i>0)
			 fprintf(ofp,"\n");

			fprintf(ofp,"Student Number: %s\n",n->record.studentnumber);
        	fprintf(ofp,"Name: %s, %s %s\n",n->record.lastName,n->record.firstName,n->record.middleName);
        	fprintf(ofp,"Program: %s\n",n->record.program);
        	fprintf(ofp,"Year Level: %d\n",n->record.yearLevel);

		flag=1;
		i++;
	}
	n=n->next;

	}
	//printf("\n");
		if(flag==0)
		fprintf(ofp,"NO STUDENT WITH THE FAMILY NAME %s EXISTS.\n",t);
}

void searchSN(list l,char* t, FILE * ofp){
	node *n = l.head;

	int i=0,flag=0;
    while(n!=NULL){
        if(strcmp(n->record.studentnumber,t)==0){
       		if(i>0)
			 fprintf(ofp,"\n");

			fprintf(ofp,"Student Number: %s\n",n->record.studentnumber);
        	fprintf(ofp,"Name: %s, %s %s\n",n->record.lastName,n->record.firstName,n->record.middleName);
        	fprintf(ofp,"Program: %s\n",n->record.program);
        	fprintf(ofp,"Year Level: %d\n",n->record.yearLevel);

		flag=1;
		i++;
	}
	n=n->next;

	}
	//printf("\n");
		if(flag==0)
		fprintf(ofp,"NO SUCH STUDENT WITH STUDENT NUMBER %s EXISTS.\n",t);
}

int check(list l,char* t){
    node *n = l.head;

	while(n!=NULL){
        if(strcmp(n->record.program,t)==0){
       		return 1;
		}
	n=n->next;

	}
	return -1;
}



////enroll a student
//withdraw a student from the roll
//display all students
//search all students based on the year level
//search all students based on the course
//search all students based on the family name
//search a student based on the student number

