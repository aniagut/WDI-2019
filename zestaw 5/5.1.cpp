#include <iostream>
#include <cmath>
using namespace std;
int NWD(int x, int y) {
	int k;
	if (x >= y) k = y;
	else k = x;
	int nwd;
	for (int i = 1; i <= k; i++) {
		if (x % i == 0 && y % i == 0) nwd = i;
	}
	return nwd;
}
int NWW(int x, int y) {
	return (x * y) / NWD(x, y);
}
struct ulamek {
	int l, m;
};
ulamek mnoz(ulamek x, ulamek y){
	ulamek wynik;
	wynik.l = x.l * y.l;
	wynik.m = x.m * y.m;
	int k = NWD(wynik.l, wynik.m);
	wynik.l /= k;
	wynik.m /= k;
	return wynik;
}
ulamek dziel(ulamek x, ulamek y) {
	ulamek wynik;
	wynik.l = x.l * y.m;
	wynik.m = x.m * y.l;
	int k = NWD(wynik.l, wynik.m);
	wynik.l /= k;
	wynik.m /= k;
	return wynik;
}
ulamek dod(ulamek x, ulamek y) {
	ulamek wynik;
	int a = NWW(x.m, y.m) / x.m;
	int b = NWW(x.m, y.m) / y.m;
	x.m = y.m = NWW(x.m, y.m);
	x.l *= a;
	y.l *= b;
	wynik.l = x.l + y.l;
	wynik.m = x.m;
	int k = NWD(wynik.l, wynik.m);
	wynik.l /= k;
	wynik.m /= k;
	return wynik;
}
ulamek odejm(ulamek x, ulamek y) {
	ulamek wynik;
	int a = NWW(x.m, y.m) / x.m;
	int b = NWW(x.m, y.m) / y.m;
	x.m = y.m = NWW(x.m, y.m);
	x.l *= a;
	y.l *= b;
	wynik.l = x.l - y.l;
	wynik.m = x.m;
	int k = NWD(wynik.l, wynik.m);
	wynik.l /= k;
	wynik.m /= k;
	return wynik;
}
int main() {
	ulamek a, b, c;
	a.l = 1;
	a.m = 2;
	b.l = 1;
	b.m = 3;
	c = dod(a, b);
	cout << c.l << "/" << c.m << endl;
	c = odejm(a, b);
	cout << c.l << "/" << c.m << endl;
	c = mnoz(a, b);
	cout << c.l << "/" << c.m << endl;
	c = dziel(a, b);
	cout << c.l << "/" << c.m << endl;
}