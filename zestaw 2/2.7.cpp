#include <iostream>
#include <cmath>
using namespace std;
int main() {
	unsigned int n;
	int i;
	cout << "Podaj liczbe: ";
	cin >> n;
	for (i = sqrt(n); i >= 1; i--) {
		if (n % i == 0) break;
	}
	cout << n << " = " << i << "*" << n / i;
	return 0;
}
