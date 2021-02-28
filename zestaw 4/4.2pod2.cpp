/*
Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę napisać
funkcję który odpowiada na pytanie, czy w każdym wierszu tablicy występuje co
najmniej jedna liczba złożona wyłącznie z nieparzystych cyfr
*/
#include <iostream>
using namespace std;
const int MAX = 3;
bool czyzniep(int n) {
	if (n == 0) return false;
	while (n > 0) {
		if (n % 2 == 0) return false;
		else n /= 10;
	}
	return true;
}
bool czyjestjednawwierszu(int tab[MAX][MAX]) {
	int i = 0;
	int j = 0;
	int a = 1;
		while (a==1) {
			if (czyzniep(tab[i][j]) == 1) {
				i++;
				j = 0;
			}
			else {
				j++;
			}
			if (j == MAX)  return false;
			if (i == MAX) return true;
		}
}
int main() {
	int t[MAX][MAX] = { {12,16,14},{7,18,21},{54,67,91} };
	cout << czyjestjednawwierszu(t);
}