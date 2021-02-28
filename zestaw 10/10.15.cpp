#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
/*
Proszę napisać funkcję, która pozostawia w liście wyłącznie elementy
unikalne. Do funkcji należy przekazać wskazanie na pierwszy element listy.
*/
void uniq(Node* head) {
	Node* tmp = head;
	while (tmp != NULL) {
		Node* tmp1 = tmp;
		while (tmp1->next != NULL) {
			if (tmp1->next->value == tmp->value) {
				Node* tmp2 = tmp1->next;
				tmp1->next = tmp1->next->next;
				delete tmp2;
			}
			else tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << ",";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node*head = new Node;
	Node*a = new Node;
	Node*b = new Node;
	Node*c = new Node;
	Node*d = new Node;
	Node*e = new Node;
	head->value = 1;
		head->next = a;
		a->value = 2;
		a->next = b;
		b->value = 2;
		b->next = c;
		c->value = 3;
		c->next = d;
		d->value = 1;
		d->next = e;
		e->value = 3;
		e->next = NULL;
		print(head);
		uniq(head);
		print(head);

}