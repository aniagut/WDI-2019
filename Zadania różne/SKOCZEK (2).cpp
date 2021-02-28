#include <iostream>
using namespace std;

/*
5. Problem skoczka szachowego (treść oczywista)
*/
const int N = 6;

bool czydotrze(int ruchy, int t[N][N], int w, int k) {
	if (ruchy == N * N) return true;
	if (ruchy < N * N) {
		if (w - 2 >= 0 && k - 1 >= 0) { //1
			if (t[w - 2][k - 1] == 0) {
				t[w - 2][k - 1] = ruchy + 1;
				if (czydotrze(ruchy + 1, t, w - 2, k - 1)) return true;
				t[w - 2][k - 1] = 0;
			}
		}
		if (w - 2 >= 0 && k + 1 <N ) { //2
			if (t[w - 2][k + 1] == 0) {
				t[w - 2][k + 1] = ruchy + 1;
				if (czydotrze(ruchy + 1, t, w - 2, k + 1)) return true;
				t[w - 2][k + 1] = 0;
			}
		}
		if (w - 1 >= 0 && k - 2 >= 0) { //3
			if (t[w - 1][k - 2] == 0) {
				t[w - 1][k - 2] = ruchy + 1;
				if (czydotrze(ruchy + 1, t, w - 1, k - 2)) return true;
				t[w - 1][k - 2] = 0;
			}
		}
		if (w - 1 >= 0 && k + 2 <N) { //4
			if (t[w - 1][k +2] == 0) {
				t[w - 1][k +2] = ruchy + 1;
				if (czydotrze(ruchy + 1, t, w - 1, k +2)) return true;
				t[w - 1][k +2] = 0;
			}
		}
		if (w +2 < N && k - 1 >= 0) { //5
			if (t[w + 2][k - 1] == 0) {
				t[w + 2][k - 1] = ruchy + 1;
				if (czydotrze(ruchy + 1, t, w + 2, k - 1)) return true;
				t[w + 2][k - 1] = 0;
			}
		}
		if (w + 2 <N && k + 1 <N) { //6
			if (t[w + 2][k + 1] == 0) {
				t[w + 2][k + 1] = ruchy + 1;
				if (czydotrze(ruchy + 1, t, w + 2, k + 1)) return true;
				t[w + 2][k + 1] = 0;
			}
		}
		if (w +1 <N && k - 2 >= 0) { //7
			if (t[w +1][k - 2] == 0) {
				t[w +1][k - 2] = ruchy + 1;
				if (czydotrze(ruchy + 1, t, w +1, k - 2)) return true;
				t[w +1][k - 2] = 0;
			}
		}
		if (w +1 <N  && k +2 <N ) { //8
			if (t[w +1][k +2] == 0) {
				t[w +1][k +2] = ruchy + 1;
				if (czydotrze(ruchy + 1, t, w +1, k +2)) return true;
				t[w +1][k +2] = 0;
			}
		}
	}
	return false;
}
int main() {
	int t[N][N] = { {1,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,0} };
	cout << czydotrze(1, t, 0, 0)<< endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
}