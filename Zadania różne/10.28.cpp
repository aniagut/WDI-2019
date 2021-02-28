/*
28. Lista reprezentuje wielomian o współczynnikach całkowitych. Elementy w
liście ułożone są według rosnących potęg. Proszę napisać funkcję
obliczającą różnicę dwóch dowolnych wielomianów. Wielomiany reprezentowane
są przez wyżej opisane listy. Procedura powinna zwracać wskaźnik do nowo
utworzonej listy reprezentującej wielomian wynikowy. Listy wejściowe
powinny pozostać niezmienione.
*/
struct Node {
	int value;
	Node* next;
};
#include <iostream>
using namespace std;
Node* roznica(Node* head1, Node* head2) {
	Node* nowyW = new Node;
	nowyW->value = -1;
	nowyW->next = NULL;
	Node* tmp1 = head1;
	Node* tmp2 = head2;
	Node* tmp3 = nowyW;
	while (tmp1 != NULL && tmp2 != NULL) {
		Node* temp = new Node;
		temp->value = tmp1->value + tmp2->value;
		temp->next = NULL;
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
		tmp3->next = temp;
		tmp3 = tmp3->next;
	}
	if (tmp1 != NULL) {
		tmp3->next = tmp1;
	}
	if (tmp2 != NULL) {
		tmp3->next = tmp2;
	}
	nowyW = nowyW->next;
	return nowyW;
}
void addToList(Node*& head, int val) {
	Node* nowy = new Node;
	nowy->value = val;
	nowy->next = NULL;
	if (head == NULL) head = nowy;
	Node* tmp = head;
	while (tmp->next != NULL) tmp = tmp->next;
	tmp->next = nowy;
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* a = NULL;
	Node* b = NULL;
	addToList(a, 1);
	addToList(a, 7);
	addToList(a, 0);
	addToList(a, 5);
	addToList(b, 4);
	addToList(b, 3);
	addToList(b, 1);
	print(a);
}