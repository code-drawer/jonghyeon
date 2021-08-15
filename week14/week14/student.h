#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

enum 권한 { 관리자 = 1, 외부인 };
/*main파일에서 변수'권한'은 전역변수이므로 따로 초기화하지 않는 한,
기본값인 0으로 초기화된다.
그러므로 관리자가 0이 되면 0 == false이므로
권한 == 관리자 가 되어버린다.
이것은 맴버함수의 조건문을 true로 만들기 때문에 오류가 난다.
이것을 방지하고자 관리자에 0이 아닌 1을 할당하였다.*/

extern int 권한;
/*extern문을 사용하여 다른 파일에서
외부변수로써 가져다 쓸 수 있도록 한다고 선언한다.
만약 static문을 사용한다면
전역변수로써는 작동하지만
다른 파일에서는 변수를 사용할 수가 없게된다.*/

class student{
	string 이름;
	string 성별;
	string 비번;

public:
	student(string, string, string);
	string 이름줘();
	void 이름바꿔(string);
	string 비번줘();
	void 비번바꿔(string);
};
