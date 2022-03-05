#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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
		string pw;
		vector<vector<Book>::iterator> ������; //����Ŭ������ ���ͷ�����
		User(string userName, string pw) {
			this->userName = userName;
			this->pw = pw;
		}
	};

	vector<Book> books;
	vector<User> users;

public:
	bool log_in(string name, string pw);
	void book_list();
	void add_book();
	void del_book();
	void user_list();
	void add_user();
	void del_user();
	void bollow_book(string name, string pw);
	void return_book(string name, string pw);

	vector<Book>& get_books() {
		return books;
	}

	vector<User>& get_users() {
		return users;
	}
};
