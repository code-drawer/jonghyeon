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
		int pw;
		vector<string> 대출목록;
		User(string userName, int pw) {
			this->userName = userName;
			this->pw = pw;
		}

		/*string get_userName() {
			return userName;
		}*/
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

	vector<User> get_users() {
		return users;
	}
};
