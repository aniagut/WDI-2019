#include <iostream>
using namespace std;
const int MAX1 = 3;
const int MAX2 = 6;
int ile(int n) {
	int ile = 0;
	while (n > 0) {
		if (n % 2 == 1) ile++;
		n /= 2;
	}
	return ile;
}
bool czyistnieje(int t1[MAX1][MAX1], int t2[MAX2][MAX2]) {
	int t[MAX1 * MAX1];
	int idx = 0;
	for (int i = 0; i < MAX1; i++) {
		for (int j = 0; j < MAX1; j++) {
			t[idx] = ile(t1[i][j]);
			idx++;
		}
	}
	for (int i = 0; i + MAX1 - 1 < MAX2; i++) {
		for (int j = 0; j + MAX1 - 1 < MAX2; j++) {
			int ilezgodnych = 0;
			for (int a = i; a < i + MAX1; a++) {
				for (int b = j; b < j + MAX1; b++) {
					bool flag = false;
					int id = 0;
					while (!flag && id < MAX1 * MAX1) {
						if (t2[a][b] == t[id]) {
							flag = true;
							ilezgodnych++;
						}
						id++;
					}
				}
			}
			if (ilezgodnych > MAX1* MAX1 / 3) return true;
		}
	}
	return false;
}
int main() {
	int t1[MAX1][MAX1] = { {1,1,1},{1,1,1},{1,1,1} };
	int t2[MAX2][MAX2] = { {3,3,1,1,3,3},{3,1,1,3,3,3},{3,3,3,3,3,3},{3,3,3,3,3,3},{3,3,3,3,3,3},{3,3,3,3,3,3} };
	cout << czyistnieje(t1, t2);
}