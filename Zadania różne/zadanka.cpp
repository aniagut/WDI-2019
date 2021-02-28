#include <iostream>
using namespace std;
/*
1. Napisać program wypisujący elementy ciągu Fibonacciego mniejsze od miliona.
*/
void wypisz(int pierwszy,int drugi) {
	if (drugi>1000000) return;
	else {
		cout << pierwszy << endl;
		wypisz(drugi, pierwszy + drugi);
	}
}
void fibo() {
	wypisz(0, 1);
}
/*
2. Znaleźć wyrazy początkowe zamiast 1,1 o najmniejszej sumie, aby w ciągu
analogicznym do ciągu Fibonacciego wystąpił wyraz równy numerowi bieżącego roku.
*/
void wyrazypocz(int rok) {
	int najmniejsza = rok;
	int p=0;
	int d=0;
		for (int i = 0; i <= rok / 2; i++) {
			for (int j = i + 1; j <= rok; j++) {
				int pierwszy = i;
				int drugi = j;
				while (pierwszy < rok) {
					int c = pierwszy;
					pierwszy = drugi;
					drugi += c;
				}
				if (pierwszy == rok) {
					if ((i + j) < najmniejsza) {
						najmniejsza = i + j;
						p = i;
						d = j;
					}
				}
			}
	}
		if (p != 0 || d != 0) cout << p << " i " << d;
		else cout << "Nie ma.";
}
void zapiszwtab(int *t, int rozm) {
	int p = 0;
	int d = 1;
	for (int i = 0; i < rozm; i++) {
		t[i] = p;
		int c = p;
		p = d;
		d += c;
	}
}
/*
3. Napisać program sprawdzający czy istnieje spójny podciąg ciągu Fibonacciego o
zadanej sumie.
*/
bool czyistniejespojny(int suma) {
	int t[30];
	zapiszwtab(t, 30);
	for (int i = 0; i < 30; i++) {
		int tmp = suma;
		int j = i;
		while (tmp> 0) {
			tmp -= t[j];
			j++;
		}
		if (tmp == 0) return true;
	}
	return false;
}
/*
4. Napisać program obliczający pierwiastek całkowitoliczbowy z liczby naturalnej
korzystając z zależności 1+3+5+... = n^2.
*/
int pierwiastek(int n) {
	int i = 1; //do 2n-1
	while (n >= 0) {
		n -= i;
		i += 2;
	}
	return (i - 3) / 2;
}
/*
2. Napisać program wczytujący dwie liczby naturalne i odpowiadający
na pytanie czy są one zbudowane z takich samych cyfr, np. 123 i
321, 1255 i 5125, 11000 i 10001.
*/
int dlugoscliczby(int n) {
	int dl = 0;
	while (n > 0) {
		n /= 10;
		dl++;
	}
	return dl;
}
bool czytesame(int a, int b) {
	int t1[100];
	int t2[100];
	int rozmiar = dlugoscliczby(a);
	for (int i = 0; i < rozmiar; i++) {
		t1[i] = a % 10;
		t2[i] = b % 10;
		a /= 10;
		b /= 10;
	}
	int idx1 = 0; 
	bool flag = true;
	while (idx1 < rozmiar && flag) {
		int idx2 = 0;
		while (t2[idx2] != t1[idx1] && idx2 != rozmiar) idx2++;
		if (idx2 == rozmiar) flag = false;
		else {
			t2[idx2] = -1;
			idx1++;
		}
		}
	return flag;
	}
/*
3. Napisać program generujący i wypisujący liczby pierwsze mniejsze
od N metodą Sita Eratostenesa
*/
void sito(int n) {
	int t[100000];
	for (int i = 0; i < n - 1; i++) {
		t[i] = i + 2;
	}
	int p = 0;
	while (p < n - 1) {
		for (int i = (p + 1); i < (n - 1); i++) {
			if (t[p]!=0 && t[i]!=0 && (t[i] % t[p]) == 0) t[i] = 0;
		}
		p++;
	}
	for (int i = 0; i < (n - 1); i++) {
		if (t[i] != 0) cout << t[i] << endl;
	}
}
/*
2. Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę napisać
funkcję który odpowiada na pytanie, czy w każdym wierszu tablicy występuje co
najmniej jedna liczba złożona wyłącznie z nieparzystych cyfr.
*/
const int MAX = 8;
bool czyzniep(int n) {
	while (n > 0) {
		if (n % 2 == 0) return false;
		n /= 10;
	}
	return true;
}
bool czyistnieje(int t[MAX][MAX]) {
	bool flag = true;
	int wiersz = 0;
	while (flag && wiersz < MAX) {
		flag = false;
		int kolumna = 0;
		while (!flag && kolumna < MAX) {
			if (czyzniep(t[wiersz][kolumna])) flag = true;
			else kolumna++;
		}
		if (kolumna == MAX) flag = false;
		wiersz++;
	}
	return flag;
}
/*
3. Dana jest tablica int t[MAX][MAX] wypełniona liczbami naturalnymi. Proszę napisać
funkcję który odpowiada na pytanie, czy istnieje wiersz w tablicy w którym każda
z liczb zawiera przynajmniej jedna cyfrę parzystą.
*/
bool czyjednaparzysta(int n) {
	while (n > 0) {
		if (n % 2 == 0) return true;
		n /= 10;
	}
	return false;
}
bool czyistnieje2(int t[MAX][MAX]) {
	int wiersz = 0;
	bool flag = false;
	while (!flag && wiersz < MAX) {
		int kolumna = 0;
		while (czyjednaparzysta(t[wiersz][kolumna]) && kolumna < MAX) kolumna++;
		if (kolumna == MAX) flag = true;
		else wiersz++;
	}
	return flag;
}
/*
8. Szachownica jest reprezentowana przez tablicę int t[8][8] wypełnioną liczbami
naturalnymi zawierającymi koszt przebywania na danym polu szachownicy. Król
szachowy znajduje się w wierszu 0 i kolumnie k. Król musi w dokładnie 7 ruchach
dotrzeć do wiersza 7. Proszę napisać funkcję, która wyznaczy minimalny koszt
przejścia króla. Do funkcji należy przekazać tablicę t oraz startową kolumnę k.
Koszt przebywania na polu startowym i ostatnim także wliczamy do kosztu przejścia.
*/
int kosztt(int t[MAX][MAX], int wiersz, int kolumna, int iloscr, int koszt) {
	if (wiersz == 7 && iloscr == 7 ) {
		return koszt;
	}
	else if(iloscr<7) {
	if (wiersz + 1 < MAX) kosztt(t, wiersz + 1, kolumna, iloscr + 1, koszt + t[wiersz + 1][kolumna]);
	if(wiersz+1<MAX && kolumna+1<MAX)  kosztt(t, wiersz+1, kolumna + 1, iloscr + 1, koszt + t[wiersz+1][kolumna + 1]);
	if(wiersz+1<MAX && kolumna-1>=0)  kosztt(t, wiersz +1 , kolumna - 1, iloscr + 1, koszt + t[wiersz + 1][kolumna - 1]);
	}
}
int main() {
	int t[MAX][MAX] = { {1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8},{1,2,3,4,5,6,7,8} };
	kosztt(t,0,3,0,t[0][3]);
}