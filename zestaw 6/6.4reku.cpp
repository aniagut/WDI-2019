/*
„Waga” liczby jest określona jako ilość różnych czynników pierwszych liczby. Na
przykład waga(1)=0, waga(2)=1, waga(6)=2, waga(30)=3, waga(64)=1. Dana jest
tablica: int t[N]. Tablica zawiera liczby naturalne. Proszę napisać funkcję, która
sprawdza czy można elementy tablicy podzielić na 3 podzbiory o równych wagach. Do
funkcji należy przekazać wyłącznie tablicę, funkcja powinna zwrócić wartość typu
bool.
*/
#include <iostream>
#include <cmath>
using namespace std;
const int N = 5;
int wagaliczby(int n) {
	int waga = 0;
	int i = 2;
	int m = n;
	while(i<=m && n!=0 ) {
			if (n % i == 0) waga++;
			while (n % i == 0 && n!=0) n /= i;
			i++;
	}
	return waga;
}
void wagitab(int tab[N],int wagi[N]) {
	for (int i = 0; i < N; i++) {
		wagi[i] = wagaliczby(tab[i]);
	}
}
bool czyMozna(int wagi[N], int index, int sum1, int sum2, int sum3) {
	if (index == N && sum1 == sum2 && sum2 == sum3) return true;
	if (index == N) return false;
	else {
		return  czyMozna(wagi, index + 1, sum1 + wagi[index], sum2, sum3) || czyMozna(wagi, index + 1, sum1, sum2 + wagi[index], sum3) ||
			czyMozna(wagi, index + 1, sum1, sum2, sum3 + wagi[index]);
	}
}
int main() {
	int liczby[N] = { 1,6,3,4,5 }; //0 2 1 1 2
	int wagi[N] = { 0 };
	wagitab(liczby, wagi);
	cout << czyMozna(wagi, 0, 0, 0, 0);
}