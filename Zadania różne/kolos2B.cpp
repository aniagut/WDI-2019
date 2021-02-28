#include <iostream>
using namespace std;
/*
Zad. 2. Dana jest tablica int t[N][N] zawierająca liczby naturalne. Proszę napisać funkcję, która sprawdza czy z tablicy
można usunąć jeden wiersz i dwie kolumny, tak aby każdy z pozostałych elementów tablicy był wielokrotnością
(co najmniej dwukrotnością) kwadratu dowolnej liczby naturalne większej od 1.
*/
const int N = 5;
bool czyWielokrotnosc(int n) {
	if (n < 8) return false;
	for (int i = 2; i <= sqrt(n/2); i++) {
		int m = n;
		if (m % i == 0) m /= i;
		if (m % i == 0) {
			m /= i;
			if (m > 1) return true;
		}
	}
	return false;
}
bool czyMozna(int t[N][N]) {
	for (int i = 0; i < N-1; i++) { //0-3
		for (int j = i + 1; j < N; j++) { //1-4
			for (int k = 0; k < N; k++) { //0-3
				int k1 = i; //0
				int k2 = j; //1
				int w1 = k; //0
				bool flag = true;
				for (int wiersz = 0; wiersz < N; wiersz++) { 
					for (int kolumna = 0; kolumna < N; kolumna++) { 
						if (wiersz != w1 && kolumna != k1 && kolumna != k2) {
							if (!czyWielokrotnosc(t[wiersz][kolumna])) flag= false; //0 0
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
	int t[N][N] = { {1,1,1,1,1}, {8,1,1,8,8}, {8,8,1,8,8}, {8,8,8,8,8}, {8,8,8,8,8} };
	cout << czyMozna(t);
}