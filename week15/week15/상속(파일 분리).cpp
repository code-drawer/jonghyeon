#include "Class.h"

int main() {
	student 종이{ "박종현",'M',24,201720555 };
	/*student클래스변수 '종이'가 선언된다.
	student클래스 생성자에 의해 student클래스 멤버변수가 초기화되며
	멤버 이니셜라이저 초기화에 의해
	person클래스 생성자에 의해 person클래스 멤버변수가 초기화된다.*/

	종이.print();  /*클래스변수 '종이'에 대해
				 student멤버함수 print를 적용시킨다.*/

	return 0;
}
