#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class bread {
public:
	bread(string �а���, string ���, string ����) {
		this->�а��� = �а���;
		this->��� = ���;
		this->���� = ����;
	}

	void ���() {
		cout << �а��� << endl << ��� << endl << ���� << endl;
	}

	void set_�а���(string �а���) {
		this->�а��� = �а���;
	}

	string get_�а���() {
		return �а���;
	}

private:
	string �а���;
	string ���;
	string ����;
};

