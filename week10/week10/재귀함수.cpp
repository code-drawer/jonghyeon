#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int p(int k, int n) {
	if (k == 0) { return n; }
	int s = 0;
	for (int i = 1; i <= n; i++) {
		s += p(k - 1, i);
	}
	return s;
}

int main() {
	int k;
	int n;
	cin >> k;
	cin >> n;
	if (k < 1) { return 0; }
	if (n < 1 || n>14) { return 0; }

	cout << p(k, n) << endl;
	return 0;
}
