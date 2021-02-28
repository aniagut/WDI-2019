#include <iostream>
#include <algorithm>
using namespace std;
int nww(int a, int b, int c) {
	int d = max(a, b);
	int e = max(d, c);
	int nww = e;
	while ((nww % a != 0) || (nww % b != 0) || (nww % c != 0)) {
		nww += e;
	}
	return nww;
}
int main() {
	int a, b, c;
	cout << "Wpisz trzy liczby: " << endl;
	cin >> a >> b >> c;
	cout << "NWW tych liczb to " << nww(a,b,c);
	return 0;
}