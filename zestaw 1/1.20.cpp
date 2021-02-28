#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
/*
Dane są ciągi: A(n+1)=sqrt(A(n)*B(n)) oraz B(n+1)=(A(n)+B(n))/2.0. Ciągi te są
zbieżne do wspólnej granicy nazywanej średnią arytmetyczno-geometryczną. Napisać
program wyznaczający średnią arytmetyczno-geometryczną dwóch liczb.
*/
float sredniaAG(float a, float b) { //15 12
	while (abs(a-b)> 0.000001) {
		float c = a; //15
		a = (a + b) / 2; //13,5
		b = sqrt(c * b); // 13,41
	}
	return a;
 }

int main() {
	float a = 24;
	float b = 6;
	cout << setprecision(20) << sredniaAG(a, b);
}