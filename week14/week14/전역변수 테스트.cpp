#include <iostream>
using namespace std;

int x; //���������� �ʱ�ȭ���� �ʾƵ� �⺻���� 0���� �ʱ�ȭ�ȴ�.

int main() {
	if (x == 0)
		cout << 1 << endl;
	if (x == false)
		cout << 2 << endl;
	if (x == NULL)
		cout << 3 << endl;

	return 0;
}
