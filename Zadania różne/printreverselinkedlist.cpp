/*
linked list in reverse order rekurencyjnie
*/
#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
//void
void printreverse(Node* head) {
	if (head== NULL) return;
	printreverse(head->next);
	cout << head->value << " ";
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* head = new Node;
	Node* a = new Node;
	Node* b = new Node;
	head->value = 1;
	head->next = a;
	a->value = 2;
	a->next = b;
	b->value = 3;
	b->next = NULL;
	print(head);
	printreverse(head);
}