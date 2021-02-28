/*
21. Dane są deklaracje:
const int N=1000;
int tab[N];
Tablica tab jest wypełniona liczbami naturalnymi. Proszę napisać
funkcję, która zwraca długość najdłuższego spójnego podciągu
będącego palindromem złożonym wyłącznie z liczb nieparzystych.
Do funkcji należy przekazać tablicę, funkcja powinna zwrócić
długość znalezionego podciągu lub wartość 0 jeżeli taki podciąg
nie istnieje.
*/
#include <iostream>
using namespace std;
const int N = 12;
bool czypalindrom(int* t, int pocz, int konc) {
	while (pocz < konc) {
		if (t[pocz] != t[konc]) return false;
		pocz++;
		konc--;
	}
	return true;
}
int najdluzszy(int t[N]) {
	int najd = 1;
	for (int ptr1 = 0; ptr1 < N - 1; ptr1++) {
		for (int ptr2 = ptr1+1; ptr2 < N; ptr2++) {
			int dlugosc = 0;
			if (czypalindrom(t, ptr1, ptr2)) dlugosc = ptr2 - ptr1 + 1;
			if (dlugosc > najd) najd = dlugosc;
		}
	}
	if (najd > 1) return najd;
	else return 0;
}
int main() {
	int t[N] = { 1,8,9,8,7,6,6,7,8,9,8,1 };
	cout << najdluzszy(t);
}