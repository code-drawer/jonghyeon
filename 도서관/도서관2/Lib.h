#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Lib {
	class Book { //클래스의 이름은 대문자로 시작한다.
	public:
		string bookName;
		string author;
		bool 대출여부;
		Book(string bookName, string author, bool 대출여부 = false) {
			this->bookName = bookName;
			this->author = author;
			this->대출여부 = 대출여부;
		}
	};

	class User {
	public:
		string userName;
		string pw;
		vector<vector<Book>::iterator> 대출목록; //벡터클래스의 이터레이터
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
