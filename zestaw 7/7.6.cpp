#include <iostream>
using namespace std;
/*
Dany jest ciąg zer i jedynek zapisany w tablicy int t[N]. Proszę napisać funkcję,
która odpowiada na pytanie czy jest możliwe pocięcie ciągu na kawałki z których
każdy reprezentuje liczbę pierwszą. Długość każdego z kawałków nie może przekraczać
30. Na przykład dla ciągu 111011 jest to możliwe, a dla ciągu 110100 nie jest
możliwe.
*/
const int N = 7;
int zamiananadec(int n) { //111
	int dlugosc = -1; //-1
	int m = n; //111
	while (m != 0) { //1
		m /= 10; //0
		dlugosc++; //2
	}
	int liczbawdec = 0;
	if (n % 2 == 1) liczbawdec ++; //liczbawdec=1;
	n /= 10; //11
	for (int i = 1; i <= dlugosc; i++) { //2
		if (n % 2 == 1) { //tak
			liczbawdec += pow(2, i); //1+2 +4
		}
		n /= 10; //0
	}
	return liczbawdec;
}
bool isPrimedec(int n) {
	int m = zamiananadec(n);
	if (m == 0 || m == 1) return false;
	else if (m == 2) return true;
	else if (m % 2 == 0) return false;
	else {
		for (int i = 3; i <= sqrt(m); i = i + 2) {
			if (m % i == 0) return false;
		}
		return true;
	}
}
bool czySiemDa(int t[N], int idx, int liczba) {
	if (idx == N && isPrimedec(liczba)) return true;
	else if (idx == N && !isPrimedec(liczba)) return false;
	else {
		if (isPrimedec(liczba)) {
			return czySiemDa(t, idx + 1, liczba * 10 + t[idx]) || czySiemDa(t, idx + 1, 0);
		}
		else
			return czySiemDa(t, idx + 1, liczba * 10 + t[idx]);
	}
}
int main() {
	int t[N] = { 1,0,1,0,1,1,0 };
	int idx = 0;
	int liczba = 0;
	cout << czySiemDa(t, idx, liczba);
}