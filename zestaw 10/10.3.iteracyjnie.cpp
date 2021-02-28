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
Node* scalanie(Node* head1, Node* head2) {
	Node* head = new Node;
	if (head1 != NULL && head2 != NULL) {
		if (head1->value > head2->value) {
			head = head2;
			head2 = head2->next;
		}
		else {
			head = head1;
			head1 = head1->next;
		}
	}
	else if (head1 != NULL) {
		head = head1;
	}
	else if (head2 != NULL) {
		head = head2;
	}
	else return NULL;
	Node* tmp = head;
			while (head1 != NULL && head2 != NULL) {
				if (head1->value > head2->value) {
					tmp->next = head2;
					head2 = head2->next;
			}
				else {
					tmp->next = head1;
					head1 = head1->next;
				}
				tmp = tmp->next;
			}
	if (head1 != NULL) {
		tmp->next = head;
	}
	if (head2 != NULL) {
		tmp->next = head2;
	}
	return head;
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << ",";
		head = head->next;
	}
	cout << endl;
}
void newElement(Node*& head, int val) {
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
int main() {
	Node* head1 = NULL;
	Node* head2 = NULL;
	newElement(head1, 5);
	newElement(head1, 9);
	newElement(head1, 19);
	newElement(head1, 65);
	newElement(head1, 503);
	newElement(head2, 3);
	newElement(head2, 15);
	newElement(head2, 21);
	newElement(head2, 38);
	newElement(head2, 3004);
	print(head1);
	print(head2);
	print(scalanie(head1, head2));

}
