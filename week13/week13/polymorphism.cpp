#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class A {
public:
	virtual void show() = 0; //���� �����Լ�
}; //�߻� Ŭ����

class B : public A {
	virtual void show() { cout << "B" << endl; }
	//�ڽ�Ŭ���������� virtual���� �� �ʿ������� ����.
};

int main() {
	A* p;
	//A a; ������. �߻�Ŭ������ ��ü�� ���� �� ����.
	B b;
	
	p = &b; p->show(); // (*p).show()�� ����.

	return 0;
}