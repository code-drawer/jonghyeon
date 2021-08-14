#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class student{
	string 이름;
	string 성별;
	string 비번;
	string 권한 = "외부인"; //기본값

public:
	student(string, string, string);
	string 이름줘();
	void 이름바꿔(string);
	string 비번줘();
	void 비번바꿔(string);
	string 권한줘();
	void 권한바꿔();
};
