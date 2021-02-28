/*
 Dana jestlista, który być może zakończona jest cyklem.
Napisać funkcję, która sprawdza ten fakt.
*/
#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
bool czyCykl(Node* head) {
	if (head != NULL && head->next != NULL) {
		Node* s_tmp = head;
		Node* f_tmp = head->next;

		while (f_tmp != NULL) {
			if (s_tmp == f_tmp) return true;
			s_tmp = s_tmp->next;
			f_tmp = f_tmp->next->next;
		}
		return false;
	}
}
int ilewcyklu(Node* head) {
	Node* s_tmp = head;
	Node* f_tmp = head->next;
	while (s_tmp != f_tmp) {
		s_tmp = s_tmp->next;
		f_tmp = f_tmp->next->next;
	}
	int ile = 1;
	while (f_tmp->next != s_tmp) {
		ile++;
		f_tmp = f_tmp->next;

	}
	return ile;
}

int main() {
	Node* head = new Node;
	Node* a = new Node;
	Node* b = new Node;
	Node* c = new Node;
	Node* d = new Node;
	head->value = 0;
	head->next = a;
	a->value = 9;
	a->next = b;
	b->value = 6;
	b->next = NULL;
	c->value = 2;
	c->next = d;
	d->value = 0;
	d->next = a;
	cout << ilewcyklu(head);
}