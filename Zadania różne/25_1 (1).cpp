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
int usun(Node*& head1, Node*& head2) {
	Node* helper1 = new Node;
	helper1->next = head1;
	Node* helper2 = new Node;
	helper2->next = head2;
	Node* tmp1 = helper1;
	Node* tmp2 = helper2;
	int licznik=0;
		while (tmp1->next && tmp2->next) {
		if (tmp1->next->value == tmp2->next->value) {
			Node* temp1 = tmp1->next;
			Node* temp2 = tmp2->next;
			tmp1->next = tmp1->next->next;
			tmp2->next = tmp2->next->next;
			delete temp1, temp2;
			licznik += 2;
		}
		else if (tmp1->next->value > tmp2->next->value) tmp2 = tmp2->next;
		else tmp1 = tmp1->next;
	}
		head1 = helper1->next;
		head2 = helper2->next;
		delete helper1, helper2;
		return licznik;
}
	void addTolist(Node * &head, int val) {
		Node* nowy = new Node;
		nowy->value = val;
		nowy->next = NULL;
		if (head == NULL) head = nowy;
		else {
			Node* tmp = head;
			while (tmp->next) tmp = tmp->next;
			tmp->next = nowy;
		}
	}
	void print(Node* head) {
		while (head) {
			cout << head->value << " ";
			head = head->next;
		}
		cout << endl;
	}
	int main() {
		Node* a = NULL;
		Node* b = NULL;
		addTolist(a, 1);
		addTolist(a, 3);
		addTolist(a, 5);
		addTolist(b, 1);
		addTolist(b, 3);
		addTolist(b, 4);
		print(a);
		print(b);
		cout << usun(a, b) << endl;
		print(a);
		print(b);

	}