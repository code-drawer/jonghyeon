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

	person(string name, char gender, int age) {  /*personŬ������
												 �������̴�.
												 (Ŭ�������� �����)
												 personŬ������
												 ���������
												 �ʱ�ȭ�Ѵ�.*/
		this->name = name;
		this->gender = gender;
		this->age = age;        /*�����̸��� �����̸��� ��ġ�� ���� 
								�����ϰ��� this->�� �������ν� 
								���罺������ '����'���� ����*/
	}
};

class student : public person {  /*studentŬ������ 
								 personŬ������ ��ӹ޾Ҵ�.*/
	int num;       //private �������

public:  //�׻� ���� ������ ����Լ�

	student(string name, char gender, int age, int num)
		/*studentŬ������ �������̴�.
		���������� (Ŭ�������� �����) ��������� �ʱ�ȭ���ش�.*/

		:person{ name, gender, age }  /*��� �̴ϼȶ����� �ʱ�ȭ.
									  �� ����� ����
									  person������ �����������
									  ���� �ʱ�ȭ�Ѵ�.*/
	{
		this->num = num;       /*num�� studentŬ����������
							   ��������̴�.
							   this->�� ���� ���� �ʱ�ȭ ���ش�.*/
	};
	void print();        //����Լ� ���� (���� ���ǵ����� ����)
};

void student::print() //studentŬ������ ����Լ�print�� ���� �����Ѵ�.
{
	cout << name << endl << gender << endl << age << endl << num << endl;
}  /*�ڽ�Ŭ������ ����Լ��� �� Ŭ������ ���������
   �θ�Ŭ�����κ��� ������ ���������
   ��� ����Ѵ�.*/

int main() {
	student ����{ "������",'M',24,201720555 };
	/*studentŬ�������� '����'�� ����ȴ�.
	studentŬ���� �����ڿ� ���� studentŬ���� ��������� �ʱ�ȭ�Ǹ�
	��� �̴ϼȶ����� �ʱ�ȭ�� ����
	personŬ���� �����ڿ� ���� personŬ���� ��������� �ʱ�ȭ�ȴ�.*/

	����.print();  /*Ŭ�������� '����'�� ���� 
				 student����Լ� print�� �����Ų��.*/

	return 0;
}
