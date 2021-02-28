/*
Dana jest tablica int t[N] zawierająca liczby naturalne mniejsze od 1000. Proszę napisać
funkcję, która zwraca długość najdłuższego, spójnego fragmentu tablicy, dla którego w
iloczynie jego elementów każdy czynniki pierwszy występuje co najwyżej raz. Na przykład dla
tablicy [2,23,33,35,7,4,6,7,5,11,13,22] wynikiem jest wartość 5.
*/
#include <iostream>
using namespace std;
const int N = 12;
bool isPrime(int n) {
	if (n == 0 || n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 2; i <= sqrt(n); i = i + 2) {
		if (n % i == 0) return false;
	}
	return true;
}
int czyraz(int n) {
	if (n % 4 == 0) return false;
	for (int i = 3; i <= sqrt(n) && n>0; i++) {
		if (n % i == 0) n /= i;
		if (n % i == 0) return false;
	}
	return true;
}
int najdluzszyfragment(int t[N]) {
	int najwdlugosc = 0;
	for (int i = 0; i < N; i++) {
		int dlugosc = 0;
		int k = i+1;
		int iloczyn = t[i];
		while (k < N && czyraz(iloczyn)) {
			iloczyn *= t[k];
			k++;
			dlugosc++;
		}
		if (dlugosc > najwdlugosc) najwdlugosc = dlugosc;
	}
	return najwdlugosc;
}
int main() {
	int t[N] = { 2,23,33,35,7,4,6,7,5,11,13,22 };
	cout << najdluzszyfragment(t);
}