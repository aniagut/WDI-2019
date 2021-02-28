/*
8. Dana jest tablica wypełniona liczbami naturalnymi:
int t[MAX][MAX];
Proszę napisać funkcję, która w poszukuje w tablicy najdłuższego ciągu
geometrycznego leżącego ukośnie w kierunku prawo-dół, liczącego co najmniej 3
elementy. Do funkcji należy przekazać tablicę. Funkcja powinna zwrócić
informacje czy udało się znaleźć taki ciąg oraz długość tego ciągu.
*/
#include <iostream>
using namespace std;
const int N = 5;
int szukajciagu(int t[N][N]) {
	int i, j;
	int najwdlugosc = 0;
	for (i = 0; i < N - 2; i++) {
		for (int j = 0; j < N - 2; j++) {
			int dlugosc = 2;
			float pierwszy = t[i][j];
			float drugi = t[i + 1][j + 1];
			float iloraz = drugi / pierwszy;
			int a = i + 2;
			int b = j + 2;
			bool flag = true;
			while (a < N && b < N && flag) {
				flag = false;
				if (t[a - 1][b - 1] * iloraz == t[a][b]) {
					flag = true;
					dlugosc++;
					a++;
					b++;
				}
			}
			if (dlugosc > najwdlugosc) najwdlugosc = dlugosc;
		}
	}
	if (najwdlugosc > 2) return najwdlugosc;
	else return -1;
}	
int main() {
	int t[N][N] = { {1,2,6,2,2},{8,2,4,5,6},{2,1,4,8,2},{2,3,2,1,16},{1,9,3,2,3} };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	cout << szukajciagu(t);
}