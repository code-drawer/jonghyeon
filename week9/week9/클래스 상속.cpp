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

	person(string name, char gender, int age) {  /*person클래스의
												 생성자이다.
												 (클래스변수 선언시)
												 person클래스의
												 멤버변수를
												 초기화한다.*/
		this->name = name;
		this->gender = gender;
		this->age = age;        /*변수이름이 인자이름과 겹치는 것을 
								방지하고자 this->를 써줌으로써 
								현재스코프의 '변수'임을 지적*/
	}
};

class student : public person {  /*student클래스가 
								 person클래스를 상속받았다.*/
	int num;       //private 멤버변수

public:  //항상 접근 가능한 멤버함수

	student(string name, char gender, int age, int num)
		/*student클래스의 생성자이다.
		마찬가지로 (클래스변수 선언시) 멤버변수를 초기화해준다.*/

		:person{ name, gender, age }  /*멤버 이니셜라이저 초기화.
									  이 방법을 통해
									  person에서의 멤버변수값도
									  같이 초기화한다.*/
	{
		this->num = num;       /*num은 student클래스에서의
							   멤버변수이다.
							   this->를 통해 따로 초기화 해준다.*/
	};
	void print();        //멤버함수 선언 (아직 정의되지는 않음)
};

void student::print() //student클래스의 멤버함수print를 마저 정의한다.
{
	cout << name << endl << gender << endl << age << endl << num << endl;
}  /*자식클래스의 멤버함수가 그 클래스의 멤버변수와
   부모클래스로부터 가져온 멤버변수를
   모두 출력한다.*/

int main() {
	student 종이{ "박종현",'M',24,201720555 };
	/*student클래스변수 '종이'가 선언된다.
	student클래스 생성자에 의해 student클래스 멤버변수가 초기화되며
	멤버 이니셜라이저 초기화에 의해
	person클래스 생성자에 의해 person클래스 멤버변수가 초기화된다.*/

	종이.print();  /*클래스변수 '종이'에 대해 
				 student멤버함수 print를 적용시킨다.*/

	return 0;
}
