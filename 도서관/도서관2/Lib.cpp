#include "Lib.h"

void Lib::book_list() {
	for (auto& elem:books) {
		cout << elem.bookName << " ";
	}
	cout << endl;
}

void Lib::add_book() {
	cout << "�߰� �� å�� �Է��Ͻÿ�" << endl;
	string name;
	cin >> name;
	cout << "���ڸ� �Է��Ͻÿ�" << endl;
	string author;
	cin >> author;
	books.push_back(Book(name,author));
}
