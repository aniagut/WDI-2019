#include <iostream>
using namespace std;
/*
17. Dana jest lista zawierająca ciąg obustronnie domkniętych przedziałów.
Krańce przedziałów określa uporządkowana para liczb całkowitych. Proszę
napisać stosowne deklaracje oraz funkcję redukującą liczbę elementów listy.
Na przykład lista: [15,19] [2,5] [7,11] [8,12] [5,6] [13,17]
powinien zostać zredukowany do listy: [13,19] [2,6] [7,12]
*/
struct Node {
	int pocz;
	int konc;
	Node* next;
};
void redukowanie(Node*& head) {
	Node* tmp = head;
	while (tmp != NULL) {
		Node* tmp1 = tmp;
		while (tmp1->next != NULL) {
			if (tmp1->next->pocz <= tmp->pocz && tmp1->next->konc >= tmp->pocz || tmp1->next->pocz >= tmp->pocz && tmp1->next->pocz <= tmp->konc)
				if (tmp1->next->konc > tmp->konc) tmp->konc = tmp1->next->konc;
				Node* tmp2 = tmp1->next;
				tmp1->next = tmp1->next->next;
				delete tmp2;
			}
			else tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->pocz << "-" << head->konc << endl;
		head = head->next;
	}
}
int main() {
	Node* head = new Node;
	Node* head1 = new Node;
	Node* head2 = new Node;
	Node* head3 = new Node;
	Node* head4 = new Node;
	Node* head5 = new Node;
	head->pocz = 15;
	head->konc = 19;
	head->next = head1;
	head1->pocz = 2;
	head1->konc = 5;
	head1->next = head2;
	head2->pocz = 7;
	head2->konc = 11;
	head2->next = head3;
	head3->pocz = 8;
	head3->konc = 12;
	head3->next = head4;
	head4->pocz = 5;
	head4->konc = 6;
	head4->next = head5;
	head5->pocz = 13;
	head5->konc = 17;
	head5->next = NULL;
	print(head);
	cout << endl;
	redukowanie(head);
	print(head);

}