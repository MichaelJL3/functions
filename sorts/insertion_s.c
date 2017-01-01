#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]){
	//INSERTION SORT PROGRAM SORTS AN ARRAY OF INTEGERS THAT 
	//ARE RANDOMLY GENERATED AND CALCULATES RUNTIME

	//basic variables
	clock_t begin, end;
	double time_spent;
	srand(time(0));
	int n = 10, max = 10, i=0;

	//cmd args
	if(argc>1)n=atoi(argv[1]);
	if(argc>2)max=atoi(argv[2]);

	//n can have a default or be defined through cmd args it is
	//the variable that determines the amount of random numbers to 
	//generate and sort
	int num[n];

	//generating pseudo random numbers
	for (;i<n; i++){
		int random = rand()%max+1;
		num[i]=random;
		printf("%d: next number is %d\n",i+1, random);
	}
	puts("");

	//begins the sequence of sorting clock starts now
	begin = clock();
	i=0;
	for(;i<n-1; i++){
		int j=i, key = num[i+1];
		if(num[i]>key){
			num[i+1] = num[i];
			num[i] = key;
			while(j>0 && num[j]<num[j-1]){
				key = num[j-1];
				num[j-1]=num[j];
				num[j] = key;
				j--;
			}
		}
	}
	end = clock();
	//process completed clock ends

	//all sorted items are now listed
	i=0;
	for (;i<n; i++){
		printf("%d: numerical order %d\n",i+1, num[i]);
	}

	//time is now calculated based on sorting the returned
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTIME SPENT: %f", time_spent);

	return 0;
}