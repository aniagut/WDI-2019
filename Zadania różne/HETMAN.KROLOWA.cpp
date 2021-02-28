#include <iostream>
using namespace std;
/*
14. Problem 8 Hetmanów (treść oczywista)
Problem ośmiu hetmanów – hetman jest figurą szachową, która bije figury znajdujące się w tej samej kolumnie,
wierszu lub przekątnej, co on sam. W jaki sposób rozstawić osiem hetmanów na tradycyjnej szachownicy 8x8 tak, 
aby wzajemnie się nie atakowały? Ile jest możliwych rozstawień? Przez rozstawienie podstawowe bądź rozwiązanie
podstawowe należy rozumieć rozwiązanie z dokładnością do izomorfizmu, tzn. z uwzględnieniem wszystkich pokrewnych
pozycji wynikających z odbić zwierciadlanych i obrotów.
*/
const int N = 4;
bool isSafe(int t[N][N], int w, int k) { //gora
	for (int i = 0; i < w; i++) {
		if (t[i][k] == 1) return false;
	}
	int i, j;
	for (i = w-1, j = k-1; i >= 0 && j >= 0; i--, j--) { //lewy skos
		if (t[i][j] == 1) return false;
	}
	for (i = w - 1, j = k + 1; i >=0 && j < N; i--, j++) { //prawy skos
		if (t[i][j] == 1) return false;
	}
	return true;
}
bool hetman(int t[N][N], int w, int ile) {
	if (ile == N) return true;
	if (ile < N) {
		for (int i = 0; i < N; i++) {
			if (isSafe(t, w, i)) {
				t[w][i] = 1;
				if (hetman(t, w + 1, ile + 1)) return true;
				t[w][i] = 0;
			}
		}
	}
	return false;
}
int main() {
	int t[N][N] = { {0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0} };
	cout << hetman(t, 0, 0)<< endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	} 
}