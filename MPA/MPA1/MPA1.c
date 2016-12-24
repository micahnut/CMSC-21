////i declare, upon my honor, that i made this MPA bymyself
#include <stdio.h>


void PrimeN(int);
int length(char []);
int verifyifN(char []);
void reverse(char[]);
void add(char[],char[],int,int);
void sub(char[],char[],int,int);
void copy(char[],char[]);
long int howmanyComb(int);

int main(){
	int  choice,choice2,x;
	char num1[100], num2[100],ans[101];
	
	do{
		printf("\t\tMenu\n\t1. Sieve of Eratosthenes\n\t2. Big Number\n\t3. Coin Changing\n\t4. Exit\n");
		fflush(stdin);
		scanf("%d",&choice);

		if(choice == 1){
			printf("Enter a number:\n");
			fflush(stdin);
			scanf("%i",&x);

			PrimeN(x);

		}
		else
		if(choice == 2){
			
			do{
				printf("Please enter a number: \n");
				fflush(stdin);
				scanf("%s",num1);
			}while(!(verifyifN(num1)));
	
			do{
				printf("Please enter another number: \n");
				fflush(stdin);
				scanf("%s", num2);
			}while(!(verifyifN(num2)));	

		reverse(num1);
		reverse(num2);
		
		//printf("\n %s %s\n",num1,num2);
		
		do{
			printf("\t\tWhat do you want to do with the numbers\n\t1. Add them \n\t2. Subtract them\n");
			fflush(stdin);
			scanf("%i",&choice2);
		
		int i=0,len1=0,len2=0,smalllen=0,biglen=0,carry=0;
		char big[100],small[100];
		
		
		len1=length(num1);
		len2=length(num2);
		
		//printf("%i %i",len1,len2);
		
		if(len1>len2){
			biglen = len1;
			smalllen = len2;	
			
			copy(big,num1);
			copy(small,num2);
			//printf("\n %s %s",big,small);
			
		}
		
		else{
			biglen = len2;
			smalllen = len1;
			
			copy(big,num2);
			copy(small,num1);
			//printf("\n %s %s",big,small);
		}

		
		
		if(choice2==1){
			
			printf("\n %s + %s =",num1,num2);
			add(big,small,biglen,smalllen);
		
		}
		
		else{
			
			printf("%s - %s =",num1,num2);
			sub(big,small,biglen,smalllen);
			
		}
			
	}while(choice2!=2 && choice2!=1);
	
	}
		else
		if(choice==3){
			int num,x;

			do
		    {
        		printf("\nInput value (0-100000):");
       			fflush(stdin);
				scanf("%d", &num);
   			 }while((num < 0) || (num > 100000));


			x= howmanyComb(num);

			printf("You have %ld combinations using 1s, 5s, 10s and 20s", x);
	
	
	}
	
		
		else
		if(choice==4){
			printf("\n Exit\n");
			break;
		}
		
		else
		printf("\n Not in the choices above!\n");
		
	}while(choice!=3);
	
	return 0;
}

	void PrimeN(int a){

	int i;
	int j,x;
	int n=10000,count=0;
	int prime[10000],temp;
	
	for(i=0,j=2;i<n;i++,j++){
		prime[i]=j;
		
		//printf("%i",prime[i]);
	}
	printf("\n");

	for(i=0;i<n;i++)
		prime[i]=1;   // set all to true
			for(i=2;i<n;i++){
				if(prime[i]!=0){
					for(j=i*i;j<n;j=j+i){
						prime[j]=0; //factors not prime
					}
				}
			}
	
	for(i=2,count=0;i<n;i++){ //counting until the desired prime number
		if(count!=a){
			if(prime[i]==1){
				temp=i;
				//printf("%d ",i);
				count++;
			}
		}	
	}
		printf("%d \n",temp);
	
	}
		int length(char st[]){
			int i=0;
		
			for(i=0;st[i]!='\0';i++);
	
			return i;	
	}
	
	int verifyifN(char st[]){
		int i=0,flag=1,len;
		
		len=length(st);
		for(;i<len;i++){
			if(!(st[i]>='0' && st[i]<='9')){
				flag=0;
				break;
			}
		}
		
		return flag;
	}
	
	void copy(char a[],char b[]){
		int i=0;
		
		for(;b[i]!='\0';i++){
			a[i]=b[i];
		}
			a[i]='\0';
	}
	void reverse(char str[]){
		int i,j,len;
		char temp;
		
		len = length(str);
		
		i=0;
		j= len-1;
		
		while(i<j){
			temp=str[i];
			str[i]=str[j];
			str[j]=temp;
			i++;
			j--;
		}
	}
	
	void add(char big[],char small[],int bigl,int smalll){
		int i=0,carry=0;
		char ans[101];
		
		for(i=0;i<smalll;i++){
			ans[i]=((big[i]-48)+(small[i]-48)+carry)+48;		
		
		//'1'-48 + '1'-48 = 2+48=50='2'
		
		/*49-48+57-48
		1+9=10+48=58
		58=58-48=10%10=0
		0+48=48
		carry =1
		*/
		
		if(ans[i]>57){
			ans[i]=(ans[i]-48)%10;
			ans[i]+=48;
			carry = 1;
		}
		else{
			carry = 0;
		}
		
		}
		for(;i<bigl;i++){ //if small lenght is finish but big length not yet
		
		if(carry==1)
		ans[i]=big[i]+1;
		
		else
		ans[i]=big[i];
		
		carry=0;	
	}
			ans[i] = '\0';
			printf("%s \n",ans);
		
		reverse(ans);
		printf("%s \n",ans);
	
	printf("\n");
	
			
	}
	void sub(char big[],char small[],int bigl,int smalll){
		int i=0,borrow=0,flag=0;
		char ans[101];
		
			/*for(i=0;i<=bigl;i++){
			 if(small[i]!='0')
			 	small[i]=small[i];
			 else
			 	small[i]='0';	
		}

		printf("%s \n",small);
		
		getch();*/
		
		for(i=0;i<smalll;i++){
			 
		if(big[i]-48<small[i]-48){
			big[i]+=10;
			
			
		//	printf("%i \n",big[i]);
		 	
			flag=1;	
	   }
	   		if(big[i+1]=='0')
				 big[i+1]+=10;
		
		ans[i]=((big[i]-48)-(small[i]-48)-borrow)+48;		
		
		
		if(flag==1){
			ans[i]=(ans[i]-48)%10;
			ans[i]+=48;
			borrow = 1;
		}
		else{
			borrow = 0;
		}
		
	}
		for(;i<bigl;i++){
		
			
		if(borrow==1)
			ans[i]=big[i]-1;

		else
			ans[i]=big[i];
			
		//if(ans[i]=9){
		//	big[i+1]-=1;
			//ans[i]=big[i];
			
		//	printf("%i \n",big[i+1]);
		//}		
			
		borrow=0;
	}
			ans[i] = '\0';
		printf("%s \n",ans);
		
		reverse(ans);
		printf("%s \n",ans);
	
	printf("\n");
	
			
	}

long int howmanyComb(int a){
	int i=0,j=1,r=1,count=0;
	
	while(i<=a){
		i=i+5;
		count=count+j;
		if(i%20==0)
			r++;
		if(i%10==0)
			j=j+r;
	}
	return count;
}
/*0-4,5-9,10-14,15-19,20-24,25-29,30-34*/
//pattern
/*1,2,4,6,10,14,20,26,35,44,56,68,84,100*/
//difference sa pattern
/*1,2,2,4,4,6,6,9,9,12,12,16,16*/	    




/*
int howmanyTwenty(int input){
	if(input > 20){
		return 1 + howmanyTwenty(input-20);
	}
	howmanyTen(input);
}

int howmanyTen(int input){
	if(input > 10){
		return 1 + howmanyTen(input-10);
	}
	howmanyFive(input);
}

int howmanyFive(int input){
	if(input > 5){
		return 1 + howmanyFive(input-5);
	}
	howmanyOne(input);
}

int howmanyOne(int input){
	if(input > 1){
		return 1 + howmanyOne(input-1);
	}
}	
*/

	
/*carrying and borrowing*/
//  (____________    _____________)//
// (   ::::            ::::      )//
//(    ::::            ::::     )//
//(    ::::            ::::    )//



