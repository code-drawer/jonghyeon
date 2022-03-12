#include "Lib.h"
#include <fstream>

int main() {
	locale::global(locale{ "Korean" });

	Lib ����Ÿ��{};
	/*����Ÿ��.add_user();
	ofstream of{ "./users.txt" };
	of << ����Ÿ��.get_users()[0].userName << endl;*/

	ifstream ifs{ "./users.txt" };
	string temp;
	while (getline(ifs, temp)) {  // ifs���� ���پ� temp�� �������� ���� �ݺ�(�����ڴ� ����)
		vector<string> v;
		size_t current = temp.find(' ');
		v.push_back(temp.substr(0, current)); //temp�� 0��°���� current���� �߶� v�� �߰�
		v.push_back(temp.substr(current + 1, temp.size() - current));
		����Ÿ��.get_users().emplace_back(v[0], v[1]);
	}
	/*���͸� ���� ���� : �ϵ忡 ������ �����ϱ⺸�ٴ�
	�ѹ��� RAM�� �ִ� ���ͷ� �ű� �ڿ� ����ϴ� ���� �� ������. (�̰��� �ε��̴�.)*/
	ifs.close();

	ifs.open("./books.txt");
	while (getline(ifs, temp)) {  // ifs���� ���پ� temp�� �������� ���� �ݺ�(�����ڴ� ����)
		vector<string> v;
		size_t current = temp.find(' ');
		v.push_back(temp.substr(0, current)); //temp�� 0��°���� current���� �߶� v�� �߰�
		v.push_back(temp.substr(current + 1, temp.size() - current - 3));
		v.push_back(temp.substr(temp.size() - 1, 1));
		����Ÿ��.get_books().emplace_back(v[0], v[1], v[2][0] != '0' ? true : false); //���׿�����
		//���׿����ڸ� ��������μ� if���� ª�� ��ü�� �� �ְ� �Ǿ���.
		//����Ÿ��.get_books().emplace_back(v[0], v[1], [=] { if (v[2][0] != '0') return true; else return false; }() );
	}
	ifs.close();

	string tokenName;
	fstream token{ "token.txt",ios::in };  //�α�����ū���� �о��
	token >> tokenName;
	token.close();

	bool flag = false;
	if (!tokenName.empty()) flag = true;
	string name;
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

				cout << name << "�� �������" << endl;
			}
		}

		cout << "� ������ ���͵帱���?" << endl;
		cout << "1 : ȸ����ȸ" << endl;
		cout << "2 : ȸ�����" << endl;
		cout << "3 : ȸ������" << endl;
		cout << "4 : ������ȸ" << endl;
		cout << "5 : �������" << endl;
		cout << "6 : ��������" << endl;
		cout << "7 : ����" << endl;
		cout << "8 : �ݳ�" << endl;
		cout << "9 : ����" << endl;
		int num;
		cin >> num;

		switch (num) {
		case 1: ����Ÿ��.user_list(); break;
		case 2: ����Ÿ��.add_user(); break;
		case 3: ����Ÿ��.del_user(); break;
		case 4: ����Ÿ��.book_list(); break;
		case 5: ����Ÿ��.add_book(); break;
		case 6: ����Ÿ��.del_book(); break;
		case 7: ����Ÿ��.bollow_book(name, pw); break;
		case 8: ����Ÿ��.return_book(name, pw); break;
		case 9: return 0;
		default: cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
		}
		system("pause"); //���� ������ �Ѿ�� ���� �Ͻ����� �����ش�.
	}

	return 0;
}
