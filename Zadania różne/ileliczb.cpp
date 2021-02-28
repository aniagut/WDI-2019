/*2. Dane są dwie liczby naturalne z których budujemy trzecią liczbę. W budowanej liczbie muszą
wystąpić wszystkie cyfry występujące w liczbach wejściowych. Wzajemna kolejność cyfr każdej z liczb
wejściowych musi być zachowana. Na przykład mając liczby 123 i 75 możemy zbudować liczby 12375,
17523, 75123, 17253, itd. Proszę napisać funkcję która wyznaczy ile liczb pierwszych można
zbudować z dwóch zadanych liczb.*/
#include <iostream>
using namespace std;
int pierwszacyfra(int n) {
	while (n >= 10) n/= 10;
	return n;
}
int modulo(int n) {
	int dzielnik = 1;
	while (n >= 10) {
		dzielnik *= 10;
		n /= 10;
	}
	return dzielnik;
}
bool isPrime(int n) {
	if (n == 0 || n == 1) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= sqrt(n); i++) {
		if (n % i == 0) return false;
	}
	return true;
}
int ilepierwszych(int x, int y, int nowa) {
	if (x == 0 && y == 0 && isPrime(nowa)) return 1;
	else if (x == 0 && y == 0) return 0;
	else if (x == 0) {
		return ilepierwszych(x, 0, (nowa * 10 * modulo(y)) + y);
	}
	else if (y == 0) {
		return ilepierwszych(0, y, (nowa *10* modulo(x)) + x);
	}
	else if (pierwszacyfra(x) == pierwszacyfra(y)) {
		return ilepierwszych(x % modulo(x), y % modulo(y), nowa * 100 + 10*pierwszacyfra(x)+pierwszacyfra(x));
	}
	else return ilepierwszych(x % modulo(x), y, nowa * 10 + pierwszacyfra(x)) + ilepierwszych(x, y % modulo(y), nowa * 10 + pierwszacyfra(y));
} 
int main() {
	cout << ilepierwszych(12, 23, 0);
}