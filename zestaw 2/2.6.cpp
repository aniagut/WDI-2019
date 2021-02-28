/*
Dana jest liczba naturalna o niepowtarzających się cyfrach pośród których nie ma
zera.Ile różnych liczb podzielnych np.przez 7 można otrzymać poprzez
wykreślenie dowolnych cyfr w tej liczbie.Np.dla 2315 będą to 21, 35, 231, 315
*/
//od 0 do 2^ilosc cyfr-1 w binarnym 
	// spr ilosc cyfr w tablicy  taka potega 10
#include <iostream>
#include <cmath>
using namespace std;
int ilosccyfr(int n) {
	int suma = 0;
	while (n != 0) {
		suma++;
		n /= 10;
	}
	return suma;
}
void zamiananabinarny(int tab[100], int n) {
	for (int i = 0; i < 100; i++) {
		tab[i] = 0;
	}
	int j = 0;
	while (n != 0) {
		tab[j] = n % 2;
		n /= 2;
		j++;
	}
}
int ilecyfr(int n) {
	int suma = 0;
	int tab[100];
	for (int i = 0; i < pow(2, ilosccyfr(n)); i++) {
		zamiananabinarny(tab, i);
		int liczba = 0;
		for (int j = 0; j < ilosccyfr(n); j++) {
			if (tab[j] == 1) {
				int k = n;
				for (int p = 1; p <= ilosccyfr(n) - 1 - j; p++) {
					k /= 10;
				}
				for (int p = 1; p <= ilosccyfr(n) - 1 - j; p++) {
					k *= 10;
				}
				liczba += k;
			}
		}
		if (liczba % 7 == 0) suma++;
	}
	return suma;
}
int main() {
	int n = 2137;
	cout << ilecyfr(n);
}