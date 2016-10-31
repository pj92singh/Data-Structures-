//Lab 4 254 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//fn protype
int fibo(int);
int fibo_recu(int);
int fibo_dynamic(int A[], int l); 

int main(){
	//variables
    int generate, b=0, indent=1, j;
    int A[100]; 

  //clock variables 
     clock_t start_i; 
     clock_t start_r; 
     clock_t start_d; 
     clock_t finish_i; 
     clock_t finish_r; 
     clock_t finish_d; 
  float sec_i, sec_r, sec_d; 

    //dynamic code ----------------fill in array 
      for (j = 0; j < 48; j++)
    {
         
      A[j] = fibo(j);
     

    }

    //testing and priting array 
    printf("Printing the array!\n");
    //print array A 
    int p; 
    for(p = 0; p < 48; p++){
      printf("%d\t",A[p]);
      
    }
    
    printf("\n");
	   //menu
	printf("\n\t254 Fibonacci program!\t\n");
    printf("<----------------------------------------->\n");
	printf("\nIt will run in 3 ways, recusivly, iterative and dynamically\n\n");
    printf("<------------------------------------------->\n");
    
    for(generate = 0; generate < 16; generate++)
    {
        //b = rand() % 99 + 1;
      
      	//first run recursive
      //----------------------------------
          printf("%d)\t\n", indent);
            start_r = clock();
          printf("For input %d, the fibonacci is:\n", b);
      	printf("Recursive run through:\n");
            
      	printf("%d\n\n",fibo_recu(b));
        finish_r = clock();
           sec_r = (float)(finish_r - start_r) / CLOCKS_PER_SEC; 
        printf("It took %f amount of seconds to calculate\n", sec_r);
        //----------------------------------
          //run iterative
          start_i = clock();
      	printf("Iterative run through:\n");
          
      	printf("%d\n\n",fibo(b));
        finish_i = clock();
          sec_i = (float)(finish_i - start_i) / CLOCKS_PER_SEC;
         printf("It took %f amount of seconds to calculate\n", sec_i);
         //----------------------------------

          //run dynamic
          start_d = clock();
      	printf("Dynamic run through:\n");
        
        printf("%d\n", fibo_dynamic(A, b));  
          finish_d = clock();
          sec_d = (float)(finish_d - start_d) / CLOCKS_PER_SEC;
          printf("It took %f amount of seconds to calculate\n", sec_d);
          printf("---------------------------\n\n");
              //update 
              indent++;
              ++b; 

    }

  

	return 0; 
}

/* Looking athe fibonacci function we based this function off the following: 
Fibonacci(0) = 0;
Fibonacci(1) = 1;
Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2); Requirement: n >= 0
Therefore had to create variables numminus1 and numminus2 to be used since we cannot use recursion!
For input  */
int fibo(int l){
	if (l<2) return l; 


	int q; 
	int num_termminus1 = 1;
	int num_term_minus2 = 0;
	int num; 

	for (q =2; q <=l; q++){
		num = num_termminus1 + num_term_minus2;
		num_term_minus2 = num_termminus1;
		num_termminus1 = num;
	}

	return num; 

}
//recursive 
int fibo_recu(int l){
	if (l<=0) {
		return 0;
}
	 if (l==1){
		return 1; 
}
	 if (l>1) {
		return  (fibo(l-1) + fibo(l-2));
}
return 0; 
}
int fibo_dynamic(int A[], int l){
    
      	if (A[l] != 0){
      	    // printf("%d\n", A[l]);
          return A[l]; 
      	 }

        int t=l ;
        if (l < 0){
                //printf("0");
                return 0; 
        }
        else if (l > 1){
                   t = fibo(l-1) + fibo(l-2);
                //  printf("%d\n", A[l] = t);
                   return A[l] = t; 
        }

	
    return 0;
}

/* calculating seconds 
int calc(){
  clock_t start; 
  clock_t finish; 
  float sec; 

  start = clock();
  finish = clock();

  sec - (float)(finish - start) / CLOCKS_PER_SEC; 
  printf("It took %f amount of seconds to calculate\n", sec);



} */ 