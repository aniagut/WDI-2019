#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
/*
 Proszę napisać funkcję, która dla podanej listy odwraca kolejność jej
elementów.
*/
void reverse(Node*& head) {
	if (head != NULL) {
		Node* tmp = head;
		Node* tmp1 = new Node;
		while (tmp->next != NULL) {
			tmp1 = tmp->next;
			tmp->next = tmp1->next;
			tmp1->next = head;
			head = tmp1;
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
	Node* a1 = new Node;
	Node* b1 = new Node;
	Node* c1 = new Node;
	head->value = 23;
	head->next = a1;
	a1->value = 56;
	a1->next = b1;
	b1->value = 57;
	b1->next = c1;
	c1->value = 123;
	c1->next = NULL;
	print(head);
	reverse(head);
	print(head);
}
