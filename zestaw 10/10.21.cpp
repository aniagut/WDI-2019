#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
/*
21. Dana jest lista, który zakończona jest cyklem.
Napisać funkcję, która zwraca liczbę elementów przed cyklem
*/
int ileprzedCyklem(Node* head) {
	Node* s_tmp = head;
	Node* f_tmp = head->next;
	while (s_tmp != f_tmp) {
		s_tmp = s_tmp->next;
		f_tmp = f_tmp->next->next;
	}
	s_tmp = s_tmp->next;
	Node* helper = head; 
	int licznik = 0;
	do {
		s_tmp = s_tmp->next;
		if (s_tmp == f_tmp) {
			licznik++;
			helper = helper->next;
		}
		s_tmp = s_tmp->next;
	} while (s_tmp != helper);
	return licznik;
}
int main() {
	Node* head = new Node;
	Node* head1 = new Node;
	Node* head2 = new Node;
	Node* head3 = new Node;
	Node* head4 = new Node;
	Node* head5 = new Node;
	head->value = 0;
	head->next = head1;
	head1->value = 0;
	head1->next = head2;
	head2->value = 0;
	head2->next = head3;
	head3->value = 0;
	head3->next = head4;
	head4->value = 0;
	head4->next = head4;
	cout << ileprzedCyklem(head);

}