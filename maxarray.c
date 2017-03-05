//Lab 9 60- 254 
// Prabhjit Singh
/* finding a row with the most 
*  number of ones in it 
*  in this case we made a predtermined array 
*  to test it on 
*/

#include <stdio.h>
#include <math.h> 


int main(){

	int rowSize = 4, columnSize = 4;
	int A[4][4]; 
// The Array
/* 	1100
	1000
	1110
	1111
*/
	
//1100
	A[0][0] = 1; 
	A[0][1] = 1; 
	A[0][2] = 0;
	A[0][3] = 0;
//1000	
	A[1][0] = 1;
	A[1][1] = 0;
	A[1][2] = 0;
	A[1][3] = 0;
//1110
	A[2][0] = 1;
	A[2][1] = 1;
	A[2][2] = 1;
	A[2][3] = 0;
//1111
	A[3][0] = 1;
	A[3][1] = 1;
	A[3][2] = 1;
	A[3][3] = 1;

printf("---------------60-254 Lab 9------------\n\n");
printf("Given array:\n\n");
//printf("\n \t1100\n \t 1000\n \t 1110\n \t 1111\n");
printf("Index||\t || Array ||\n");
int i, j, num=0; 
for(i=0; i<rowSize; i++){

	printf("(%d)\t",num);
		num++; 

	for(j=0; j<columnSize; j++)

	{

	printf("%d\t",A[i][j]);

	}
	printf("\n");

}

int maxrow = 0;
int row = 0, column = -1;
while (column < columnSize && row < rowSize ){
if (A[row][column + 1] == 1) {column++; maxrow = row;} else row++;
}
printf("\nMax number of 1’s is in row %d \n", maxrow);







	return 0; 
}
