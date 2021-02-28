#include <iostream>
using namespace std;
/*
PROBLEM 8 HETMANOW
*/
const int N = 8;
bool isSafe(int plansza[N][N], int wiersz, int kolumna) {
	//spr wierszy z lewej
	for (int i = 0; i < kolumna; i++) {
		if (plansza[wiersz][i] == 1) return false;
	}
	//przekatna gorna z lewej
	int i;
	int j;
	if(wiersz>0 && kolumna>0){
		for (i = wiersz - 1,j = kolumna - 1; i >= 0 && j >= 0; i--, j--) {
			if (plansza[i][j] == 1) return false;
		}
	}
	//spr przekatnej dolnej z lewej
	if (wiersz < N - 1 && kolumna>0) {
		for (i = wiersz+1,j = kolumna - 1; i <= N - 1 && j >= 0; i++, j--) {
			if (plansza[i][j] == 1) return false;
		}
	}
	return true;
}
bool solve8queens(int plansza[N][N], int kolumna) {
	if (kolumna >= N) return true;
	for (int i = 0; i < N; i++) {
		if (isSafe(plansza, i, kolumna)) {
			plansza[i][kolumna] = 1;
			if (solve8queens(plansza, kolumna + 1)) return true;
			plansza[i][kolumna] = 0;
		}
	}
	return false; 
}
int main() {
	int plansza[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			plansza[i][j] = 0;
	}
	}
	cout << ileustawien(plansza, 0) << endl;

}

