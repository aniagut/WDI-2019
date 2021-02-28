#include <iostream>
using namespace std;
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
struct Node {
	int value;
	Node* next;
};
Node* sumamnogosciowa(Node* head1, Node* head2) {
	Node* newList = new Node;
	newList->value = -1;
	newList->next = NULL;
	Node* helper = newList;
	while (head1 != NULL) {
		Node* tmp = head2;
		while (tmp != NULL && tmp->value>=head1->value) {
			tmp = tmp->next;
		}
		if (tmp == NULL) {
			helper->next = head1;
			head1 = head1->next;
			helper = helper->next;
		}
	}
}