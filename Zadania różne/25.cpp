#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
/*
24. Dwie listy zawierają niepowtarzające się (w obrębie listy) liczby
naturalne. W pierwszej liście liczby są posortowane rosnąco, a w drugiej
nie. Proszę napisać funkcję usuwającą z obu list liczby występujące w obu
listach. Do funkcji należy przekazać wskazania na obie listy, funkcja
powinna zwrócić łączną liczbę usuniętych elementów.
*/
void func(Node*& head1, Node*& head2) {
	int suma = 0;
	Node* helper1 = new Node;
	Node* helper2 = new Node;
	helper1->next = head1;
	helper2->next = head2;
	Node* tmp2 = helper2;
	while (tmp2->next != NULL) {
		Node* tmp1 = helper1;
		while (tmp1->next != NULL && tmp1->next->value < tmp2->next->value) {
			tmp1 = tmp1->next;
		}
		if (tmp1->next != NULL && tmp1->next->value == tmp2->next->value) {
			Node* temp1 = tmp1->next;
			Node* temp2 = tmp2->next;
			tmp1->next = tmp1->next->next;
			tmp2->next = tmp2->next->next;
			delete temp1, temp2;
			suma += 2;
		}
		else tmp2 = tmp2->next;
	}
	head1 = helper1->next;
	head2 = helper2->next;
	delete helper1, helper2;
	cout << suma << endl;
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
	Node* s = NULL;
	Node* n = NULL;
	addToList(s, 1);
	addToList(s, 4);
	addToList(s, 6);
	addToList(s, 8);
	addToList(n, 9);
	addToList(n, 2);
	addToList(n, 72);
	addToList(n, 3);
	print(s);
	print(n);
	func(s, n);
	print(s);
	print(n);
}