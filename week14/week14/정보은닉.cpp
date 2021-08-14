#include "student.h"

int main() {
	student 종이{ "박종현", "남", "0417"};

	cout << 종이.이름줘() << endl;
	종이.이름바꿔("종현박");
	cout << 종이.이름줘() << endl;

	cout << 종이.권한줘() << endl;
	cout << 종이.비번줘() << endl;
	종이.비번바꿔("0000");
	cout << 종이.비번줘() << endl;

	종이.권한바꿔();
	//맴버변수'권한'을 변경하여 맴버함수의 조건문을 충족시킨다.
	cout << 종이.권한줘() << endl;
	cout << 종이.비번줘() << endl;
	종이.비번바꿔("0000");
	cout << 종이.비번줘() << endl;

	return 0;
}