#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 10;
void wypelniampospirali(int tab[MAX][MAX]) {
	int x = MAX / 2;
	int y = MAX / 2;
	int dlugoscciagu = 1;
	int kierunek = 0;
	int m = 0;
	int i = 1;
	while (i <= MAX * MAX) {
		for (int n = 1; n <= dlugoscciagu; n++) {
			tab[x][y] = i;
			i++;
			if (kierunek % 4 == 0) x--;
			else if (kierunek % 4 == 1) y--;
			else if (kierunek % 4 == 2) x++;
			else y++;
		}
		kierunek++;
		m++;
		if (m % 2 == 0) dlugoscciagu++;
	}
}
int main() {
	int t[MAX][MAX];
	wypelniampospirali(t);
	for (int j = 0; j < MAX; j++) {
		for (int i = 0; i < MAX; i++) {
			if (t[i][j] >= 10) cout << t[i][j] << " ";
			else cout << t[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}