/*
6. Dany jest ciąg zer i jedynek zapisany w tablicy int t[N]. Proszę napisać funkcję,
która odpowiada na pytanie czy jest możliwe pocięcie ciągu na kawałki z których
każdy reprezentuje liczbę pierwszą. Długość każdego z kawałków nie może przekraczać
30. Na przykład dla ciągu 111011 jest to możliwe, a dla ciągu 110100 nie jest
możliwe.
*/
#include <iostream>
using namespace std;
const int N = 6;
bool isPrime(int n) {
	if (n == 0 || n==1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= sqrt(n); i = i + 2) {
		if (n % i == 0) return false;
	}
	return true;
}
bool czybin(int t[N], int p, int k) {
	int co = 1;
	int liczba = 0;
	for (int i = k; i >= p; i--) {
		liczba += (t[i] *co);
		co *= 2;
	}
	if (isPrime(liczba)) return true;
	else return false;
}
bool czyMozliwe(int t[N], int p, int k) {
	if (k == N-1 && czybin(t,p,k)) return true;
	if (k < N-1) {
		if (czybin(t, p, k)) {
			return czyMozliwe(t, k + 1, k + 1) || czyMozliwe(t, p, k + 1);
		}
		else return czyMozliwe(t, p, k + 1);
	}
	return false;
}
int main() {
	int t[N] = {1,1,1,0,1,1};
	cout << czyMozliwe(t, 0, 0);
}