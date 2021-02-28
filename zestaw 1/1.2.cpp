#include <iostream>
#include <cmath>
#include <string>
using namespace std;
//Znaleźć wyrazy początkowe zamiast 1,1 o najmniejszej sumie, aby w ciągu
//analogicznym do ciągu Fibonacciego wystąpił wyraz równy numerowi bieżącego roku
const int rok = 2019;
bool czywystapi(int a, int b) {
	while (b < 2019) {
		int c = a;
		a = b;
		b += c;
	}
	if (b == 2019) return true;
	else return false;
}
void findStartingPoints() {
	int a = 1;
	int i, j;
	int suma=rok+2;
	while(a<(rok/2)+1) {
		int b = a + 1;
		bool find = false;
		while (!find && b <= 2019) {
			find = czywystapi(a, b);
			b++;
		}
		if (find&&(a + b - 1) < suma) {
			suma = a + b - 1;
			i = a;
			j = b - 1;
		}
		a++;
	}
	cout << i << " " << j;
}
int main() {
	findStartingPoints();
}
