/* Prabhjit Singh  
sorting using quick sort 
and its parition */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int B[], int, int);
void insertionSort(int B[], int);
int partition(int B[], int, int);
void printQuickSort(int B[], int);

int main()
{
	int A[1000]; // array for sorting
	int B[1000]; // copy of original array
	int n; // user input
	int i; // counter
	
	/* Clock Varibles */
	clock_t start_i;
	clock_t start_q;
	clock_t finish_i;
	clock_t finish_q;
	
	float second_i, second_q;
	printf("\t\t Lab 6 254 Inseration Sort and Quick Sort.\n");
	printf("\t\t<<---------------------------------------->>\n");
	// Scan in size of array
	printf("Please enter the size of the array A:\n");
	scanf("%d", &n);
	
	srand(time(NULL));
	
	// Filling array with random integers
	for(i = 0; i < n; i++)
	{
		A[i] = (rand() % 78) + 2;
	}
	
	// Printing Array
	printf("Original Randomized Array\n");
	printf("<<---------------------------------------->>\n");
	
	for(i = 0; i < n; i++)
	{
		printf("%d\t", A[i]);
	}
	
	// Making two arrays for sorting purposes
	for(i = 0; i < n; i++)
	{
		B[i] = A[i];
	}

	start_i = clock();
	
	// Insertion Sort Call
	insertionSort(A, n);
	
	finish_i = clock();
		
	printf("\n");
	
	start_q = clock();
	
	// Quick Sort Call
	quickSort(B, 0, n - 1);
	printQuickSort(B, n);
	
	finish_q = clock();
	
	// Time Calculations
	
	second_i = (float) (finish_i - start_i)/ CLOCKS_PER_SEC;
	second_q = (float) (finish_q - start_q)/ CLOCKS_PER_SEC;
	
	// Printing Time Calculations
	printf("<<---------------------------------------->>\n");
	printf("\nIt took %f amount of seconds to calculate (Insertion)\n ", second_i);
	printf("<<---------------------------------------->>\n");
	printf("\nIt took %f amount of seconds to calculate (Quick)\n", second_q);
	printf("<<---------------------------------------->>\n");
	
	// End program
	return 0;
}

void insertionSort(int A[], int n)
{
	int i, j, o; // temp
	int temp; // temp 
	
	//Starting at 2nd index to end of array
	for(i = 1; i < n; i++)
	{
		j = i;
		
		//Iterate and compare while it satisfies the condition
		while(j > 0 && A[j] < A[j - 1])
		{
			temp = A[j];
			A[j] = A[j - 1];
			A[j - 1] = temp;
			j--;
		}
	}
	
	// Printing insertion sort array
	printf("\n<<---------------------------------------->>\n\n");
	printf("\nInsertion Sort\n");
	
	for(o = 0; o < n; o++)
	{
		printf("%d\t", A[o]);
	}
	
}
	
void quickSort(int B[], int first, int last)
{	
	int r; //temp
	
	if(first < last)
	{
		r = partition(B, first, last);
		quickSort(B, first, r);
		quickSort(B, r + 1, last);
	}
}

int partition(int B[], int first, int last)
{
	int a, temp; //temp
	int lp; //left pointer
	int rp; //right pointer
		
	a = B[first];
	
	lp = first - 1;
	rp = last + 1;
	
	do{
		do{
			rp -= 1;
			
		  }while(B[rp] > a);
		
		do{
			lp += 1; 		
		  
		  }while(B[lp] < a);
		  
	    //swap
	    if(lp < rp)
	    {
	   		temp = B[lp];
	   		B[lp] = B[rp];
	   		B[rp] = temp;
	    }
	 
	  }while(lp < rp);
	
	return rp;
}

void printQuickSort(int B[], int n)
{
	int i;
	printf("<<---------------------------------------->>\n");
	printf("<<---------------------------------------->>\n");
	printf("Quick Sort\n");
	
	for(i = 0; i < n; i++)
	{
		printf("%d\t", B[i]);
	}
	
	printf("\n");
}
