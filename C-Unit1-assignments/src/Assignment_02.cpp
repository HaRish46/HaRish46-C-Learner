
//
// Compute factorial of a given positive integer
// 0 <= n <= 100
//
// return value         - number of digits in n!
// factorialDigits[158] - digits of n!
//

int digits(int n) {
	//printf("%d di \n", n);
	int l = 0;
	while (n) {
		n /= 10;
		l++;
	}
	return l;
}
void shift(int n, int l, int factorial[]) {
	//printf("shift %d %d \n", n, l);
	for (int i = l - 1;i >= 0;i--) {
		factorial[i + n] = factorial[i];
	}
}
int factorialOfN(int n, int factorialDigits[158]) {
	for (int k = 0;k < 158;k++)factorialDigits[k] = 0;
	factorialDigits[0] = 1;
	if (n == 0 || n == 1)return 1;
	int l = 0;
	int i = 0;
	int j;
	int p = 0, c = 0;
	while (n) {
		i = l;
		while (i >= 0) {
			c = factorialDigits[i] * n + c;
			factorialDigits[i] = c % 10;
			c = c / 10;
			int d = digits(c);
			if (i == 0) {
				i += d;
				i--;
				if (d>0)
					shift(d, l, factorialDigits);
				l += d;
				while (i >= 0) {
					factorialDigits[i--] = c % 10;
					c /= 10;
				}
			}
			i--;
		}
		n -= 1;
	}
	return l + 1;
}
//
// recamán’s sequence: "subtract if you can, otherwise add"
//
// a(0) = 0; for n > 0, a(n) = a(n-1) - n if positive and
// not already in the sequence, otherwise a(n) = a(n-1) + n.
//
// http://oeis.org/A005132
//
// Write a function to find the first n numbers in this sequence
// n >= 0
//
// e.g:
// 0 => {0}
// 2 => {0, 1, 3}
// 5 => {0, 1, 3, 6, 2, 7}
//
// Note:
// The sequence will contain (n + 1) terms.
//
void recamanSequence(int n, int sequence[]) {
	sequence[0] = 0;
	
	int a[500] = { 0 };
		int x;
	for (int i = 1;i <= n;i++) {
		x = sequence[i - 1];
		if ((x - i) > 0 && a[x - i] == 0) {
			sequence[i] = x - i;
			a[x - i] = 1;
		}
		else {
			sequence[i] = x + i;
			a[x + i] = 1;
		}
	}

}
