#include <iostream>
using namespace std;
void doskonale() {
	for (int i = 1; i < 1000000; i++) {
		int suma = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				suma = suma + j;
			}
		}
		if (suma == i) {
			cout << i << endl;
		}

	}
}
int main() {
	cout << "Liczby doskonale mniejsze od milliona:" << endl;
doskonale();
	return 0;
}