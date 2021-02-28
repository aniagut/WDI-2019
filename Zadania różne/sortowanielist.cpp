/*
23. Proszę napisać funkcję scalającą dwie posortowane listy w jedną
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
Node* mergeSort(Node* head1, Node* head2) {
	Node* nowa = new Node;
	nowa->value = -1;
	nowa->next = NULL;
	Node* tmp3 = nowa;
	while (head1 != NULL && head2 != NULL) {
		if (head1->value > head2->value) {
			tmp3->next = head2;
			head2 = head2->next;
		}
		else {
			tmp3->next = head1;
			head1 = head1->next;
		}
		tmp3 = tmp3->next;
		tmp3->next = NULL;
	}
	if (head1 != NULL) tmp3->next = head1;
	if (head2 != NULL) tmp3->next = head2;
	nowa = nowa->next;
	return nowa;
}
Node* mergesortReku(Node* head1, Node* head2) {
	Node* result = new Node;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		if (head1->value < head2->value) {
			result = head1;
			result->next = mergesortReku(head1->next, head2);
		}
		else {
			result = head2;
			result->next = mergesortReku(head1, head2->next);
		}
		return result;
	}
}

void addToList(Node*& head, int val) {
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
	Node* a = NULL;
	Node* b = NULL;
	addToList(a, 1);
	addToList(a, 3);
	addToList(a, 7);
	addToList(a, 10);
	addToList(a, 12);
	addToList(a, 14);
	addToList(b, 2);
	addToList(b, 4);
	addToList(b, 5);
	addToList(b, 13);
	addToList(b, 21);
	print(a);
	print(b);
	print(mergesortReku(a, b));

}