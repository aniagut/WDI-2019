/*
V kartkówka - WSKAŹNIKI (grupa a)
- dana jest uporządkowana lista 2-kierunkowa, napisz procedury lub funkcje: dodawania elementu do
listy za jakiś element i wstawiania elementu do listy na pierwsze miejsce, na ich podstawie napisz
procedurę lub funkcję, która doda element w odpowiednie miejsce
*/
#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next, * prev;
};
void addFront(Node*& head, int val) {
	Node* nowy = new Node;
	nowy->value = val;
	nowy->next = NULL;
	nowy->prev = NULL;
	if (head == NULL) head = nowy;
	else {
		nowy->next = head;
		head->prev = nowy;
		head = nowy;
	}
}
void addBehind(Node*& head, int val, int valzaktorym) {
	Node* nowy = new Node;
	nowy->prev = NULL;
	nowy->next = NULL;
	nowy->value = val;
	if (head == NULL) {
		head = nowy;
	}
	else if (head->value == valzaktorym) {
		nowy->prev = head;
		if (head->next != NULL) {
			nowy->next = head->next;
			head->next->prev = nowy;
			head->next = nowy;
		}
		else {
			head->next = nowy;
		}
	}
	else {
		Node* tmp = head;
		while (tmp->next != NULL && tmp->next->value != valzaktorym) tmp = tmp->next;
		if (tmp->next == NULL) {
			tmp->next = nowy;
			nowy->prev = tmp;
			nowy->next = NULL;
		}
		else {
			tmp = tmp->next;
			nowy->prev = tmp;
			if (tmp->next != NULL) {
				nowy->next = tmp->next;
				tmp->next->prev = nowy;
				tmp->next = nowy;
			}
			else {
				tmp->next = nowy;
				nowy->next = NULL;
			}
		}
	}
}
void dodajewodpowiedniemiejsce(Node*& head, int val) {
	Node* nowy = new Node;
	nowy->value = val;
	nowy->prev = NULL;
	nowy->next = NULL;
	if (head == NULL || head->value >= val) addFront(head, val);
	else {
		Node* tmp = head;
		while (tmp->next != NULL && tmp->next->value < val) tmp = tmp->next;
		addBehind(head, val, tmp->value);
	}
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* head = NULL;
	addFront(head, 103);
	addFront(head, 19);
	addFront(head, 7);
	addFront(head, 4);
	addFront(head, 1);
	print(head);
	dodajewodpowiedniemiejsce(head, 0);
	print(head);
	dodajewodpowiedniemiejsce(head, 8);
	print(head);
	dodajewodpowiedniemiejsce(head, 99);
	print(head);
	dodajewodpowiedniemiejsce(head, 109);
	print(head);
}