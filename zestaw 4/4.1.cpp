#include <iostream>
using namespace std;
const int MAX = 10;
void fillTable(int t[MAX][MAX]) {
	int x = MAX / 2; //zaczynamy w srodku tablicy
	int y = MAX / 2;
	int dlugosc_ciagu = 1;
	int m = 0;
	int kierunek = 1; // 1 w lewo, 2 w gore, 3 w prawo, 0 w dol;
	int i = 1;
	while (i <= MAX * MAX) {
		for (int n = 1; n <= dlugosc_ciagu; n++) {
			t[x][y] = i;
			i++;
			if (kierunek % 4 == 0) y++;
			else if (kierunek % 4 == 1) x--;
			else if (kierunek % 4 == 2) y--;
			else x++;
		}
		kierunek++;
		m++;
		if (m % 2 == 0) dlugosc_ciagu++;
	}
}

int main() {
	int tab[MAX][MAX];
	fillTable(tab);
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (tab[i][j] <= 9) {
				cout << tab[j][i] << "  ";
			}
			else {
				cout << tab[j][i] << " ";
			}
		}
		cout << endl;
	}
	return 0;
}