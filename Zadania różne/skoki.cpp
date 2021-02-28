/*
25. Tablica t[N] jest wypełniona liczbami naturalnymi. Skok z pola i-tego można wykonać
na pola o indeksach i+k, gdzie k jest czynnikiem pierwszym liczby t[i] (mniejszym
od niej samej). Napisz funkcję, która sprawdza, czy da się przejść z pola 0 do N-1
– jeśli się da, zwraca ilość skoków, jeśli się nie da, zwraca -1.
*/
#include <iostream>
using namespace std;
const int N = 10;
int czynnik(int n) {
	if (n <= 3) return 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) return i;
	}
	return 0;
}
int skoki(int t[N], int idx, int skok) {
	if (idx == N - 1) return skok;
	if (idx < N-1 && czynnik(t[idx] != 0)) {
		int czynn = czynnik(t[idx]);
		return skoki(t, idx + czynn, skok+1);
	}
}
int main() {
	cout << czynnik(14);
	int t[N] = { 4,1,14,1,9,1,1,4,1,1 };
	cout << skoki(t, 0, 0);
}