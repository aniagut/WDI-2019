/* Liczba dwu-trzy-piątkowa w rozkładzie na czynniki pierwsze nie posiada innych
czynników niż 2,3,5. Jedynka też jest taką liczbą. Napisz program, który wylicza
ile takich liczb znajduje się w przedziale od 1 do N włącznie.*/
#include <iostream>
using namespace std;
long long ile(long long n) {
	int suma = 0;
	for (long long i = 1; i <= n; i++) {
		long long j = i;
		while (j % 2 == 0) j = j / 2;
		while (j % 3 == 0) j = j / 3;
		while (j % 5 == 0)  j = j / 5;
		if (j == 1) suma++;
	}
	return suma;
}
int main() {
	long long n;
	cout << "dej liczbe:";
	cin >> n;
	cout << "W przedziale 1-" << n << " jest " << ile(n) << " takich liczb.";
	return 0;
}