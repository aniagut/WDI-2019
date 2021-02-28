#include <iostream>
using namespace std;
/*
Liczby naturalne a,b są komplementarne jeżeli ich suma jest liczbą pierwszą. Dana
jest tablica typu int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę
napisać funkcję, która zeruje elementy nie posiadające liczby komplementarnej.
*/
const int MAX = 5;
bool czypierwsza(int n) {
	int suma = 0;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) suma++;
		if (suma == 2) return false;
	}
	return true;
}
bool checkNumber(int n, int tab[MAX][MAX]) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (czypierwsza(n + tab[i][j])) return true;
		}
	}
	return false;
}
void zerujeniekomplem(int tab[MAX][MAX]) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (!checkNumber(tab[i][j], tab)) tab[i][j] = 0;
		}
	}
}
int main() {
	int tab[MAX][MAX] = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25} };
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	zerujeniekomplem(tab);
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cout << tab[i][j] << " ";
		}
		cout << endl;
	}
}