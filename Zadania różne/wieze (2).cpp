/*
20. Dana jest tablica t[N][N] (reprezentująca szachownicę) wypełniona liczbami
naturalnymi. Proszę napisać funkcję która ustawia na szachownicy dwie wieże, tak
aby suma liczb na „szachowanych” przez wieże polach była największa. Do funkcji
należy przekazać tablicę, funkcja powinna zwrócić położenie wież. Uwagazakładamy, że wieża szachuje cały wiersz i kolumnę z wyłączeniem pola na którym
stoi
*/
#include <iostream>
using namespace std;
const int N = 6;
int sumapol(int t[N][N], int sumykol[N], int sumywier[N], int w1, int w2, int k1, int k2) {
	return (sumykol[k1] + sumykol[k2] + sumywier[w1] + sumywier[w2] - 2 * t[w1][k1] - 2 * t[w2][k2] - t[w1][k2] - t[w2][k1]);
}
void najwsuma(int t[N][N]) {
	int sumakol[N];
	int sumawier[N];
	for (int i = 0; i < N; i++) {
		sumakol[i] = 0;
		sumawier[i] = 0;
	}
	int idx = 0;
	while (idx < N) {
		for (int i = 0; i < N; i++) {
			sumakol[idx] += t[i][idx];
			sumawier[idx] = t[idx][i];
		}
		idx++;
	}
	int najwsuma = 0;
	int w1=0, w2=0, k1=0, k2=0;
	for (int i = 0; i < N-1; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = 0; k < N-1; k++) {
				for (int l = k + 1; l < N; l++) {
					int suma = sumapol(t, sumakol, sumawier, i, j, k, l);
					if (suma > najwsuma) {
						najwsuma = suma;
						w1 = i;
						w2 = j;
						k1 = k;
						k2 = l;
					}
				}
			}
		}
	}
	cout << w1 << " " << k1 << " " << w2 << " " << k2 << " suma:" << najwsuma;
}
int main() {
	int t[N][N] = { {1,2,5,4,1,0},{2,3,4,1,2,1},{5,7,1,0,9,1},{2,1,1,1,0,2},{2,4,3,1,0,1},{7,3,2,1,1,2} };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	najwsuma(t);
}