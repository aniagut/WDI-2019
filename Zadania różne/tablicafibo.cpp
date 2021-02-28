/*
16. Dana jest duża tablica int t[MAX]. Proszę napisać funkcję,
która zwraca informację czy w tablicy zachodzi następujący
warunek: „wszystkie elementy, których indeks jest elementem
ciągu Fibonacciego są liczbami złożonymi, a wśród pozostałych
przynajmniej jedna jest liczbą pierwszą”
*/
#include<iostream>
using namespace std;
bool isPrime(int n) {
	if (n == 0 || n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= sqrt(n); i = i + 2) {
		if (n % i == 0) return false;
	}
	return true;
}
void fibo(int t[33]) {
	t[0] = 0;
	t[1] = 1;
	for (int i = 2; i < 33; i++) {
		t[i] = t[i - 1] + t[i - 2];
	}
}
const int MAX = 10;
bool czyzachodzi(int t[MAX]) {
	int t1[33];
	fibo(t1);
	int idx = 0;
	bool flagnaprime = false;
	for (int i = 0; i < MAX; i++) {
		if (i != t1[idx]) {
			if (isPrime(t[i])) flagnaprime = true;
			while (i > t1[idx]) {
				idx++;
			}
			if (i == t1[idx]) if (isPrime(t[i])) return false;
		}
		else {
			if (isPrime(t[i])) return false;
		}
	}
	return flagnaprime;
}
int main(){
	int t[MAX] = { 4,4,4,4,2,4,4,4,4,4 };
	cout << czyzachodzi(t);

}