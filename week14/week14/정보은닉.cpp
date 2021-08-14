#include "student.h"

int main() {
	student 종이{ "박종현", "남", "0417","관리자"};

	cout << 종이.이름줘() << endl;
	종이.이름바꿔("종현박");
	cout << 종이.이름줘() << endl;

	cout << 종이.비번줘() << endl;
	종이.비번바꿔("0000");
	cout << 종이.비번줘() << endl;

	return 0;
}
