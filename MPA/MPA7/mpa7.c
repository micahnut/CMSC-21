#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#define BUFSIZE 100000

typedef struct elem{
    int coef,exp; //data
    struct elem *next;
}node;

typedef struct{
    node *head, *tail;
    int size;
}list;


void init(list*);
void append(list*,int,int);
void display(list);
void display2(node*);
int deleteItem(list*,int);
node* itemAt(list,int);
int setItem(list*,int,int);
void simplify(list *l);
list add(list, list);
list sub(list,list);
void arrange(list *l);
list multiply(list, list);
list getNumbers(char[BUFSIZE]);
node* getTerm(char[200]);


int main() {
	FILE *ifp;
	ifp= fopen("mpa7.in","r");
	
	char polx[BUFSIZE],poly[BUFSIZE];
	
    list l1,l2,sum,diff,prod;
    int numpoly,n,x,y;
    int n2,i=0;
   	int t;
    
    if(ifp == NULL){
		perror("Error while opening the file.\n");
		exit(EXIT_FAILURE);
	}
	
		
		
		//fscanf(ifp,"%d",&numpoly);
		fgets(polx,BUFSIZE,ifp);
		t=atoi(polx);
		
		while(t>0){
			init(&l1);
    		init(&l2);
			init(&sum);
			init(&diff);
			init(&prod);
			
			fgets(polx,BUFSIZE,ifp);
			fgets(poly,BUFSIZE,ifp);
			
			
			//printf("%s \n", polx);
			//printf("%s \n",poly);
			
			l1=getNumbers(polx);
			l2=getNumbers(poly);
			
			sum=add(l1,l2);
			diff=sub(l1,l2);
			prod=multiply(l1,l2);
			arrange(&sum);
			arrange(&diff);
			arrange(&prod);
			display(sum);
			display(diff);
			display(prod);
			printf("\n");
				
			t--;
		}
	return 0;
}


void init(list* l){
    l->size = 0;
    l->head = l->tail = NULL;
}

void append(list* l,int x,int y){
    node *n = malloc(sizeof(node));
    
    n->coef = x;
    n->exp = y;
    n->next = NULL;
    if(l->size==0){
        l->head = l->tail = n;
    }
    else{
        l->tail->next = n;
        l->tail = n;
    }
    l->size++;
    }


void display(list l){
    node *tmp = l.head;
    while(tmp!=NULL){
    	
    	if(tmp->coef!=0){
    
		if(tmp->exp==0)
    		printf("%d",tmp->coef);
		else if(tmp->exp==1)
    		printf("%dx",tmp->coef);
    	else if(tmp->coef==1)
			printf("x^%d",tmp->exp);
		else if(tmp->coef==-1){
			printf("-x^%d",tmp->exp);
		}
					
		else	
        	printf("%dx^%d",tmp->coef,tmp->exp);
	}
		tmp = tmp->next;
		
		
		if(tmp!=NULL){
			if(tmp->coef>0)
				printf("+");
    	}
	}
    printf("\n");
}


int deleteItem(list* l,int pos){
    node *tmp = l->head, *del;
    int i = 1;
    if(pos<1 || pos>l->size)
        return 0;
    else{
        if(pos==1){
            del = l->head;
            l->head = del->next;
            del->next = NULL;
        }
        else{
            while(i<pos-1){
                tmp = tmp->next;
                i++;
            }
            del = tmp->next;
            tmp->next = del->next;
            del->next = NULL;
            if(del==l->tail)
                l->tail = tmp;
        }
        free(del);
        l->size--;
    }
}


node* itemAt(list l, int pos){
    node *tmp = l.head;
    int i = 1;

    while(i<pos){
        tmp = tmp->next;
        i++;
    }
    return tmp;
}

int setItem(list *l, int pos, int x){
    if(pos<1 || pos > l->size)
        return 0;

    node *tmp = l->head;
    int i = 1;

    while(i<pos){
        tmp = tmp->next;
        i++;
    }
    tmp->coef = x;
    return 1;
}

void simplify(list *l){
    int i=1,j;
	
	//display(*l);
	
    for(;i<l->size;i++){
        for(j=i+1;j<=l->size;j++){
            if(itemAt(*l,i)->exp==itemAt(*l,j)->exp){
              setItem(l,i,itemAt(*l,i)->coef + itemAt(*l,j)->coef );
				deleteItem(l,j);       		
	    		j--;
	    	}
		}
    }
}
 
list add(list l1, list l2){
    list sum;
    init(&sum);
    int c=1;
    
    while(c<=l1.size){
        append(&sum,itemAt(l1,c)->coef,itemAt(l1,c)->exp);
        c++;
    
	}
	
	c=1;
	while(c<=l2.size){
		append(&sum,itemAt(l2,c)->coef,itemAt(l2,c)->exp);
		c++;
	}
	
	//display(sum);
	simplify(&sum);
	return sum;
}

list sub(list l1, list l2){
    list sum;
    init(&sum);
    int c=1;
    
    while(c<=l1.size){
        append(&sum,itemAt(l1,c)->coef,itemAt(l1,c)->exp);
        c++;
    
	}
	
	c=1;
	while(c<=l2.size){
		append(&sum,(itemAt(l2,c)->coef)*-1,itemAt(l2,c)->exp);
		c++;
	}
	
	//display(sum);
	simplify(&sum);
	return sum;
}

void arrange(list *l){
    int i=1,j;
	int tmpcoef,tmpexp;
	//display(*l);
	
    for(;i<l->size;i++){
        for(j=i+1;j<=l->size;j++){
            if(itemAt(*l,i)->exp<=itemAt(*l,j)->exp){
              	tmpcoef=itemAt(*l,j)->coef;
				tmpexp=itemAt(*l,j)->exp;
				itemAt(*l,j)->coef=itemAt(*l,i)->coef;
              	itemAt(*l,j)->exp=itemAt(*l,i)->exp;
              	itemAt(*l,i)->coef=tmpcoef;
	    		itemAt(*l,i)->exp=tmpexp;
			}
		}
    }
}

//multiplication

list multiply(list l1, list l2){
	list prod;
	init(&prod);
	int coef,exp;
	int c=1,d=1;
	
	while(c<=l1.size){
		while(d<=l2.size){
			coef= itemAt(l1,c)->coef * itemAt(l2,d)->coef;
			exp= itemAt(l1,c)->exp + itemAt(l2,d)->exp;
			d++;
			append(&prod,coef,exp);
		}
		d=1;
		c++;
	}
	
	//display(prod);
	simplify(&prod);
	return prod;
}


list getNumbers(char poly[BUFSIZE]){

node *n;
list l;
char tmp[ BUFSIZE ];
int i,j;

int xcheck=0;
int ccheck=0;

	init(&l);
	
	for(i=0,j=0;poly[i]!='\0';i++,j++){
		
		if(poly[i]=='+' || poly[i]=='-' ){
			//printf("%d",i);
			tmp[j] = '\0';
			n = getTerm(tmp);								
			//printf("%d",i);
			append(&l,n->coef,n->exp);		
			j=0;
		}	
		tmp[j]=poly[i];
	}

	tmp[j]='\0';
	n = getTerm(tmp);								
			//printf("%d",i);
			append(&l,n->coef,n->exp);
		
	return l;	
}

node* getTerm(char st[200]){

node *n = malloc(sizeof(node));
char tmp[200];
int i,j;
int xcheck=0;
int ccheck=0;	
int coefcheck=0;
	
	//printf("%s", st);
	
	for(i=0,j=0;st[i]!='\0';i++,j++){
		
		if(st[0]!='x')
			coefcheck=1;
			//tmp[j]=st[i];
			//printf("tmp-->%s \n ", tmp);
			
		if(st[i]=='x' /*&& coefcheck ==1 */ ){
			xcheck=1;
			tmp[j]= '\0';
			//printf("%s",tmp);
			n->coef = atoi(tmp);
			//printf("%d",n->coef);
			j=0;
			i++;
		}
			
		if(st[i]=='^'){
			ccheck=1;
			i++;	
		}
		
		if(st[i]!='x' && st[i]!='^')
			tmp[j]=st[i];
				
}
	//printf("tmp-->%s \n ", tmp);
	//printf("%d",i);
	
	tmp[j]='\0';

	if(coefcheck==0){
		n->coef = 1;
		n->exp = atoi(tmp);	
	}

	if(xcheck == 0 ){
		n->coef = atoi(tmp);
		n->exp = 0;
	}
	
	else if(ccheck == 0)
		n->exp= 1;
	
	else{
		n->exp = atoi(tmp);
	}
	
	//printf("%d %d \n",n->coef, n->exp);
	return n;
}
