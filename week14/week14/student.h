#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

enum ���� { ������ = 1, �ܺ��� };
/*main���Ͽ��� ������ ���� �ʱ�ȭ�ص��� �ʴ� ��,
������ �⺻������ null == 0 == false�̴�.
�����ڰ� 0�� �Ǹ� 0 == false�̹Ƿ�
���� == ������ �̴�.
�̰��� �ɹ��Լ��� ���ǹ��� true�� ����� ������ ������ ����.
�̰��� �����ϰ��� �����ڿ� 0�� �ƴ� 1�� �Ҵ��Ͽ���.*/

extern int ����;
/*extern���� ����Ͽ� �ٸ� ���Ͽ���
�ܺκ����ν� ������ �� �� �ֵ��� �Ѵٰ� �����Ѵ�.
���� static���� ����Ѵٸ�
���������ν�� �۵�������
�ٸ� ���Ͽ����� ������ ����� ���� ���Եȴ�.*/

class student{
	string �̸�;
	string ����;
	string ���;

public:
	student(string, string, string);
	string �̸���();
	void �̸��ٲ�(string);
	string �����();
	void ����ٲ�(string);
};
