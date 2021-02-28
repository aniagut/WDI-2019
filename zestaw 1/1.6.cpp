#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
float rozwiazanie() { //f(x)=x^2 - 2019
	float a = -2019;
	float b = 2019;
	float e = 0.001;
	while (abs(pow(((a + b) / 2), 2) - 2019) > e) {
		if ((pow(b, 2) - 2019)* (pow(((a + b) / 2), 2) - 2019) < 0) {
			a = (a + b) / 2;
		}
		else {
			b = (a + b) / 2;
		}
	}
	return (a + b) / 2;
}
int main() {
	cout << setprecision(20) << rozwiazanie();
	return 0;
}