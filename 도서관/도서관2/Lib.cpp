#include "Lib.h"

void Lib::book_list() {
	for (auto& elem : books) {
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
	books.push_back(Book(name, author));  //books.emplace_back(name,author)
}

void Lib::del_book() {
	cout << "���� �� å�� �Է��Ͻÿ�" << endl;
	string name;
	cin >> name;
	books.erase(find_if(books.begin(), books.end(), [name](Book temp) {return temp.bookName == name; }));
	//erase�� ������ �ڷ����� ���ͷ������̴�.
}

void Lib::user_list() {
	for (auto& elem : users) {
		cout << elem.userName << " ";
	}
	cout << endl;
}

void Lib::add_user() {
	cout << "����� ������ �̸��� �Է��Ͻÿ�" << endl;
	string name;
	cin >> name;
	cout << "��й�ȣ�� ����ϼ���" << endl;
	string pw;
	cin >> pw;
	users.emplace_back(name, pw);
}

void Lib::del_user() {
	cout << "���� �� ȸ���� �Է��Ͻÿ�" << endl;
	string name;
	cin >> name;
	cout << "��й�ȣ�� �Է��Ͻÿ�" << endl;
	string pw;
	cin >> pw;
	auto iter = find_if(users.begin(), users.end(),
		[name, pw](User temp) {return temp.userName == name and temp.pw == pw; });
	if (iter == users.end()) { cout << "�̸� �Ǵ� ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl; }
	else users.erase(iter);
}
