
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

bool czyJest(Node* head, int val) {
	while (head != NULL) {
		if (head->value == val) return true;
		head = head->next;
	}
	return false;
}

void add(Node*& head, int val) {
	Node* nowy = new Node;
	nowy->value = val;
	nowy->next = NULL;
	Node* tmp = head;
	if (head == NULL) {
		head = nowy;
	}
	else {
		while (tmp->next != NULL) {
			if (tmp->next->value == val) return;
		}
		tmp->next = nowy;
	}
}

void del(Node*& head, int val) {
	if (head == NULL) return;
	else if (head->value == val) {
		if (head->next != NULL) {
			Node* tmp = head;
			head = head->next;
			delete tmp;
		}
		else delete head;
	}
	else {
		Node* tmp = head;
		while (tmp->next != NULL && tmp->next->value!=val) {
			tmp = tmp->next;
		}
		if (tmp->next == NULL) return;
		else {
			Node* temp = tmp->next;
			tmp->next = tmp->next->next;
			delete temp;
		}
	}
}

void print(Node* head) {
	while (head != NULL) {
		cout << head->value << ", ";
		head = head->next;
	}
}

int main() {
	Node* head=new Node;
	Node* pierwszy=new Node;
	Node* drugi=new Node;
	Node* trzeci=new Node;
	Node* czwarty = new Node;
	head->value = 9;
	head->next = pierwszy;
	pierwszy->value = 7;
	pierwszy->next = drugi;
	drugi->value = 90;
	drugi->next = trzeci;
	trzeci->value = 1;
	trzeci->next = czwarty;
	czwarty->value = 5;
	czwarty->next = NULL;
	cout << czyJest(head, 90);
	print(head);
	cout << endl;
	add(head, 17);
	print(head);
	cout << endl;
	del(head, 90);
	print(head);
	cout << endl;
	del(head, 9);
	print(head);
}