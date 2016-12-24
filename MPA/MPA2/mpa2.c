#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//this will be allowed only for mpa2

int arr1[1000000], arr2[1000000], arr3[1000000];

void BubbleSort(int *, FILE *);
void SelectionSort(int *, FILE *);
void InsertionSort(int *, FILE *);
void timestamp();

int main(){
	

	int i,m,s;
	FILE *ifp, *fwrite1, *fwrite2, *fwrite3;

	ifp = fopen("numbers.dat", "r");
	fwrite1 = fopen("mbubble.out", "w");
	fwrite2 = fopen("mselection.out", "w");
	fwrite3 = fopen("minsertion.out", "w");

	 if( ifp == NULL )
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }


    for(i=0;(fscanf(ifp, "%d ",&m)==1);i++){
    	arr1[i]=m;
    	arr2[i]=m;
    	arr3[i]=m;
	}

		timestamp();
		BubbleSort(arr1,fwrite1);
		SelectionSort(arr2,fwrite2);
		InsertionSort(arr3,fwrite3);



    fclose(ifp);
    fclose(fwrite1);
    fclose(fwrite2);
    fclose(fwrite3);
	return 0;
}

void BubbleSort(int *ptr, FILE *fwrite1){
	int size=1000000;
	int temp,i,j;

	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(*(ptr+j)>*(ptr+j+1)){
				temp = *(ptr+j);
				*(ptr+j)=*(ptr+j+1);
				*(ptr+j+1)=temp;
			}
		}
	}

	for(i = 0; i < size; i++)
        fprintf(fwrite1,"%d ", *(ptr + i));
    timestamp();
}

void InsertionSort(int *ptr, FILE *fwrite2){
	int i,j,temp;
	int min = *ptr;
	int size=1000000;
	//int *ptrmin=&min;

	for(i=0;i<size;i++){
		for(j=i;j<size;j++){
			if(*(ptr+i)>*(ptr+j)){
				min=*(ptr+j);
				//locate =j;
				temp=*(ptr+j);
				*(ptr+j)=*(ptr+i);
				*(ptr+i)= temp;
		}

	}
	//	printf("\n");
		//for(x=0;x<size;x++){
		//printf("%d  ",ptr[x]);

	}

	for(i = 0; i < size; i++)
        fprintf(fwrite2,"%d ", *(ptr + i));
    timestamp();
	//getch();
}
void SelectionSort(int *ptr, FILE *fwrite3){
	int locate;
	int i,j,temp,z,smallIn;
	int min;
	int size=1000000;
	//int *ptrmin=&min;

	for(i=0;i<size;i++){
        min = *(ptr + i); //ito yung chinange ko na part
		for(j=i;j<size;j++){
			if(min >= *(ptr+j)){
				min = *(ptr+j);
				locate = j;
			}
		}

			printf("\n");

			//printf("min = %d temp = %d locate = %d\n" , min, temp,locate);
				//temp=min + temp;
				//min = temp-min;
				//temp = temp - min;
			//printf("min = %d temp = %d \n" , min, temp);
			if(i != locate)
            {
                temp=*(ptr+i);
                *(ptr+i)= min;
				*(ptr+locate)= temp;
            }

		//break;
		//for(z=0;z<size;z++){
		//printf("%d  ",ptr[z]);
	//}
	//getch();
	}

	for(i = 0; i < size; i++)
        fprintf(fwrite3,"%d ", *(ptr + i));
    timestamp();
}

void timestamp(){
    time_t ltime;
    ltime=time(NULL); 
    printf("%s",asctime( localtime(&ltime) ) );
}