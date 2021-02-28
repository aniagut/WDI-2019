#include <iostream>
using namespace std;
const int MAX = 3;
void czyelementwystepujeraz(int tab[MAX][MAX], int czywyst[MAX][MAX]) {
	int x = 0;
	int y = 0;
	while (x < MAX) {
		while (y < MAX) {
			int suma= 0;
			for (int i = 0; i < MAX; i++) {
				for (int j = 0; j < MAX; j++) {
					if((tab[i][j]==tab[x][y])&&((i!=x)||(j!=y))) suma++;
				}
			} 
			if (suma == 0) czywyst[x][y] = true;
			else czywyst[x][y] = false;
			y++;
		}
		x++;
		y = 0;
	}
}
void zamiana(int a, int b) {
	int c = a;
	a = b;
	b = c;
}
void porzadkowator(int tab[MAX*MAX], int n) {
	int i = 0;
	int j = 0;
	while (j < 1) {
		int suma=0;
		for (int i = 0; i < n; i++){
			if (tab[i] > tab[i + 1]) {
				zamiana (tab[i], tab[i + 1]);
				suma++;
			}
		}
		if (suma == 0) j = 1;
	}
}
void przepisywator(int tab[MAX][MAX], int tab1[MAX * MAX]) {
	int czywyst[MAX][MAX];
	czyelementwystepujeraz(tab, czywyst);
	int k = 0;
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				while (k < MAX*MAX) {
					if (czywyst[i][j] == true) {
						tab1[k] = tab[i][j];
				}
			}
		}
	}
		porzadkowator(tab1, k);
		if (k < MAX*MAX - 1) {
			for (int i = k + 1; i < MAX * MAX; i++) {
				tab1[i] = 0;
			}
		}
		for (int a = 0; a < MAX * MAX; a++) {
			cout << tab1[a] << " ";
		}
}
int main() {
	int t[MAX][MAX] = { {99,11,7},{12,11,6},{3,7,76} };
	int t2[MAX*MAX] = {0};
	przepisywator(t, t2);
}