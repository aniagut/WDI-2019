/*
4. Proszę napisać funkcję, która dla podanej listy odwraca kolejność jej
elementów.
*/
//IT
#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
Node* reverse(Node*& head) {
	if (head != NULL) {
		Node* tmp1 = head;
		Node* tmp2 = new Node;
		while (tmp1->next != NULL) {
			tmp2 = tmp1->next;
			tmp1->next = tmp2->next;
			tmp2->next = head;
			head = tmp2;
		}
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
void addFront(Node*& head,int val) {
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
int main() {
	Node* head = NULL;
	addFront(head, 0);
	addFront(head, 1);
	addFront(head, 2);
	addFront(head, 3);
	print(head);
	print(reverse(head));
}