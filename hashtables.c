/*  
	pj92singh
	Prabhjit Singh 
	Hash tables and probing,
	taking in a lower bound and random integers 

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include  <sys/types.h>

//global 
int wait_int = 1; 


//functions 
int findPrime(int);
int isPrime(int);
int nextPrime(int num); 
int insert_in_array(int A[], int num, int temp); 
int quadratic(int B[], int num, int temp); 
int count, count_quad; 
int main()
{
	int temp, i, j; // temps
	float alpha; // load factor
	float lowerBound;
	
	printf("Please enter the load factor from 0.1-0.9\n");
	scanf("%f", &alpha);
	if(alpha >=1 || alpha == 0){
		do{
			
				printf("ERROR!! Please enter the load factor LESS than 1!!!!\n");
				scanf("%f", &alpha);
		
		}while(alpha >=1 || alpha == 0); 
	} 
	
	lowerBound = 10000/alpha;
	
	temp = findPrime(lowerBound);
	
	int A[temp], B[temp]; // array
	
	printf("Please wait scaning in random integers\n");
	
	srand(time(NULL));
	//-----------------------------------
	//for linear
	for(i = 0; i < 10000; i++)
	{
		//using insert to array function 
		//to fill up the array
		insert_in_array(A, (rand() % 997) - 500, temp);
	}
	//------------------------------------
	//for quadratic 
	for(i = 0; i < 10000; i++)
	{
	quadratic(B, (rand() % 997) - 500, temp);
	}
	//wait(&wait_int); 
	printf("******Scaning complete******\n");
	

	printf("\t %d (linear) \t %d (quad)\n",count, count_quad );



	return 0;	
}
int findPrime(int lowerBound)
{
	int i;
	
	for(i = lowerBound; 1; i++)
	{
		if(isPrime(i))
		{
			return i;
		}
	}
	
	return 0;
}
int isPrime(int num)
{
	int i;
	
	for(i = 2; i < num; i++)
	{
		if(num % i == 0)
		{
			return 0;
		}	
	}
	
	return 1;
}
int nextPrime(int num){

	int c;
    if (num == 2)
        c = 3;
    else
    {
        num += 2;
       c =  isPrime(num) ? nextPrime(num) : num;
    }

    return c;
}
int insert_in_array(int A[], int num, int temp){

int i; 

for(i=num; 1 > 0; i = i+1 % temp){

	count++; 
	if (A[i] == 0){
		A[i] = 1; 
		
		return count; 
	}
	

}

//printf("The number of probes of linear %d\n", count);
return 0; 
}

int quadratic(int B[], int num, int temp){
int h; 
h = num % temp; 
int n=2, i;
int index=h;
for (i=1;i < temp; i = i*i % temp)
{
	count_quad++; 
	if(B[index] == 0){
		B[index] = 1; 
		break; 
	}
	else{
		index = (h+i*i)%temp;
	}

	return count_quad; 
}
//printf("The number of probes of quadratic %d\n", count_quad);
return 0; 
}