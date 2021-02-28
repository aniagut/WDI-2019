/*
18. Kolejne elementy listy o zwiększającej się wartości pola val nazywamy
podlistą rosnącą. Proszę napisać funkcję, która usuwa z listy wejściowej
najdłuższą podlistę rosnącą. Warunkiem usunięcia jest istnienie w liście
dokładnie jednej najdłuższej podlisty rosnącej.
*/
#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};
void usuwaPodliste(Node*& head) {
	Node* longestBeg = new Node;
	int longestLength = 0;
	bool flag = false;
	Node* temp = head;
	while (temp != NULL) {
		Node* tmp = temp;
		Node* currentBeg = temp;
		int currentLength = 1;
		while (tmp->next != NULL && tmp->next->value > tmp->value) {
			currentLength++;
			tmp = tmp->next;
		}
		if (currentLength == longestLength) flag = false;
		if (currentLength > longestLength) {
			flag = true;
			longestLength = currentLength;
			longestBeg = currentBeg;
		}
		temp = temp->next;
	}
	if (flag) { 
		Node* helper = new Node;
		helper->value = -1;
		helper->next = head;
		Node* tmp = helper;
		while (tmp->next != longestBeg) tmp = tmp->next;
		Node* tmp2 = longestBeg;
		for (int i = 1; i < longestLength; i++) {
			tmp2 = tmp2->next;
		}
		tmp->next = tmp2->next;
		tmp2->next = NULL;
		while (longestBeg != NULL) {
			Node* tmp1 = longestBeg;
			longestBeg = longestBeg->next;
			delete tmp1;
		}
		Node* tmp3 = helper;
		helper = helper->next;
		delete tmp3;
		head = helper;
	}
}
void print(Node* head) {
	while (head != NULL) {
		cout << head->value << ",";
		head = head->next;
	}
	cout << endl;
}
void addFront(Node*& head, int val) {
	Node* nowy = new Node;
	nowy->value = val;
	nowy->next = NULL;
	if (head == NULL) head = nowy;
	else {
		Node* tmp = head;
		head = nowy;
		nowy->next = tmp;
	}
}
int main() {
	Node* head = NULL;
	addFront(head, 13);
	addFront(head, 12);
	addFront(head, 401);
	addFront(head, 400);
	addFront(head, 210);
	addFront(head, 109);
	addFront(head, 110);
	print(head);
	usuwaPodliste(head);
	print(head);

}





