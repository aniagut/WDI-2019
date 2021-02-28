#include <iostream>
using namespace std;
int ostatnianiezerowasilni(long long n) {
	//946
	//1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 * 11 * 12 * 13 * 14 * 15
	int ostatniacyfra = 1;
	for (long long i = 1; i <= n; i++) {
		long long j = i;
		while (j % 5 == 0) {
			j = j / 5; 
			ostatniacyfra = ostatniacyfra / 2;
		}
		j = j % 10;
		ostatniacyfra = ostatniacyfra * j;
		ostatniacyfra = ostatniacyfra % 10; //2
	} return ostatniacyfra;
}
int main() {
	long long n;
	cout << "dej liczbe:";
	cin >> n;
	cout << "Ostatnia niezerowa cyfra liczby " << n << "! wynosi " << ostatnianiezerowasilni(n);
	return 0;
}
			
