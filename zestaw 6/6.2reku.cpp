/*
1. Dany jest zestaw odważników int t[N]. Napisać funkcję, która sprawdza czy jest
możliwe odważenie określonej masy. Odważniki można umieszczać tylko na jednej
szalce.
2. Poprzednie zadanie, odważniki można umieszczać na obu szalkach.
*/
#include <iostream>
using namespace std;
const int N = 5;
bool isPossible2(int mass, int arr[N], int index) {
	if (mass == 0) return true;
	for (int i = index; i < N; i++) {
		if ((isPossible2(mass-arr[i],arr,i+1)) || (isPossible2(mass+arr[i],arr,i+1))) return true;
	}
	return false;
}
int main() {
	int odwazniki[N] = { 1,15,4,7 };
	int masa;
	cin >> masa;
	cout << isPossible2(masa, odwazniki, 0);
}