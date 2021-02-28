#include <iostream>
using namespace std;
/*

21. Dana jest tablica int t[N][N] (reprezentująca szachownicę) wypełniona liczbami
naturalnymi. W każdej kolumnie znajduje się dokładnie jedna wieża, której numer
wiersza zawiera tablica int w[N]. Proszę napisać funkcję która wybiera do
usunięcia z szachownicy dwie wieże, tak aby suma liczb na polach szachowanych
przez pozostałe wieże była najmniejsza. Do funkcji należy przekazać tablice t i
w, funkcja powinna zwrócić numery kolumn z których usunięto wieże. Uwaga -
zakładamy, że wieża szachuje cały wiersz i kolumnę z wyłączeniem pola na którym
stoi
*/
const int N = 6;
int sumapol(int t[N][N],int w[N], int sumakol[N], int sumawier[N], int k1, int k2){
	int suma = 0;
	for (int i = 0; i < N; i++) {
		if (i != k1 && i != k2) {
			suma += sumakol[i];
		}
	}
	for (int i = 0; i < N && i!=k1 && i!=k2; i++) {
		int cos = 0;
		for (int j = i - 1; j >= 0 && j!=k1 && j!=k2; j++) {
			if (w[j] == w[i]) cos = 1;
		}
		if (cos == 0) {
			suma += (t[w[i]][k1] + t[w[i]][k2]);
		}
	}
	for (int i = 0; i < N && i != k1 && i != k2;i++) {
		suma -=  t[w[i]][i];
	}
	return suma;
}
void jakieusunac(int t[N][N], int w[N]) {
	int sumakol[N];
	int sumawier[N];
	for (int i = 0; i < N; i++) {
		sumakol[i] = 0;
		sumawier[i] = 0;
	}
	int idx = 0;
	while (idx < N) {
		for (int i = 0; i < N; i++) {
			sumakol[idx] = t[i][idx];
			sumawier[idx] = t[idx][i];
			idx++;
		}
	}
	int najwsuma = 0;
	int k1 = 0;
	int k2 = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int suma=sumapol(t,w,sumakol,sumawier,i,j);
			if (suma > najwsuma) {
				najwsuma = suma;
				k1 = i;
				k2 = j;
			}
		}
	}
	cout << "suma: " << najwsuma << " " << k1 << " " << k2 << endl;
}
int main() {
	int t[N][N] = { {1,5,1,9,1,2},{8,4,0,2,4,3},{6,3,4,4,5,1},{7,2,9,1,6,3},{3,2,9,1,0,2},{7,2,9,1,1,4} };
	int w[N] = { 1,0,3,5,2,3 };
	for (int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			cout << t[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << w[i] << " ";
	}
	cout << endl<< endl;
	jakieusunac(t, w);
}