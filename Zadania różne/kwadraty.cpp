#include <iostream>
using namespace std;
const int N = 8;
bool kwadrat(int t[N][N], int k) {
	int dlugosc;
	if (N % 2 == 0) dlugosc = N - 1;
	else dlugosc = N;
	while (dlugosc >= 3) {
		for (int i = 0; i + dlugosc - 1 < N; i++) {
			for (int j = 0; j + dlugosc - 1 < N; j++) {
				if (t[i][j] * t[i + dlugosc - 1][j + dlugosc - 1] * t[i][j + dlugosc - 1] * t[i + dlugosc - 1][j] == k) {
					cout << (i + dlugosc) / 2 << " , " << (j + dlugosc) / 2 << endl;
					return true;
				}
			}
		}
		dlugosc -= 2;
	}
	cout << " NIE MA" << endl;
	return false;
}
int main() {
	int t1[N][N] = { {1,2,3,4,5,6,7,8},{8,7,6,5,4,3,2,1},{2,2,2,2,3,3,3,3},{4,4,4,4,5,5,5,5},{1,2,1,2,3,4,3,4},{2,2,2,2,2,2,2,2},{1,1,1,1,1,1,1,1},{2,2,3,3,4,4,5,5} };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << t1[i][j] << " ";
		}
		cout << endl;
	}
	cout << kwadrat(t1, 16);
}