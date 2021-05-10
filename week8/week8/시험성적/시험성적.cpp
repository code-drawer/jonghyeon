#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int a;
	cin >> a;
	if (a < 0 || a>100) return 0;
	else if (90 <= a && a <= 100) cout << "A";
	else if (80 <= a && a <= 89) cout << "B";
	else if (70 <= a && a <= 79) cout << "C";
	else if (60 <= a && a <= 69) cout << "D";
	else cout << "F";
	return 0;
}