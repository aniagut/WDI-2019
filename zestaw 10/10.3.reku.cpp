/*
3. Proszę napisać funkcję scalającą dwie posortowane listy w jedną
posortowaną listę. Do funkcji należy przekazać wskazania na pierwsze
elementy obu list, funkcja powinna zwrócić wskazanie do scalonej listy.
- funkcja iteracyjna,
- funkcja rekurencyjna.
*/
//REKUUU
#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
Node* mergeReku(Node* head1, Node* head2) {
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		Node* result = new Node;
		if (head1->value < head2->value) {
			result = head1;
			head1 = head1->next;
		}
		else {
			result = head2;
			head2 = head2->next;
		}
		result->next = mergeReku(head1, head2);
		return result;
	}
}

void print(Node* head) {
	while (head != NULL) {
		cout << head->value << ",";
		head = head->next;
	}
	cout << endl;
}
void dodanieNaKoniec(Node*& head, int val) {
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
int main() {
	Node* head1 = NULL;
	Node* head2 = NULL;
	dodanieNaKoniec(head1, 0);
	dodanieNaKoniec(head2, 1);
	print(head1);
	print(head2);
	dodanieNaKoniec(head1, 2);
	dodanieNaKoniec(head2, 3);
	print(head1);
	print(head2);
	dodanieNaKoniec(head1, 4);
	dodanieNaKoniec(head2, 5);
	print(head1);
	print(head2);
	dodanieNaKoniec(head1, 6);
	dodanieNaKoniec(head2, 7);
	print(head1);
	print(head2);
	dodanieNaKoniec(head1, 8);
	dodanieNaKoniec(head2, 9);
	print(head1);
	print(head2);
	print(mergeReku(head1, head2));

}