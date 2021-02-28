/*27. Proszę napisać funkcję, która rozdziela listę na dwie listy. Pierwsza
powinna zawierać klucze parzyste dodatnie, drugi klucze nieparzyste ujemne,
pozostałe elementy należy usunąć z pamięci. Do funkcji należy przekazać
wskaźniki na listę z danymi oraz wskaźniki na listy wynikowe. Funkcja
powinna zwrócić liczbę usuniętych elementów. */


#include <iostream>
using namespace std;
struct Node {
	int value;
	Node* next;
};

void addToList(Node*&head, int val) {
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

void del(Node*& head, int val) {
	if (head != NULL) {
		Node* helper = new Node;
		helper->next = head;
		Node* tmp = helper;
		while (tmp->next != NULL && tmp->next->value != val) tmp = tmp->next;
		if (tmp->next != NULL) {
			Node* temp = tmp->next;
			tmp->next = tmp->next->next;
			delete temp;
		}
		head = helper->next;
	}
}
	int usuwanietakieo(Node * &head, Node * &nu, Node * &pd) {
		int licznik = 0;
		Node* helper = new Node;
		helper->next = head;
		Node* tmp = helper;
		while (tmp->next != NULL) {
			if (tmp->next->value > 0 && tmp->next->value % 2 == 0) {
				addToList(pd,tmp->next->value);
				tmp = tmp->next;
			}
			if (tmp->next->value < 0 && tmp->next->value % 2 != 0) {
				addToList(nu, tmp->next->value);
				tmp = tmp->next;
			}
			else {
				del(head, tmp->next->value);
				licznik++;
			}
		}
		head = helper->next;
		return licznik;
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
		Node* nu = NULL;
		Node* pd = NULL;
		addToList(head, 4);
		addToList(head, -8);
		addToList(head, 13);
		addToList(head, 9);
		addToList(head, -1);
		addToList(head, 24);
		addToList(head, -7);
		addToList(head, 18);
		addToList(head, 41);
		addToList(head, 100);
		addToList(head, -3);
		addToList(head, -14);
		print(head);
		usuwanietakieo(head, nu, pd);
		print(head);
		print(nu);
		print(pd);
	}