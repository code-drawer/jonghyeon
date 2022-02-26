#include "Lib.h"

void Lib::book_list() {
	for (auto& elem : books) {
		cout << elem.bookName << " ";
	}
	cout << endl;
}

void Lib::add_book() {
	cout << "추가 할 책을 입력하시오" << endl;
	string name;
	cin >> name;
	cout << "저자를 입력하시오" << endl;
	string author;
	cin >> author;
	books.push_back(Book(name, author));  //books.emplace_back(name,author)
}

void Lib::del_book() {
	cout << "삭제 할 책을 입력하시오" << endl;
	string name;
	cin >> name;
	books.erase(find_if(books.begin(), books.end(), [name](Book temp) {return temp.bookName == name; }));
	//erase의 인자의 자료형은 이터레이터이다.
}

void Lib::user_list() {
	for (auto& elem : users) {
		cout << elem.userName << " ";
	}
	cout << endl;
}

void Lib::add_user() {
	cout << "등록할 유저의 이름을 입력하시오" << endl;
	string name;
	cin >> name;
	cout << "비밀번호를 등록하세요" << endl;
	string pw;
	cin >> pw;
	users.emplace_back(name, pw);
}

void Lib::del_user() {
	cout << "삭제 할 회원을 입력하시오" << endl;
	string name;
	cin >> name;
	cout << "비밀번호를 입력하시오" << endl;
	string pw;
	cin >> pw;
	auto iter = find_if(users.begin(), users.end(),
		[name, pw](User temp) {return temp.userName == name and temp.pw == pw; });
	if (iter == users.end()) { cout << "이름 또는 비밀번호가 일치하지 않습니다." << endl; }
	else users.erase(iter);
}
