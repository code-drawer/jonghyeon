#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

enum ���� { ������ = 1, �ܺ��� };
/*main���Ͽ��� ����'����'�� ���������̹Ƿ� ���� �ʱ�ȭ���� �ʴ� ��,
�⺻���� 0���� �ʱ�ȭ�ȴ�.
�׷��Ƿ� �����ڰ� 0�� �Ǹ� 0 == false�̹Ƿ�
���� == ������ �� �Ǿ������.
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
