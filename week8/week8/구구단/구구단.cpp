#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int n;
	cin >> n;
	if (n < 1 || n>9) return 0;
	for (int m = 1; m < 10; m += 1) {
		cout << n << "*" << m << "=" << n * m << endl;
	}
	return 0;
}