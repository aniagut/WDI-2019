#include <iostream>
using namespace std;
/*
19. Dana jest tablica wypełniona liczbami naturalnymi int t[MAX][MAX];
Proszę napisać funkcję, która zwraca liczbę par elementów, o określonym
iloczynie, takich że elementy są odległe o jeden ruch skoczka szachowego.
*/
const int N= 5;

int liczbapar(int t[N][N],int sprawdzone[N][N], int wiersz, int kolumna, int wynik) {
	int ile = 0;
	if (wiersz - 2 >= 0 && kolumna - 1 >= 0) {
		if (sprawdzone[wiersz - 2][kolumna - 1] == 0 && t[wiersz][kolumna] * t[wiersz - 2][kolumna - 1] == wynik) ile += 1;
	}
	if (wiersz - 2 >= 0 && kolumna + 1 < N) {
		if (sprawdzone[wiersz - 2][kolumna + 1] == 0 && t[wiersz][kolumna] * t[wiersz - 2][kolumna +1] == wynik) ile += 1;
	}
	if (wiersz - 1 >= 0 && kolumna - 2 >= 0) {
		if (sprawdzone[wiersz - 1][kolumna - 2] == 0 && t[wiersz][kolumna] * t[wiersz - 1][kolumna - 2] == wynik) ile += 1;
	}
	if (wiersz - 1 >= 0 && kolumna + 2 < N) {
		if (sprawdzone[wiersz - 1][kolumna +2] == 0 && t[wiersz][kolumna] * t[wiersz - 1][kolumna +2] == wynik) ile += 1;
	}
	//
	if (wiersz +2 <N && kolumna - 1 >= 0) {
		if (sprawdzone[wiersz +2][kolumna - 1] == 0 && t[wiersz][kolumna] * t[wiersz +2][kolumna - 1] == wynik) ile += 1;
	}
	if (wiersz +2<N && kolumna + 1 < N) {
		if (sprawdzone[wiersz +2][kolumna + 1] == 0 && t[wiersz][kolumna] * t[wiersz+2][kolumna + 1] == wynik) ile += 1;
	}
	if (wiersz + 1 <N && kolumna - 2 >= 0) {
		if (sprawdzone[wiersz + 1][kolumna - 2] == 0 && t[wiersz][kolumna] * t[wiersz +1][kolumna - 2] == wynik) ile += 1;
	}
	if (wiersz + 1 <N && kolumna + 2 < N) {
		if (sprawdzone[wiersz + 1][kolumna + 2] == 0 && t[wiersz][kolumna] * t[wiersz + 1][kolumna + 2] == wynik) ile += 1;
	}
	return ile;
}
int ilepar(int t[N][N], int iloczyn) {
	int suma = 0;
	int sprawdzone[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sprawdzone[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			suma += liczbapar(t, sprawdzone, i, j, iloczyn);
			sprawdzone[i][j] = 1;
		}
	}
	return suma;
}
int main() {
	int t[N][N] = { {1,1,1,1,1}, {1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1},{1,1,1,1,1} };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	cout << ilepar(t, 1);

}