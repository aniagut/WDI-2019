#include <iostream>
using namespace std;
const int N = 6;
void suma(int t[N], int sumid, int sumel, int idx,int ile, int* najmile, int* sumadozwr) {
	if (sumid == sumel && ile != 0) {
		if (ile < *najmile) {
			*najmile = ile;
			*sumadozwr = sumel;
		}
	}
	if (idx < N) {
		for (int i = idx; i < N; i++) {
		suma(t, sumid + i, sumel + t[i], i + 1,ile+1,najmile,sumadozwr);
		}
	}
}
int zwr(int t[N]) {
	int sumadozwr = 0;
	int najmile = N+1;
	suma(t, 0, 0, 0, 0, &najmile, &sumadozwr);
	return sumadozwr;
}
int main() {
	int t[N] = { 1,2,0,1,1,2 };
	cout << zwr(t);
}