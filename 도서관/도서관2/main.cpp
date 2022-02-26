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
		v.push_back(temp.substr(current + 1, temp.size() - current - 2));
		v.push_back(temp.substr(temp.size() - 1, 1));
		����Ÿ��.get_books().emplace_back(v[0], v[1], v[2][0] != '0' ? true : false);
		// ����Ÿ��.get_books().emplace_back(v[0], v[1], [=] { if (v[2][0] != '0') return true; else return false; }() );
	}
	ifs.close();

	return 0;
}
