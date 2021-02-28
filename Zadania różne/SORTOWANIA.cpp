/*
SORTOWANIE PRZEZ WSTAWIANIE-INSERTION SORT
*/
#include <iostream>
using namespace std;
const int N = 10;
void insertionSort(int* t, int len) {
	for (int curr = 1; curr < len; curr++) {
		int key = t[curr];
		int prev = curr - 1;
		while ( prev>=0 && t[prev] > key) {
			t[prev+1]=t[prev];
			prev--;
		}
		t[prev + 1] = key;
	}
}
//n^2

/*
SORTOWANIE PRZEZ SELEKCJE-SELECTION SORT REKU
*/
void swap(int& n, int& m) {
	int c = n;
	n = m;
	m = c;
}
void selectionSort(int* t, int rozmiar, int idx) {
	if (idx == rozmiar - 1) return;
		int min = t[idx];
		int minidx = idx;
		for (int i = idx + 1; i < rozmiar; i++) {
			if (t[i] < min) {
				min = t[i];
				minidx = i;
			}
		}
		swap(t[idx], t[minidx]);
		selectionSort(t, rozmiar, idx + 1);
}
/*
SORTOWANIE BĄBELKOWE-BUBBLESORT
*/
void bubbleSort(int* t, int rozmiar) {
	bool flag = true;
	int dl = rozmiar - 1;
	while (flag) {
		flag = false;
		for (int i = 0; i < dl; i++) {
			if (t[i] > t[i + 1]) {
				swap(t[i], t[i + 1]);
				flag = true;
			}
			dl--; // bo ostatni juz bedzie na koncu 
		}
	}
}
/*
SORTOWANIE SZYBKIE-QUICK SORT
*/
void quickSort(int* t, int p, int k) {
	int i = p;
	int j = k;
	int key = t[(p + k) / 2];
	while(i<=j){
		while (t[i] < key) i++;
		while (t[j] > key) j--;
		if (i <= j) {
			swap(t[i], t[j]);
			i++;
			j--;
		}
	}
	if (p < j) quickSort(t, p, j);
	if (k > i) quickSort(t, i, k);
}
/*
MERGE SORT
*/
void merge(int* t, int p, int m, int k) {
	int i = p;
	int j = m + 1;
	int wsk = p;
	int a[N];
	while (i <= m && j <= k) {
		if (t[i] < t[j]) {
			a[wsk] = t[i];
			wsk++;
			i++;
		}
		else {
			a[wsk] = t[j];
			wsk++;
			j++;
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
	for (int w = p; w <= k; w++) {
		t[w] = a[w];
	}
}
void mergeSort(int* t,int p, int k) {
	if (p < k) {
		int m = (p + k) / 2;
		mergeSort(t, p, m);
		mergeSort(t, m + 1, k);
		merge(t, p, m, k);
	}
}

int main() {
	int t[] = { 1,5,0,91,5,43,4,18,100,1 };
	for (int i = 0; i < N; i++){
		cout << t[i] << " ";
}
	cout << endl;
	mergeSort(t,0, 9);
	for (int i = 0; i < N; i++) {
		cout << t[i] << " ";
	}
	cout << endl;
}