/*   Napisać program obliczający pierwiastek całkowitoliczbowy z liczby naturalnej
korzystając z zależności 1+3+5+... = n^2.    (2n-1) */
#include <iostream>
using namespace std;
int pierwiastek(int x) { //25
	int suma = 0;
	int i;
	for (i = 1; i <= x; i=i+2) { 
			suma = suma + i; 
			if (suma > x) return (i - 1) / 2;
		}
	}

int main() {
	int x;
	cout << "Wpisz liczbe:";
	cin >> x;
	cout << "Pierwiastek calkowitoliczbowy z liczby " << x << " to " << pierwiastek(x);
	return 0;
}
