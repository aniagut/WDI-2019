/*19. Dana jestlista, który być może zakończona jest cyklem.
Napisać funkcję, która sprawdza ten fakt.*/
#include<iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
bool czycykl(Node* head) {
	if (head != NULL && head->next != NULL) {
		Node* s_tmp = head;
		Node* f_tmp = head->next;
		while (f_tmp->next != NULL && f_tmp->next->next != NULL) {
			if (s_tmp == f_tmp) return true;
			s_tmp = s_tmp->next;
			f_tmp = f_tmp->next->next;
		}
	}
	return false;
}
void add(Node*& head, int val) {
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
void dodcykl(Node*& wsk) {
	if (wsk != NULL) {
		Node* tmp = wsk;
		while (tmp->next != NULL) tmp = tmp->next;
		tmp->next = wsk;
	}
}
void print(Node* head) {
	while (head) {
		cout << head->value<< " ";
		head = head->next;
	}
	cout << endl;
}
int ilewcyklu(Node* head) {
	Node* s_tmp = head;
	Node* f_tmp = head->next;
	while (s_tmp != f_tmp) {
		s_tmp = s_tmp->next;
		f_tmp = f_tmp->next->next;
	}
	int ile = 1;
	while (f_tmp->next != s_tmp) {
		ile++;
		f_tmp = f_tmp->next;

	}
	return ile;
}
int ileprzed(Node* head) {
	Node* s_tmp = head;
	Node* f_tmp = head->next;
	while (s_tmp != f_tmp) {
		s_tmp = s_tmp->next;
		f_tmp = f_tmp->next->next;
	}
	Node* helper = head;
	int licznik = 0;
	bool flag = true;
	while (flag) {
		while (s_tmp->next != helper && s_tmp->next != f_tmp) s_tmp = s_tmp->next;
		if (s_tmp->next == helper) return licznik;
		else {
			licznik++;
			helper = helper->next;
			s_tmp = s_tmp->next;
		}

	}
}
Node* ostatniprzed(Node* head) {
	Node* s_tmp = head;
	Node* f_tmp = head->next;
	while (s_tmp != f_tmp) {
		s_tmp = s_tmp->next;
		f_tmp = f_tmp->next->next;
	}
	bool flag = true;
	Node* helper = head;
	while (flag) {
		while (s_tmp->next != helper->next && s_tmp->next != f_tmp) s_tmp = s_tmp->next;
		if (s_tmp->next == helper->next) return helper;
		else {
			helper = helper->next;
			s_tmp = s_tmp->next;
		}
	}
}
/*
23. Proszę napisać funkcję scalającą dwie posortowane listy w jedną
posortowaną listę. Do funkcji należy przekazać wskazania na pierwsze
elementy obu list, funkcja powinna zwrócić wskazanie do scalonej listy.
- funkcja iteracyjna,
- funkcja rekurencyjna.
*/
Node* merge(Node* head1, Node* head2) {
	Node* nowa = new Node;
	nowa->next = NULL;
	Node* tmp = nowa;
	while (head1 && head2) {
		if (head1->value < head2->value) {
			tmp->next = head1;
			head1 = head1->next;
		}
		else {
			tmp->next = head2;
			head2 = head2->next;
		}
		tmp = tmp->next;
	}
	if (head1) tmp->next = head1;
	if (head2) tmp->next = head2;
	nowa = nowa->next;
	return nowa;
}
Node* mergeRequ(Node* head1, Node* head2) {
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;
	Node* result;
	if (head1->value < head2->value) {
		result = head1;
		head1 = head1->next;
	}
	else {
		result = head2;
		head2 = head2->next;
	}
	result->next = mergeRequ(head1, head2);
	return result;

}
int main() {
	Node* head1 = NULL;
	Node* head2 = NULL;
	add(head1, 2);
	add(head1, 4);
	add(head1, 7);
	add(head1, 10);
	add(head1, 12);
	add(head1, 12);
	add(head2, 3);
	add(head2, 5);
	add(head2, 6);
	add(head2, 11);
	print(head1);
	print(head2);
	print(mergeRequ(head1, head2));
}