#include <iostream>
using namespace std;
const int N = 5;

int sumatablicy(int t[N][N], int k1, int k2, int t1[N]) {
	int suma = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j != k1 && j != k2 && i != t1[j]) {
				suma += t[i][j];
			}
			if ((j == k1 || j == k2) && i != t1[k1] && i != t1[k2]) {
				suma += t[i][j];
			}
		}
	}
	return suma;
}

void polozenie(int t[N][N],int t1[N]) {
	int najwsuma = 0;
	int k1, k2;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int suma = sumatablicy(t, i, j, t1);
			if (suma > najwsuma) {
				najwsuma = suma;
				k1 = i;
				k2 = j;
			}
		}
	}
	cout << "Suma: " << najwsuma << endl;
	cout << k1 << " " << t1[k1] << endl;
	cout << k2 << " " << t1[k2] << endl;
	}

int main() {
	int t1[N] = { 1,4,0,2,2 };
	int t[N][N] = { {1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5} };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	polozenie(t, t1);
}