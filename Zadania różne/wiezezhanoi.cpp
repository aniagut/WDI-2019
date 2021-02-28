#include <iostream>
using namespace std;
 
void hanoi(int ile, char start, char koniec, char pomocnik) {
	if (ile > 0) {
		hanoi(ile - 1, start, pomocnik, koniec);
		cout << "Przesun dysk z " << start << " do " << koniec << endl;
		hanoi(ile - 1, pomocnik, koniec, start);
	}
}

int main() {
	hanoi(3, 'a', 'b', 'c');
}