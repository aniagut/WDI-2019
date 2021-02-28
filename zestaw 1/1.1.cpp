// Znaleźć wyrazy początkowe zamiast 1,1 o najmniejszej sumie, aby w ciągu
//analogicznym do ciągu Fibonacciego wystąpił wyraz równy numerowi bieżącego roku.
#include <iostream>
using namespace std;
void pierwszewyrazy() {
int wyraz1, wyraz2, wyraz3;
for (int i = 2; i <= 2019; i++) {
	wyraz1 = i;
	while (j <= 2019) {
		wyraz2 = j;
		while (wyraz3 <= 2019) {
			wyraz3 = wyraz1 + wyraz2;
			wyraz1 = wyraz2;
			wyraz2 = wyraz3;
		}
		if (wyraz3 == 2019) {
			cout << i << endl;
			cout << j << endl;
			break;
		}
		else j++;
	}
}
int main() {
	pierwszewyrazy();
	return 0;
}

