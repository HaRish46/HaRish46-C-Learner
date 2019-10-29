/*

Here you will be doing the same ArraysQuestion you did before, but now in multiple ways.

OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7]
INPUTS: An Integer N
OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)
ERROR CASES: Return NULL for invalid inputs
Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}

Observations: (Write down what you observed here):

Way 1 :It is taking too long to go through each number.

Way 2 :comlplexity is reduced as no prime number can be even except 2.

Way 3:A given number is prime if it is not divided by any prime less than that.
Conclusion :
*/

#include <stdio.h>
#include <math.h>
#include<stdlib.h>


/*

Manually loop over every element, Find if its prime or not. Store it in an array.
Write the worst complexity code you can write :D.
*/
bool isprime(int n) {
	for (int i = 2;i <= sqrt(n);i++)
		if (n%i == 0)
			return false;
	return true;
}
int* nPrimeBruteForce(int N)
{
	if (N <= 1)return NULL;
	int *a = (int *)malloc(sizeof(int));
	int i = 1;
	int b = 3;
	a[i - 1] = 2;
	while (b<=N) {
		if (isprime(b)) {
			a = (int*)realloc(a,(i+1)*sizeof(int));
			a[i] = b;
			i++;
		}
		b++;
	}
	return a;
}


/*
Remove even numbers, Run it again.
Just remove even numbers. So it should essentially take half of time for function 1, Did it really happened?

*/
int* nPrimeEvenRemoved(int N)
{
	if (N <= 1)return NULL;
	int *a = (int *)malloc(sizeof(int));
	int i = 1;
	int b = 3;
	a[i - 1] = 2;
	while (b <= N) {
		if (isprime(b)) {
			a = (int*)realloc(a, (i + 1) * sizeof(int));
			a[i] = b;
			i++;
		}
		b+=2;
	}
	return a;
}

/*
Do all optimizations you can think of.

Hint : 
A number can be considered a prime, if its not divisible by any of the primes which are less than it.
ie 100 can be considered as a prime, if no prime number which is less than 100 divides 100 (With remainder as 0).
7 is prime as no prime less than it (2,3,5) can divide it. Think proof for this too.

This heavily reduces the number of divisions you do. If you did correctly you should see some heavy difference in timings.

*/
bool isprimeOpt(int*a,int m,int n) {
	for (int i = 0;i <m;i++)
		if (n%a[i] == 0)
			return false;
	return true;
}
int* nPrimeOptimized(int N)
{
	if (N <= 1)return NULL;
	int *a = (int *)malloc(sizeof(int));
	int i = 1;
	int b = 3;
	a[i - 1] = 2;
	while (b <= N) {
		if (isprimeOpt(a,i,b)) {
			a = (int*)realloc(a, (i + 1) * sizeof(int));
			a[i] = b;
			i++;
		}
		b += 2;
	}
	return a;
}