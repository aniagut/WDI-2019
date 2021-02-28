#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
/*
22. Proszę napisać funkcję, która sprawdza czy jedna lista zawiera się w
drugiej.Do funkcji należy przekazać wskazania na pierwsze elementy obu
list, funkcja powinna zwrócić wartość logiczną.
*/
bool czyZawierasie(Node* head1, Node* head2) {
	while (head1!=NULL && head2 != NULL) {
		if (head2 == head1) {
			Node* tmp1 = head1;
			Node* tmp2 = head2;
			while (tmp1->next != NULL && tmp1->next==tmp2->next) {
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
			}
			if (tmp1 -> next == NULL) return true;
		}
		head2 = head2->next;
	}
	return false;
}
int main() {
	Node* head1 = new Node;
	Node* head2 = new Node;
	Node* head1a = new Node;
	Node* head2a = new Node;
	Node* head1b = new Node;
	Node* head2b = new Node;
	Node* head1c = new Node;
	Node* head2c = new Node;
	Node* head2d = new Node;
	Node* head2e = new Node;
	head1->value = 0;
	head1->next = head1a;
	head1a->value = 1;
	head1a->next = head1b;
	head1b->value = 2;
	head1b->next = head1c;
	head1c->value = 3;
	head1c->next = NULL;
	head2->value = 3;
	head2->next = head2a;
	head2a->value = 3;
	head2a->next = head1;
	cout << czyZawierasie(head1, head2);
}