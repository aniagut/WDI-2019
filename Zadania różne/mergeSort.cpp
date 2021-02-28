#include <iostream>
using namespace std;
void mergeSort(int a[], int lena, int b[], int lenb, int c[],int lenc) {
	int i = 0;
	int j = 0;
	int k = 0;
	while (i < lena && j < lenb) {
		if (a[i] < b[j]) {
			c[k] = a[i];
			i++;
		}
		else {
			c[k] = b[j];
			j++;
		}
		k++;
	}
	while (i < lena) {
		c[k] = a[i];
		i++;
		k++;
	}
	while (j < lenb) {
		c[k] = b[j];
		j++;
		k++;
	}
}
int main() {
	int a[5] = { 12,31,40,76,120 };
	int b[7] = { 3,7,21,63,84,87,132 };
	int c[12];
	for (int i = 0; i < 5; i++) {
		cout<< a[i] << " ";
	}
	cout << endl;
	for (int j = 0; j < 7; j++) {
		cout << b[j] << " ";
	}
	cout << endl;
	mergeSort(a, 5, b, 7, c, 12);
	for (int i = 0; i < 12; i++) {
		cout << c[i] << " ";
	}
	cout << endl;
}