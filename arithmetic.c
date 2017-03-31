/* Recurisve functions
Prabhjit Singh
*/ 

#include<stdio.h> 
/* 
Declaring function prototypes,
 for summation, factorial and fibo 
 each take on int as input, 
 while gcd and power take two int inputs
  */ 
int sum(int);
int fact(int);
int fibo(int);
int gcd(int, int);
int power(int, int);


int main(){
 	int n1, n2, pick;

do{ 
/* Each case switch case will allow the user 
to jump into the preffered function they want to use. 

Summation, Factorial and Fibonacci use one number as input,
while GCD, power use two numbers as input. 
And input is a postive number! If an invlaid input is given 
for the functions then the program will tell the user it
is an invalid input, so a negative number will
 give an invalid print statement. 

If any of the inputs are less than 0 then
 in any case it will print out the 
"Invalid input and let the user know"
If the right input is given then the
 order follows as the menu. 
 1 Summation 2 Factorial 3 Fibonacci 4. GCD 
 5. Power and 6 Exits the program!
 */
 
	printf("Choose which function to call: \n 1. Summation  \n 2. Factorial \n 3. Fibonacci \n 4. GCD-Greatest Common Denominator \n 5. Power \n 6. Exit\n"); 
	scanf("%d", &pick);
		switch(pick){
			case 1:
				printf("Enter the number you want the Summation of\n");
				scanf("%d", &n1); 
				if (n1<0){
					printf("Invalid input! Please put in a postive number! \n");
				}
				else if (n1>0){
					printf("The Summation of the %d is %d \n", n1, sum(n1));
				}
				break; 
			case 2:
				printf("Enter the number you want the Factorial of\n");
				scanf("%d", &n1); 
				if (n1<0){
					printf("Invalid input! Please put in a postive number! \n");
				}
				else if (n1>0){
					printf("The Factorial of the %d is %d \n", n1, fact(n1));	
				}
				break;
			case 3:
				printf("Enter the number you want the Fibonacci of\n");
				scanf("%d", &n1); 
				if (n1<0){
					printf("Invalid input! Please put in a postive number! \n");
				}
				else if (n1>0){
					printf("The Fibonacci of the %d is %d \n", n1, fibo(n1));
				}
				break; 
			case 4: 
				printf("Enter the two numbers you want the Greatest Common Denominator of\n");
				scanf("%d %d", &n1, &n2);
				printf("The Greatest Common Denominator of %d and %d is %d \n", n1, n2, gcd(n1, n2));
				break; 
			case 5:
				printf("Enter the number and then the power \n");
				scanf("%d %d", &n1, &n2);
				printf("The answer of %d to the power %d is %d \n", n1, n2, power(n1, n2)); 
				break; 
			case 6:
				return 0;
				break; 
			default:
				printf("Invalid option!\n"); 
		}	
	}while (pick != 6);

return 0; 
} 


int sum(int n1){// declaring summation function which uses a postive input
/*(n+1)/2 is what this summation function is based on. So for the input of 3 This means 1+2+3 = 6 Therefore summation of 3 is 6. With recursive call the function keeps doing the sum(n1-1) part until it reaches zero. */ 	
	if (n1 <= 0){
		return 0;
}
	else {
		return n1 + sum(n1-1); 
}

}
/* Declaring the factorial function which requires a postive input 
and based on the following :
Factorial(0) = 1;
Factorial(n) = n * (n-1) * . . . * 2 * 1 Requirement: n >= 0
the follwing function works in an iretative way to find the factorial.
example factorial of 3. since 3*2*1 = 6.
With the function using recurvise, it keeps doing the recursion in the d * fact(d-1); section until it zero, then it knows it has gone through the input's factorials. 
 */ 		 

int fact(int d){
	if (d<=0){
		return 1;
}
	else{
		return d *fact(d-1);  
}
}

/* Looking athe fibonacci function we based this function off the following: 
Fibonacci(0) = 0; this is the first case therefore return is 0! 
Fibonacci(1) = 1; this is the next case therefore retrun is 1! 
Using recrusive call, so whatever the input is we use that in the function and minus 1 add it with minus 2 and return that as long as it follows the following: 
Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2); Requirement: n >= 0 
*/
int fibo(int l){
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

/* GCD is based off of the following:
gcd (x, y) = x, if y=0	 thats why in the code we return t! 	
gcd (x, y) = gcd (y, x MOD y), 
if y > 0 
Follwoing this just use y  (t % y)  */ 
int gcd(int t, int y){
	if ( y <= 0){
	return t; 
}
	if ( y > 0 ){
		return gcd(y, t % y); 
		
	}
return 0; 
}	

/*In the first if statement we are bascially setting a base case when the power is equal to 0 and the power function will return 1. If the power you entered is 1 then the answer is just the int a, because anything to the power 1 is just the number. 
Now using recursive call if the power is anything else, we just call the it in the power function so  if tis 2 to the power of 3. 
it goes via a * power(a, b-1) 
			=2 * power(2, 3-1) 
			=2 * power (2, 2)
			=2 * 4 
			=8*/ 

int power(int a, int b)
{
	if (b == 0){
   return 1; 
}
	if (b == 1){
		return a;
	}
	if (b>1)
	{
		return  a * power(a, b-1);  
	}
	return 0; 
} 
