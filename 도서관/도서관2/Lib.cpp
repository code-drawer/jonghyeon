#include "Lib.h"

void Lib::book_list() {
	for (auto& elem : books) {
		cout << elem.bookName << " " << elem.author << endl;
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

bool Lib::log_in(string name, string pw) {
	auto iter = find_if(users.begin(), users.end(),
		[name, pw](User temp) {return temp.userName == name and temp.pw == pw; });
	if (iter == users.end()) return false;
	else return true;
}

void Lib::bollow_book(string name, string pw) {
	cout << "���� å�� �Է��Ͻÿ�" << endl;
	string bookName;
	cin >> bookName;
	cout << "���ڸ� �Է��Ͻÿ�" << endl;
	string author;
	cin >> author;

	auto bookIter = find_if(books.begin(), books.end(),
		[bookName, author](Book temp) { return temp.bookName == bookName and temp.author == author; });
	if (bookIter == books.end()) {
		cout << "�ش��ϴ� ������ �������� �ʽ��ϴ�." << endl;
		return;
	}

	else if (bookIter->���⿩�� == true) {
		cout<< "�ش� ������ ���� �������Դϴ�." << endl;
		return;
	}

	else bookIter->���⿩�� = true;

	auto userIter = find_if(users.begin(), users.end(),
		[name, pw](User temp) {return temp.userName == name and temp.pw == pw; });

	userIter->������.push_back(bookIter);

	/*fstream file{ "books.txt",ios::out | ios::app };
	file << true;
	file.close();*/
}

void Lib::return_book(string name, string pw) {
	auto userIter = find_if(users.begin(), users.end(),
		[name, pw](User temp) { return temp.userName == name and temp.pw == pw; });

	if (userIter->������.empty()) {
		cout<< "���� ���� å�� �����Ф�" << endl;
		return; }

	cout << "� å�� �ݳ��Ͻðڽ��ϱ�?" << endl;
	for (const auto& elem : userIter->������)
		cout << elem->bookName << " " << elem->author << endl;

	string bookName;
	string author;
	cout << "������ : ";
	cin >> bookName;
	cout << "���� : ";
	cin >> author;

	auto bookIter = find_if(userIter->������.begin(), userIter->������.end(),
		[bookName, author](vector<Book>::iterator temp) {
			return temp->bookName == bookName and temp->author == author;
		});

	if (bookIter == userIter->������.end()) {
		cout<< "�߸� �Է��ϼ̽��ϴ�." << endl;
		return;
	}

	else {
		(userIter->������[bookIter - (userIter->������.begin())])->���⿩�� = false;
		//(*bookIter)->���⿩�� = false; �� ���� ���� �� ȿ�����̴�.
		//������ bookIter�� ����Ű�� Book��ü(books�� ����)�� '���⿩��'�� false�� �ٲپ�� �Ѵ�.

		userIter->������.erase(bookIter);
	}
}
// *(v.begin()) == v[0]�� �����Ѵ�.
