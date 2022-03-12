#include "Lib.h"

void Lib::book_list() {
	for (auto& elem : books) {
		cout << elem.bookName << " " << elem.author << endl;
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

bool Lib::log_in(string name, string pw) {
	auto iter = find_if(users.begin(), users.end(),
		[name, pw](User temp) {return temp.userName == name and temp.pw == pw; });
	if (iter == users.end()) return false;
	else return true;
}

void Lib::bollow_book(string name, string pw) {
	cout << "빌릴 책을 입력하시오" << endl;
	string bookName;
	cin >> bookName;
	cout << "저자를 입력하시오" << endl;
	string author;
	cin >> author;

	auto bookIter = find_if(books.begin(), books.end(),
		[bookName, author](Book temp) { return temp.bookName == bookName and temp.author == author; });
	if (bookIter == books.end()) {
		cout << "해당하는 도서가 존재하지 않습니다." << endl;
		return;
	}

	else if (bookIter->대출여부 == true) {
		cout<< "해당 도서는 현재 대출중입니다." << endl;
		return;
	}

	else bookIter->대출여부 = true;

	auto userIter = find_if(users.begin(), users.end(),
		[name, pw](User temp) {return temp.userName == name and temp.pw == pw; });

	userIter->대출목록.push_back(bookIter);

	/*fstream file{ "books.txt",ios::out | ios::app };
	file << true;
	file.close();*/
}

void Lib::return_book(string name, string pw) {
	auto userIter = find_if(users.begin(), users.end(),
		[name, pw](User temp) { return temp.userName == name and temp.pw == pw; });

	if (userIter->대출목록.empty()) {
		cout<< "아직 빌린 책이 없어요ㅠㅠ" << endl;
		return; }

	cout << "어떤 책을 반납하시겠습니까?" << endl;
	for (const auto& elem : userIter->대출목록)
		cout << elem->bookName << " " << elem->author << endl;

	string bookName;
	string author;
	cout << "도서명 : ";
	cin >> bookName;
	cout << "저자 : ";
	cin >> author;

	auto bookIter = find_if(userIter->대출목록.begin(), userIter->대출목록.end(),
		[bookName, author](vector<Book>::iterator temp) {
			return temp->bookName == bookName and temp->author == author;
		});

	if (bookIter == userIter->대출목록.end()) {
		cout<< "잘못 입력하셨습니다." << endl;
		return;
	}

	else {
		(userIter->대출목록[bookIter - (userIter->대출목록.begin())])->대출여부 = false;
		//(*bookIter)->대출여부 = false; 로 쓰는 것이 더 효율적이다.
		//삭제한 bookIter가 가리키는 Book객체(books의 원소)의 '대출여부'를 false로 바꾸어야 한다.

		userIter->대출목록.erase(bookIter);
	}
}
// *(v.begin()) == v[0]가 성립한다.
