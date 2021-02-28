#include <iostream>
using namespace std;
void sito(int n) {
	bool tab[1000];
	for (int i = 2; i <= n; i++) {
		tab[i] = true;
	}
	for (int j = 2; j <= sqrt(n); j++) {
		for (int i = 2; i <= n; i++) {
			if (j != i && i % j == 0) tab[i] = false;
		}
	}
	for (int k = 2; k <= n; k++) {
		if (tab[k] == true) cout << k << endl;
	}
}
int main() {
	int n;
	cin >> n;
	sito(n);
}