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
void usun(Node*& head) {
	Node* tmp = head;
	while (tmp!=NULL && tmp->next!= NULL) {
		if (tmp->value > tmp->next->value) {
			Node* temp = tmp->next;
			tmp->next = tmp->next->next;
			delete temp;
		}
		tmp = tmp->next;
	}
}
void add(Node*& head, int val) {
	Node* nowy = new Node;
	nowy->value = val;
	nowy->next = NULL;
	if (head == NULL) head = nowy;
	else {
		Node* tmp = head;
		while (tmp->next) tmp = tmp->next;
		tmp->next = nowy;
	}
}
void print(Node* head) {
	while (head) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* head = NULL;
	add(head, 4);
	add(head, 6);
	add(head, 5);
	add(head, 7);
	add(head, 3);
	add(head, 2);
	add(head, 1);
	add(head, 7);
	add(head, 2);
	print(head);
	usun(head);
	print(head);


}