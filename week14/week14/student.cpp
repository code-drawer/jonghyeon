#include "student.h"
//�ɹ��Լ� (�ܺ�)������ cpp����

student::student(string �̸�, string ����, string ���, string ����) {//������ ����
	this->�̸� = �̸�;
	this->���� = ����;
	this->��� = ���;

	this->���� = ����;
}
string student::�̸���() {
	return �̸�;
}
void student::�̸��ٲ�(string �̸�) {
	this->�̸� = �̸�;
}
string student::�����() {
	if (���� == "������")
		return ���;
	else
		return "��!������ ���ܴ�!";
}
void student::����ٲ�(string ���) {
	if (���� == "������")
		this->��� = ���;
	else
		cout << "��!������ ���ܴ�!" << endl;
}
