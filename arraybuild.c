/* 
Array builder and serach
Prabhjit Singh
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h> 

#define M 6 // given base case of number of columns 
#define N 5 // given base case of number of rows 
#define RANDMIN 15 //Minimum value of the random numbers
#define RANDMAX 75 //Maximum value of the random numbers

//function prototypes 
void PrintArray2D(int A[][N], int num_rows, int num_columns);
void PopulateRandom2D(int A[][N], int num_rows, int num_columns, int rmin, int rmax); 
void LinearSearch2D(int A[][N], int num_rows, int num_columns, int numfind);
void LeftShift2D(int A[][N], int num_rows, int num_columns); 


int main(){
	
	int i, j, pick; //pick for the menu for options
	int A[M][N]; // original array
	int copyA[M][N];//copied array 
	int numfind; //the variable for which number to find in the array


    do{ 
/* Each case switch case will allow the user to jump into the preffered function they want to use. 
From getting a random array, to finding a number in the arrary and then last being the left shift before the exit option. If an invlaid input is given the menu starts over again after letting the user know they have inputted an invalid option. */

    printf("Choose which function to call: \n 1. Randomized Array  \n 2. Find a number in Array \n 3. Left shift Array \n 4. Exit \n"); 
    scanf("%d", &pick);
        switch(pick){
            case 1:
                    /*Option 1 where we populate the array with random integers between the max and min values and we print out the array using the printarray2d function*/
                    PopulateRandom2D(A, M, N, RANDMIN, RANDMAX);

                    //Print the array
                    printf("Randomized array:\n");
                    PrintArray2D(A, M, N);
                    
            
                break; 

            case 2:
                     /*Option 2, Search the array for a number inputted by the user using linear search */
                    printf("Please enter a value to seach for: ");
                    scanf("%d", &numfind);
                    LinearSearch2D(A, M, N, numfind);

                    //Copied the array and we search it and work with this instead of the orginal
                    for(i = 0; i < M; i++)
                        for(j = 0; j < N; j++)
                            copyA[i][j] = A[i][j];
                break;
           
            case 3:

				    /*Option 3: Left shifting the array */
				    LeftShift2D(copyA, M, N);

				    //Printing the shifted array
				    printf("Your LEFT shifted array is:\n");
				    PrintArray2D(copyA, M, N);

                return 0;
                break; 

             case 4:
				return 0;
				break; 
			default:
				printf("Invalid option!\n"); 
		}	
	}while (pick != 4);
// exiting the while loop 
          
	return 0; 
}
/*PopulateRAndom2D function, populates the array between the max and minium values, also between the default number of rows and columns. */
void PopulateRandom2D(int A[][N], int num_rows, int num_columns, int rmin, int rmax) {
    int row, col;

    // intializing the random function to genereate numbers
    srand(time(NULL));

    for (row = 0; row < num_rows; row++) {
        for (col = 0; col < num_columns; col++) {
            A[row][col] = rmin + rand() % (rmax - rmin + 1);
        }
    }
}
/*PrintArray2D function spits out an array that is confined to number of rows and columns from left to right. */
void PrintArray2D(int A[][N], int num_rows, int num_columns) {
    int row, col;

    for (row = 0; row < num_rows; row++) {
        for (col = 0; col < num_columns; col++) {
            printf("%10d", A[row][col]);
        }
        printf("\n"); //starts a new line after each row to begin the next new row
    }
    printf("\n"); // adds a blank line between each printout
}
/*LinearSearch2D: searches an array for the number that is specifed by the user(numfind). The Linear search method is applied below to find the number*/
void LinearSearch2D(int A[][N], int num_rows, int num_columns, int numfind) {
    int row, col;
    int found = 0;

    for (row = 0; row < num_rows; row++) {
        for (col = 0; col < num_columns; col++) {
            if (A[row][col] == numfind) {
                /* letting the user know the number is found in what row/column and if it has multiple copies we let them know where else the number is located. */
                printf ("Value %d was found at Row %d, Column %d).\n", numfind, col+1, row+1);
                found = 1;
            }
        }
    }
    // if the number is not found we must let the user know
    if (!found)
        printf ("Sorry the value you entered (%d) was not found.\n", numfind);
}

/*LeftShift2D function moves each element in the array to the left and also wraps around the first element to the last position. Using 2 for loops to start shifting the rows and then continuning each column to the left. */
void LeftShift2D(int A[][N], int num_rows, int num_columns) {
    int firstValue;
    int row, col;

    // the first number will be moved to the last 
    firstValue = A[0][0];

    // start shifting from the first row
    for (row = 0; row < num_rows; row++) {

        // shift each column to the left
        for (col = 0; col < num_columns-1; col++) {
            //shift left
            A[row][col] = A[row][col+1];
        }

        /*shift the first number of the next row, and to the last position of this next row. But skip this action for last row. */ 
        if(row < num_rows-1)
            A[row][num_columns-1] = A[row+1][0];
    }

    /* The important part of copying the old first value to the last position therefore we do not lose this number */ 
    A[num_rows-1][num_columns-1] = firstValue;
}
