#include <iostream>
using namespace std;
/*
INSERTION SORT-trzymamy naraz jeden element i dopasowujemy go do tych, ktore juz mamy posortowane
*/
void insertionSort(int t[], int len) {
	for (int curr = 1; curr < len; curr++) {
		int key = t[curr];
		int prev = curr - 1;
		while (key < t[prev]&& prev>=0) {
			t[prev + 1] = t[prev];
			prev--;
		}
		t[prev + 1] = key;
	}
}
int main() {
	int t[10] = { 90,17,6,43,2,86,75,9,0,81 };
	for (int i = 0; i < 10; i++) {
		cout << t[i] << " ";
	}
	cout << endl;
	insertionSort(t, 10);
	for (int i = 0; i < 10; i++) {
		cout << t[i] << " ";
	}
}