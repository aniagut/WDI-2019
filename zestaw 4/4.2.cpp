#include <iostream>
using namespace std;
/*
Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę napisać
funkcję który odpowiada na pytanie, czy w każdym wierszu tablicy występuje co
najmniej jedna liczba złożona wyłącznie z nieparzystych cyfr.
*/
const int MAX = 5;
bool checkNumber(int n) {
	while (n > 0) {
		if (n % 2 == 0) return false;
		n /= 10;
	}
	return true;
}
bool czyWystepuje(int tab[MAX][MAX]) {
	bool flag = true;
	int i = 0;
	while (i < MAX && flag) {
		int j = 0;
		bool flag2 = false;
		while(j<MAX && !flag2) {
			if (checkNumber(tab[i][j])) flag2 = true;
			else j++;
		}
		if (j == MAX) flag = false;
		 else i++;
	} 
	return flag;
}
int main() {
	int tab[MAX][MAX] = { {24,4,8,17,12}, {31,10,14,2,4}, {11,16,2,8,0}, {11,2,34,51,7}, {12,33,43,12,10} };
	cout << czyWystepuje(tab);
}