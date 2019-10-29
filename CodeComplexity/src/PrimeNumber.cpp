/*
Problem Code : ISPRIME

In this lesson you will write 3 ways of how to find a prime number and then note down its performances.

Question : Given a number return 1 if its a prime number ,0 otherwise.

Dont try to over optimize soultion unless asked. Write bad code its okay. The purpose of this lesson is to learn
how bad code effects the time taken for running.

Observations: (Write down what you observed here):

Way 1 :It is taking too long to go through each number.

Way 2 :comlplexity is reduced square root.

Way 3:comlplexity is reduced square root by 2 .

Conclusion : even numbers are not primes and for odd numbers check only odd number division and till upto square root.
*/

#include <stdio.h>
#include <math.h>

/*
Divide the number with all elements from  1 to number and check whether its prime number or not.
Dont do any optimizations. Just write the brute force code.
*/
int isPrimeBruteForce(int number){

	if (number <= 1)return 0;
	for (int i = 2;i < number;i++) {
		if (number%i == 0)return 0;
	}
	return 1;
}

/*
Is checking division till number neccesary? 

You can do it just till half of number or even better just square root of n.

Divide the number with all elements from  1 to sqrt(number) and check whether its prime number or not.
Dont do any more optimizations.

Think why is it sufficient to do it till just square root of number.
*/
int isPrimeSquareRoot(int number){
	if (number <= 1)return 0;
	for (int i = 2;i <= sqrt(number);i++) {
		if (number%i == 0)return 0;
	}
	return 1;
}

/*
Add more optimizations you like, 
Like if a number is odd number you need not divide it with even numbers. etc.
*/
int isPrimeOptimized(int number){
	if (number == 2)return 1;
	if (number <= 1|| number % 2 == 0)return 0;
	for (int i = 3;i <= sqrt(number);i=i+2) {
		if (number%i == 0)return 0;
	}
	return 1;
}


