/*
17. W szachownicy o wymiarach 8x8 każdemu z pól przypisano liczbę naturalną. Na ruchy
króla nałożono dwa ograniczenia: król może przesunąć się na jedno z 8 sąsiednich
pól jeżeli ostatnia cyfra liczby na polu na którym stoi jest mniejsza od pierwszej
cyfry liczby pola docelowego, oraz w drodze do obranego celu (np. narożnika) król
nie może wykonać ruchu, który powoduje oddalenie go od celu. /////////// Dana jest globalna
tablica int t[8][8] wypełniona liczbami naturalnymi reprezentująca szachownicę.
Lewy górny narożnik ma współrzędne w=0 i k=0. Proszę napisać funkcję sprawdzającą
czy król może dostać się z pola w,k do prawego dolnego narożnika .
*/
#include <iostream>
using namespace std;
const int N = 5;
int pierwszaliczba(int n) {
	while (n >= 10) n /= 10;
	return n;
}
bool czytrafi(int t[N][N], int w, int k) {
	if (w == N - 1 && k == N - 1) return true;
	if (w < N - 1 && k < N - 1) {
		if (t[w][k] % 10 < pierwszaliczba(t[w + 1][k + 1])) if (czytrafi(t, w + 1, k + 1)) return true;
		if (t[w][k] % 10 < pierwszaliczba(t[w][k + 1])) if (czytrafi(t, w, k + 1)) return true;
		if (t[w][k] % 10 < pierwszaliczba(t[w + 1][k])) if (czytrafi(t, w + 1, k)) return true;
	}
	else if (w == N - 1 && k < N - 1) {
		if (t[w][k] % 10 < pierwszaliczba(t[w][k + 1])) if (czytrafi(t, w, k + 1)) return true;
	}
	else if (w < N - 1 && k == N - 1) {
		if (t[w][k] % 10 < pierwszaliczba(t[w + 1][k])) if (czytrafi(t, w + 1, k)) return true;
	}
	return false;
 }
int main() {
	int t[N][N] = { {12,13,14,15,16},{33,11,45,32,87},{96,15,63,12,10},{82,18,46,20,51},{23,61,78,95,41} };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	cout << czytrafi(t, 0, 0);
}