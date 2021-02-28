/*
Proszę napisać funkcję, która dla podanej sumy i listy
nominałów wypisuje ilość możliwości na jakie możliwości
na jakie można wydać daną sumę.
*/
#include <iostream>
using namespace std;
const int N = 7;
int nailesposobow(int suma, int reszty[N], int indeks) {
	if (suma == 0) return 1;
	else if (indeks == N) return 0;
	else if (suma < 0) {
		return nailesposobow(suma, reszty, indeks + 1);
	}
	else {
		return nailesposobow(suma - reszty[indeks], reszty, indeks) + nailesposobow(suma, reszty, indeks + 1);
	}
}
/*
Dane są dwie liczby naturalne z których budujemy trzecią liczbę. W budowanej liczbie muszą
wystąpić wszystkie cyfry występujące w liczbach wejściowych. Wzajemna kolejność cyfr każdej z
liczb wejściowych musi być zachowana.
Na przykład mając liczby 123 i 75 możemy zbudować liczby 12375, 17523, 75123, 17253, itd.
Proszę napisać funkcję która wyznacza ile liczb pierwszych można zbudować z dwóch zadanych
liczb.
*/
bool  isPrime(int n) {
	if (n == 0 || n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= sqrt(n); i = i + 2) {
		if (n % i == 0) return false;
	}
	return true;
}
int pierwszaliczba(int n) {
	int m = n;
	while (m >= 10) m /= 10;
	return m;
}
int przeziledzielic(int n) {
	int dzielnik = 1;
	int m = n;
	while (m > 10) {
		m /= 10;
		dzielnik *= 10;
	}
	return dzielnik;
}
int naile(int a, int b, int liczba) {
	if (a == 0 && b == 0) {
		return isPrime(liczba);
	}
	else {
		if (b == 0) {
			return naile(a % przeziledzielic(a), b, liczba * 10 + pierwszaliczba(a));
		}
		if (a == 0) {
			return naile(a, b % przeziledzielic(b), liczba * 10 + pierwszaliczba(b));
		}
		else {
			return naile(a % przeziledzielic(a), b, liczba * 10 + pierwszaliczba(a)) + naile(a, b % przeziledzielic(b), liczba * 10 + pierwszaliczba(b));
		}
	}
}
/*
Dane są deklaracje:
const int N=1000;
int tab[N];
Tablica tab jest wypełniona liczbami naturalnymi. Proszę napisać funkcję, która zwraca długość
najdłuższego spójnego podciągu będącego palindromem złożonym wyłącznie z liczb
nieparzystych. Do funkcji należy przekazać tablicę, funkcja powinna zwrócić długość
znalezionego podciągu, lub wartość 0, jeżeli taki podciąg nie istnieje.
*/
bool czyPalindrom(int t[N],int i, int j) {
	int a = i;
	int b = j;
	while (a < b) {
		if (t[a] != t[b]) return false;
		a++;
		b--;
	}
	return true;
}
int jaka(int i, int j) {
	return j - i + 1;
}
int dlugosc(int t[N], int i, int j) {
	if (i < j && czyPalindrom(t, i, j)) return jaka(i, j);
	else if (i < j) {
		return dlugosc(t, i + 1,j) || dlugosc(t, i, j + 1);
	}
	else return 0;
}

int main() {
	int t[N] = { 0,1,1,0,1,1,2 };
	cout << dlugosc(t, 0, N - 1);
}