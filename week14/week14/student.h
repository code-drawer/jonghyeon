#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class student{
	string �̸�;
	string ����;
	string ���;
	string ���� = "�ܺ���"; //�⺻��

public:
	student(string, string, string);
	string �̸���();
	void �̸��ٲ�(string);
	string �����();
	void ����ٲ�(string);
	string ������();
	void ���ѹٲ�();
};
