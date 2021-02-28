/*Napisać program wyznaczający pierwiastek kwadratowy ze wzoru Newtona.*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
float pierwiastekkwadratowy(float n) {
	float e = 0.000001;
	float a = 1;
	float b = n;
	while (abs(a - b) > e) {
		a = (a + b) / 2;
		b = n / a;
	}
	return a;
}
int main() {
	float n;
	cout << "Wpisz liczbe: ";
	cin >> n;
	cout << "Pierwiastek z " << n << " wynosi " << setprecision(20) << pierwiastekkwadratowy(n);
	return 0;
}
