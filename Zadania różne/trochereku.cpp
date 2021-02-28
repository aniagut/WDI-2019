/*
1. Dany jest zestaw odważników int t[N]. Napisać funkcję, która sprawdza czy jest
możliwe odważenie określonej masy. Odważniki można umieszczać tylko na jednej
szalce.
*/
#include <iostream>
using namespace std;
const int N = 8;
bool czymozliwe(int t[N], int masa,int idx) {
	if (masa== 0) return true;
	if (idx < N) {
		for (int i = idx; i < N; i++) {
			if (masa - t[i] >= 0) {
				if (czymozliwe(t, masa - t[i], i + 1)) return true;
			}
		}
	}
	return false;
}
/*2. Poprzednie zadanie, odważniki można umieszczać na obu szalkach. */
bool czymozliwe2(int t[N], int masa, int idx) {
	if (masa == 0) return true;
	if (idx < N) {
		for (int i = idx; i < N; i++) {
			if (czymozliwe2(t, masa - t[i], i + 1) || czymozliwe2(t, masa + t[i], i + 1)) return true;
		}
	}
	return false;
}
/*3. Poprzednie zadanie. Program powinien wypisywać wybrane odważniki.*/
bool czymozliwe3(int t[N], int masa, int idx) {
	if (masa == 0) return true;
	if (idx < N) {
		for (int i = idx; i < N; i++) {
			if (czymozliwe3(t, masa - t[i], i + 1)) {
				cout << "Na druga strone : " << t[i] << endl;
				return true;
			}
			if (czymozliwe3(t, masa + t[i], i + 1)) {
				cout << "Na te sama strone: " << t[i] << endl;
				return true;
			}
		}
	}
	return false;
}
/*
4. „Waga” liczby jest określona jako ilość różnych czynników pierwszych liczby. Na
przykład waga(1)=0, waga(2)=1, waga(6)=2, waga(30)=3, waga(64)=1. Dana jest
tablica: int t[N]. Tablica zawiera liczby naturalne. Proszę napisać funkcję, która
sprawdza czy można elementy tablicy podzielić na 3 podzbiory o równych wagach. Do
funkcji należy przekazać wyłącznie tablicę, funkcja powinna zwrócić wartość typu
bool.
*/
bool isPrime(int n) {
	if (n == 0 || n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= sqrt(n); i=i+2) {
		if (n % i == 0) return false;
	}
	return true;
}
int wagaliczby(int n) {
	if (n == 0 || n == 1) return 0;
	if (n == 2) return 1;
	int waga = 0;
	int i = 2;
	while (n > 0) {
		if (isPrime(i)&& n%i==0) waga++;
		while(n % i == 0) n /= i;
		if (n == 1) return waga;
		i++;
	}
}
bool czyMoznapodzielic(int t[N],int suma1, int suma2,int suma3,int idx) {
	if (idx == N && wagaliczby(suma1) == wagaliczby(suma2) && wagaliczby(suma2) == wagaliczby(suma3)) return true;
	if (idx < N) {
		if (czyMoznapodzielic(t, suma1 + t[idx], suma2, suma3, idx + 1) || czyMoznapodzielic(t, suma1, suma2 + t[idx], suma3, idx + 1) || czyMoznapodzielic(t, suma1, suma2, suma3 + t[idx], idx + 1)) return true;
	}
	return false;
}
bool func(int t[N]) {
	int suma1 = 0; int suma2 = 0; int suma3 = 0;
	int idx = 0;
	return czyMoznapodzielic(t, suma1, suma2, suma3, idx);
}
/*
5. Problem skoczka szachowego (treść oczywista) SKOCZEK==KONIK w pionie lub w poziomie i dalej na ukos oddalac sie
problem-czy moze obejsc wszystkie pola stajac na kazdym tylko raz
*/
bool czyruch(int t[N][N],int wiersz,int kolumna) {
	if (wiersz < 0 || wiersz >= N || kolumna < 0 || kolumna >= N) return false;
	if (t[wiersz][kolumna] == 1) return false;
	return true;
}
bool czytak(int t[N][N], int wiersz, int kolumna, int suma) {
	if (suma == N * N) return true;
	if (czyruch(t, wiersz - 1, kolumna - 2)) {
		wiersz = wiersz - 1;
		kolumna = kolumna - 2;
		t[wiersz][kolumna] = 1;
		suma++;
		if (czytak(t, wiersz, kolumna, suma)) return true;
		t[wiersz][kolumna] = 0;
		wiersz = wiersz + 1;
		kolumna = kolumna + 2;
		suma--;
	}
	if (czyruch(t, wiersz - 1, kolumna + 2)) {
		wiersz = wiersz - 1;
		kolumna = kolumna + 2;
		t[wiersz][kolumna] = 1;
		suma++;
		if (czytak(t, wiersz, kolumna, suma)) return true;
		t[wiersz][kolumna] = 0;
		wiersz = wiersz + 1;
		kolumna = kolumna - 2;
		suma--;
	}
	if (czyruch(t, wiersz - 2, kolumna -1)) {
		wiersz = wiersz -2;
		kolumna = kolumna -1;
		t[wiersz][kolumna] = 1;
		suma++;
		if (czytak(t, wiersz, kolumna, suma)) return true;
		t[wiersz][kolumna] = 0;
		wiersz = wiersz +2;
		kolumna = kolumna + 1;
		suma--;
	}
	if(czyruch(t, wiersz - 2, kolumna + 1)) {
		wiersz = wiersz - 2;
		kolumna = kolumna + 1;
		t[wiersz][kolumna] = 1;
		suma++;
		if (czytak(t, wiersz, kolumna, suma)) return true;
		t[wiersz][kolumna] = 0;
		wiersz = wiersz + 2;
		kolumna = kolumna - 1;
		suma--;
	}
	if (czyruch(t, wiersz +1, kolumna -2)) {
		wiersz = wiersz +1;
		kolumna = kolumna - 2;
		t[wiersz][kolumna] = 1;
		suma++;
		if (czytak(t, wiersz, kolumna, suma)) return true;
		t[wiersz][kolumna] = 0;
		wiersz = wiersz -1;
		kolumna = kolumna +2;
		suma--;
	}
	if (czyruch(t, wiersz + 1, kolumna + 2)) {
		wiersz = wiersz + 1;
		kolumna = kolumna + 2;
		t[wiersz][kolumna] = 1;
		suma++;
		if (czytak(t, wiersz, kolumna, suma)) return true;
		t[wiersz][kolumna] = 0;
		wiersz = wiersz - 1;
		kolumna = kolumna - 2;
		suma--;
	}
	if (czyruch(t, wiersz + 2, kolumna -1)) {
		wiersz = wiersz + 2;
		kolumna = kolumna -1;
		t[wiersz][kolumna] = 1;
		suma++;
		if (czytak(t, wiersz, kolumna, suma)) return true;
		t[wiersz][kolumna] = 0;
		wiersz = wiersz -2;
		kolumna = kolumna +1;
		suma--;
	}
	if (czyruch(t, wiersz + 2, kolumna + 1)) {
		wiersz = wiersz + 2;
		kolumna = kolumna + 1;
		t[wiersz][kolumna] = 1;
		suma++;
		if (czytak(t, wiersz, kolumna, suma)) return true;
		t[wiersz][kolumna] = 0;
		wiersz = wiersz - 2;
		kolumna = kolumna - 1;
		suma--;
	}
	return false;
}
bool skoczek() {
	int t[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			t[i][j] = 0;
		}
	}
	return czytak(t, 0, 0, 1);
}


int main() {
	cout << skoczek();

}