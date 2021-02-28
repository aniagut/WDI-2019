#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
/*
99. Dana jest lista, który zakończona jest cyklem. Napisać funkcję, która
zwraca wskaźnik do ostatniego elementu przed cyklem.
*/
Node* ostatniprzedcyklem(Node* head) {
	Node* s_tmp = head;
	Node* f_tmp = head->next;
	while (s_tmp != f_tmp) {
		s_tmp = s_tmp->next;
		f_tmp = f_tmp->next->next;
	}
	//s_tmp=f_tmp
	Node* helper = head;
	do {
		s_tmp = s_tmp->next;
		if (s_tmp == f_tmp) helper = helper->next;
	} while (s_tmp != helper->next);
	return helper;
}
int main() {
	Node* head = new Node;
	Node* head1 = new Node;
	Node* head2 = new Node;
	Node* head3 = new Node;
	Node* head4 = new Node;
	Node* head5 = new Node;
	Node* head6 = new Node;
	head->value = 0;
	head->next = head1;
	head1->value = 1;
	head1->next = head2;
	head2->value = 2;
	head2->next = head3;
	head3->value = 3;
	head3->next = head4;
	head4->value = 4;
	head4->next = head5;
	head5->value = 5;
	head5->next = head6;
	head6->value = 6;
	head6->next = head4;
	cout << (ostatniprzedcyklem(head))->value;
}

