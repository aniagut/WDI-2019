/*
 Napisać program zamieniający liczbę naturalną z systemu 10 na
podstawę 2-16
*/
#include <iostream> 
#include <string>
using namespace std;
void napodstawe(int p, int n) {
	string syst = "0123456789ABCDEF";
	char tab[100];
	int i = 0;
	int suma = 0;
	if (n == 0) cout << "0";
	while (n != 0) {
		tab[i] = syst[n % p];
		n /= p;
		i++;
		suma++;
}
	for (int j = suma - 1; j >= 0; j--) {
		cout << tab[j];
	}
}
int main() {
	int p, n;
	cin >> n;
	cin >> p;
	napodstawe(p, n);
}