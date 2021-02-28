#include <iostream>
using namespace std;

bool czyjestiloczynem(int n) {
	int fib[31];
	fib[0] = 0;
	fib[1] = 1;
	for (int j = 2; j <= 31; j++) {
		fib[j] = fib[j - 1] + fib[j - 2];
	}
	for (int i = 0; i <= n; i++) {
		if (fib[i] * fib[i+1] == n) {
			return true;
			break;
		}
	}
	return false;
}
	int main() {
		int n;
		cout << "Wpisz liczbe:";
		cin >> n;
		if (czyjestiloczynem(n) == 0) {
			cout << "Nie jest " << endl;
		}
		else {
			cout << "Jest" << endl;
		}
	}