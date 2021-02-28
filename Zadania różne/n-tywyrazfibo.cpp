/*
N-ty wyraz ciagu Fibonacciego
*/
#include <iostream>
using namespace std;
//iteracyjnie
int fib(int n) {
	if (n == 1) return 0;
	else if (n == 2) return 1;
	else {
		int w1 = 0;
		int w2 = 1;
		int i = 2;
		while (i < n) {
			int c = w1;
			w1 = w2;
			w2 += c;
			i++;
		}
		return w2;
	}
}
//rekurencyjnie
int fibreku(int n) {
	if (n == 1) return 0;
	else if (n == 2) return 1;
	else {
		return fib(n - 1) + fib(n - 2);
	}
}

int main() {
	cout << fib(5)<< endl;
	cout << fibreku(6);
}