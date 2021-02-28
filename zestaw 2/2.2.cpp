/*Napisz program wczytujący liczbę naturalną z klawiatury i odpowiadający na pytanie,
czy liczba ta jest wielokrotnością dowolnego wyrazu ciągu danego wzorem
A(n) = n * n + n + 1.*/
#include <iostream>
using namespace std;
bool czyjestwielokrotnoscia(int n) {
	for (int i = 1; i <= n; i++) {
		int wyraz = i * i + i + 1;
		if (n % wyraz == 0) {
			return true;
			break;
		}
	} return false;
}
int main() {
	int n;
	cout << "dej liczbe:";
	cin >> n;
	if (czyjestwielokrotnoscia(n) == 1) {
		cout << "Jest wielokrotnoscia.";
	}
	else {
		cout << "Nie jest wielokrotnoscia.";
	}
	return 0;
}
