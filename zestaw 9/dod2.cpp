#include <iostream>
using namespace std;
/*
2. Proszę napisać funkcję usuwającą ostatni element listy. Do funkcji
należy przekazać wskazanie na pierwszy element listy.

*/
struct Node {
	int value;
	Node* next;
};

void delLast(Node*& head) {
	if (head == NULL) return;
	Node* tmp = head;
	Node* prev = NULL;
	while (tmp->next != NULL) {
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	delete tmp;
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << ",";
		head = head->next;
	}
	cout << endl;
}

int main() {
	Node* head = new Node;
	Node* pierwszy = new Node;
	Node* drugi = new Node;
	head->value = 7;
	head->next = pierwszy;
	pierwszy->value = 56;
	pierwszy->next = drugi;
	drugi->value = 90;
	drugi->next = NULL;
	print(head);
	delLast(head);
	print(head);
	delLast(head);
	print(head);
	delLast(head);
	print(head);
}