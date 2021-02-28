/*
Zad. 3. Dana jest tablica t[N][N] wypełniona liczbami całkowitymi. Tablica reprezentuje szachownicę. Proszę napisać
funkcję, która sprawdza czy da się umieścić w każdym wierszu jednego króla szachowego tak aby żadne dwa króle
nie stały w odległości mniejszej niż dwa ruchy króla. Dodatkowo, suma wartości pól zajmowanych przez wszystkie
figury była równa zero.
*/
#include <iostream>
using namespace std;
const int N = 5;
bool isSafe(int zajete[N][N], int wiersz, int kolumna) {
	if (zajete[wiersz - 1][kolumna - 1] == 1 || zajete[wiersz - 1][kolumna] == 1 || zajete[wiersz - 1][kolumna + 1] == 1) return false;
	return true;
}
bool sprawdzanie(int t[N][N],int zajete[N][N],int suma,int wiersz) {
	if (wiersz == N && suma == 0) return true;
	if (wiersz < N) {
		for (int i = 0; i < N; i++) {
			if (isSafe(zajete, wiersz, i)) {
				zajete[wiersz][i] = 1;
				suma += t[wiersz][i];
				if (sprawdzanie(t, zajete, suma, wiersz + 1))return true;
				zajete[wiersz][i] = 0;
				suma -= t[wiersz][i];
			}
		}
	}
	return false;
}
bool function(int t[N][N]) {
	int wykorzystane[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			wykorzystane[i][j] = 0;
		}
	}
	return sprawdzanie(t, wykorzystane, 0, 0);
}

int main() {
	int t[N][N] = { {1,1,1,1,1}, {1,1,1,1,1}, {1,1,1,1,1}, {1,1,1,-1,1}, {1,1,1,1,1} };
	cout << function(t);
}