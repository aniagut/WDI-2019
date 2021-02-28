//LISTA DWUKIERUNKOWA
#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next, * prev;
};
struct Opis {
	int counter;
	Node *head,*tail;
};
/*
Dodawanie na poczatek listy
*/
void addFront(Opis*& opis, Node*& head, int val) {
	Node* nowy = new Node;
	nowy->value = val;
	nowy->next = head;
	nowy->prev = NULL;
	head = nowy;
	if (head->next) {
		head->next->prev = head;
	}
	opis->head = head;
	(opis->counter)++;
}
void addBack(Opis*& opis, Node*& tail, int val) {
	Node* nowy = new Node;
	nowy->prev = tail;
	nowy->value = val;
	nowy->next = NULL;
	tail = nowy;
	if (tail->prev) tail->prev->next = nowy;
	opis->tail = tail;
	(opis->counter)++;
}
void addInFront(Node*& head, int val1, int val2) {
	Node* nowy = new Node;
	nowy->value = val2;
	if (!head) {
		head = nowy;
		nowy->prev = NULL;
		nowy->next = NULL;
	}
	if (head->value == val1) {
		nowy->next = head;
		nowy->prev = NULL;
		head = nowy;
		head->next->prev = head;
	}
	Node* tmp = head;
	while (tmp->next && tmp->next->value != val1) tmp = tmp->next;
		if (!tmp->next) {
			tmp->next = nowy;
			nowy->next = NULL;
			nowy->prev = tmp;
		}
		if (tmp->next->value == val1) {
			nowy->next = tmp->next;
			nowy->prev = tmp;
			tmp->next = nowy;
			nowy->next->prev = nowy;
		}
}
void printFront(Node* head) {
	while (head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}
void printBack(Node* tail) {
	while (tail != NULL) {
		cout << tail->value << " ";
		tail = tail->prev;
	}
	cout << endl;
}
int main() {
	Node* head = new Node;
	Node* a = new Node;
	Node* b = new Node;
	Node* c = new Node;
	Node* d = new Node;
	head->prev = NULL;
	head->value = 3;
	head->next = a;
	a->prev = head;
	a->value = 7;
	a->next = b;
	b->prev = a;
	b->value = 9;
	b->next = c;
	c->prev = b;
	c->value = 19;
	c->next = d;
	d->prev = c;
	d->value = 87;
	d->next = NULL;
	Opis* opis = new Opis;
	opis->head = head;
	opis->tail = d;
	opis->counter = 5;
	printFront(opis->head);
	printBack(opis->tail);
	addFront(opis, head, 14);
	printFront(opis->head);
	printBack(opis->tail);
	cout << opis->head->value << endl;
	cout << opis->counter << endl;
	addBack(opis, d, 100);
	printFront(opis->head);
	printBack(opis->tail);
	cout << opis->tail->value << endl;
	cout << opis->counter;
	addInFront(head, 87, 10);
	printFront(head);

}