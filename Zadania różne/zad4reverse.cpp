#include <iostream>
using namespace std;
/*
4. Proszę napisać funkcję, która dla podanej listy odwraca kolejność jej
elementów.
*/
struct Node {
	int value;
	Node* next;
};
Node* reverse(Node*& head) {
	if (head != NULL) {
		Node* tmp = head;
		while (tmp->next != NULL) {
			Node* temp = tmp->next;
			tmp->next = tmp->next->next;
			temp->next = head;
			head = temp;
		}
	}
	return head;
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
	Node* head = NULL;
	addBack(head, 7);
	addBack(head, 90);
	addBack(head, 61);
	addBack(head, 6);
	addBack(head, 41);
	print(head);
	print(reverse(head));
}