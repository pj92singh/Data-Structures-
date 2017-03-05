//lab 5 254 
//Prabhjit Singh
//103180339 
//coin change 
//using greedy algo
#include<stdio.h>

int dyn(int input, int c1, int c2, int c3, int c4); 
int coin_dynamic(int A[], int input, int c1, int c2, int c3, int c4); 
int count( int S[], int m, int n ); 

int main(){
    //denomiations 
    int c1 = 1, c2 = 5, c3 = 10, c4 = 25, input; 

	int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 4;
    int A[100], j; 
   // printf(" %d ", count(arr, m, n));

                 //dynamic code ----------------fill in array 
                  for (j = 0; j < 100; j++)
                {
                  printf("For %d)\n", j);   
                  A[j] =  dyn(j, c1, c2, c3, c4); 
                 

                }


                printf("\t\tLab 5: Dynamic Coin Problem\n");
    printf("----------------------------------------------------------------\n");
    //--------------------------------
    //ask the user for input
    printf("\nPlease enter the amount you want change for:\n");
    scanf("%d", &input); 

    //if input iz less than zero there is no need for making change
        if(input <= 0){
            printf("\nNo change needed for the input since it is less than or equal to 0\n");

        }
        else{
                printf("...........\n");
                printf("Taking input and providing the best solutions:\n");
                printf("The change required is:\n");
                dyn(input, c1, c2, c3, c4); 
                //-------------------------------------------
                printf("----------------------------------------------------------------\n");
                printf("Dynamic run through:\n");
                coin_dynamic(A, input, c1, c2, c3, c4); 


            }

	return 0; 
}


int dyn(int input, int c1, int c2, int c3, int c4){

    int amount=0, c1_amount =0, c2_amount = 0, c3_amount = 0, c4_amount = 0; 
    int remainder_3, remainder_4, remainder_5; 
    //----------------------------------------
    //----------------------------------------
    if(input == 1)
    {
        c1_amount = 1; 
        printf("Number of pennies needed are %d\n", c1_amount);
        return c1; 
    }
    //----------------------------------------
    if(input > 1 && input < 5)
    {
        do{
           
            c1_amount++; 
        }while(c1_amount != input); 

        printf("You need %d pennies for your change!\n", c1_amount); 
    }

    //----------------------------------------
    if(input == 5)
    {
        c2_amount = 1; 
         printf("Number of nickles needed are %d\n", c2_amount);
        return c2; 
    }

    //----------------------------------------
    if(input > 5 && input < 10)
    {
        c2_amount = 1; 
        
        // 9 - 5 = 4 ( 4 pennies)

        // 6 - 5 = 1 
        c1_amount =  input - c2; 

        printf("You need %d nickle(s) and you need %d pennies\n", c2_amount, c1_amount);

    }

    //----------------------------------------
    if(input == 10)
    {
        // 10 cents 
        c3_amount = 1; 
         printf("Number of dimes needed are %d\n", c3_amount);
        
    }
    //----------------------------------------
    if(input > 10 && input <= 19)
     {
         //minimum of 10 cents max of of 20 cents therefore 2 dimes, therefore minimum amount of dimes needed are 1 
            c3_amount = 1; 
                
            // 15 - 10 = 5
            remainder_3 =  input - c3; 

                            if(remainder_3 < 5)
                            {
                              c1_amount = remainder_3 * c1; 

                              printf("You need %d dimes and you need %d pennies\n", c3_amount, c1_amount);
                           
                            }

                            else if(remainder_3 >= 5)
                            {
                                printf("You need %d dimes and also,\n", c3_amount); 
                                input = remainder_3; 
                                dyn(input, c1, c2, c3, c4); 


                            }


                        

                       // printf("You need %d dimes and you need %d pennies\n", c3_amount, c1_amount);
    }

    
    //----------------------------------------
     if(input >= 20 && input < 25)
    {
         //minimum of 10 cents max of of 20 cents therefore 2 dimes, therefore minimum amount of dimes needed are 1 
         c3_amount = 2; 
         //24 - 20 = 4
        remainder_4 = input - (2 * c3); 

        printf("You need %d dimes and also,\n", c3_amount); 
        //printf("test %d\n", remainder_4);
        //input = remainder_4; 
        dyn(remainder_4, c1, c2, c3, c4); 



    }
    //----------------------------------------
    if(input == 25)
    {
        c4_amount = 1; 
         printf("Number of quarters needed are %d\n", c4_amount);
       
    }
    //----------------------------------------
    if(input > 25)
    {
        c4_amount = 1; 
        //31 - 25 = 6
        //75-25 = 50 
        remainder_5 = input - c4; 
         printf("Number of quarters needed are %d\n", c4_amount);

          dyn(remainder_5, c1, c2, c3, c4); 

            

    }
    

    return 0; 
}
//--------------------------------------------------------------------
int coin_dynamic(int A[], int input, int c1, int c2, int c3, int c4){
    
        if (A[input] != 0){
            // printf("%d\n", A[input]);
          return A[input]; 
         }

        int t=input ;
        if (input < 0){
                //printf("0");
                return 0; 
        }
        else if (input > 1){
                   t = dyn(input, c1, c2, c3, c4);
                //  printf("%d\n", A[input] = t);
                   return A[input] = t; 
        }

    
    return 0;
}

/*
int count( int S[], int m, int n )
{
    int i, j, x, y;
 
    // We need n+1 rows as the table is consturcted in bottom up manner using 
    // the base case 0 value case (n = 0)
    int table[n+1][m];
    
    // Fill the enteries for 0 value case (n = 0)
    for (i=0; i<m; i++)
        table[0][i] = 1;
 
    // Fill rest of the table enteries in bottom up manner  
    for (i = 1; i < n+1; i++)
    {
        for (j = 0; j < m; j++)
        {
            // Count of solutions including S[j]
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0;
 
            // Count of solutions excluding S[j]
            y = (j >= 1)? table[i][j-1]: 0;
 
            // total count
            table[i][j] = x + y;
        }
    }
    return table[n][m-1];
} 
    */ 
