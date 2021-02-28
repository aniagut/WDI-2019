/*
22. Dane są deklaracje:
const int N=1000;
int tab[N];
Tablica tab jest wypełniona liczbami naturalnymi. Proszę napisać
funkcję, która zwraca długość najdłuższego, spójnego podciągu
rosnącego dla którego suma jego elementów jest równa sumie
indeksów tych elementów. Do funkcji należy przekazać tablicę,
funkcja powinna zwrócić długość znalezionego podciągu lub
wartość 0 jeżeli taki podciąg nie istnieje.
*/

#include <iostream>
using namespace std;
const int N = 10;
int najdluzszy = 1;
int podciag(int t[N]) {
	for (int i = 0; i < N - 1; i++) {
		int dlugosc = 1;
		int faktdlugosc = 1;
		int sumael = t[i];
		int sumaidx = i;
		int j = i + 1;
		while (t[j] > t[j - 1] && j < N) {
			dlugosc++;
			sumael += t[j];
			sumaidx += j;
			if (sumael == sumaidx) faktdlugosc = dlugosc;
			j++;
		}
		if (faktdlugosc > najdluzszy) najdluzszy = faktdlugosc;
	}
	if (najdluzszy == 1) return 0;
	else return najdluzszy;
}
int main() {
	int t1[N] = { 0,1,0,1,5,6,7,6,8,9 };
	cout << podciag(t1);
}