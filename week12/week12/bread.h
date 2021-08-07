#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class bread {
public:
	bread(string 밀가루, string 계란, string 버터) {
		this->밀가루 = 밀가루;
		this->계란 = 계란;
		this->버터 = 버터;
	}

	void 재료() {
		cout << 밀가루 << endl << 계란 << endl << 버터 << endl;
	}

	void set_밀가루(string 밀가루) {
		this->밀가루 = 밀가루;
	}

	string get_밀가루() {
		return 밀가루;
	}

private:
	string 밀가루;
	string 계란;
	string 버터;
};

