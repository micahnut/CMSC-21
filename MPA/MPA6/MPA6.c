#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 1000


int checker(char *);
int funcheck(char * , int);

int main( int argc, char** argv ){
	int flag=0;
	
    const char *delimiter_characters = " ";
    const char *filename = "mpa6.in";
    FILE *input_file = fopen( filename, "r" ), *ofp;
    ofp= fopen("chuim.out","w");
    
    const char *qoute="'";
    char buff[ BUFSIZE ];
    char *last_token;
    int i=0,check=0;
    int check2=0;
    int check3=0;
    int flag2=0,flag3=0;
    int func=0;

    if( input_file == NULL ){

        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);

    }else{

        
        while( fgets(buff, BUFSIZE, input_file) != NULL ){
        	i=0,check=0;
            check2=0;
            check3=0;
            flag2=0;
            func=0;

            
            last_token = strtok( buff, delimiter_characters );
            	
			if(strcmp(last_token, "char")!= 0 && strcmp(last_token, "int")!=0 && strcmp(last_token,"float")!=0 && strcmp(last_token,"double")!=0 && strcmp(last_token,"void")!=0){
                		fprintf(ofp, "INVALID \n");
						//printf("INVALID \n");
                		last_token=NULL;
					}
			
			else{

				while( last_token != NULL ){
					if(strcmp(last_token, "char")== 0 || strcmp(last_token, "int")==0 || strcmp(last_token,"float")==0 || strcmp(last_token,"double")==0 || strcmp(last_token,"void")==0){
						flag++;
					
					
					//if(strcmp(last_token,"void")==0)
					   // func=1;	
										
					if(flag==2){
						fprintf(ofp, "INVALID \n");
						//printf("INVALID \n");
						last_token=NULL;
					}
					

			}
					
				else{		
					for(i=0;*(last_token+i)!=';';i++){
						if((*(last_token+i)>='a' && *(last_token+i)<='z' ) || (*(last_token+i)>='1' && *(last_token+i)<='9') ){
						 //printf("%c \n",*(last_token+i));
						 //return 0;
						 check=1;
						 
						}

						if(check3==1){
								
								check2=checker(last_token);
								//printf(">>>>%d \n",check2);
								if(check2==0){
									flag2=1;	
									break;
								}
								check3=0;	
						}
						if((*(last_token+i)=='=') || (*(last_token+i)==',') || (*(last_token+i)=='+') ){
						//printf("%c \n",*(last_token+i));
						
						check3=1;
						//last_token = strtok( NULL, delimiter_characters );
						//check=checker(last_token+i);
						}
						
						if(*(last_token+i)=='('){
								check2=funcheck(last_token , i);
								if(check2==0){
									flag3=1;
									break;
								}
								if(check2==1){
									flag3=1;
									break;
								}						
						}
					}
					if(check==1){
						if(*(last_token+i)==';')
						check2=1;
						
						//if(func==1)
						//check2=0;
						}
        	   		 
					}
        	   		 
        	    if(flag2==1){
        	    	last_token=NULL;
        	    	flag2=0;	
        		}
        		else if(flag3==1){
        			last_token=NULL;
        			flag3=0;
				}
        	    else	
        	    last_token = strtok( NULL, delimiter_characters );
        	}
        	if(check2==1)
        		fprintf(ofp, "VALID \n");
				//printf("VALID\n");
        	else
        		fprintf(ofp, "INVALID \n");
        		//printf("INVALID\n");
        	   	    
       	 }		
    }
    
        if( ferror(input_file) ){
            perror( "The following error occurred \n" );
        }

        fclose( input_file );
		fclose(ofp);
    }

    return 0;

}

int checker(char *last_token){
	 int i,check=0;
	 const char *qoute="'";
	 									
		for(i=0;*(last_token+i)!=';';i++){
						
						if(*(last_token+i)=='c'){
						    	if(*(last_token+i+1)=='h')
							      	if(*(last_token+i+2)=='a')
										if(*(last_token+i+3)=='r')
										check=0;
										
						    	return check;
							}
						if(*(last_token+i)=='i'){
							 if(*(last_token+i+1)=='n')
							 	if(*(last_token+i+2)=='t')
							 		check=0;
							 return check;
						}

						if(*(last_token+i)=='f'){
							if(*(last_token+i+1)=='l')
								if(*(last_token+i+2)=='o')
									if(*(last_token+i+3)=='a')
										if(*(last_token+i+4)=='t')
											check=0;
							return check;
						}

						if(*(last_token+i)=='d'){
							if(*(last_token+i+1)=='o')
								if(*(last_token+i+2)='u')
									if(*(last_token+i+3)=='b')
										if(*(last_token+i+4)=='l')
											if(*(last_token+i+5)=='e')
												check=0;
							return check;				
						}
						if(*(last_token+i)=='v'){
							if(*(last_token+i+1)=='o')
								if(*(last_token+i+2)=='i')
									if(*(last_token+i+3)=='d')
										check=0;
							return check;		
						}
						
						if(*(last_token+i)=='w'){
							if(*(last_token+i+1)=='h')
								if(*(last_token+i+2)=='i')
									if(*(last_token+i+3)=='l')
										if(*(last_token+i+4)=='e')
											check=0;
							return check;				
						}
						

						if((*(last_token+i)>='a' && *(last_token+i)<='z' ) || (*(last_token+i)>='A' && *(last_token+i)<='Z' )|| (*(last_token+i)>='1' && *(last_token+i)<='9')  || (*(last_token+i)=='*') || (*(last_token+i)=='+') || (*(last_token+i)=='-') ||(*(last_token+i)=='/')|| (*(last_token+i)==qoute) ){
						 //printf("%c \n",*(last_token+i));
						 //return 0;
						 check=1;
						 
						}

						//check=1;					
		}
return check;

}

int funcheck(char *last_token , int i){
	int check=0;
	i=i+1;
	
	if(*(last_token+i)=='i'){
		if(*(last_token+i+1)=='n')
			if(*(last_token+i+2)=='t')
				if(*(last_token+i+3)=='[')
					if(*(last_token+i+4)==" ")
							if(*(last_token+i+5)==']')
								check=1;
							return check;					
						}
	if(*(last_token+i)=='i'){
		if(*(last_token+i+1)=='n')
			if(*(last_token+i+1)=='t')
				if(*(last_token+i+2)==')')
					check=1;
			return check;
	}
	
	if(*(last_token+i)=='v'){
		if(*(last_token+i+1)=='o')
			if(*(last_token+i+2)=='i')
				if(*(last_token+i+3)=='d')
					if(*(last_token+i+4)==')')
					check=1;
			return check;		
	}
		if(*(last_token+i)=='i'){
			if(*(last_token+i+1)=='n')
				if(*(last_token+i+2)=='t')
					if(*(last_token+i+3)=='[')
						if(*(last_token+i+4)==" ")
							if(*(last_token+i+5)==']')
								if(*(last_token+i+6)=='[')
									if(*(last_token+i+7)==']')
										if(*(last_token+i+8)==')')
								check=1;
							return check;					
						}
						
						
	return check;					
}

//not halfway done
