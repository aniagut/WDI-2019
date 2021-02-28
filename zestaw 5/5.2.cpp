#include <iostream>
using namespace std;
struct ulamek {
	int l, m;
};
int NWD(int x, int y) {
	int k;
	if (x >= y) k = y;
	else k = x;
	int i;
	for (i = 1; i <= k; i++) {
		if (x % i == 0 && y % i == 0)  return i;
	}
	return i;
}
int NWW(int x, int y) {
	return (x * y) / NWD(x, y);
}
ulamek mnoz(ulamek x, ulamek y) {
	ulamek wynik;
	wynik.l = x.l * y.l;
	wynik.m = x.m * y.m;
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
ulamek dziel(ulamek x, ulamek y) {
	ulamek wynik;
	wynik.l = x.l * y.m;
	wynik.m = x.m * y.l;
	int k = NWD(wynik.l, wynik.m);
	wynik.l /= k;
	wynik.m /= k;
	return wynik;
}
void liczy(ulamek a, ulamek b, ulamek c, ulamek d, ulamek e, ulamek f) {
	//ax+by+c==0 //dx+ey+f=0 *(-a/d) //-ax-ae/dy-af/d =0 by-ae/d*y +c-af/d=0 y(b-ae/d)=af/d-c y=(af/d-c)/(b-ae/d)=(a*f*d)/((d-c)*(b-a*e))
	ulamek y = dziel(mnoz(mnoz(a, f), d), (mnoz(odejm(d, c), odejm(b, mnoz(a, e)))));
	//ax+by+c=0
	//(-c - by) / a = x;
	ulamek x = dziel(dod(c, mnoz(b, y)), a);
	x.l *= (-1);
	cout << "x= " << x.l << "/" << x.m << endl;
	cout << "y= " << y.l << "/" << y.m << endl;
}
int main() {
	ulamek a, b, c, d, e, f;
	a.l = 1;
	a.m = 4;
	b.l = 10;
	b.m = 12;
	c.l = -2;
	c.m = 1;
	d.l = 1;
	d.m = 19;
	e.l = 1;
	e.m = 7;
	f.l = -1;
	f.m = 4;
	liczy(a, b, c, d, e, f);
}