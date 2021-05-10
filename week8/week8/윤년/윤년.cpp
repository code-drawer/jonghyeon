#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int y;
	cin >> y;
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
		cout << 1;
	}
	else cout << 0;
	return 0;
}