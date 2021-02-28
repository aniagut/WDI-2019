#include <iostream>
using namespace std;
/*
BINARY SEARCH-ITERACYJNIE
*/
int binarySearch(int list[], int len, int value) {
	int p = 0;
	int k = len - 1;
	while (p <= k) {
		int mid = (p + k) / 2;
		if (list[mid] == value) return mid;
		else if (list[mid] > value) {
			k = mid - 1;
		}
		else p = mid + 1;
	}
	return -1;
}
int main() {
	int t[7] = { 3,5,9,10,81,92,102 };
	cout << binarySearch(t, 7, 3);
}
