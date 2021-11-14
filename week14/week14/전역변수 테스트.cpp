#include <iostream>
using namespace std;

int x; //전역변수는 초기화하지 않아도 기본값인 0으로 초기화된다.

int main() {
	if (x == 0)
		cout << 1 << endl;
	if (x == false)
		cout << 2 << endl;
	if (x == NULL)
		cout << 3 << endl;

	return 0;
}
