/*Zadanie 3.
Napisz funkcję, która przyjmuje wskaźnik do początku jednokierunkowego
łańcucha odsyłaczowego, a następnie przenosi na początek wszystkie elementy,
w których zapisie ósemkowym występuje nieparzysta liczba piątek.*/
#include <iostream>
using namespace std;
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
void napocz(Node*& head) {
	if (head != NULL) {
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
	}
}
void add(Node*& head,int val) {
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
	Node* head = NULL;
	add(head, 7);
	add(head, 5);
	add(head, 12);
	add(head, 13);
	add(head, 4);
	add(head, 37);
	print(head);
	napocz(head);
	print(head);
}