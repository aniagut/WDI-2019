#include <iostream>
using namespace std;
/*
3. Dana jest niepusta lista, proszę napisać funkcję usuwającą co drugi
element listy. Do funkcji należy przekazać wskazanie na pierwszy element
listy.
*/
struct Node {
	string napis;
	Node* next;
};
void del(Node* head) {
		Node* tmp = head;
		while (tmp->next != NULL) {
			Node* temp = tmp->next;
			tmp->next = tmp->next->next;
			delete temp;
			if (tmp->next != NULL) tmp = tmp->next;
		}
} 
/*
7. Zbiór mnogościowy zawierający napisy jest reprezentowany w postaci
jednokierunkowej listy. Napisy w łańcuchu są uporządkowane
leksykograficznie. Proszę napisać stosowne definicje typów oraz funkcję
dodającą napis do zbioru. Do funkcji należy przekazać wskaźnik do listy
oraz wstawiany napis, funkcja powinna zwrócić wartość logiczną wskazującą,
czy w wyniku operacji moc zbioru uległa zmianie.
*/
void dodyjnapis(Node*& head, string nap) {
	Node* nowy = new Node;
	nowy->napis = nap;
	nowy->next = NULL;
	if (head == NULL) head = nowy;
	else if ((int)nap[0] <= ((int)(head->napis)[0]) {
		while()
	}
	else {
		Node* tmp = head;
		while((int)nap[0]>)
	}
}
/*
void addToList(Node*& head, int val) {
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
*/
int main() {
	/*
	Node* head = NULL;
	addToList(head, 1);
	addToList(head, 10);
	addToList(head, 12);
	addToList(head, 18);
	addToList(head, 11);
	addToList(head, 2);
	addToList(head, 1);
	addToList(head, 8);
	*/
	cout << (int)'a';



}
