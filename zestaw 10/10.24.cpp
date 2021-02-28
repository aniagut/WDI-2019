/*
24. Dwie listy zawierają niepowtarzające się (w obrębie listy) liczby
naturalne. W pierwszej liście liczby są posortowane rosnąco, a w drugiej
nie. Proszę napisać funkcję usuwającą z obu list liczby występujące w obu
listach. Do funkcji należy przekazać wskazania na obie listy, funkcja
powinna zwrócić łączną liczbę usuniętych elementów.
*/
#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
int ileElementow(Node*& head1, Node*& head2) {
	Node* helper1 = new Node;
	Node* helper2 = new Node;
	helper1->value = -1;
	helper2->value = -1;
	helper1->next = head1;
	helper2->next = head2;
	int licznik = 0;
	Node* tmp1 = helper1;
	while (tmp1->next != NULL) {
		Node* tmp2 = helper2;
		while (tmp2->next != NULL) {
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
	Node* tmp3 = helper1;
	helper1 = helper1->next;
	delete tmp3;
	Node* tmp4 = helper2;
	helper2 = helper2->next;
	delete tmp4;
	return licznik;
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
		cout << head->value << ",";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* head1 = NULL;
	Node* head2 = NULL;
	add(head1, 0);
	add(head1, 1);
	add(head1, 2);
	add(head1, 3);
	add(head1, 4);
	add(head2, 3);
	add(head2, 5);
	add(head2, 8);
	add(head2, 1);
	add(head2, 9);
	print(head1);
	print(head2);
	cout << ileElementow(head1, head2) << endl;
	print(head1);
	print(head2);
}