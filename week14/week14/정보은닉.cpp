#include "student.h"
int 권한;
/*헤더파일에서 extern문을 사용했던 변수를
main이 되는 곳에 전역변수로 선언해준다. (초기화를 할 수도 있다.)*/

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
