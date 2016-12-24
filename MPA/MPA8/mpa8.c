#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000000



typedef struct holder{
	int count;
	char item[MAX];
	struct holder *left;
	struct holder *right;

}btnode;

typedef struct elem{
	char item[MAX];
	struct elem *next;
}node;

typedef struct{
	node *head, *tail;
	int size;
}list;

btnode * addItem(btnode *, char[MAX]);
void displaytree(btnode*);
void init(list*);
void append(list*,char[MAX]);
void displaylinked(list);
int searchbin(btnode*,char[200]);
int searchlinked(list,char[200]);

int main(){
	btnode *root = NULL;
	int n,i;
	char buff[MAX];
	char words[200];
	
	FILE *ifp, *test;
	int c;
	list l;
	int treecount,listcount;
	int t;
	char x[200];
	
	
	ifp = fopen("words.data","r");
	if(ifp == NULL){
		perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
	}
	
	init(&l);
		
  	while(c!=EOF){
    c = fscanf(ifp, "%s", x);

    	if (c != EOF){

      	root=addItem(root, x);
		append(&l,x);	
    	}
	}
	
	//displaylinked(l);
	//return 0;
	
	test = fopen("mp8a.in","r");
	
	if(test == NULL){
		perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
	}
	
	fgets(buff,MAX,test);
	t=atoi(buff);
	
	while(t>0){
		fscanf(test, " %[^\n]s", &words);
		fgets(buff,MAX,test);
		treecount = searchbin(root, words);
		listcount = searchlinked(l,words);	
		printf("%s : %d, %d \n" ,words,treecount,listcount);
		t--;
	}
	
	//scanf(" %[^\n]s",&words);
	
	//treecount = searchbin(root, words);
	//listcount = searchlinked(l,words);
	//displaytree(root);
	//displaylinked(l);
	
	//printf("%s : %d, %d \n" ,words,treecount,listcount);
	
	fclose(ifp);
	fclose(test);
	return 0;

}

void init(list* l){
	l->size = 0;
	l->head = l->tail = NULL;
}

void displaytree(btnode *n){
	if(n!=NULL){
		displaytree(n->left);
		printf("%s: %d \n", n->item,n->count);
		displaytree(n->right);
	}
}

btnode * addItem(btnode *r, char word[20]){
	
	if (r==NULL){
		r=malloc(sizeof(btnode));
		strcpy(r->item,word);
		r->count=1;
		r->left=NULL;
		r->right=NULL;
		return r;

	}
	else{
		if(strcmp(word,r->item)>0)
			r->right= addItem(r->right,word);
		else if(strcmp(word,r->item)<0)
			r->left = addItem(r->left,word);
		else
			r->count++;
		return r;
					
	}
}

void displaylinked(list l){
	node *tmp = l.head;
	while(tmp!=NULL){
		printf("%s ",tmp->item);
		tmp = tmp->next;
	}
	printf("\n");
}

void append(list* l,char word[20]){
	node *n = malloc(sizeof(node));
	strcpy(n->item,word);
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

int searchbin(btnode *r, char word[200]){
	
	while(r!=NULL){
	
	if(strcmp(r->item,word)==0)
		return 1;
	else if(strcmp(r->item,word)==1)
		return 1 + searchbin(r->left,word);
		
	else if(strcmp(r->item,word)==-1)
		return 1 + searchbin(r->right,word);
						
//	printf("YOO!\n");
	}
}


int searchlinked(list l,char word[200]){
	node *n = l.head;
	int count=1;
	
	while(n!=NULL){
		if(strcmp(n->item,word)==0)
		return count;
		
		n=n->next;
		count++;
	}

	return count;	
}
