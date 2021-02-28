/*5. Problem skoczka szachowego (treść oczywista)  przechodzi przez wszystkie pola, w kazdym polu tylko raz*/
#include <iostream>
using namespace std;
const int N = 3;
bool czyMozna(int t[N][N],int destw, int destk) {
	if (t[destw][destk]) return true;
	return false;
}
bool czyPrzejdzie(int t[N][N], int w, int k, int suma) {
	if (suma == N * N) return true;
	if (w < N && k < N) {
		if ((w - 1 >= 0) && (k - 2 >= 0) && czyMozna(t, w - 1, k - 2)) { //1
			t[w - 1][k - 2] = 1;
			suma++;
			if (czyPrzejdzie(t, w - 1, k - 2, suma)) return true;
			t[w - 1][k - 2] = 0;
			suma--;
		}
		if ((w + 1 <= N-1) && (k - 2 >= 0) && czyMozna(t, w + 1, k - 2)) { //2
			t[w + 1][k - 2] = 1;
			suma++;
			if (czyPrzejdzie(t, w + 1, k - 2, suma)) return true;
			t[w + 1][k - 2] = 0;
			suma--;
		}
		if ((w -2 >= 0) && (k - 1 >= 0) && czyMozna(t, w -2, k - 1)) { //3
			t[w -2][k - 1] = 1;
			suma++;
			if (czyPrzejdzie(t, w -2, k - 1, suma)) return true;
			t[w -2][k - 1] = 0;
			suma--;
		}
		if ((w +2 <= N-1) && (k - 1 >= 0) && czyMozna(t, w +2 , k - 1)) { //4
			t[w +2][k - 1] = 1;
			suma++;
			if (czyPrzejdzie(t, w + 2, k - 1, suma)) return true;
			t[w + 2][k - 1] = 0;
			suma--;
		}
		if ((w -2 >=0) && (k + 1 <=N-1) && czyMozna(t, w -2, k + 1)) { //5
			t[w - 2][k + 1] = 1;
			suma++;
			if (czyPrzejdzie(t, w - 2, k + 1, suma)) return true;
			t[w - 2][k + 1] = 0;
			suma--;
		}
		if ((w + 2 <=N-1) && (k + 1 <= N - 1) && czyMozna(t, w + 2, k + 1)) { //6
			t[w + 2][k + 1] = 1;
			suma++;
			if (czyPrzejdzie(t, w + 2, k + 1, suma)) return true;
			t[w + 2][k + 1] = 0;
			suma--;
		}
		if ((w + 1 <= N - 1) && (k + 2 <= N - 1) && czyMozna(t, w + 1, k + 2)) { //7
			t[w + 1][k + 2] = 1;
			suma++;
			if (czyPrzejdzie(t, w + 1, k + 2, suma)) return true;
			t[w + 1][k + 2] = 0;
			suma--;
		}
		if ((w -1 >=0) && (k + 2 <= N - 1) && czyMozna(t, w - 1, k + 2)) { //8
			t[w - 1][k + 2] = 1;
			suma++;
			if (czyPrzejdzie(t, w - 1, k + 2, suma)) return true;
			t[w - 1][k + 2] = 0;
			suma--;
		}
	}
	return false;
}
bool func() {
	int t[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			t[i][j] = 0;
		}
	}
	return czyPrzejdzie(t, 0, 0, 0);
}
int main() {
	cout << func();
}