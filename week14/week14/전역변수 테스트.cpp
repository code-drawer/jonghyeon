#include <iostream>
using namespace std;

int a; //���������� �ʱ�ȭ���� �ʾƵ� �⺻���� 0���� �ʱ�ȭ�ȴ�.

int main() {
	if (a == 0)
		cout << 1 << endl;
	if (a == false)
		cout << 2 << endl;
	if (a == NULL)
		cout << 3 << endl;

	return 0;
}
