#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void display(char table[10][10]);
void snakes(char table[10][10]);
void ladder(char table[10][10]);
//void checkposition();


int main(){
	srand((unsigned int)time(NULL));
	
	int dice;
	
	int players;
	int die;
	int r,c,l,d;
	int curPos, rowPos;
	char choice;
    char ta[10][10];
	
	int flag=0,flag2=0,flag3=0;
	int position;
	int p2,p3,p4;
	int i,j,x,z,y;
    int winner=0;
    
    for(i=0;i<10;i++)
       for(j=0;j<10;j++)
           ta[i][j]='\0';
    
	printf("Hello, let's play snakes & ladders\n");        
    
    do{
		printf("How many players are playing?\n");
		scanf("%d",&players);
	}while(players<1 && players>4 );
	
	printf("but sorry, this program can only play with one player");
		
	rowPos=9;
	curPos=0;
	if(players==1){
		do{
		printf("\n\n");
		
		for(i=0;i<10;i++)
			for(j=0;j<10;j++)
				if(ta[i][j] != 'A')
					ta[i][j]='\0';
	
	ta[rowPos][curPos]='A';
	snakes(ta);
	ladder(ta);
	display(ta);
	
		printf("Please press r to roll your dice\n");
		fflush(stdin);
		scanf("%d",&die);
		getch();
		

	
	dice=rand()%6+1;
		x=dice;
		printf("\n");
		printf("dice>>%d \n",dice);
		
		r=rowPos%2;
		
		if(r!=0){
			curPos+=x;
				if(curPos>9){	
					rowPos--;
					printf("curpos>>%d",curPos);			
						z=curPos-x;
						if(z==9){
							curPos=9;
							curPos-=(x-1);
						}
						else{
						d=curPos-9;
						curPos=9;
						curPos=curPos-d+1;
						printf("curpos>>%d",curPos);
						printf("x>>>>%d \n",x);
					}
					flag2=1;
				}
			ta[rowPos][curPos]='A';
			}
		

		if(flag2!=1){
			if(r==0){
				curPos-=x;//-3
				printf("curpos>>%d",curPos);
				printf("x>>>>%d \n",x);
				if(curPos<0){
					rowPos--;
					//curPos+=x;
					
					d=x+curPos;//1
					y=d+curPos;//-2
					if(y==0){
						curPos=0;
						curPos=curPos+x-1;
					}	
					curPos=0;
					curPos=curPos+x-d-1;//2

					
				}
			}
			ta[rowPos][curPos]='A';
		}
		flag2=0;
		printf("row>>>%d col>>>%d \n",rowPos,curPos);
	
			
		
	printf("dice>>%d \n",dice);		
	display(ta);
	printf("\n\n");
	
	if(ta[0][0]=='A'){
		printf("Congratulations! You have won the game\n");
		winner=1;
	}
	
	}while(winner==0);	
}
	return 0;
}

void display(char table[10][10]){
    //201 203 187 188 185 204 205 206 186
    int i,j;
    printf("%c",201);
    for(i=0;i<9;i++)
        printf("%c%c%c%c",205,205,205,203);
    printf("%c%c%c%c\n",205,205,205,187);
    
    for(i=0; i<10; i++){
        for(j=0;j<10;j++){
            printf("%c %c ",186,table[i][j]);
        }
        if(i<9){
            printf("%c\n%c",186,204);
            for(j=0;j<9;j++)
                printf("%c%c%c%c",205,205,205,206);
            printf("%c%c%c%c\n",205,205,205,185);
        }
    }
    
    printf("%c\n%c",186,200);
    for(i=0;i<9;i++)
        printf("%c%c%c%c",205,205,205,202);
    printf("%c%c%c%c\n",205,205,205,188);
}

void snakes(char table[10][10]){
	int sh1,st1,sh1c,st1c;
	int sh2,st2,sh2c,st2c;
	int sh3,st3,sh3c,st3c; 
	
	int repeat=0,repeat2=0,repeat3=0;
	char snakeH1='H',snakeT1='T';
	char snakeH2='H',snakeT2='T';
	char snakeH3='H',snakeT3='T';
	
	do{
		
		sh1=rand()%9+1;
		sh1c=rand()%9+1;
		st1=rand()%9+1;
		st1c=rand()%9+1;
		
		
		if(table[sh1][sh1c]!='\0' && table[sh1][sh1c]!='\0')
			repeat=1;
		else if(sh1>st1)
			repeat=1;
		else if(sh1%2==1 && sh1==0)
			repeat=1;
		else if(sh1%2==0 && sh1==9)
			repeat=1;		
		else if (sh1%2==1 && sh1c<st1c && sh1==st1)
			repeat=1;
		else if (sh1%2==0 && sh1c>st1c && sh1==st1)
			repeat=1;
		else
			repeat=0;			

	
	}while(repeat==1);
	
	table[sh1][sh1c]= snakeH1;
	table[st1][st1c]= snakeT1;
		
	do{
		
		sh2=rand()%9+1;
		sh2c=rand()%9+1;
		st2=rand()%9+1;
		st2c=rand()%9+1;
		
		
		if(table[sh2][sh2c]!='\0' && table[sh2][sh2c]!='\0')
			repeat2=1;
		else if(sh2>st2)
			repeat2=1;
		else if(sh2%2==1 && sh2==0)
			repeat2=1;
		else if(sh2%2==0 && sh2==9)
			repeat2=1;		
		else if (sh2%2==1 && sh2c<st2c && sh2==st2)
			repeat2=1;
		else if (sh2%2==0 && sh2c>st2c && sh2==st2)
			repeat2=1;
		else
			repeat2=0;			

	
	}while(repeat2==1);
	
	table[sh2][sh2c]= snakeH2;
	table[st2][st2c]= snakeT2;
	
	do{
		
		sh3=rand()%9+1;
		sh3c=rand()%9+1;
		st3=rand()%9+1;
		st3c=rand()%9+1;
		
		
		if(table[sh3][sh3c]!='\0' || table[sh3][sh3c]!='\0')
			repeat3=1;
		else if(sh3>st3)
			repeat3=1;
		else if(sh3%2==1 && sh3==0)
			repeat3=1;
		else if(sh3%2==0 && sh3==9)
			repeat3=1;		
		else if (sh3%2==1 && sh3c<st3c && sh3==st3)
			repeat3=1;
		else if (sh3%2==0 && sh3c>st3c && sh3==st3)
			repeat3=1;
		else
			repeat3=0;			

	
	}while(repeat3==1);
	
	table[sh3][sh3c]= snakeH3;
	table[st3][st3c]= snakeT3;	

}

void ladder(char table[10][10]){
	int lh1,lt1,lh1c,lt1c;
	int lh2,lt2,lh2c,lt2c;
	int lh3,lt3,lh3c,lt3c; 
	
	int repeat=0,repeat2=0,repeat3=0;
	char ladderH1='L',ladderT1='U';
	char ladderH2='L',ladderT2='U';
	char ladderH3='L',ladderT3='U';
		
		do{
		
		lh1=rand()%9+1;
		lh1c=rand()%9+1;
		lt1=rand()%9+1;
		lt1c=rand()%9+1;
		
		
		if(table[lh1][lh1c]!='\0' && table[lh1][lh1c]!='\0')
			repeat=1;
		else if(lh1>lt1)
			repeat=1;
		else if(lh1%2==1 && lh1==0)
			repeat=1;
		else if(lh1%2==0 && lh1==9)
			repeat=1;		
		else if (lh1%2==1 && lh1c<lt1c && lh1==lt1)
			repeat=1;
		else if (lh1%2==0 && lh1c>lt1c && lh1==lt1)
			repeat=1;
		else
			repeat=0;			

	
	}while(repeat==1);
	
	table[lh1][lh1c]= ladderH1;
	table[lt1][lt1c]= ladderT1;
	
	do{
		
		lh2=rand()%9+1;
		lh2c=rand()%9+1;
		lt2=rand()%9+1;
		lt2c=rand()%9+1;
		
		
		if(table[lh2][lh2c]!='\0' && table[lh2][lh2c]!='\0')
			repeat2=1;
		else if(lh2>lt2)
			repeat2=1;
		else if(lh2%2==1 && lh2==0)
			repeat2=1;
		else if(lh2%2==0 && lh2==9)
			repeat2=1;		
		else if (lh2%2==1 && lh2c<lt2c && lh2==lt2)
			repeat2=1;
		else if (lh2%2==0 && lh2c>lt2c && lh2==lt2)
			repeat2=1;
		else
			repeat2=0;			

	
	}while(repeat2==1);
	
	table[lh2][lh2c]= ladderH2;
	table[lt2][lt2c]= ladderT2;
	
	do{
		
		lh3=rand()%9+1;
		lh3c=rand()%9+1;
		lt3=rand()%9+1;
		lt3c=rand()%9+1;
		
		
		if(table[lh3][lh3c]!='\0' && table[lh3][lh3c]!='\0')
			repeat3=1;
		else if(lh3>lt3)
			repeat3=1;
		else if(lh3%2==1 && lh3==0)
			repeat3=1;
		else if(lh3%2==0 && lh3==9)
			repeat3=1;		
		else if (lh3%2==1 && lh3c<lt3c && lh3==lt3)
			repeat3=1;
		else if (lh3%2==0 && lh3c>lt3c && lh3==lt3)
			repeat3=1;
		else
			repeat3=0;			

	
	}while(repeat3==1);
	
	table[lh3][lh3c]= ladderH3;
	table[lt3][lt3c]= ladderT3;
}


//wala pa jud ito nafinish sir T.T 


