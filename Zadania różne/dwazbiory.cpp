#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
int dwazbiory(Node*& head1, Node*& head2) {
	Node* helper1 = new Node;
	Node* helper2 = new Node;
	int ile = 0;
	helper1->next = head1;
	helper2->next = head2;
	Node* tmp2 = helper2;
	while (tmp2->next != NULL) {
		Node* tmp1 = helper1;
		while (tmp1->next != NULL && tmp1->next != tmp2->next) tmp1 = tmp1->next;
		if (tmp1->next == NULL) tmp2 = tmp2->next;
		else {
			while (tmp2->next != NULL) {
				Node* nowy = tmp2->next;
				tmp1->next = nowy;
				tmp2 = tmp2->next;
				tmp1 = tmp1->next;
				ile++;
			}
		}
	}
	head1 = helper1->next;
	head2 = helper2->next;
	return ile;
}
void add(Node*& head, int val) {
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
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* headA = new Node;
	Node* a1 = new Node;
	Node* a2b3 = new Node;
	Node* a3b4 = new Node;
	Node* headB = new Node;
	Node* b1 = new Node;
	Node* b2 = new Node;
	headA->value = 5;
	a1->value = 11;
	a2b3->value = 3;
	a3b4->value = 2;
	headB->value = 13;
	b1->value = 7;
	b2->value = 17;
	headA->next = a1;
	a1->next = a2b3;
	a2b3->next = a3b4;
	a3b4->next = NULL;
	headB->next = b1;
	b1->next = b2;
	b2->next = a2b3;
	print(headA);
	print(headB);
	cout << dwazbiory(headA, headB)<<endl;
	print(headA);
	print(headB);

}