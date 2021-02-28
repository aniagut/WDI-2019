#include <iostream>
using namespace std;
/*
10. Proszę napisać funkcję, otrzymującą jako parametr wskaźnik na pierwszy
element listy o wartościach typu int, usuwającą wszystkie elementy, których
wartość dzieli bez reszty wartość bezpośrednio następujących po nich
elementów.
*/
struct Node {
	int value; //3578511
	Node* next;
};
bool czyDzieli(int m, int n) {
	if (n % m == 0) return true;
	else return false;
}
void del(Node*& head) {
	while (head != NULL && head->next != NULL && czyDzieli(head->value, head->next->value)) {
		head = head->next;
	}
	Node* tmp = head;
	while (tmp->next != NULL && tmp->next->next != NULL) {
		if (czyDzieli(tmp->next->value, tmp->next->next->value)) {
			Node* tmp1 = tmp->next;
			tmp->next = tmp->next->next;
			delete tmp1;
		}
		else {
			tmp = tmp->next;
		}
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
	a->value = 6;
	a->next = b;
	b->value = 12;
	b->next = c;
	c->value = 24;
	c->next = d;
	d->value = 48;
	d->next = e;
	e->value = 96;
	e->next = NULL;
	print(head);
	del(head);
	print(head);
}