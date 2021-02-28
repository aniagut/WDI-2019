/*
17. W szachownicy o wymiarach 8x8 każdemu z pól przypisano liczbę naturalną. Na ruchy
króla nałożono dwa ograniczenia: król może przesunąć się na jedno z 8 sąsiednich
pól jeżeli ostatnia cyfra liczby na polu na którym stoi jest mniejsza od pierwszej
cyfry liczby pola docelowego, oraz w drodze do obranego celu (np. narożnika) król
nie może wykonać ruchu, który powoduje oddalenie go od celu. Dana jest globalna
tablica int t[8][8] wypełniona liczbami naturalnymi reprezentująca szachownicę.
Lewy górny narożnik ma współrzędne w=0 i k=0. Proszę napisać funkcję sprawdzającą
czy król może dostać się z pola w,k do prawego dolnego narożnika .
*/
#include <iostream>
using namespace std;
int pierwszacyfra(int n) {
	while (n >= 10) n /= 10;
	return n;
}
bool czydostaniesie(int t[8][8], int w, int k) {
	if (w ==7 && k ==7) return true;
	if (w < 7 || k < 7) {
		if (w + 1 < 8 && k + 1 < 8 && t[w][k] % 10 < pierwszacyfra(t[w + 1][k + 1])) {
			if(czydostaniesie(t,w+1,k+1)) return true;
		}
		if (w + 1 < 8 && t[w][k] % 10 < pierwszacyfra(t[w + 1][k])) {
			if (czydostaniesie(t, w + 1, k)) return true;
		}
		if (k + 1 < 8 && t[w][k] % 10 < pierwszacyfra(t[w][k + 1])) {
			if (czydostaniesie(t, w, k + 1)) return true;
		}
	}
return false;
}
int main() {
	int t[8][8] = { {17,84,31,14,51,62,70,81}, {12,31,51,18,10,21,22,81},{11,61,92,18,10,21,71,91},{10,12,21,71,14,30,24,28},{10,20,30,11,52,63,99,10},{11,24,21,44,12,10,65,12},{12,62,32,18,19,97,10,61},{12,32,14,56,55,48,91,11} };
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
}
	cout << czydostaniesie(t, 0, 0);
}