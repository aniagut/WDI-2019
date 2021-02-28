#include <iostream>
using namespace std;
bool czypierwsza(long long n) {
	if (n == 2) {
		return true;
	}
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
			break;
		}
	}
	return true;
}
int main() {
	long long n;
	cout << "Wpisz liczbe:";
	cin >> n;
	if (czypierwsza(n) == 0) cout << "Nie jest pierwsza";
	else cout << "Jest pierwsza";
	return 0;
}