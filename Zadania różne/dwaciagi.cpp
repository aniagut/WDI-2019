#include <iostream>
#include <cmath>
using namespace std;
/*
a(1) = 1;
a(n) = a(n-1) + b(n)/3;
b(1) = 2;
b(n) = b(n-1) + a(n - 1);
Proszę napisać program, który wczytuje liczbę naturalną k i odnajduje wyraz należący do jednego z ciągów o wartości najbliższej k.
Program powinien wypisać numer znalezionego wyrazu i ciąg z którego on pochodzi. Jeżeli więcej niż jeden wyraz jest jednakowo odległy od k,
należy wybrać ten o mniejszym numerze.
*/

void wypiszcos(int k) {
	int a = 1; //wyraz z a
	int b = 2; //wyraz z b
	int small = INT_MAX; //najmniejsza odleglosc
	int na = 1; // numer aktualnego wyrazu z a
	int nb = 1; //numaer aktualnego wyrazu z b
	int d; // numer podobnego wyrazu
	string jakiciag;
	while (a <= k && b <= k) {
		if (abs(k - a) < small) {
			small = abs(k - a);
			d = na;
			jakiciag = "a";
		}
		if (abs(k - b) < small) {
			small = abs(k - b);
			d = nb;
			jakiciag = "b";
		}
		b = b + a;
		a = a + b / 3;
		na++;
		nb++;
	}
	while (a <= k) {
		int h = b;
		if (abs(k - a) < small) {
			small = abs(k - a);
			d = na;
			jakiciag = "a";
		}
		h = h + a;
		a = a + h/3;
		na++;
	}
	while (b <= k) {
		int h = a;
		if (abs(k - b) < small) {
			small = abs(k - b);
			d = nb;
			jakiciag = "b";
		}
		b = b + h;
		h = h + b / 3;
		nb++;
	}
	if (abs(k - a) < small) {
		small = abs(k - a);
		d = na;
		jakiciag = "a";
	}
	if (abs(k - b) < small) {
		d = nb;
		jakiciag = "b";
	}
	cout << jakiciag << " " << d;

}
int main() {
	int k = 20;
	wypiszcos(k);
}