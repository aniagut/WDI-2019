#include <iostream>
using namespace std;
int fib(int n) {
	int fib1 = 1;
	int fib2 = 1;
	for (int i = 3; i <= n; i++) {
		int c = fib1;
		fib1 = fib2;
		fib2 += c;
	}
	return fib2;
}
bool czyjest(int x) {
	for (int m = 0; m < x; m++) {
		for (int n = m; n < x; n++) {
			if (fib(m) * fib(n) == x) return true;
		}
	}
	return false;
}
int main() {
	int x;
	cin >> x;
	cout << czyjest(x);
}