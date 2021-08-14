#include "student.h"
//맴버함수 (외부)구현용 cpp파일

student::student(string 이름, string 성별, string 비번, string 권한) {//생성자 구현
	this->이름 = 이름;
	this->성별 = 성별;
	this->비번 = 비번;

	this->권한 = 권한;
}
string student::이름줘() {
	return 이름;
}
void student::이름바꿔(string 이름) {
	this->이름 = 이름;
}
string student::비번줘() {
	if (권한 == "관리자")
		return 비번;
	else
		return "얘!권한이 없단다!";
}
void student::비번바꿔(string 비번) {
	if (권한 == "관리자")
		this->비번 = 비번;
	else
		cout << "얘!권한이 없단다!" << endl;
}
