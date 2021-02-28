#include <iostream>
using namespace std;
/*PROBLEM SKOCZKA SZACHOWEGO 
JEDNO POLE W PIONIE LUB POZIOMIE I JEDNO NA UKOS W KIERUNKU ODDALAJACYM OD POCZATKOWEGO
*/
const int N = 5;
bool isSafe(int tab[N][N], int wiersz, int kolumna) {
	if (kolumna == 0) return true;
	if (kolumna >=1) {
		if (wiersz >= 2) {
			if (tab[wiersz - 2][kolumna - 1]) return false;
		}
		if (wiersz <= N - 3) {
			if (tab[wiersz + 2][kolumna - 1]) return false;
		}
	}
	if (kolumna >= 2) {
		if (wiersz >= 1) {
			if (tab[wiersz - 1][kolumna - 2]) return false;
		}
		if (wiersz <= N - 2) {
			if (tab[wiersz + 1][kolumna - 2]) return false;
		}
	}
	return true;
}
bool isPossible(int t[N][N], int kolumna) {
	if (kolumna == N) return true;
	if (kolumna < N) {
		for (int i = 0; i < N; i++) {
			if (isSafe(t, i, kolumna)) {
				t[i][kolumna]=1;
				if(isPossible(t,kolumna+1)) return true;
				t[i][kolumna] = 0;
			}
		}
	}
	return false;
}
bool funct() {
	int plansza[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			plansza[i][j] = 0;
		}
	}
	isPossible(plansza, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << plansza[i][j] << " ";
		}
		cout << endl;
	}
	return isPossible(plansza, 0);
}
int main() {
	cout << funct();
}