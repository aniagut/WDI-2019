#include <iostream>
using namespace std;
/*
Napisz funkcję, która przyjmuje wskaźnik do początku jednokierunkowego
łańcucha odsyłaczowego, a następnie przenosi na początek wszystkie
elementy, w których zapisie ósemkowym występuje nieparzysta liczba piątek.
*/
struct Node {
	int value;
	Node* next;
};
bool warunek(int n) {
	int ile = 0;
	while (n > 0) {
		if (n % 8 == 5) ile++;
		n /= 8;
	}
	if (ile % 2 != 0) return true;
	else return false;
}
Node* napoczatek(Node*& head) {
	Node* tmp = head;
	while (tmp->next != NULL) {
		if (warunek(tmp->next->value)) {
			Node* temp = tmp->next;
			tmp->next = tmp->next->next;
			temp->next = head;
			head = temp;
		}
		else tmp = tmp->next;
	}
	return head;
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
void print(Node* head) {
	while (head) {
		cout << head->value << " ";
		head = head->next;
	}
	cout << endl;
}
int main() {
	Node* head = NULL;
	add(head, 2);
	add(head, 5);
	add(head, 3);
	add(head, 5);
	add(head, 7);
	add(head, 9);
	add(head, 5);
	print(head);
	print(napoczatek(head));
}