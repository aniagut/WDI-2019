/*
17. Mamy zdefiniowaną n-elementową tablicę liczb całkowitych. Proszę
napisać funkcję zwracającą wartość typu bool oznaczającą, czy w
tablicy istnieje dokładnie jeden element najmniejszy i dokładnie
jeden element największy (liczba elementów najmniejszych oznacza
liczbę takich elementów o tej samej wartości).
*/
#include <iostream>
using namespace std;
const int N = 20;
bool najmnajw(int t[N]) {
	int najm = t[0];
	int najw = t[0];
	bool flag1 = true;
	bool flag2 = true;
	for (int i= 1; i < N; i++) {
		if (t[i] == najw) flag1 = false;
		else if (t[i] > najw) {
			flag1 = true;
			najw = t[i];
		}
		if (t[i] == najm) flag2 = false;
		if (t[i] < najm) {
			najm = t[i];
			flag2 = true;
		}
	}
	if (flag1 && flag2) {
		cout << najm << " " << najw << endl;
		return true;
	}
	else return false;
}
int main() {
	int t[N] = { 1,8,9,63,0,-4,-19,20,103,-81,13,-5,99,-107,-106,22,12,0,1,-32 };
	cout << najmnajw(t);
}