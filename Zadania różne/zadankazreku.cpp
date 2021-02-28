#include <iostream>
using namespace std;
const int N = 20;
void printwithcomma(long long value) {
	int t[3];
	for (int i = 2; i >= 0; i--) {
		t[i] = value % 10;
		value /= 10;
	}
	cout << value << ",";
	for (int i = 0; i < 3; i++) {
		cout << t[i];
	}
}
/*
3. A is an array containing n integers. Write a recursive function to find the number of times a
given integer x appears in A
*/
int numberofx(int value, int n) {
	if (value == n) return 1;
	else if (value < 10) return 0;
	else if (value % 10 == n) return 1 + numberofx(value / 10, n);
	else return numberofx(value / 10, n);
}
/*
4. Write a recursive function to implement selection sort
*/
void swap(int& n, int& m) {
	int c = n;
	n = m;
	m = c;
}
void selectionSort(int *t, int rozm, int idx) {
	if (idx == rozm-1) return;
	int min = t[idx];
	int indeks=idx;
	for (int i = idx + 1; i < rozm; i++) {
		if (t[i] < min) {
			min = t[i];
			indeks = i;
		}
	}
	swap(t[idx], t[indeks]);
	selectionSort(t, rozm, idx + 1);
}
/*
5. Write a recursive function to return the largest element in an integer array
*/
int largestelement(int* t, int p,int k) {
	if (p == k) return t[p];
	else if (t[p] > t[k]) return largestelement(t, p, k - 1);
	else return largestelement(t, p + 1, k);
}
/*
6. Write a recursive function to search for a given number in an int array
*/
int givennumber(int* t, int p, int k, int value) {
	if (t[p] == value) return p;
	else if (p == k) return -1;
	else return givennumber(t, p + 1, k, value);
}
/*
7. Write a recursive function to search for a given number in a sorted int array.
*/
int givennumberins(int* t, int p, int k,int value) {
	int m = (p + k) / 2;
	if (p > k) return -1;
	else if (t[m] == value) return m;
	else if (t[m] > value) return givennumberins(t, p, m - 1, value);
	else return givennumberins(t, m + 1, k, value);
}

int main() {
	int t[] = { 91,5,82,7,43,1};
	cout << givennumber(t, 0, 6, 0);
}