#include <iostream>
using namespace std;
struct ulamek{
	int mianownik;
	int licznik;
};
int NWD(int a, int b) {
	if (a == b) return a;
	else if (a > b) return NWD(a - b, b);
	else return NWD(a, b - a);
}
ulamek skracanie(ulamek a) {
	int dzielnik = NWD(a.licznik, a.mianownik);
	a.licznik /= dzielnik;
	a.mianownik /= dzielnik;
	return a;
}
ulamek dodawanie(ulamek a, ulamek b) {
	ulamek c;
	c.licznik = a.licznik * b.mianownik + b.licznik * a.mianownik;
	c.mianownik = a.mianownik * b.mianownik;
	return skracanie(c);
}
int main() {
	ulamek a;
	ulamek b;
	a.licznik = 2;
	a.mianownik = 7;
	b.licznik = 3;
	b.mianownik = 9;
	cout << dodawanie(a, b).licznik << "/" << dodawanie(a, b).mianownik;
}