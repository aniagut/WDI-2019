/*
Zad. 2. Dana jest tablica int t[N][N] zawierająca liczby naturalne. Proszę napisać funkcję, która sprawdza czy z tablicy
można usunąć jeden wiersz i dwie kolumny, tak aby każdy z pozostałych elementów tablicy w zapisie dwójkowym
posiadał nieparzystą liczbę jedynek.
*/
#include <iostream>
using namespace std;
const int N = 5;
bool warunek(int n) {
	int ilosc = 0;
	while (n > 0) {
		if (n % 2 == 1) ilosc++;
		n /= 2;
	}
	if (ilosc % 2 == 0) return false;
	else return true;
}
bool czyDasie(int t[N][N]) {
	for (int i = 0; i < N - 1; i++) {
		for (int j = i; j < N; j++) {
			for (int k = 0; k < N; k++) {
				int k1 = i;
				int k2 = j;
				int w1 = k;
				bool flag = true;
				for (int w = 0; w < N; w++) {
					for (int kol = 0; kol < N; kol++) {
						if (w != w1 && kol != k1 && kol != k2) {
							if (!warunek(t[w][kol])) flag = false;
						}
					}
				}
				if (flag) return true;
			}
		}
	}
	return false;
}
int main() {
	int t[N][N] = { {3,3,3,3,2}, {2,3,3,2,2}, {2,2,3,2,2}, {2,3,2,2,2}, {2,2,3,2,2} };
	cout << czyDasie(t);
}