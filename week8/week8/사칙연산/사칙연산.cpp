#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int a;
	int b;
	cin >> a >> b;
	cout << a + b << endl
		<< a - b << endl
		<< a * b << endl
		<< a / b << endl
		<< a % b << endl;
	return 0;
}