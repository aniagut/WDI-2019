#include<iostream>
using namespace std;

/*
8. Szachownica jest reprezentowana przez tablicę int t[8][8] wypełnioną liczbami
naturalnymi zawierającymi koszt przebywania na danym polu szachownicy. Król
szachowy znajduje się w wierszu 0 i kolumnie k. Król musi w dokładnie 7 ruchach
dotrzeć do wiersza 7. Proszę napisać funkcję, która wyznaczy minimalny koszt
przejścia króla. Do funkcji należy przekazać tablicę t oraz startową kolumnę k.
Koszt przebywania na polu startowym i ostatnim także wliczamy do kosztu przejścia
*/
const int N = 8;
void czydotrze(int t[N][N], int w, int k, int ruchy, int koszt, int* najmkoszt) {
	if (ruchy == 7) {
		if (koszt < *najmkoszt) *najmkoszt = koszt;
	}
	if (ruchy < 7) {
		czydotrze(t, w + 1, k, ruchy + 1, koszt + t[w + 1][k], najmkoszt);
		if (k - 1 >= 0) {
			czydotrze(t, w + 1, k - 1, ruchy + 1, koszt + t[w + 1][k - 1], najmkoszt);
		}
		if (k + 1 < N) {
			czydotrze(t, w + 1, k + 1, ruchy+1, koszt + t[w + 1][k + 1], najmkoszt);
		}
	}
}
int najmniejszy(int t[N][N], int k) {
	int najmniejszy = INT_MAX;
	czydotrze(t, 0, k, 0, t[0][k], &najmniejszy);
	return najmniejszy;
}
int main() {
	int t[N][N] = { {0,1,2,3,4,5,6,7},{0,1,2,3,4,5,6,7},{0,1,2,3,4,5,6,7},{0,1,2,3,4,5,6,7},{0,1,2,3,4,5,6,7},{0,1,2,3,4,5,6,7},{0,1,2,3,4,5,6,7},{0,1,2,3,4,5,6,7} };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << t[i][j] << " ";
		}
		cout << endl;
	}
	cout << najmniejszy(t, 6);
}
