#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
/*
2. Dane są dwie listy cykliczne powstałe przez zapętlenie listy jednokierunkowej posortowanej
rosnąco, dla każdej listy dany jest wskaźnik wskazujący przypadkowy element w takiej liście.
Proszę napisać funkcję, która dla dwóch list cyklicznych, usuwa z obu list elementy
występujące w obu listach. Do funkcji należy przekazać wskaźniki na dwie listy, funkcja
powinna zwrócić łączną liczbę usuniętych elementów.
*/
#include <iostream>
using namespace std;
int usunzcykli(Node*& head1, Node*& head2) {
	int ile=0;
	Node* tmp1 = head1;
	Node* tmp2 = head2;
	while (tmp1->next != head1) {
		while (tmp2->next != head2 && tmp2->next->value != tmp1->next->value) tmp2 = tmp2->next;
		if (tmp2->next->value == tmp1->next->value) {
			Node* temp1 = tmp1->next;
			Node* temp2 = tmp2->next;
			tmp1->next = tmp1->next->next;
			tmp2->next = tmp2->next->next;
			delete temp1, temp2;
			ile += 2;
		}
		else {
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
	}
	return ile;
}
void add(Node*& head, int val) {
	Node* nowy = new Node;
	nowy->value = val;
	nowy->next = NULL;
	if (head == NULL) head = nowy;
	else {
		Node* tmp = head;
		while (tmp->next != NULL) tmp = tmp->next;
		tmp->next = nowy;
	}
}
void cykl(Node*& head) {
	if (head != NULL) {
		Node* tmp = head;
		while (tmp->next != NULL) tmp = tmp->next;
		tmp->next = head;
	}
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}
void printcykl(Node* head) {
	if (head != NULL) {
		Node* tmp = head;
		cout << tmp->value << " ";
		while (tmp->next != head) {
			cout << tmp->next->value << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
}
/*
2) Dana jest tablica t[N][N] (reprezentująca szachownicę) wypełniona liczbami całkowitymi z zakresu -9 ..9. Proszę napisać funkcję.która
ustawia na szachownicy dwie wieŹe, tak aby suma liczb na szachowanych polach była największa. Do funkcji należy przekazać tablicę, funkcja
powinna zwrócić położenie wież'
*/
const int N = 3;
void zajmowanie(int zajete[N][N], int wiersz, int kolumna) {
	for (int i = 0; i < N; i++) {
		zajete[wiersz][i] = 1;
		zajete[i][kolumna] = 1;
	}
}
void odzajmowanie(int zajete[N][N], int wiersz, int kolumna) {
	for (int i = 0; i < N; i++) {
		zajete[wiersz][i] = 0;
		zajete[i][kolumna] = 0;
	}
}
int szachowane(int t[N][N], int zajete[N][N], int wiersz, int kolumna) {
	int suma = 0;
	for (int i = 0; i < N; i++) {
		if (zajete[wiersz][i] == 0) suma += t[wiersz][i];
		if (zajete[i][kolumna] == 0) suma += t[i][kolumna];
	}
	return suma;
}
void szachownica(int t[N][N], int suma, int* najwsuma,int ile, int zajete[N][N]) {
	if (ile == 2) {
		if (suma > *najwsuma) *najwsuma =suma;
	}
	if(ile<2) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (zajete[i][j] == 0) {
					int s = szachowane(t, zajete, i, j);
					zajmowanie(zajete, i, j);
						szachownica(t, suma + s, najwsuma, ile + 1, zajete);
						odzajmowanie(zajete, i, j);
				}
			}
		}
	}
}
int funct(int t[N][N]) {
	int zajete[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			zajete[i][j] = 0;
		}
	}
	int najwsuma = -100000;
	szachownica(t, 0, &najwsuma, 0, zajete);
	return najwsuma;
}
int main() {
	int t[N][N] = { {1,10,1},{10,1,1},{1,1,10} };
	cout << funct(t);
}
	
	