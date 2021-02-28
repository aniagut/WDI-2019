#include <iostream>
using namespace std;
/*
6. Dany jest ciąg zer i jedynek zapisany w tablicy int t[N]. Proszę napisać funkcję,
która odpowiada na pytanie czy jest możliwe pocięcie ciągu na kawałki z których
każdy reprezentuje liczbę pierwszą. Długość każdego z kawałków nie może przekraczać
30. Na przykład dla ciągu 111011 jest to możliwe, a dla ciągu 110100 nie jest
możliwe.
*/
const int N = 6;
int jakatoliczba(int t[N], int pocz, int konc) {
	int potega = 0;
	int liczba = 0;
	for (int i = konc; i >= pocz; i--) {
		liczba += t[i] * pow(2, potega);
		potega++;
	}
	return liczba;
}
bool isPrime(int n) {
	if (n == 0 || n == 1) return false;
	if(n==2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= sqrt(n); i=i + 2) {
		if (n % i == 0) return false;
	}
	return true;
}
bool czypierwszawbin(int t[N],int pocz,int konc) {
	return (isPrime(jakatoliczba(t, pocz, konc)));
}
bool czyMozliwe(int t[N],int pocz, int konc) {
	if (konc == N-1 && czypierwszawbin(t,pocz,konc)) return true;
	if(konc<N) {
		if (czypierwszawbin(t, pocz, konc)) return czyMozliwe(t, pocz, konc + 1) || czyMozliwe(t, konc + 1, konc + 2);
		else return czyMozliwe(t, pocz, konc + 1);
	}
	return false;
}
int main() {
	int t[N] = {0, 1, 0, 1,0,0};
	cout << czyMozliwe(t, 0, 0);
}