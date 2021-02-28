#include <iostream>
#include <cmath>
using namespace std;
/*
Dany jest zestaw odważników int t[N]. Napisać funkcję, która sprawdza czy jest
możliwe odważenie określonej masy. Odważniki można umieszczać tylko na jednej
szalce.
*/
//trzeba utworzyc podzbiory utworzone z elementow tablicy
//jesli suma elementow ktoregos podzbioru rowna masie to mozna
const int N = 10;
void zamiananabinarny(int n, int tab[N]) {
	int i = 0;
	int suma = -1;
	while (n != 0) {
			tab[i] = n % 2;
			n /= 2;
			i++;
			suma++;
		}
	if (suma < N - 1) {
		for (int j = suma + 1; j < N; j++) {
			tab[j] = 0;
		}
	}
	}
//uzyskuje liczbe w syst binarnym ale odwrocona i reszte zer


bool czymoznaodwazyc(int tab[N], int masa, int t[N]) {
	for (int i = 1; i < pow(2, N); i++) {
		zamiananabinarny(i, tab);
		int suma = 0;
		for (int i = 0; i < N; i++) {
			if (tab[i] == 1) suma += t[i];
		}
		if (suma == masa) return true;
	}
	return false;
}
int main() {
	int t[N] = { 20,2,18,4,16,6,14,8,12,10 };
	int tab[N] = { 0 };
	int masa = 54;
	cout << czymoznaodwazyc(tab, masa, t);
}