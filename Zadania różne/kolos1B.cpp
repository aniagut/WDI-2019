/*
Zad. 1. Dane są dwie tablice int t1[N], int t2[N] wypełnione liczbami naturalnymi. Proszę napisać funkcję, która
sprawdza czy z każdej z tablic można wyciąć po jednym kawałku, tak aby suma elementów w obu kawałkach była:
iloczynem dokładnie dwóch liczb pierwszych. Oba kawałki powinny być jednakowej długości
*/
#include <iostream>
using namespace std;
const int N = 10;
bool isPrime(int n) {
	if (n == 0 || n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
bool warunek(int suma1, int suma2) {
	if (suma1 + suma2 <= 2)return false;
	for (int i = 2; i <=sqrt(suma1 + suma2); i++) {
		if ((suma1 + suma2) % i == 0){
			if (isPrime(i) && isPrime(((suma1 + suma2) / i))) return true;
		}
	}
	return false;
}
bool func(int t1[N], int t2[N]) {
	int dlugosc = 1;
	while (dlugosc <= N) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int suma1 = 0;
				int suma2 = 0;
				for (int a = i; a < i + dlugosc; a++) {
					suma1 += t1[a];
				}
				for (int b = j; b < j + dlugosc; b++) {
					suma2 += t2[b];
				}
				if (warunek(suma1, suma2)) {
					cout << i << " " << j << " " << dlugosc << " " << suma1 << " " << suma2<< endl;
					return true;
				}
			}
		}
		dlugosc++;
	}
	return false;
}
int main() {
	int t1[N] = { 4,10,4,2,6,7,1,9,2,9 };
	int t2[N] = { 4,7,12,7,9,1,4,12,4,1};
	cout << func(t1, t2);

} 