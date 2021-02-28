#include <iostream>
using namespace std;
/*
Dane są deklaracje:
struct node {
 int val;
 node* next;
};
1. Proszę napisać funkcję wstawiającą na koniec listy nowy element. Do
funkcji należy przekazać wskazanie na pierwszy element listy oraz wstawianą
wartość.
*/
struct Node {
	int value;
	Node* next;
};

void setEnd(Node*& head, int val) {
	Node* nowy = new Node;
	nowy->value = val;
	nowy->next = NULL;
	if (head == NULL) {
		head = nowy;
	}
	else {
		Node* tmp = head;
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = nowy;
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
	head = NULL;
	setEnd(head, 7);
	print(head);
	setEnd(head, 14);
	print(head);
	setEnd(head, 91);
	print(head);
}