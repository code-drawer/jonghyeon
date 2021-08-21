#include "Class.h"

person::person(string name, char gender, int age) {
	/*person클래스의생성자이다.
	(클래스변수 선언시) 멤버변수를초기화한다.*/

	this->name = name;
	this->gender = gender;
	this->age = age;        /*변수이름이 인자이름과 겹치는 것을
							방지하고자 this->를 써줌으로써
							현재스코프의 '변수'임을 지적*/
}

student::student(string name, char gender, int age, int num)
/*student클래스의 생성자이다.
마찬가지로 (클래스변수 선언시) 멤버변수를 초기화해준다.*/

	:person{ name, gender, age }  /*멤버 이니셜라이저 초기화.
								  이 방법을 통해
								  person에서의 멤버변수값도
								  한번에 초기화한다.
								  (이때, 익명의 person객체가 생성된다.)*/
{
	this->num = num;       /*num은 student클래스에서의 멤버변수이다.
						   this->를 통해 따로 초기화 해준다.*/
}

void student::print() //student클래스의 멤버함수print를 정의한다.
{
	cout << name << endl << gender << endl << age << endl << num << endl;
}  /*자식클래스의 멤버함수가 그 클래스의 멤버변수와
   부모클래스로부터 가져온 멤버변수를 모두 출력한다.*/
