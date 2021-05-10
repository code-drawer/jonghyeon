#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int n;
	cin >> n;
	for (int i = n-1; i >=0; i -= 1) {
		for (int j = 0; j < i; j += 1) {
			cout << " ";
		}
		for (int j = 0; j < n - i; j += 1) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}