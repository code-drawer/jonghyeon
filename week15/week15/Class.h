#pragma once
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;  //�켱 std namespace���� �ʿ��� �Լ����� �����´�.

class person {
protected:           //��ӹ��� Ŭ���������� ���� ������ �������

	string name;
	char gender;
	int age;

public:           //�׻� ���� ������ ����Լ�

	person(string name, char gender, int age);
};

class student : public person {
	//studentŬ������personŬ������ ��ӹ޾Ҵ�.

	int num;       //private �������

public:  //�׻� ���� ������ ����Լ�

	student(string, char, int, int); //������ ���� (���� ���ǵ����� ����)
	void print();        //����Լ� ���� (���� ���ǵ����� ����)
};
