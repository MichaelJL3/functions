#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[]){
	//QUICK SORT USING CMD ARGS AND DISPLAY RUNTIME

	//basic variables
	srand(time(0));
	clock_t begin, end;
	double total;
	int n = 10, max = 10, i = 0;

	//cmd args
	if(argc>1)n = atoi(argv[1]);
	if(argc>2)max = atoi(argv[2]);

	//array for storing random number sequence for sorting
	//declared later for possible n cmd arg
	int num[n];

	//pseudo randomly generating n numbers between 0 and max
	for(; i<n; i++){
		num[i] = rand()%max+1;
		printf("%d: random number %d\n", i+1, num[i]);
	}

	puts("");
	//timing starts as well as actual sorting
	begin = clock();
	int pivot = 0, first = 1, last = n, i = 0;
	for(; i<n; i++){
		while(num[first]>num[pivot])
			first++;
		while(num[first])
	}
	end = clock();

	i=0;
	//prints number array
	for(; i<n; i++){
		printf("%d: numerical order %d\n", i+1, num[i]);
	}
	
	//display total runtime
	total = (double)(end - begin)/CLOCKS_PER_SEC;
	printf("\nTIME SPENT: %f\n", total);

	return 0;
}