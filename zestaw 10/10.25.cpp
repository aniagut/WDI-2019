/*
25. Dwie listy zawierają niepowtarzające się (w obrębie listy) liczby
naturalne. W obu listach liczby są posortowane rosnąco. Proszę napisać
funkcję usuwającą z każdej listy liczby nie występujące w drugiej. Do
funkcji należy przekazać wskazania na obie listy, funkcja powinna zwrócić
łączną liczbę usuniętych elementów.
*/
#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
int ileusun(Node*& head1, Node*& head2) {
	Node* helper1 = new Node;
	helper1->value = -1;
	helper1->next = head1;
	Node* helper2 = new Node;
	helper2->value = -1;
	helper2->next = head2;
	Node* tmp1 = helper1;
	int licznik = 0;    //2 4 7 10 14 21 //3 4 11 14 17 29
	while (tmp1->next != NULL) {
		Node* tmp2 = helper2;
		while (tmp1->next != NULL && tmp2->next != NULL && tmp1->next->value>= tmp2->next->value) {
			if (tmp1->next->value == tmp2->next->value) {
				Node* tmp3 = tmp1->next;
				Node* tmp4 = tmp2->next;
				tmp1->next = tmp1->next->next;
				tmp2->next = tmp2->next->next;
				delete tmp3;
				delete tmp4;
				licznik += 2;
			}
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return licznik;
}
void addtolist(Node*& head, int val){ 
Node* nowy = new Node;
nowy->value = val;
nowy->next = NULL;
if (head == NULL) head = nowy;
else {
	Node* tmp = head;
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}
	tmp->next = nowy;
}
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << ",";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* head1 = NULL;
	Node* head2 = NULL;
	addtolist(head1, 2);
	addtolist(head1, 4);
	addtolist(head1, 7);
	addtolist(head1, 10);
	addtolist(head1, 14);
	addtolist(head1, 21);
	addtolist(head2, 3);
	addtolist(head2, 4);
	addtolist(head2, 11);
	addtolist(head2, 14);
	addtolist(head2, 17);
	addtolist(head2, 29);
	print(head1);
	print(head2);
	cout << ileusun(head1, head2) << endl;
	print(head1);
	print(head2);
}