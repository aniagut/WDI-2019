/*
26. Dane są dwie niepuste listy, z których każda zawiera niepowtarzające
się elementy. Elementy w pierwszej liście są uporządkowane rosnąco, w
drugiej elementy występują w przypadkowej kolejności. Proszę napisać
funkcję, która z dwóch takich list stworzy jedną, w której uporządkowane
elementy będą stanowić sumę mnogościową elementów z list wejściowych.
Do funkcji należy przekazać wskazania na obie listy, funkcja powinna
zwrócić wskazanie na listę wynikową. Na przykład dla list:
2 -> 3 -> 5 ->7-> 11
8 -> 2 -> 7 -> 4
powinna pozostać lista:
2 -> 3 -> 4 -> 5 ->7-> 8 -> 11
*/
#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
void wstaw(Node*& head, int val) {
	Node* helper = new Node;
	helper->next = head;
	Node* tmp = helper;
	Node* nowy = new Node;
	nowy->value = val;
	nowy->next = NULL;
	while (tmp->next != NULL && tmp->next->value < val) tmp = tmp->next;
	if (tmp->next == NULL) tmp->next = nowy;
	else if(tmp->next->value>val) {
		nowy->next = tmp->next;
		tmp->next = nowy;
	}
	head = helper->next; 
}
Node* del(Node* head1, Node* head2) {
	Node* nowy = head1;
	while (head2 != NULL) {
		wstaw(nowy, head2->value);
		head2 = head2->next;
	}
	return nowy;
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
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
int main() {
	Node* head1 = NULL;
	Node* head2 = NULL;
	add(head1, 2);
	add(head1, 3);
	add(head1, 5);
	add(head1, 7);
	add(head1, 11);
	add(head2, 8);
	add(head2, 2);
	add(head2, 7);
	add(head2, 4);
	print(del(head1,head2));
}