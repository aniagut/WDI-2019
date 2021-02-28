/*
3.Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę napisać
funkcję który odpowiada na pytanie, czy istnieje wiersz w tablicy w którym każda
z liczb zawiera przynajmniej jedna cyfrę parzystą.
*/
#include <iostream>
using namespace std;
const int MAX = 5;
bool czyzParzystych(int n) {
	while (n > 0) {
		if (n % 2 != 0) return false;
		n /= 10;
	}
	return true;
}
bool czyIstnieje(int t[MAX][MAX]) {
	bool flag = false;
	int i = 0;
	while (i < MAX && !flag) {
		int j = 0;
		bool flag2 = true;
		while (j < MAX && flag2) {
			if (!czyzParzystych(t[i][j])) flag2 = false;
			else j++;
		}
		if (j == MAX) flag = true;
		else i++;
	}
	return flag;
}
int main() {
	int t[MAX][MAX] = { {82,28,4,42,22},{11,13,23,4,1},{12,42,80,2,4},{12,32,45,21,1},{22,40,227,6,2} };
	cout << czyIstnieje(t);
}