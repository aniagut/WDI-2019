#include <iostream>
using namespace std;
/*
9. Proszę napisać funkcję, otrzymującą jako parametr wskaźnik na pierwszy
element listy o wartościach typu int, usuwającą wszystkie elementy, których
wartość jest mniejsza od wartości bezpośrednio poprzedzających je
elementów.
*/
struct Node {
	int value;
	Node* next;
};
void del(Node*& head) {
	while (head != NULL && head->next != NULL && head->value < head->next->value) {
		head = head->next;
	}
	Node* tmp1 = head;
	while (tmp1->next != NULL && tmp1->next->next != NULL) {
		if (tmp1->next->value < tmp1->next->next->value) {
			Node* tmp2 = tmp1->next;
			tmp1->next = tmp1->next->next;
			delete tmp2;
		}
		else tmp1->next = tmp1->next->next;
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
	Node* head = new Node;
	Node* a = new Node;
	Node* b = new Node;
	Node* c = new Node;
	Node* d = new Node;
	Node* e = new Node;
	head->value = 3;
	head->next = a;
	a->value = 5;
	a->next = b;
	b->value = 7;
	b->next = c;
	c->value = 5;
	c->next = d;
	d->value = 9;
	d->next = e;
	e->value = 11;
	e->next = NULL;
	print(head);
	del(head);
	print(head);

}