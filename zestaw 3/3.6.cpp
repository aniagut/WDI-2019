/*
Proszę napisać program, który wczytuje wprowadzany z klawiatury
ciąg liczb naturalnych zakończonych zerem stanowiącym wyłącznie
znacznik końca danych. Program powinien wypisać 10 co do
wielkości wartość, jaka wystąpiła w ciągu. Można założyć, że w
ciągu znajduje się wystarczająca liczba elementów.

*/

#include <iostream>
using namespace std;
void codowielk10(int tab[], int size) {
	int i = 0;
	bool czydalej = true;
	int suma = 0;
	while (czydalej) {
		while (i < size - 1) {
			if (tab[i] > tab[i + 1]) {
				int c = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = c;
				suma++;
			} i++;
		} if (suma == 0) czydalej = false;
		else {
			suma = 0;
			i = 0;
		}
	}
	cout << tab[9];
}
int main() {
	int t[1000];
	int n = 10;
	int i = 0;
	int suma = 0;
	while (n != 0) {
		cin >> n;
		if (n != 0) {
			t[i] = n;
			i++;
			suma++;
		}
	}
	codowielk10(t, suma);
}