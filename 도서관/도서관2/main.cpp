#include "Lib.h"
#include <fstream>

int main() {
	locale::global(locale{ "Korean" });

	Lib 베리타스{};
	/*베리타스.add_user();
	ofstream of{ "./users.txt" };
	of << 베리타스.get_users()[0].userName << endl;*/

	ifstream ifs{ "./users.txt" };
	string temp;
	while (getline(ifs, temp)) {  // ifs에서 한줄씩 temp에 가져오는 것을 반복(구분자는 공백)
		vector<string> v;
		size_t current = temp.find(' ');
		v.push_back(temp.substr(0, current)); //temp의 0번째부터 current개를 잘라서 v에 추가
		v.push_back(temp.substr(current + 1, temp.size() - current));
		베리타스.get_users().emplace_back(v[0], v[1]);
	}
	/*벡터를 쓰는 이유 : 하드에 일일이 접근하기보다는
	한번에 RAM에 있는 벡터로 옮긴 뒤에 사용하는 것이 더 빠르다. (이것이 로딩이다.)*/
	ifs.close();

	ifs.open("./books.txt");
	while (getline(ifs, temp)) {  // ifs에서 한줄씩 temp에 가져오는 것을 반복(구분자는 공백)
		vector<string> v;
		size_t current = temp.find(' ');
		v.push_back(temp.substr(0, current)); //temp의 0번째부터 current개를 잘라서 v에 추가
		v.push_back(temp.substr(current + 1, temp.size() - current - 3));
		v.push_back(temp.substr(temp.size() - 1, 1));
		베리타스.get_books().emplace_back(v[0], v[1], v[2][0] != '0' ? true : false); //삼항연산자
		//삼항연산자를 사용함으로서 if문을 짧게 대체할 수 있게 되었다.
		//베리타스.get_books().emplace_back(v[0], v[1], [=] { if (v[2][0] != '0') return true; else return false; }() );
	}
	ifs.close();

	string tokenName;
	fstream token{ "token.txt",ios::in };  //로그인토큰파일 읽어옴
	token >> tokenName;
	token.close();

	bool flag = false;
	if (!tokenName.empty()) flag = true;
	string name;
	string pw;
	while (true) {
		system("cls"); //화면 클리너(파이썬에서의 clear)

		if (!flag) {
			cout << "이름을 입력하시오" << endl;
			cin >> name;
			cout << "비밀번호를 입력하시오" << endl;
			cin >> pw;
			if (!베리타스.log_in(name, pw)) {
				cout << "이름 또는 비밀번호가 일치하지 않습니다." << endl;
				break; 
			}
			else {
				flag = true;

				token.open("token.txt",ios::out);
				token << name; //로그인 토큰에 등록
				token.close();

				cout << name << "님 어서오세요" << endl;
			}
		}

		cout << "어떤 업무를 도와드릴까요?" << endl;
		cout << "1 : 회원조회" << endl;
		cout << "2 : 회원등록" << endl;
		cout << "3 : 회원삭제" << endl;
		cout << "4 : 도서조회" << endl;
		cout << "5 : 도서등록" << endl;
		cout << "6 : 도서삭제" << endl;
		cout << "7 : 대출" << endl;
		cout << "8 : 반납" << endl;
		cout << "9 : 종료" << endl;
		int num;
		cin >> num;

		switch (num) {
		case 1: 베리타스.user_list(); break;
		case 2: 베리타스.add_user(); break;
		case 3: 베리타스.del_user(); break;
		case 4: 베리타스.book_list(); break;
		case 5: 베리타스.add_book(); break;
		case 6: 베리타스.del_book(); break;
		case 7: 베리타스.bollow_book(name, pw); break;
		case 8: 베리타스.return_book(name, pw); break;
		case 9: return 0;
		default: cout << "잘못 입력하셨습니다." << endl;
		}
		system("pause"); //다음 루프로 넘어가기 전에 일시정지 시켜준다.
	}

	return 0;
}
