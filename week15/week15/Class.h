#pragma once
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;  //우선 std namespace에서 필요한 함수들을 가져온다.

class person {
protected:           //상속받은 클래스에서만 접근 가능한 멤버변수

	string name;
	char gender;
	int age;

public:           //항상 접근 가능한 멤버함수

	person(string name, char gender, int age);
};

class student : public person {
	//student클래스가person클래스를 상속받았다.

	int num;       //private 멤버변수

public:  //항상 접근 가능한 멤버함수

	student(string, char, int, int); //생성자 선언 (아직 정의되지는 않음)
	void print();        //멤버함수 선언 (아직 정의되지는 않음)
};
