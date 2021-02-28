#include <iostream>
using namespace std;
/*
SELECTION SORT-znajdujemy najmniejszy element i dajemy go na poczatek
*/
int smallest(int list[], int pocz, int rozm) {
	int small = pocz;
	for (int i = pocz + 1; i < rozm; i++) {
		if (list[i] < list[small]) small = i;
	}
	return small;
}
void swap(int& a, int& b) {
	int c = a;
	a = b;
	b = c;
}
void selectionSort(int list[], int len) {
	for (int i = 0; i < len - 1; i++) {
		int s = smallest(list,i, len);
		swap(list[i], list[s]);

	}
}
int main() {
	int t[9] = { 32,5,34,2,5,46,23,89,12 };
	for (int i = 0; i < 9; i++) {
		cout << t[i] << " ";
	}
	cout << endl;
	selectionSort(t, 9);
	for (int i = 0; i < 9; i++) {
		cout << t[i] << " ";
	}
}
