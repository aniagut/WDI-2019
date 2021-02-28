/*
1. Dany jest zestaw odważników int t[N]. Napisać funkcję, która sprawdza czy jest
możliwe odważenie określonej masy. Odważniki można umieszczać tylko na jednej
szalce.
*/
#include <iostream>
using namespace std;
const int N = 6;
bool czyMozliwe(int t[N], int masa, int idx) {
	if (masa == 0) return true;
	for (int i = idx; i < N; i++) {
		if (masa - t[i] < 0) continue;
		if(czyMozliwe(t, masa - t[i], i + 1)) return true;
	}
	return false;
}
//2. Poprzednie zadanie, odważniki można umieszczać na obu szalkach.
bool czyMozliwe2(int t[N], int masa, int idx) {
	if (masa == 0) return true;
	for (int i = idx; i < N; i++) {
		if (czyMozliwe2(t, masa - t[i], i + 1) || czyMozliwe2(t, masa + t[i], i + 1)) return true;
	}
	return false;
}
//3. Poprzednie zadanie. Program powinien wypisywać wybrane odważniki.
bool wypiszOdwazniki(int t[N], int masa, int idx) {
	if (masa == 0) return true;
	for (int i = idx; i < N; i++) {
		if (wypiszOdwazniki(t, masa - t[i], i + 1)) {
			cout << "Na przeciwna strone: " << t[i] << endl;
			return true;
		}
		if (wypiszOdwazniki(t, masa + t[i], i + 1)) {
			cout << "Na te sama strone: " << t[i] << endl;
			return true;
		}
	}
	return false;
}
/*
4.„Waga” liczby jest określona jako ilość różnych czynników pierwszych liczby. Na
przykład waga(1)=0, waga(2)=1, waga(6)=2, waga(30)=3, waga(64)=1. Dana jest
tablica: int t[N]. Tablica zawiera liczby naturalne. Proszę napisać funkcję, która
sprawdza czy można elementy tablicy podzielić na 3 podzbiory o równych wagach. Do
funkcji należy przekazać wyłącznie tablicę, funkcja powinna zwrócić wartość typu
bool.
*/
int wagaliczby(int n) {
	if (n == 1 || n == 0) return 0;
	int waga = 0;
	int m = n;
	for (int i = 2; i <= n; i++) {
		if (m > 0 && m % i == 0) waga++;
		while (m > 0 && m % i == 0) m /= i;
		if (m == 1) return waga;
	}
}
bool Sumy(int wagi[N], int suma1, int suma2, int suma3, int idx) {
	if (idx == N && suma1 == suma2 && suma2 == suma3) return true;
	else if (idx == N) return false;
	else return Sumy(wagi, suma1 + wagi[idx], suma2, suma3, idx + 1) || Sumy(wagi, suma1, suma2 + wagi[idx], suma3, idx + 1) || Sumy(wagi, suma1, suma2, suma3 + wagi[idx], idx + 1);
}
	bool czyMoznaPodzielic(int t[N]) {
	int wagi[N];
	for (int i = 0; i < N; i++) {
		wagi[i] = wagaliczby(t[i]);
	}
	if (Sumy(wagi, 0, 0, 0, 0)) return true;
	else return false;
}

int main() {
	int t[N] = {30,35,3,4,2,6 }; //3 2 1 1 1,2
	cout << czyMoznaPodzielic(t);

}