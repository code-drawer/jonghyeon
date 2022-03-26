#include "Lib.h"
#include <fstream>

int main() {
	locale::global(locale{ "Korean" });

	Lib ����Ÿ��{};
	/*����Ÿ��.add_user();
	ofstream of{ "./users.txt" };
	of << ����Ÿ��.get_users()[0].userName << endl;*/

	ifstream ifs{ "./books.txt" };

	string temp;
	while (getline(ifs, temp)) {  // ifs���� ���پ� temp�� �������� ���� �ݺ�(�����ڴ� ����)
		vector<string> v;
		size_t current = temp.find(',');
		v.push_back(temp.substr(0, current)); //temp�� 0��°���� current���� �߶� v�� �߰�
		v.push_back(temp.substr(current + 1, temp.size() - current - 3));
		v.push_back(temp.substr(temp.size() - 1, 1));
		����Ÿ��.get_books().emplace_back(v[0], v[1], v[2][0] != '0' ? true : false); //���׿�����
		//���׿����ڸ� ��������μ� if���� ª�� ��ü�� �� �ְ� �Ǿ���.
		//����Ÿ��.get_books().emplace_back(v[0], v[1], [=] { if (v[2][0] != '0') return true; else return false; }() );
	}
	ifs.close();

	ifs.open("./users.txt");
	while (getline(ifs, temp)) {  // ifs���� ���پ� temp�� �������� ���� �ݺ�(�����ڴ� ����)
		vector<string> v;
		size_t current = temp.find(',');
		size_t previous{};
		while (current != string::npos) {
			v.push_back(temp.substr(previous,current-previous));
			previous = current + 1;
			current = temp.find(',', previous);
		}
		v.push_back(temp.substr(previous, current - previous));
		����Ÿ��.get_users().emplace_back(v[0], v[1], [&����Ÿ��, &v]() {
			// å�� 1�� ���� ��: v[2], v[3] => 2�� �ݺ�
			// å�� 2�� ���� ��: v[2], v[3], v[4], v[5] => 4�� �ݺ�
			// ���� å�� ���� * 2 ��ŭ �ݺ��ؾ� �Ѵ�.
			vector<vector<Lib::Book>::iterator> ������_å_���;
			for (auto iter = v.begin() + 2; iter != v.end(); iter += 2) {
				auto ������_å = find_if(����Ÿ��.get_books().begin(), ����Ÿ��.get_books().end(),
					[&iter](Lib::Book temp) { return temp.bookName == *iter and temp.author == *(iter + 1); });
				������_å->���⿩�� = true;

				������_å_���.push_back(������_å);
			}
			return ������_å_���;
			}());
	}
	/*���͸� ���� ���� : �ϵ忡 ������ �����ϱ⺸�ٴ�
	�ѹ��� RAM�� �ִ� ���ͷ� �ű� �ڿ� ����ϴ� ���� �� ������. (�̰��� �ε��̴�.)*/
	ifs.close();

	string name;
	fstream token{ "token.txt",ios::in };  //�α�����ū���� �о��
	token >> name;
	token.close();

	bool flag = false;
	if (!name.empty()) flag = true;
	string pw;
	while (true) {
		system("cls"); //ȭ�� Ŭ����(���̽㿡���� clear)

		if (!flag) {
			cout << "�̸��� �Է��Ͻÿ�" << endl;
			cin >> name;
			cout << "��й�ȣ�� �Է��Ͻÿ�" << endl;
			cin >> pw;
			if (!����Ÿ��.log_in(name, pw)) {
				cout << "�̸� �Ǵ� ��й�ȣ�� ��ġ���� �ʽ��ϴ�." << endl;
				break; 
			}
			else {
				flag = true;

				token.open("token.txt",ios::out);
				token << name; //�α��� ��ū�� ���
				token.close();
			}
		}

		system("cls");
		cout << name << "�� �������" << endl;
		cout << "� ������ ���͵帱���?" << endl;
		cout << "1 : ȸ����ȸ" << endl;
		cout << "2 : ȸ�����" << endl;
		cout << "3 : ȸ������" << endl;
		cout << "4 : ������ȸ" << endl;
		cout << "5 : �������" << endl;
		cout << "6 : ��������" << endl;
		cout << "7 : ����" << endl;
		cout << "8 : �ݳ�" << endl;
		cout << "9 : �α׾ƿ�" << endl;
		cout << "0 : ����" << endl;
		int num;
		cin >> num;

		switch (num) {
		case 1: ����Ÿ��.user_list(); break;
		case 2: ����Ÿ��.add_user(); break;
		case 3: ����Ÿ��.del_user(); break;
		case 4: ����Ÿ��.book_list(); break;
		case 5: ����Ÿ��.add_book(); break;
		case 6: ����Ÿ��.del_book(); break;
		case 7: 
			if (pw.empty()) {
				����Ÿ��.bollow_book(name);
				break;
			}
			����Ÿ��.bollow_book(name, pw);
			break;
		case 8:
			if (pw.empty()) {
				����Ÿ��.return_book(name);
				break;
			}
			����Ÿ��.return_book(name, pw);
			break;
		case 9:
			token.open("token.txt", ios::out);
			token << "";
			cout << "�α׾ƿ� �Ǽ̽��ϴ�." << endl;
			token.close();
			flag = false;
			break;
		case 0: return 0;
		default: cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		}
		system("pause"); //���� ������ �Ѿ�� ���� �Ͻ����� �����ش�.
	}

	return 0;
}
