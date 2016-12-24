#include <stdio.h>

void display(char [3][3]);
int checkW(char [3][3]);
void emptyboard(char [3][3]);

int main(){
    char ta[3][3]={{'\0','\0','\0'},{'\0','\0','\0'},{'\0','\0','\0'}};
	char choice;
	int player =0;
	int winner =0;
    int row;
    int column;
    int r;
    int c;
    int i=0;
    int flag=0;
    int spaces=9;
    
	
	printf("Let's PLay TicTacToe :) \n\n");
	
    
    for(;i<9 && winner!=1; i++){
		if(choice=='Y'|| choice=='y'){
    	i=i-1;
    	//printf("%i \n ",i);
    	}
		player=i%2+1;
    	display(ta);
    	
    	
		do{
    		printf("Player %d \n", player);
    		printf("Enter the row then the column number where you want to put your character.\n");
    		scanf("%d %d", &r, &c);
    		
    		
    	row=r-1;
		column=c-1;
		
		if(ta[row][column]=='\0'){
			if(player==1)
    		ta[row][column]='X';
			 
       		else
        	ta[row][column]='O';
			
			flag=1;
			spaces--;
		}
		
		else{
			printf("The space is filled up. Your Turn again.\n");
			flag=0;
			i--;
		}
		
		}while(r<0 && r<3 && c<0 && c>3  && flag==0 && (spaces<9 && spaces!=0));	
		
		
		winner=checkW(ta);
		//printf("%d \n ", winner);
		printf("\n");
		
		if(winner==1){
			printf("winner player %d !\n",player);
			display(ta);
			
			do{
				printf("do you want to play again?(Y or N):\n");
				fflush(stdin);
				scanf("%c",&choice);
					
			}while((choice != 'y') && (choice != 'Y') &&
	    	 (choice != 'n') && (choice != 'N'));
	    	 
			if((choice=='Y') ||(choice=='y')){
				emptyboard(ta);
				i=0;
				winner=0;
				spaces=9;
				flag=0;
			}
			else
				return 0;
		//printf("%i \n ",i);
		}
		
		
		if(spaces==0 && winner==0){
			printf("Draw! No winner for this game. \n");
			display(ta);
			do{
				printf("do you want to play again?(Y or N):\n");
				fflush(stdin);
				scanf("%c",&choice);
					
			}while((choice != 'y') && (choice != 'Y') &&
	    	 (choice != 'n') && (choice != 'N'));
	    	 
			if((choice=='Y') ||(choice=='y')){
				emptyboard(ta);
				i=0;
				winner=0;
				spaces=9;
				flag=0;
			}
			else
				return 0;
		}
			
	}
	return 0;
}

void display(char table[3][3]){
    //201 203 187 188 185 204 205 206 186
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",201,205,205,205,203,205,205,205,203,205,205,205,187);
    printf("%c %c %c %c %c %c %c\n",186,table[0][0],186,table[0][1],186,table[0][2],186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("%c %c %c %c %c %c %c\n",186,table[1][0],186,table[1][1],186,table[1][2],186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",204,205,205,205,206,205,205,205,206,205,205,205,185);
    printf("%c %c %c %c %c %c %c\n",186,table[2][0],186,table[2][1],186,table[2][2],186);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,202,205,205,205,202,205,205,205,188);
}

int checkW(char table[3][3]){
	char sym1='X';
	char sym2='O';
	//line check
	//first row
	if((table[0][0]==sym1) && (table[0][1]==sym1) && (table[0][2]==sym1)) 
	return 1;
	//2nd row
	if((table[1][0]==sym1) && (table[1][1]==sym1) && (table[1][2]==sym1)) 
	return 1;
	//3rd row
	if((table[2][0]==sym1) && (table[2][1]==sym1) && (table[2][2]==sym1))
	 return 1;
	//1st row
	if((table[0][0]==sym2) && (table[0][1]==sym2) && (table[0][2]==sym2)) 
	return 1;
	//2nd row
	if((table[1][0]==sym2) && (table[1][1]==sym2) && (table[1][2]==sym2)) 
	return 1;
	//3rd row
	if((table[2][0]==sym2) && (table[2][1]==sym2) && (table[2][2]==sym2))
	 return 1; 
	//column check
	if((table[0][0]==sym1)&& (table[1][0]==sym1) && (table[2][0]==sym1)) 
	return 1;
	if((table[0][1]==sym1) && (table[1][1]==sym1) && (table[2][1]==sym1)) 
	return 1;
	if((table[0][2]==sym1) && (table[1][2]==sym1) && (table[2][2]==sym1))
	return 1;
	//column check
	if((table[0][0]==sym2)&& (table[1][0]==sym2) && (table[2][0]==sym2)) 
	return 1;
	if((table[0][1]==sym2) && (table[1][1]==sym2) && (table[2][1]==sym2)) 
	return 1;
	if((table[0][2]==sym2) && (table[1][2]==sym2) && (table[2][2]==sym2))
	return 1;
	
	if ((table[0][0] == sym1) && (table[1][1] == sym1) && (table[2][2] == sym1))
    return 1;
	
	if ((table[0][0] == sym2) && (table[1][1] == sym2) && (table[2][2] == sym2))
    return 1;
    
  	if ((table[0][2] == sym1) && (table[1][1] == sym1) && (table[2][0] == sym1))
    return 1;
	
  	if ((table[0][2] == sym2) && (table[1][1] == sym2) && (table[2][0] == sym2))
    return 1;
    
	return 0;
	
}

void emptyboard(char table[3][3])
{
  int row, column;

  for (row = 0; row < 3; row++){
    for (column = 0; column < 3; column++){
      table[row][column] = '\0';
 		 }
	}
}
