//Napisać program wyznaczający wartość liczby e korzystając z zależności: e = 1/0! +
//1 / 1!+ 1 / 2!+ 1 / 3!+ ...
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
float wartosce() {
	float wartosc = 2;
	float i = 2;
	float mianownik1 = 1;
	float mianownik2 = 2;
	while (abs((1 / mianownik1) - (1 / mianownik2)) > 0.000001) {
		mianownik2 = mianownik1;
		mianownik1 *= i;
		i++;
		wartosc += (1 / mianownik1);
	}
	return wartosc;
}
int main() {
	cout << setprecision(20) << wartosce();
}