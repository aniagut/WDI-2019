#include <iostream>
using namespace std;
void zaprzyjaznione() {
	for (int i = 1; i < 1000000; i++) {
		int suma = 0;
		for(int j=1; j<i;j++) {
			if (i % j == 0) suma = suma + j;
		}
		int suma1 = 0;
		for(int k=1;k<suma;k++) {
			if (suma % k == 0) suma1 = suma1 + k;
		}
		if ((i == suma1) && (i != suma) && (suma > i)) {
			cout << i << " " << suma << endl;
		}
	}
}
int main() {
	cout << "Liczby zaprzyjaznione mniejsze od miliona to:" << endl;
	zaprzyjaznione();
}