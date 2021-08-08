#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class A {
public:
	virtual void show() = 0; //순수 가상함수
}; //추상 클래스

class B : public A {
	virtual void show() { cout << "B" << endl; }
};

int main() {
	A* p;
	//A a; 못쓴다. 추상클래스는 객체를 만들 수 없다.
	B b;
	
	p = &b; p->show(); // (*p).show()와 같다.

	return 0;
}