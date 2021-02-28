#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
/*
5. Proszę napisać funkcję, która rozdziela elementy listy wejściowej do 10
list, według ostatniej cyfry pola val. W drugim kroku powstałe listy należy
połączyć w jedną listę, która jest posortowana niemalejąco według ostatniej
cyfry pola val.
*/
//tablica dziesiecioelementowa
void rozdzielanie(Node* arr[10], Node* head) {
	while (head != NULL) {
		Node* temp = head;
		head = head->next;
		temp->next = arr[temp->value % 10];
		arr[temp->value % 10] = temp;
	}
}
Node* laczenieList(Node* arr[10]) {
	Node* helper = new Node;
	helper->value = -1;
	helper->next = NULL;
	Node* temp = helper;
	for (int i = 0; i < 10; i++) {
		temp->next = arr[i];
		while (temp->next != NULL) temp = temp->next;
	}
	Node* newList = helper->next;
	delete helper;
	return newList;
}
Node* func(Node* head) {
	Node** arr = new Node * [10];
	for (int i = 0; i < 10; i++) {
		arr[i] = NULL;
	}
	rozdzielanie(arr, head);
	return laczenieList(arr);
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
	Node* head = NULL;
	addBack(head, 65);
	addBack(head, 43);
	addBack(head, 81);
	addBack(head, 9);
	addBack(head, 50);
	addBack(head, 47);
	addBack(head, 33);
	addBack(head, 91);
	print(head);
	print(func(head));

}