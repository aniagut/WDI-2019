/*
3.Mamy cykliczną listę zawierającą liczby całkowite. Każda pierwsza cyfra kolejnej liczby jest równa
ostatniej cyfrze poprzedniej liczby.
np. 123 - 324 - 435 - 578 -> łańcuch się zapętla
Napisz funkcję wstawiającą liczbę do listy. Liczba ma zastąpić dwie już istniejące elementy cyklu.
dla przykładu tutaj, za (324 - 435) można wstawić 35
Funkcja powinna zwrócić wartość logiczną w zależności od tego czy próba wstawiania zakończyła się
sukcesem.
*/
#include <iostream>
using namespace std;
struct Node {
	int val;
	Node* next;
};
int pierwszaliczba(int n) {
	while (n > 10) n /= 10;
	return n;
}
bool wstaw(Node*& wsk, int val1) {
	Node* tmp = wsk;
	int first = pierwszaliczba(val1);
	int last = val1 % 10;
	do {
		if (pierwszaliczba(tmp->val) == first && tmp->next->val % 10 == last) {
			tmp->val = val1;
			Node* temp = tmp->next;
			tmp->next = tmp->next->next;
			delete temp;
			return true;
		}
		tmp = tmp->next;
	} while (tmp != wsk);
	return false;
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* head = new Node;
	Node* a = new Node;
	Node* b = new Node;
	Node* c = new Node;
	head->val = 123;
	a->val = 324;
	b->val = 435;
	c->val = 578;
	head->next = a;
	a->next = b;
	b->next = c;
	c->next = head;
	cout << wstaw(head, 100);
}