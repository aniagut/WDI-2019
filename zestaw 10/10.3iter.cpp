#include <iostream>
using namespace std;
/*
3. Proszę napisać funkcję scalającą dwie posortowane listy w jedną
posortowaną listę. Do funkcji należy przekazać wskazania na pierwsze
elementy obu list, funkcja powinna zwrócić wskazanie do scalonej listy.
- funkcja iteracyjna,
- funkcja rekurencyjna.
*/
struct Node {
	int value;
	Node* next;
};

Node* posortowanaiterac(Node*& head1, Node*& head2, Node*& head) {
	head->value = -1;
	head->next = NULL;
	Node* p = head;
	while (head1 != NULL & head2 != NULL) {
		if (head1->value > head2->value) {
			p->next = head2;
			head2 = head2->next;
		}
		else {
			p->next = head1;
			head1 = head1->next;
		}
		p = p->next;
	}
	while (head2 != NULL) {
		p->next = head2;
		head2 = head2->next;
	}
	while (head1 != NULL) {
		p->next = head1;
		head1 = head1->next;
	}
	Node* tmp = head;
	head = head->next;
	delete tmp;
	return head;
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
	Node* head1 = new Node;
	Node* a1 = new Node;
	Node* b1 = new Node;
	Node* c1 = new Node;
	Node* head2 = new Node;
	Node* a2 = new Node;
	Node* b2 = new Node;
	Node* c2 = new Node;
	head1->value = 23;
	head1->next = a1;
	a1->value = 56;
	a1->next = b1;
	b1->value = 57;
	b1->next = c1;
	c1->value = 123;
	c1->next = NULL;
	head2->value = 12;
	head2->next = a2;
	a2->value = 14;
	a2->next = b2;
	b2->value = 89;
	b2->next = c2;
	c2->value = 120;
	c2->next = NULL;
	print(head1);
	print(head2);
	print(posortowanaiterac(head1, head2, head));
}