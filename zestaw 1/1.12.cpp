#include <iostream>
#include <algorithm>
using namespace std;
int nwd(int a, int b, int c) {
	int d = min(a, b);
	int e = min(d, c);
	for(int i=e; i>0; i--) {
		if ((a % i==0) && (b % i==0) && (c % i==0)) {
			return i;
		}
	}
}
int main() {
	int a, b, c;
	cout << "Wpisz liczby: " << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	cout << "NWD tych liczb to: " << nwd(a, b, c);
	return 0;
}