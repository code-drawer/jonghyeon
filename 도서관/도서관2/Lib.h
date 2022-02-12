#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Lib {
	class Book { //Ŭ������ �̸��� �빮�ڷ� �����Ѵ�.
	public:
		string bookName;
		string author;
		bool ���⿩��;
		Book(string bookName, string author, bool ���⿩�� = false) {
			this->bookName = bookName;
			this->author = author;
			this->���⿩�� = ���⿩��;
		}
	};

	class User {
	public:
		string userName;
		vector<string> ������;
		User(string userName) {
			this->userName = userName;
		}
	};

	vector<Book> books;
	vector<User> users;

public:
	void book_list();
	void add_book();
	void del_book();
	void user_list();
	void add_user();
	void del_user();
};
