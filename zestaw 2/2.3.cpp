#include <iostream>
#include <string>
using namespace std;
bool czypalindrom(string n) {
	int dlugosc = n.length() - 1;
	int i=0;
	while (i <= dlugosc / 2) {
		if (n[i] == n[dlugosc - i]) i++;
		else return false;
	} return true;
	
}
int main() {
	string n;
	cin >> n;
	cout << czypalindrom(n);
}