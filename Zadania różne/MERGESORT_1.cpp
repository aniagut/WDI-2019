//MERGE SORT
#include <iostream>
using namespace std;
const int N = 6;
void merge(int t[N], int p, int m, int k) {
	int a[N];
	int i = p;
	int j = m + 1;
	int wsk = p;
	while (i <= m && j <= k) {
		if (t[i] > t[j]) {
			a[wsk] = t[j];
			j++;
			wsk++;
		}
		else {
			a[wsk] = t[i];
			wsk++;
			i++;
		}
	}
	while (i <= m) {
		a[wsk] = t[i];
		wsk++;
		i++;
	}
	while (j <= k) {
		a[wsk] = t[j];
		wsk++;
		j++;
	}
	for (int i = p; i <= k; i++) {
		t[i] = a[i];
	}
}
void mergeSort(int t[N], int p, int k ) {
	if (p < k) {
		int m = (p + k) / 2;
		mergeSort(t, p, m);
		mergeSort(t, m + 1, k);
		merge(t,p, m, k);
	}
}

int main() {
	int t[N] = { 3,8,19,5,42,1 };
	mergeSort(t, 0, 5);
	for (int i = 0; i < 6; i++) {
		cout << t[i] << " ";
	}
}