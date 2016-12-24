#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
	
    void converttoR(int,int);
    void RomtoD(char[]);
    int checkifR(char []);
    void intoW(int, int);
	
int main(){
	int numcase;
	int testcase;
    int n;
	int i,x,j,ctr;
	int temp;
    int num[1000];
	char roman[1000];
	int y=0;
    int flag=1,flag1=1;
	
	
	scanf("%d", &numcase);
	
	do{
		scanf("%d", &testcase);
		if(testcase==1){
			scanf("%d",&n);
            if(n>2147483647 || n<-2147483647){
                printf("INVALID \n");
            }
        else{    
		  if(n<0){
              n=n*(-1);
              printf("NEGATIVE ");
          }
            
           temp=n;
	
   		for(i=0;temp!=0;i++)
			temp=temp/10;
	   
    		intoW(n,i);
            printf("\n");
         
        }
       }
        
	    if(testcase==2){
		int n;
    	int i,len;
	   	int temp,x;
	    int num[1000];
        int rom,ctr,k,flag=1;
            
            scanf("%d",&n);
	
	   if(n>3000)
		  printf("INVALID \n");
       else if(n==0)	
		  printf("INVALID \n");
	   else{
		  temp=n;
		  //x=n;
		
	     for(i=0;temp!=0;i++)
		  temp=temp/10;
	
	
	   converttoR(n,i);
       printf("\n");
	   }
	}
	   if(testcase==3){
            int j;
	scanf("%s",roman);
	 for(i = 0; roman[i] != '\0'; i++){
                if(roman[i] != 'I' && roman[i] != 'V' && roman[i] != 'X' && roman[i] != 'L' && roman[i] != 'C' && roman[i] != 'D' && roman[i] != 'M'){
                   printf("INVALID\n");
                    //printf("j>>%d \n",j);
					//printf("ctr>>%d \n",ctr);
                    flag=0;
					break;
				}
				//printf("i>>%d \n",i);
				for(j=i,ctr=0;roman[j]!='\0';j++)
					if(roman[i]==roman[j]){
                    	//printf("j>>%d \n",j);
					    //printf("i>>%d \n",i);
						//printf("ctr>>%d \n",ctr);
						if(roman[i]!=roman[j-1])
						ctr--;
					ctr++;
				}
			//	printf("j>>%d \n",j);
			//	printf("ctr>>%d \n",ctr);	
				if(ctr==4){
					//printf("j>>%d \n",j);
					//printf("ctr>>%d \n",ctr);
				  printf("INVALID\n");
                   flag=0;
				    break;
                }
                
                for(j=i,ctr=0;roman[j]=='C';j++)
                	ctr++;
                
				if((roman[j]=='D' && ctr>1)){
					//	printf("j>>%d \n",j);
					//printf("ctr>>%d \n",ctr);
					printf("INVALID\n");
					flag=0;
					break;
						
            	}
            	for(j=i,ctr=0;roman[j]=='D';j++)
            		ctr++;
            	
				//printf("j>>%d \n",j);
				//printf("ctr>>%d \n",ctr);	
				if(ctr>1||roman[j]=='M' && ctr){
					//	printf("j>>%d \n",j);
					//printf("ctr>>%d \n",ctr);
					printf("INVALID \n");
					flag=0;
					break;
				}	
				 for(j = i,ctr=0; roman[j] == 'V'; j++)
                    ctr++;


                if((ctr>1)||(roman[j] == 'M' && ctr == 1) || (roman[j] == 'X'  && ctr == 1) || (roman[j] == 'L' && ctr == 1)|| (roman[j] == 'C' && ctr == 1)|| (roman[j] == 'D' && ctr == 1)){
                    //printf("j>>%d \n",j);
					//printf("ctr>>%d \n",ctr);
					printf("INVALID\n");
                    flag=0;
					break;
                }
  				
				  for(j = i,ctr=0; roman[j] == 'L'; j++)
                    ctr++;


                if((ctr>1)||(roman[j] == 'C'&& ctr) || (roman[j] == 'D' && ctr) || (roman[j] == 'M'&& ctr)){
                    printf("INVALID\n");
                    //printf("j>>%d \n",j);
					//printf("ctr>>%d \n",ctr);
					flag=0;
					break;
                }
                
				for(j = i, ctr = 0; roman[j] == 'X'; j++)
                    ctr++;


                if((roman[j] == 'L' && ctr > 1) || (roman[j] == 'C' && ctr > 1) || (roman[j] == 'D' && ctr) || (roman[j] == 'M' && ctr)){
                    //printf("j>>%d \n",j);
					//printf("ctr>>%d \n",ctr);
					printf("INVALID\n");
                    flag=0;
					break;
                }
                
                for(j = i, ctr = 0; roman[j] == 'I'; j++)
                    ctr++;
					//printf("ctr>>%d",ctr);
			
                if((roman[j] == 'V' && ctr > 1) || (roman[j] == 'X' && ctr > 1) || (roman[j] == 'L' && ctr)|| (roman[j] == 'C' && ctr) || (roman[j] == 'D' && ctr) || (roman[j] == 'M' && ctr)){
                   	//printf("j>>%d \n",j);
					//printf("ctr>>%d \n",ctr);
					printf("INVALID\n");
                    flag=0;
					break;
                }
                
                if((roman[i] == 'I' && roman[i+1] == 'V' && roman[i+2] == 'I') ||(roman[i] == 'I' && roman[i+1] == 'X' && roman[i+2] == 'I')){
                    //printf("j>>%d \n",j);
					//printf("ctr>>%d \n",ctr);
					printf("INVALID\n");
                   flag=0;
				    break;
                }
                           	
	}

	if(flag!=0){
	RomtoD(roman);
	printf("\n");
    }
       
       }
		numcase--;
	}while(numcase>0);
	
	
	return 0;

}


void intoW(int x, int i){
	char Ones[10][10] = {"ONE", "TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
    char Teens[15][15] = {"TEN","ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN","SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN"};
    char Tens[15][15] = {"TWENTY","THIRTY","FOURTY","FIFTY","SIXTY","SEVENTY","EIGHTY","NINETY"};
 	//char m[10][10]={"Thousand","Million", "Billion"};
	int j;	
	int p,a;
		
	if(i==0)
		printf("ZERO");
		
	
	else if(i==1)
		printf("%s", Ones[x-1]);
	
	else if(i==2){
		if(x>=20){
			a=x/10;
			p=x%10;
			if(p!=0)
			printf("%s-%s", Tens[a-2], Ones[p-1]);
			
			else
			printf("%s",Tens[a-2]);
		}
		if(x>=10 && x<20){
		j=x%10;
		printf("%s", Teens[j]);
	}
		
}
	else if(i==3){
		int a, b, c,d,e,f,flag=0;
		a=x/100;
		printf("%s HUNDRED", Ones[a-1]);
		c=x%100;
		b=c/10;
		if(c>=20){
			f=c%10;
			if(f!=0){
				printf(" %s-%s", Tens[b-2], Ones[f-1]);
				flag=1;
			}
			else
			printf(" %s", Tens[b-2]);	
		}
		if(c>=10 && c<20){
			e=c%10;
			printf(" %s", Teens[e]);
			flag=1;
		}
		
		d=c%10;
		
		if(d!=0 && flag!=1){
			printf(" %s", Ones[d-1]);
		}
		
		flag=0;			
	}
	else if(i==4){
		int a,f,g,h,k,l,m,o,flag1=0;
		k=x/1000;
		printf("%s THOUSAND", Ones[k-1]);
		f=x%1000;
		g=f/100;
		
		if(g!=0)     
			printf(" %s HUNDRED", Ones[g-1]);
		h=f%100;
		//printf("h>>%d \n",h);
		l=h/10;
		//printf("l>>%d \n",l);
		
		if(h>=20){
			a=h%10;
			if(a!=0){
				printf(" %s-%s", Tens[l-2], Ones[a-1]);
				flag1=1;
			}
			else
			printf(" %s", Tens[l-2]);
		}
		if(h>=10 && h<20){
			m=h%10;
			printf(" %s", Teens[m]);
			flag1=1;
		}
		o=h%10;
		
		if(o!=0 && flag1!=1){
			printf(" %s", Ones[o-1]);
		}
		flag1=0;
	}
	
	else if(i==5){
		int a=0,b=0,f=0,g=0,h=0,k=0,l=0,m=0,n=0,o=0,s=0,flag1=0;
		f=x/1000;

		if(f>=20){
		g=f/10;
		h=f%10;
		 	if(h==0)
			printf("%s THOUSAND", Tens[g-2]);
		//printf("h>>%d",h);
			else
			printf("%s-%s THOUSAND", Tens[g-2], Ones[h-1]);
			
		}
		if(f>=10 && f<20){
			a=f%10;
			printf("%s THOUSAND", Teens[a]);
		}
		
		l=x%1000;
		k=l/100;
		
		if(k!=0)
		printf(" %s HUNDRED", Ones[k-1]);
		
		m=l%100;
		
		n=m/10;
		
		if(m>=20){
			b=m%10;
			if(b!=0){
			printf(" %s-%s", Tens[n-2], Ones[b-1]);
			flag1=1;
			}
			else
			printf(" %s", Tens[n-2]);
		}
		if(m>=10 && m<20){
			o=m%10;
			printf(" %s", Teens[o]);
			flag1=1;
		}
		s=m%10;
		
		if(s!=0 && flag1!=1){
			printf(" %s", Ones[s-1]);
		}
		flag1=0;
		
	}
	else if(i==6){
		int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,k=0,l=0,m=0,n=0,o=0,z=0,flag=0;
		a=x/100000;
		
		printf("%s HUNDRED", Ones[a-1]);
		b=x%100000;
		c=b/1000;
		
		if(c>=20){
		d=c/10;
		e=c%10;
			if(e==0)
			printf(" %s THOUSAND", Tens[d-2]);
			else
			printf(" %s-%s THOUSAND", Tens[d-2], Ones[e-1]);	
			
		}
		if(c>=10 && c<20){
			f=c%10;
			printf(" %s THOUSAND", Teens[f]);
		}
		if(c<10 && c!=0){
			printf(" %s THOUSAND", Ones[c-1]);
		}
		if(c==0)
			printf(" THOUSAND"); 
			
		g=b%1000;
		h=g/100;
		
		if(h!=0)
		printf(" %s HUNDRED", Ones[h-1]);
		
		k=g%100;
		l=k/10;
		
		if(k>=20){
			z=k%10;
			if(z!=0){
			printf(" %s-%s", Tens[l-2], Ones[z-1]);
			flag=1;
		}
			else
			printf(" %s", Tens[l-2]);
		}
		if(k>=10 && k<20){
			m=k%10;
			printf(" %s", Teens[m]);
			flag=1;
		}
		n=k%10;
		
		if(n!=0 && flag!=1){
			printf(" %s", Ones[n-1]);
		}
		flag=0;
		
	}
	else if(i==7){
		int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,k=0,l=0,m=0,n=0,o=0,r=0,s=0,t=0,flag=0;
		
		a=x/1000000;
		printf("%s MILLION", Ones[a-1]);
		b=x%1000000;
		c=b/100000;
		
		if(c!=0)
		printf(" %s HUNDRED", Ones[c-1]);
		
		d=b%100000;
		e=d/1000;
		
		if(e>=20){
		f=e/10;
		g=e%10;
			if(g==0)
			printf(" %s THOUSAND", Tens[f-2]);
				
			else
			printf(" %s-%s THOUSAND", Tens[f-2], Ones[g-1]);
			
		}
		if(e>=10 && e<20){
			h=e%10;
			printf(" %s THOUSAND", Teens[h]);
		}
		if(e<10 && e!=0){
			
			printf(" %s THOUSAND", Ones[e-1]);
		}
		if(e==0)
			printf(" THOUSAND"); 
			
		k=d%1000;
		l=k/100;
		//printf("l>>%d",l);
		if(l!=0)					
		printf(" %s HUNDRED", Ones[l-1]);
		
		m=k%100;
		n=m/10;
		
		if(m>=20){
			t=m%10;
			if(t!=0){
			printf(" %s-%s", Tens[n-2],Ones[t-1]);
			flag=1;
			}
			else
			printf(" %s", Tens[n-2]);
		}
		if(m>=10 && m<20){
			o=m%10;
			printf(" %s", Teens[o]);
			flag=1;
		}
		r=m%10;
		
		if(r!=0 && flag!=1){
			printf(" %s", Ones[r-1]);
		}
		flag=0;
			
	}
	else if(i==8){
		int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,k=0,l=0,m=0,n=0,o=0,r=0,s=0,t=0,u=0,v=0,flag=0;
		
		a=x/1000000;
		
		if(a>=20){
			b=a/10;
			c=a%10;
			if(c==0)
				printf("%s MILLION", Tens[b-2]);
			else
				printf("%s-%s MILLION", Tens[b-2], Ones[c-1]);
				
		}
		if(a>=10 && a<20){
			d=a%10;
			printf("%s MILLION", Teens[d]);
		}
		
		e=x%1000000;
		f=e/100000;
		
		printf(" %s HUNDRED", Ones[f-1]);
		g=e%100000;
		h=g/1000;
		
		if(h>=20){
		k=h/10;
		l=h%10;
			if(l==0)
				printf(" %s THOUSAND", Tens[k-2]);
			else
				printf(" %s-%s THOUSAND", Tens[k-2], Ones[l-1]);
		
		}
		if(h>=10 && h<20){
			m=h%10;
			printf(" %s THOUSAND", Teens[m]);
			
		}
		if(h<10){
			printf(" %s THOUSAND", Ones[h-1]);
			
		}
	
		o=g%1000;
		r=o/100;
		if(r!=0)
			printf(" %s HUNDRED", Ones[r-1]);
		
		n=o%100;
		s=n/10;
		
		if(n>=20){
			v=n%10;
			if(v!=0){
				printf(" %s-%s", Tens[s-2], Ones[v-1]);
				flag=1;
			}
			else
			printf(" %s", Tens[s-2]);
		}
		if(n>=10 && n<20){
			t=n%10;
			printf(" %s", Teens[t]);
			flag=1;
		}
		u=n%10;
		
		if(u!=0 && flag!=1){
			printf(" %s", Ones[u-1]);
		}
		flag=0;
	
	}
	else if(i==9){
		int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,k=0,l=0,m=0,n=0,o=0,r=0,s=0,t=0,u=0,y=0,z=0,q=0,flag=0;
		
		a=x/100000000;
		b=x%100000000;
		
		printf("%s HUNDRED",Ones[a-1]);
		
		c=b/1000000;
		
		if(c>=20){
			d=c/10;
			e=c%10;
			if(e==0)
				printf(" %s MILLION", Tens[d-2]);
			else
				printf(" %s-%s MILLION", Tens[d-2], Ones[e-1]);
				
		}
		if(c>=10 && c<20){
			f=c%10;
			printf(" %s MILLION", Teens[f]);
		}
		
		g=x%1000000;
		h=g/100000;
		
		printf(" %s HUNDRED", Ones[h-1]);
		k=g%100000;
		l=k/1000;
		
		if(l>=20){
			m=l/10;
			n=l%10;
				if(n==0)
					printf(" %s THOUSAND", Tens[m-2]);
				else
					printf(" %s-%s THOUSAND", Tens[m-2], Ones[n-1]);
						
		}
		if(l>=10 && l<20){
			o=l%10;
			printf(" %s THOUSAND", Teens[o]);
		}
		if(l<10){
			printf(" %s THOUSAND", Ones[l-1]);
		}
		
		r=k%1000;
		s=r/100;
		
		if(r!=0)
			printf(" %s HUNDRED", Ones[r-1]);
			
		t=r%100;
		u=t/10;
		
		if(t>=20){
			q=t%10;
			if(q!=0){
				printf(" %s-%s", Tens[u-2], Ones[q-1]);
				flag=1;
			}
			else
			printf(" %s", Tens[u-2]);
		}
		if(t>=10 && t<20){
			z=t%10;
			printf(" %s", Teens[z]);
			flag=1;
		}
		
		y=t%10;
		if(y!=0 && flag!=1){
			printf(" %s", Ones[y-1]);
		}
		flag=0;
					
	}		
		
}





void converttoR(int x,int i){
	char ones[][10]= {"I","II","III","IV","V","VI","VII","VIII","IX"};
	char tens[][10]= {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
	char hundreds[][10]= {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
	char thousands[][4]= {"M","MM","MMM"};	
	
	if(i==4){
		int a=0,b=0,c=0,d=0,e=0,f=0,g=0;
		
		a=x/1000;
		
		//printf("a>>%d \n",a);
		//if(a==3);
		printf("%s",thousands[a-1]);		
		b=x%1000;
		c=b/100;
		printf("%s",hundreds[c-1]);
		d=b%100;
		e=d/10;
		printf("%s",tens[e-1]);
		f=d%10;
		printf("%s",ones[f-1]);
		
	}
	if(i==3){
		int a=0,b=0,c=0,d=0;
		
		a=x/100;
		printf("%s",hundreds[a-1]);
		b=x%100;
		c=b/10;
		printf("%s",tens[c-1]);
		d=b%10;
		printf("%s",ones[d-1]);
		
	}
	if(i==2){
		int a=0,b=0,c=0;
		
		a=x/10;
		printf("%s",tens[a-1]);
		b=x%10;
		printf("%s",ones[b-1]);
		
	}
	if(i==1){
		int a=0;
		
		a=x;
		
		printf("%s",ones[a-1]);
	}
}

	void RomtoD(char rom[]){
	int i=0,len=0,sum=0;
	
	
	for(i=0;rom[i]!='\0';i++){
		if(rom[i]=='I'){
			if(rom[i+1]=='V'){
			sum+=4;
			i++;
		}
			else if(rom[i+1]=='X'){
			sum+=9;
			i++;
		}
			else
				sum+=1;
		}
		else if(rom[i]=='V')
			sum+=5;
	
		else if(rom[i]=='X'){
			if(rom[i+1]=='C'){
				sum+=90;
				i++;
			}
			else if(rom[i+1]=='L'){
				sum+=40;
				i++;
			}
			else				
				sum+=10;
		}
		else if(rom[i]=='L')
			sum+=50;
			
		else if(rom[i]=='C'){
			if(rom[i+1]=='M'){
				sum+=900;
				i++;
			}
			else if(rom[i+1]=='D'){
				sum+=400;
				i++;
			}
			else	
				sum+=100;
		}
		else if(rom[i]=='D')
			sum+=500;
		else if(rom[i]=='M')
			sum+=1000;
	}
	
	printf("%d",sum);
}



