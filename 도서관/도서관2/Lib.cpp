#include "Lib.h"

void Lib::book_list() {
	for (auto& elem:books) {
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
	books.push_back(Book(name,author));
}
