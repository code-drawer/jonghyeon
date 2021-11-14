#include "Class.h"

person::person(string name, char gender, int age) {
	/*personŬ�����ǻ������̴�.
	(Ŭ�������� �����) ����������ʱ�ȭ�Ѵ�.*/

	this->name = name;
	this->gender = gender;
	this->age = age;        /*�����̸��� �����̸��� ��ġ�� ����
							�����ϰ��� this->�� �������ν�
							���罺������ '����'���� ����*/
}

student::student(string name, char gender, int age, int num)
/*studentŬ������ �������̴�.
���������� (Ŭ�������� �����) ��������� �ʱ�ȭ���ش�.*/

	:person{ name, gender, age }  /*��� �̴ϼȶ����� �ʱ�ȭ.
								  �� ����� ����
								  person������ �����������
								  �ѹ��� �ʱ�ȭ�Ѵ�.
								  (�̶�, �͸��� person��ü�� �����ȴ�.)*/
{
	this->num = num;       /*num�� studentŬ���������� ��������̴�.
						   this->�� ���� ���� �ʱ�ȭ ���ش�.*/
}

void student::print() //studentŬ������ ����Լ�print�� �����Ѵ�.
{
	cout << name << endl << gender << endl << age << endl << num << endl;
}  /*�ڽ�Ŭ������ ����Լ��� �� Ŭ������ ���������
   �θ�Ŭ�����κ��� ������ ��������� ��� ����Ѵ�.*/
