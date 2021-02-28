#include <iostream>
using namespace std;
/*
1. Zaimplementuj zbiór mnogościowy liczb naturalnych korzystając ze
struktury listy.
- czy element należy do zbioru
- dodanie elementu do zbioru
- usunięcie elementu ze zbioru

*/
struct Node {
	int value;
	Node* next;
};
bool czyNalezy(Node* head, int val) {
	while (head != NULL) {
		if (head->value == val) return true;
		head = head->next;
	}
	return false;
}
void addFront(Node*& head, int val) {
	Node* nowy = new Node;
	nowy->value = val;
	nowy->next = NULL;
	if (head == NULL) {
		head = nowy;
	}
	else {
		nowy->next = head;
		head = nowy;
	}
}
void addBack(Node*& head, int val) {
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
void addToSortedList(Node*& head, int val) {
	Node* nowy = new Node;
	nowy->value = val;
	nowy->next = NULL;
	Node* helper = new Node;
	helper->next = head;
	Node* tmp = helper;
	while (tmp->next != NULL && tmp->next->value <= val) {
		tmp = tmp->next;
	}
	if (tmp->next == NULL) tmp->next = nowy;
	else {
		Node* temp = tmp->next;
		tmp->next = nowy;
		nowy->next = temp;
	}
	head = helper->next;
	delete helper;
}
void delElement(Node*& head, int val) {
	Node* helper = new Node;
	helper->next = head;
	Node* tmp = helper;
	while (tmp->next != NULL && tmp->next->value != val) {
		tmp = tmp->next;
	}
	if (tmp->next == NULL) return;
	else {
		Node* temp = tmp->next;
		tmp->next = tmp->next->next;
		delete temp;
	}
	head = helper->next;
	delete helper;
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
	addFront(head, 7);
	addFront(head, 5);
	addFront(head, 4);
	addFront(head, 3);
	addFront(head, 2);
	addFront(head, 1);
	print(head);
	addToSortedList(head, 8);
	print(head);
	addToSortedList(head, 0);
	print(head);
	addToSortedList(head, 4);
	print(head);
	addToSortedList(head, 6);
	print(head);
	cout << czyNalezy(head, 0);
	cout << czyNalezy(head, 4);
	cout << czyNalezy(head, 8);
	cout << czyNalezy(head, 14);
	cout << czyNalezy(head, 27);
}