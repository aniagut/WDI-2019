/*
Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę napisać
funkcję która zwraca wiersz i kolumnę dowolnego elementu, dla którego iloraz
sumy elementów w kolumnie w którym leży element do sumy elementów wiersza w
którym leży element jest największa.
*/
#include <iostream>
using namespace std;
const int MAX = 3;
/*

*/
int sumaNajwKolumny(int t[MAX][MAX]) {
	int result = -1;
	int k;
	for (int j = 0; j < MAX; j++) {
		int suma = 0;
		for (int i = 0; i < MAX; i++) {
			suma += t[i][j];
		}
		if (suma > result) {
			result = suma;
			k = j;
		}
	}
	return k;
}
int sumaNajmWiersza(int t[MAX][MAX]) {
	int result = INT_MAX;
	int w;
	for (int i = 0; i < MAX; i++) {
		int suma = 0;
		for (int j = 0; j < MAX; j++) {
			suma += t[i][j];
		}
		if (suma < result) {
			result = suma;
			w = i;
		}
	}
	return w;
}
void wypisuje(int tab[MAX][MAX]) {
	cout << "Wiersz: " << sumaNajmWiersza(tab) << " Kolumna: " << sumaNajwKolumny(tab);
}
int main() {
	int t[MAX][MAX] = { {1,6,6},{2,7,1},{2,3,1} };
	wypisuje(t);
}