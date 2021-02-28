#include <iostream>
using namespace std;
/*
9. Dana jest tablica wypełniona liczbami naturalnymi:
int t[MAX][MAX];
Proszę napisać funkcję, która w poszukuje w tablicy kwadratu o liczbie pól
będącej liczbą nieparzystą większą od 1, którego iloczyn 4 pól narożnych wynosi
k. Do funkcji należy przekazać tablicę i wartość k. Funkcja powinna zwrócić
informacje czy udało się znaleźć kwadrat oraz współrzędne (wiersz, kolumna)
środka kwadratu.
*/
const int N = 5;
bool czydasie(int t[N][N], int dlugosc, int iloczyn, int k,int proba) {
	if (iloczyn == k) return true;
	if (proba == 0) {
		for (int i = 0; i < N-dlugosc; i++) {
			for (int j = 0; j < N-dlugosc; j++) {
				if (czydasie(t, dlugosc, iloczyn * t[i][j] * t[i][j + dlugosc - 1] * t[i + dlugosc - 1][j] * t[i + dlugosc - 1][j + dlugosc - 1], k, proba + 1)||czydasie(t,dlugosc+2,iloczyn,k,proba)) {
					cout << "wiersz: " << i << " kolumna: " << j << endl;
					return true;
				}
			}
		}
	}
	return false;
}
int main() {
	int t[N][N] = { {3,2,3,2,3},{1,2,3,2,1},{2,4,6,4,2},{2,4,6,4,2},{3,1,1,1,3} };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	cout << czydasie(t,3, 1, 36, 0);
}