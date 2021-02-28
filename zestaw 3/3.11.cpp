#include <iostream>
using namespace std;
/*
Napisać funkcję, która dla tablicy int t[MAX] wypełnionej
liczbami naturalnym wyznacza długość najdłuższego, spójnego
podciągu arytmetycznego.
*/
const int MAX = 15;
int dlugoscciaguaa(int tab[MAX]) {
	int dlugosc = 0;
	for (int i = 0; i < MAX; i++) {
		bool flag = true;
		int roznica = tab[i + 1] - tab[i];
		int j = i + 2;
		int dlugosc1 = 2;
		while (j < MAX && flag) {
			if ((tab[j] - tab[j - 1]) == roznica) {
				j++;
				dlugosc1++;
			}
			else flag = false;
			if (dlugosc1 > dlugosc) dlugosc = dlugosc1;
		}
	}
	return dlugosc;
}
	int main() {
		int tab[15] = { 1,2,78,34,51,62,5,81,9,10,1,12,1,14,10 };
		cout << dlugoscciaguaa(tab);
	}