/*
ZAMIANA NA BINARNY I NA KAZDY REKURENCYJNIE
*/
#include <iostream>
using namespace std;
void zamiananabin(int n) {
	if (n == 0) return;
	zamiananabin(n / 2);
	cout << n % 2;
}
void zamiananakazdy(int n, int syst) {
	if (n == 0) return;
	string system = "0123456789ABCDEF";
	zamiananakazdy(n / syst, syst);
	cout << system[n % syst];
}
int main() {
	zamiananabin(10);
	cout << endl;
	zamiananakazdy(95,16);

}