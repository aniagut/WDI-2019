/*
Zad. 1. Dane są dwie tablice int t1[N], int t2[N] wypełnione liczbami naturalnymi. Proszę napisać funkcję, która
sprawdza czy z każdej z tablic można wyciąć po jednym kawałku, tak aby suma elementów w obu kawałkach była:
co najmniej drugą potęgą dowolnej liczby naturalnej. Łączna długości obu kawałków powinna wynosić 24.
*/
#include <iostream>
using namespace std;
const int N = 12;
bool warunek(int suma1,int suma2) {
	int n = suma1 + suma2;
	if (n == 1) return true;
	for (int i = 2; i <= sqrt(n); i++) {
		int m = n;
		while (m % i == 0) {
			m /= i;
			if (m == 1) return true;
		}
	}
	return false;
}
bool isPossible(int t1[N], int t2[N]) {
	int dlugosc1;
	int dlugosc2;
	if (N >= 23) {
		 dlugosc1 = 23;
		 dlugosc2 = 1;
	}
	else {
		dlugosc1 = N;
		dlugosc2 = 24 - N;
	}
	while (dlugosc1>0 && dlugosc2<=N) {
		for (int pocz1 = 0; pocz1 < N; pocz1++) {
			for (int pocz2 = 0; pocz2 < N; pocz2++) {
				int suma1 = 0;
				int suma2 = 0;
				for (int i = pocz1; i < pocz1 + dlugosc1; i++) {
					suma1 += t1[i];
				}
				for (int i = pocz2; i < pocz2 + dlugosc2; i++) {
					suma2 += t2[i];
				}
				if (warunek(suma1, suma2)) {
					cout << pocz1 << " " << pocz2 << " " << dlugosc1 << " " << dlugosc2 << " " << suma1 << " " << suma2 << endl;
					return true;
				}
			}
		}
		dlugosc1--;
		dlugosc2++;
	}
	return false;
}
	int main() {
		int t1[N] = { 1,1,1,1,1,1,1,1,1,1,1,1 };
		int t2[N] = { 1,1,1,1,1,1,1,1,2,1,1,1 };
	isPossible(t1, t2);
	}