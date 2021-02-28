/*
31. Mamy daną liczbę całkowitą. W tablicy jednowymiarowej należy znaleźć n liczb,
których suma jest równa danej liczbie. Proszę napisać funkcję Nka, która otrzymując
jako parametry (1) tablicę int t[N],) n (ilość liczb stanowiących sumę) oraz sumę
sprawdza, ile można w niej znaleźć „enek”.
*/
#include <iostream>
using namespace std;
const int N = 10;
int funct(int t[N], int n, int i, int mojasuma, int mojei,int idx) {
	if (mojasuma == n && mojei==i) return 1;
	if (mojasuma > n || idx==N || mojei>i) return 0;
	return funct(t, n, i, mojasuma + t[idx], mojei+1, idx + 1) + funct(t, n, i, mojasuma, mojei, idx + 1);
}
int Nka(int t[N], int n, int i) {
	return funct(t, n, i, 0,-0, 0);
}
int main() {
	int t[N] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << Nka(t, 9, 3);
}