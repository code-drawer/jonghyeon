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
		:person{ name, gender, age }  //��� �̴ϼȶ����� �ʱ�ȭ
	{
		this->num = num;
	};
	void print();        //����Լ� ����
};

void student::print() //����Լ� ����
{
	cout << name << endl << gender << endl << age << endl << num << endl;
}

int main() {
	student ����{ "������",'M',24,201720555 };
	����.print();
	system("pause");  //��������
	return 0;
}
