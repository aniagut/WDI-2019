/*
3. Proszę napisać funkcję scalającą dwie posortowane listy w jedną
posortowaną listę. Do funkcji należy przekazać wskazania na pierwsze
elementy obu list, funkcja powinna zwrócić wskazanie do scalonej listy.
- funkcja iteracyjna,
- funkcja rekurencyjna.
*/
#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};

Node* merge2ListsReku(Node* head1, Node* head2) {
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;
	Node* result;
	if (head1->value < head2->value) {
		result = head1;
		head1 = head1->next;
	}
	else {
		result = head2;
		head2 = head2->next;
	}
	result->next = merge2ListsReku(head1, head2);
	return result;
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
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* head1 = NULL;
	Node* head2 = NULL;
	addBack(head1, 1);
	addBack(head1, 7);
	addBack(head1, 12);
	addBack(head1, 25);
	addBack(head2, 2);
	addBack(head2, 14);
	addBack(head2, 17);
	addBack(head2, 24);
	addBack(head2, 26);
	addBack(head2, 31);
	print(head1);
	print(head2);
	print(merge2ListsReku(head1, head2));
}