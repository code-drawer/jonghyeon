#include "student.h"
int 권한;
/*헤더파일에서 extern문을 사용하기 위해
전역변수'권한'을 main파일에서 원본변수로써 선언해준다.*/

int main() {
	student 종이{ "박종현", "남", "0417"};

	cout << 종이.이름줘() << endl;
	종이.이름바꿔("종현박");
	cout << 종이.이름줘() << endl;

	cout << 종이.비번줘() << endl;
	종이.비번바꿔("0000");
	cout << 종이.비번줘() << endl;

	권한 = 관리자;
	cout << 종이.비번줘() << endl;
	종이.비번바꿔("0000");
	cout << 종이.비번줘() << endl;

	return 0;
}
