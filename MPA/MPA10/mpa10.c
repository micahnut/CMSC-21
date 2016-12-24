#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#define MAX 1000

using namespace std;

class BigNum{
	int fib[MAX];

public:
	BigNum();
	BigNum(int);
	BigNum(string);
	//BigNum operator *(BigNum,BigNum);
	//BigNum operator +(BigNum,BigNum);
	//BigNum operator -(BigNum,BigNum);
	//BigNum operator /(BigNum,BigNum);
	//BigNum operator %(BigNum,BigNum);
}
void fibonacci(int);
void add(char[],char[]);
void mul(int[],int[]);
void div(int[],int[]);
void sub(char[],char[]);
void sub(int[],int[]);
void mod(int[],int[]);
int length(char[]);
void reverse(char[]);
void copy(char [],char []);


BigNum :: BigNum(){
	for(int i=0; i<MAX;i++){
		fib[i]=0;
	}
}

BigNum :: BigNum(int a){
	int i;

	for(i=0;i<MAX;i++)
		fib[i]=0;

	i=0;
	while(a>0 && i<MAX){
		fib[i++]= a%10;
		a /=10;
	}	
}

BigNum:: BigNum(string a){

	for(i=0; a[i] != '\0'; i++)
		fib[i] = a[i];

}


void multiply(int a[], int b[]){
    int c[MAX];
    int i, j, k, rem, tmp, tmpval;
    
    for(i=0; a[i]!='\0'; i++);
    for(j=0; b[j]!='\0'; j++);
    
    for(i=0;i<MAX;i++){
    	for(j=0;j<MAX;j++){
    		tmpval=a[i]*b[j];
    		c[i+j] += tmpval%10;
    		c[i+j+1] += tmpval/10;
    	}
    }
    
}

void subtract(int a[], int b[]){
    int ans[MAX];
    int i, j, k, l;
    
    for(i=0; a[i]!='\0'; i++);
    for(j=0; b[j]!='\0'; j++);
    
    if(j > i)
        k = j;
    else
        k = i;
        
    for(l=0; k != 0; k--){
        if(a[i] > b[i])
            ans[k] = a[i] - b[j];
        else{
            a[i] += 10;
            while(a[i-l] == 0){
                a[i-l] = 9; 
                l++;
            }
            a[i-l] = 9;         
            ans[k] = a[i] - b[j];
        }   
    }       
    
}

void divide(int a[], int b[]){
    int ans[MAX];
    int i, j, k;
    
    for(i=0; a[i]!='\0'; i++);
    for(j=0; b[j]!='\0'; j++);
    
    if(j > i)
        k = j;
    else
        k = i;  
    
    for(; k != 0; k--){
        ans[k] = a[i] / b[j];
    }   
}

void modulo(int a[], int b[]){
    int ans[MAX];
    int i, j, k, z;
    
    for(i=0; a[i]!='\0'; i++);
    for(j=0; b[j]!='\0'; j++);
    
    if(j >= i)
        k = j;
    else
        k = i;
        
    for(z=1; k != -1; k--){
        if(a[i] > b[i])
            c[k] = a[i] - b[j];
        else{
            a[i] += 10;
            while(a[i-z] == 0){
                a[i-z] = 9; 
                z++;
            }
            a[i-z] = 9;         
            c[k] = a[i] - b[j];
        }   
    }           
        
            
}

void add(char a[],char b[]){
		int i=0,carry=0;
		char ans[101];
		int bigl,smalll;
		int len1,len2;

		len1=length(a);
		len2=length(b);
	
		if(len1>len2){
			bigl = len1;
			smalll = len2;	
			
			copy(big,a);
			copy(small,b);
						
		}
		
		else{
			bigl = len2;
			smalll = len1;
			
			copy(big,b);
			copy(small,a);
			
		}
		
		for(i=0;i<smalll;i++){
			ans[i]=((big[i]-48)+(small[i]-48)+carry)+48;		
		
		if(ans[i]>57){
			ans[i]=(ans[i]-48)%10;
			ans[i]+=48;
			carry = 1;
		}
		else{
			carry = 0;
		}
		
		}
		for(;i<bigl;i++){ 
		
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

		void sub(char a[],char b[]){
		int i=0,borrow=0,flag=0;
		char ans[101];
		int bigl,smalll;
		int len1,len2;

		len1=length(a);
		len2=length(b);
	
		if(len1>len2){
			bigl = len1;
			smalll = len2;	
			
			copy(big,a);
			copy(small,b);
			
			
		}
		
		else{
			bigl = len2;
			smalll = len1;
			
			copy(big,b);
			copy(small,a);
			
		}

		for(i=0;i<smalll;i++){
			 
		if(big[i]-48<small[i]-48){
			big[i]+=10;
			
		 	
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
			
		borrow=0;
	}
			ans[i] = '\0';
		printf("%s \n",ans);
		
		reverse(ans);
		printf("%s \n",ans);
	
	printf("\n");
	
			
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

	int length(char st[]){
		int i=0;
		
		for(i=0;st[i]!='\0';i++);
	
	return i;	
	}


	void copy(char a[],char b[]){
		int i=0;
		
		for(;b[i]!='\0';i++){
		a[i]=b[i];
		}
		a[i]='\0';
	}




void fibonacci(int x){
	int one[MAX],two[MAX],three[MAX];
	int i,j,flag=0,tmp,l,k;

	for(i=0;i<MAX;i++){
		one[i]=0;
		two[i]=0;
		three[i]=0;
	}

	two[MAX-1]=1;

	for(i=0;i<x;i++){

		for(l=0;l<MAX;l++)
			three[l]=one[l]+two[l];

		for(k=MAX-1;k>0;k--){
			if(three[k]>9){
				tmp=three[k];
				three[k]%=10;
				three[k-1]+=(tmp/10);
			}
		}

		if(i==x-3)
			break;

		for(j=0;j<MAX;j++)
			one[j]=two[j];
		for(j=0;j<MAX;j++)
			two[j]=three[j];				

	}

	for(i=0;i<MAX;i++){
		cout<<three[i];
	}


	int main(){
		string line;
		ifstream myfile("mpa10.in");
		int count,t;
		
		if(myfile.is_open()){
			getline(myfile,line);
			t= atoi(line);

			while(t>0){
				getline(myfile,line){
				count=atoi(line);
				fibonacci(count);

				t--;
			}
		}
		myfile.close();

		return 0;
	}



