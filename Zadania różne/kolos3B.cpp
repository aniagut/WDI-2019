/*
Zad. 3. Dana jest tablica t[N][N] wypełniona liczbami całkowitymi. Tablica reprezentuje szachownicę. Proszę napisać
funkcję, która sprawdza czy da się umieścić w każdym wierszu jednego hetmana szachowego aby żaden hetman nie
zagrażał hetmanowi z sąsiedniego wiersza. Dodatkowo, suma wartości pól zajmowanych przez wszystkie figury była
równa zero.
*/
#include <iostream>
using namespace std;
const int N = 5;
bool isSafe(int zajete[N][N], int wiersz, int kolumna) {
	//spr kolumny z gory
	for (int i = 0; i < wiersz; i++) {
		if (zajete[i][kolumna]) return false;
	}
	//spr przekatnej z lewej
	int i;
	int j;
	for (i = wiersz - 1, j = kolumna - 1; i >= 0 && j >= 0; i--, j--) {
		if (zajete[i][j]) return false;
	}
	//spr przekatnej z prawej
	for (i = wiersz - 1, j = kolumna + 1; i >= 0 && j < N; i--, j++) {
		if (zajete[i][j]) return false;
	}
	return true;
}
bool czyDaSie(int t[N][N],int zajete[N][N], int wiersz,int suma) {
	if (wiersz == N && suma == 0) return true;
	if (wiersz < N) {
		for (int i = 0; i < N; i++) {
			if (isSafe(zajete,wiersz,i)) {
				zajete[wiersz][i] = 1;
				suma += t[wiersz][i];
				if (czyDaSie(t, zajete, wiersz + 1, suma)) return true;
				zajete[wiersz][i] = 0;
				suma -= t[wiersz][i];
			}
		}
	}
	return false;
}
bool funct(int t[N][N]) {
	int zajete[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			zajete[i][j] = 0;
		}
	}
	czyDaSie(t, zajete, 0, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << zajete[i][j] << " ";
		}
		cout << endl;
	}
	return czyDaSie(t, zajete, 0, 0);
}
int main() {
	int plansza[N][N] = {{ -1,1,0,-1,1 }, { 1,0,1,-1,1 }, { -1,0,1,0,1 }, { 1,1,-1,1,0 }, { 1,0,1,1,-1 }};
	cout << funct(plansza);
}