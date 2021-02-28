#include <iostream>
using namespace std;
/*
Dany jest zestaw odważników int t[N]. Napisać funkcję, która sprawdza czy jest
możliwe odważenie określonej masy. Odważniki można umieszczać tylko na jednej
szalce
*/
const int N = 4;
bool isPossible(int mass, int arr[N], int index) { 
	if (mass == 0) { 
		return true;
	}
	for (int i = index; i < N; i++) { 
		if ((mass - arr[index]) < 0) continue; 
		if (isPossible((mass - arr[i]),arr,(i+1))) return true; 
	}
	return false;
}
int main() {
	int odwazniki[N] = { 1,5,8,10 };
	int masa;
	cin >> masa;
	cout << isPossible(masa, odwazniki, 0);
}