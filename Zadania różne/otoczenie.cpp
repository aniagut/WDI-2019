/*
17. Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę napisać
funkcję która zwraca wiersz i kolumnę dowolnego elementu, dla którego suma
otaczających go elementów jest największa.
*/
#include <iostream>
using namespace std;
const int MAX = 6;
int otoczenie(int t[MAX][MAX], int wiersz, int kolumna) {
	int suma = 0;
	if (wiersz - 1 >= 0) {
		suma += t[wiersz - 1][kolumna];
		if (kolumna - 1 >= 0) {
			suma += t[wiersz - 1][kolumna - 1];
		}
		if (kolumna + 1 < MAX) {
			suma += t[wiersz - 1][kolumna + 1];
		}
	}
	if (wiersz + 1 < MAX) {
		suma += t[wiersz + 1][kolumna];
		if (kolumna - 1 >= 0) {
			suma += t[wiersz + 1][kolumna - 1];
		}
		if (kolumna + 1 < MAX) {
			suma += t[wiersz + 1][kolumna - 1];
		}
	}
		if(kolumna-1>=0) suma += t[wiersz][kolumna - 1];
		if(kolumna+1<MAX) suma += t[wiersz][kolumna +1];
		return suma;
}

void najwsuma(int t[MAX][MAX]) {
	int najwsuma = 0;
	int w;
	int k;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			int suma = otoczenie(t, i, j);
			if (suma > najwsuma) {
				najwsuma = suma;
				w = i;
				k = j;
			}
		}
	}
	cout << w << " " << k << endl;
}
int main() {
	int t[MAX][MAX] = { {1,5,3,4,2,0},{2,19,1,7,5,3},{9,7,4,12,0,7},{11,4,6,5,4,3},{16,1,10,4,3,3},{1,11,10,24,1} };
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	najwsuma(t);
}