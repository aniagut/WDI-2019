/*
20. Dane są dwie tablice t1[N] i t2[N] zawierające liczby naturalne.
Z wartości w obu tablicach możemy tworzyć sumy. „Poprawna” suma
to taka, która zawiera co najmniej jeden element (z tablicy t1
lub t2) o każdym indeksie. Na przykład dla tablic: t1 =
[1,3,2,4] i t2 = [9,7,4,8] poprawnymi sumami są na przykład
1+3+2+4, 9+7+4+8, 1+7+3+8, 1+9+7+2+4+8. Proszę napisać funkcje
generującą i wypisująca wszystkie poprawne sumy, które są
liczbami pierwszymi. Do funkcji należy przekazać dwie tablice,
funkcja powinna zwrócić liczbę znalezionych i wypisanych sum.
*/
#include <iostream>
using namespace std;
const int N = 4;
bool isPrime(int n) {
	if (n == 1 || n == 0) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (int i = 3; i <= sqrt(n); i = i + 2) {
		if (n % i == 0) return false;
	}
	return true;
}
void ilepoprawnychsum(int t1[N], int t2[N], int idx,int suma, int* ile) {
	if (idx == N) {
		if (isPrime(suma)) {
			(*ile)++;
			cout << suma << endl;
		}
	}
	if (idx < N) {
		return ilepoprawnychsum(t1, t2, idx + 1, suma + t1[idx], ile), ilepoprawnychsum(t1, t2, idx + 1, suma + t2[idx], ile), ilepoprawnychsum(t1, t2, idx + 1, suma += t1[idx] + t2[idx], ile);
	}
}
int main() {
	int t1[N] = { 1,3,2,4 };
	int t2[N] = { 9,7,4,8 };
	int ile = 0;
	ilepoprawnychsum(t1, t2, 0, 0, &ile);
	cout << ile;
}