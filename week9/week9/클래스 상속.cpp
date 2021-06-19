#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class person {
protected:
	string name;
	char gender;
	int age;
public:
	person(string name, char gender, int age) {
		this->name = name;
		this->gender = gender;
		this->age = age;
	}
};

class student : public person {
	int num;
public:
	student(string name, char gender, int age, int num)
		:person{ name, gender, age }  //멤버 이니셜라이저 초기화
	{
		this->num = num;
	};
	void print();        //멤버함수 선언
};

void student::print() //멤버함수 정의
{
	cout << name << endl << gender << endl << age << endl << num << endl;
}

int main() {
	student 종이{ "박종현",'M',24,201720555 };
	종이.print();
	system("pause");  //설정문제
	return 0;
}
