/*
Napisać program wczytujący dwie liczby naturalne i odpowiadający
na pytanie czy są one zbudowane z takich samych cyfr, np. 123 i
321, 1255 i 5125, 11000 i 10001
*/
#include <iostream>
using namespace std;
bool czyztychsamych(int n, int m) {
	for (int i = 0; i <= 9; i++) {
		int tmp1 = n;
		int tmp2 = m;
		int suma1 = 0;
		int suma2 = 0;
		while (tmp1 != 0) {
			if (tmp1 % 10 == i) suma1++;
			if (tmp2 % 10 == i) suma2++;
			tmp1 /= 10;
			tmp2 /= 10;
		}
		if (suma1 != suma2) return false;
	} return true;
}
int main() {
	int m, n;
	cin >> m;
	cin >> n;
	cout << czyztychsamych(m, n);
}