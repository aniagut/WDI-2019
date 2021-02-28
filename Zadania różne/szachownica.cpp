/*
8. Szachownica jest reprezentowana przez tablicę int t[8][8] wypełnioną liczbami
naturalnymi zawierającymi koszt przebywania na danym polu szachownicy. Król
szachowy znajduje się w wierszu 0 i kolumnie k. Król musi w dokładnie 7 ruchach
dotrzeć do wiersza 7. Proszę napisać funkcję, która wyznaczy minimalny koszt
przejścia króla. Do funkcji należy przekazać tablicę t oraz startową kolumnę k.
Koszt przebywania na polu startowym i ostatnim także wliczamy do kosztu przejścia.

*/
#include <iostream>
using namespace std;
const int N = 8;
void przejscie(int t[N][N], int wiersz, int kolumna,int iloscr,int koszt, int* najmkoszt) {
	if (wiersz == 7 && iloscr == 7) {
		if (koszt < *najmkoszt) *najmkoszt = koszt;
	}
	if (iloscr < 7) {
		if (wiersz + 1 < N && kolumna - 1 >= 0 && kolumna + 1 < N) {
			przejscie(t, wiersz + 1, kolumna, iloscr + 1, koszt + t[wiersz + 1][kolumna], najmkoszt);
			przejscie(t, wiersz + 1, kolumna + 1, iloscr + 1, koszt + t[wiersz + 1][kolumna + 1], najmkoszt);
			przejscie(t, wiersz + 1, kolumna - 1, iloscr + 1, koszt + t[wiersz + 1][kolumna - 1], najmkoszt);
		}
		else if (kolumna + 1 >= N) {
			przejscie(t, wiersz + 1, kolumna, iloscr + 1, koszt + t[wiersz + 1][kolumna], najmkoszt);
			przejscie(t, wiersz + 1, kolumna - 1, iloscr + 1, koszt + t[wiersz + 1][kolumna - 1], najmkoszt);
		}
		else if (kolumna - 1 < 0) {
			przejscie(t, wiersz + 1, kolumna, iloscr + 1, koszt + t[wiersz + 1][kolumna], najmkoszt);
			przejscie(t, wiersz + 1, kolumna + 1, iloscr + 1, koszt + t[wiersz + 1][kolumna + 1], najmkoszt);
		}
	}
}
int funct(int t[N][N]) {
	int najmkoszt = INT_MAX;
	przejscie(t, 0, 3, 0, t[0][3], &najmkoszt);
	return najmkoszt;
}
int main() {
	int t[N][N] = { {1,1,1,0,1,1,1,1},{1,1,0,1,1,1,1,1},{1,0,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{1,0,1,1,1,1,1,1},{1,1,0,1,1,1,1,1},{1,1,1,0,1,1,1,1},{1,1,1,1,0,1,1,1} };
	
	cout << funct(t);
}