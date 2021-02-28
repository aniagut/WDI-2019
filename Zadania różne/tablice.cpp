/*
22. Dana jest tablica int t[N][N] wypełniona przypadkowymi wartościami. Proszę
napisać funkcję, która dla zmiennej typu tablica zwraca numer wiersza w którym
występuje najdłuższy spójny fragment złożony z liczb o tej samej wartości. W
przypadku kilku fragmentów o tej samej długości należy zwrócić pozycję
pierwszego z nich.
*/
#include<iostream>
using namespace std;
const int N = 6;
int najdluzszyspojny(int t[N][N]) {
	int najdluzszy = -INT_MAX;
	int wiersz;
	int w = 0;
	while (w < N) {
		int j = 0;
		while(j<N-1){
			int dlugosc = 1;
			while (j < N && t[w][j] == t[w][j + 1]) {
				dlugosc++;
				j++;
			}
			if (dlugosc > najdluzszy) {
				najdluzszy = dlugosc;
				wiersz = w;
			}
			if (j < N) j++;
	}
		w++;
	}
	return wiersz;
}
int main() {
	int t[N][N] = { {1,2,3,4,5,6},{1,2,2,2,3,4},{3,3,3,3,3,1},{3,3,3,3,0,0},{1,7,1,2,2,2},{0,1,2,3,3,4} };
	cout << najdluzszyspojny(t);
}