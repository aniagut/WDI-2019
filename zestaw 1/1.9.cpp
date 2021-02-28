#include <iostream>
using namespace std;
void podzielniki(long long n) {
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) cout << i << endl;
	}
}
int main() {
	int n;
	cout << "Wpisz liczbe:";
	cin >> n;
	podzielniki(n);
	return 0;
}