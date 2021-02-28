/*
20. Dana jest lista, który zakończona jest cyklem.
Napisać funkcję, która zwraca liczbę elementów w cyklu.
*/

#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
int dlugoscCyklu(Node* head) {
	Node* s_tmp = head;
	Node* f_tmp = head->next;
	while (s_tmp != f_tmp) {
		s_tmp = s_tmp->next;
		f_tmp = f_tmp->next->next;
	}
	s_tmp = s_tmp->next;
	int dlugosc = 1;
	while (s_tmp!=f_tmp) {
		s_tmp = s_tmp->next;
		dlugosc++;
	}
	return dlugosc;
}
int main() {
	Node* head = new Node;
	Node* head1 = new Node;
	Node* head2 = new Node;
	Node* head3 = new Node;
	Node* head4 = new Node;
	Node* head5 = new Node;
	Node* head6 = new Node;
	Node* head7 = new Node;
	head->value = 19;
	head->next = head1;
	head1->value = 19;
	head1->next = head2;
	head2->value = 19;
	head2->next = head3;
	head3->value = 19;
	head3->next = head4;
	head4->value = 19;
	head4->next = head5;
	head5->value = 19;
	head5->next = head6;
	head6->value = 19;
	head6->next = head7;
	head7->value = 19;
	head7->next = head4;
	cout << dlugoscCyklu(head);
}