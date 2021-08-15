#include <iostream>
using namespace std;

int a; //전역변수는 초기화하지 않아도 기본값인 0으로 초기화된다.

int main() {
	if (a == 0)
		cout << 1 << endl;
	if (a == false)
		cout << 2 << endl;
	if (a == NULL)
		cout << 3 << endl;

	return 0;
}
