
#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

	string intToString(int i) {
	stringstream s;
	s << i;
	return s.str();
}

int main() {
	int a, b, n;
cout << "Podaj a : "; 
cin >> a;
cout << "Podaj b : "; 
cin >> b;
cout << "Podaj n : "; 
cin >> n;

	string wynik = intToString(a / b);

	wynik += ".";

	while (n--) {
		a = (a % b) * 10;
		wynik += (a / b) + '0';
	}

cout << wynik << endl;

	return 0;
}