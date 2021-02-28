#include <iostream>
#include <cmath>
using namespace std;
const int N=10;
void zamiananabindotab(int n, int t[N]) {
	int i = 0;
	while (n != 0) {
		t[i] = n % 2;
		n /= 2 ;
	}
}
void zerowanietabl(int tab[N]) {
	for (int i = 0; i < N; i++) tab[i] = 0;
}
bool czymoznaodwazyc(int masa, int t1[N], int t2[N], int tab[N]) {
	for (int i = 1; i < pow(2, N); i++) {
		int suma1 = 0;
		zerowanietabl(t1);
		zamiananabindotab(i, t1);
		for (int j = 0; j < N; j++) {
			if (t1[i] == 1) suma1 += tab[i];
		}
		if (masa == suma1) return true;
		for (int i = 1; i < pow(2, N); i++) {
			int suma2 = 0;
			zerowanietabl(t2);
			zamiananabindotab(i, t2);
			for (int j = i+1; j < N; j++) {
				if (t2[i] == 1) suma1 += tab[i];
			}
			if (suma2 == masa || abs(suma1 - suma2) == masa) return true;
		}
	}
	return false;
}
int main() {
	int tab[N] = { 3,2,5,7 };
	int t1[N];
	int t2[N];
	int masa = 13;
	cout <<czymoznaodwazyc(masa, t1, t2, tab);
}