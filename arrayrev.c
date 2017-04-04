//Prabhjit Singh
//pj92singh 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

/* this program takes an int size n
    for an array then allocates an array of that size
    and takes in input from user to fill it up
    then prints out the array from the last spot to
    the first spot (reverse)
*/ 

int main(){
    int n, i, j; 
    //scan size of array
    scanf("%d",&n);
    //allocate an array of that size 
    int *arr = malloc(sizeof(int) * n);
    printf("%d\n", n); 
    //put the numbers in the array
    for(j=0; j<n; j++){
        scanf("%d", arr[j]); 
    }
    //print out the array in reverse 
    for(i=(n-1); i >= 0; i--){
        printf("%d ", arr[i]); 
    }
    return 0;
}