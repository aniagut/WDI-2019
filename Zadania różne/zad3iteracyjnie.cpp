#include <iostream>
using namespace std;
/*
3. Proszę napisać funkcję scalającą dwie posortowane listy w jedną
posortowaną listę. Do funkcji należy przekazać wskazania na pierwsze
elementy obu list, funkcja powinna zwrócić wskazanie do scalonej listy.
- funkcja iteracyjna,
- funkcja rekurencyjna.
*/
struct Node {
	int value;
	Node* next;
};
Node* merge2List(Node* in1, Node* in2) {
	Node* out=new Node;
	out->next = NULL;
	Node* tmp = out;
	Node* tmp1 = in1;
	Node* tmp2 = in2;
	while (tmp1 != NULL && tmp2 != NULL) {
		if (tmp1->value < tmp2->value) {
			tmp->next = tmp1;
			tmp1 = tmp1->next;
		}
		else {
			tmp->next = tmp2;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	if (tmp1 != NULL) {
		tmp->next = tmp1;
	}
	if (tmp2 != NULL) {
		tmp->next = tmp2;
	}
	Node* temp = out;
	out = out->next;
	delete temp;
	return out;
}
void addBack(Node*& head, int val) {
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
	Node* head1 = NULL;
	Node* head2 = NULL;
	addBack(head1, 8);
	addBack(head1, 10);
	addBack(head1, 16);
	addBack(head1, 82);
	addBack(head1, 163);
	addBack(head2, 4);
	addBack(head2, 15);
	addBack(head2, 27);
	addBack(head2, 87);
	print(head1);
	print(head2);
	print(merge2List(head1, head2));

}