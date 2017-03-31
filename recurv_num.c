/* 
Prabhjit Sing h
This program will reverse an number 
that is given, using iterative func
and a recursive fun
*/
#include<stdio.h>

 int ReverseDigits_Iterative(int);
 int ReverseDigits_Recursive(int); 

 int main (){
 	int V1;
 	printf("Enter an integer number in the range from 0 to 1 billion:");
 	scanf("%d", &V1);

 	printf("Iteration: the number with digits reversed is %d\n", ReverseDigits_Iterative(V1));
 	printf("Recursion: the number with digits reversed is %d\n", ReverseDigits_Recursive(V1));

 	return 0;
 }
 /* The reverseinteger function takes the unsigned input and it will as long as it is not zero it whil jump into the while loop and preform the divison operation on the int m for each iteration. And with each iteration the reverse, which is rev = rev + m%10. With this first step the int m is taken and the modoules of it by 10 each iteration. Then the result is added to rev which is then multiplied by 10 at each iteration --> rev = rev * 10. Therefore the new reverse number is built  up at each iteration a digit from the orginal number is added in reverse order. This process works properly when input is 1234 to give 4321, or even when the input has zeroes in it like 12001. The zeroes are still added to the rev order, so the 1 will be folled by the two zeors after the two iteration, since rev is added with m%10, adding zero to 1 and multiplying by 10 gives it 10, then multiplying the second time because the second zero making it 100. Then the rest is carried out normally to give 10021. 
If the number entered is zero then it does not jump in the while loop and the answer is just simply 0.  */
int ReverseDigits_Iterative(int a){
	int rev=0; 
	while (a !=0){ // while a isn't 0 we will divide and use modulus to get each digit 
		rev = rev * 10;
		rev = rev + a%10; 
		a = a/10; 

}
return rev; 
} /* The ReverseDigits_Recursive function will use a the base cases  as such:
If the entered number n equals zero then the function returns 0.
If its any other number then the number is recurvisely divdied by 10, while the retrun of t is built up after each modulus of n by 10. Then the rule of t= t * 10 is applied to build up the number and it is returned. */ 
int ReverseDigits_Recursive(int n){
static int t = 0;
 
   if (n == 0) 
      return 0;
 
   t = t * 10;
   t = t + n % 10;
   ReverseDigits_Recursive(n/10);
   return t;
}