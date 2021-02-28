/*
2. Dane są dwie tablice mogące pomieścić taką samą liczbę elementów:
 int t1[N][N];
 int t2[M]; // M = N*N
W każdym wierszu tablicy t1 znajdują się uporządkowane niemalejąco (w obrębie wiersza) liczby
naturalne. Proszę napisać fragment programu przepisujący wszystkie liczby z tablicy t1 do t2, tak aby
liczby w tablicy t2 były uporządkowane niemalejąco.
*/
#include <iostream>
using namespace std;
const int N = 8;
void przepisanie(int t[N][N], int t1[N * N]) {
	int tabidx[N];
	for (int i = 0; i < N; i++) tabidx[i] = 0;
	int idx = 0;
	while (idx < N*N) {
		int najm = INT_MAX;
		int najmidx;
		for (int i = 0; i < N; i++) {
			if (tabidx[i] < N) {
				if (t[i][tabidx[i]] <najm) {
					najm = t[i][tabidx[i]];
					najmidx = i;
				}
			}
		}
		t1[idx] = najm;
		idx++;
		tabidx[najmidx]++;
	}
}
int main() {
	int t[N][N] = { {1,2,3,4,5,6,7,8},{4,6,7,10,11,12,13},{0,1,9,10,12,13,17,62},{1,1,1,1,1,2,2,2},{9,14,17,24,29,32,32,32},{1,1,2,2,3,3,4,5},{10,19,28,37,46,55,64,73}, {30, 31, 33, 41,47,57,67,69} };
	int t1[N * N];
	for (int i = 0; i < N * N; i++) t1[i] = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << t[i][j] << " ";
		}
		cout<< endl;
	}
	przepisanie(t, t1);
	for (int i = 0; i < N * N; i++) {
		cout << t1[i] << " ";
	}

}
