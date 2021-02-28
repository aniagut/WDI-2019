/*
21. Dana jest tablica int t[N] zawierająca liczby naturalne. Po tablicy możemy
przemieszczać się według następującej zasady: z pola o indeksie i możemy
przeskoczyć na pole o indeksie i+k jeżeli k jest czynnikiem pierwszym liczby t[i]
mniejszym od t[i]. Proszę napisać funkcję, która zwraca informację czy jest możliwe
przejście z pola o indeksie 0 na pole o indeksie N-1. Funkcja powinna zwrócić
liczbę wykonanych skoków lub wartość -1 jeżeli powyższe przejście nie jest możliwe.
*/
#include <iostream>
using namespace std;
const int N = 10;
int czynnpierwszymniejszy(int n) {
	if (n <= 3) return 0;
	if (n % 2 == 0) return 2;
	for (int i = 3; i <= sqrt(n); i = i + 2) {
		if (n % i == 0) return i;
	}
	return 0;
}
int czynnpierwszy(int n) {
	if (n == 0 || n == 1) return 0;
	if (n == 2 || n == 3) return n;
	if (n % 2 == 0) return 2;
	for (int i = 3; i <= sqrt(n); i = i + 2) {
		if (n % i == 0) return i;
	}
	return n;
}
bool czymozliwe(int t[N], int idx, int skoki) {
	if (idx == N - 1) {
		cout << skoki << endl;
		return true;
	}
	if (idx < N && czynnpierwszymniejszy(t[idx]) != 0) {
	return (czymozliwe(t, idx + czynnpierwszymniejszy(t[idx]), skoki + 1));

	}
	return false;
}
int main() {
	int t[N] = { 9,6,4,4,25,4,2,4,3,18 };
	cout << czymozliwe(t, 0, 0);
}