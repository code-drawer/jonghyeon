#include "Lib.h"
#include <fstream>

int main() {
	locale::global(locale{ "Korean" });

	/*Lib ����Ÿ��{};
	����Ÿ��.add_user();
	ofstream of{ "./users.txt" };
	of << ����Ÿ��.get_users()[0].userName << endl;*/

	ifstream ifs{ "./users.txt" };
	vector<string> v;
	string temp;
	while (getline(ifs, temp)) {
		cout << temp << endl;
		v.push_back(temp);
	} /*���͸� ���� ���� : �ϵ忡 ������ �����ϱ⺸�ٴ� 
	�ѹ��� RAM�� �ִ� ���ͷ� �ű� �ڿ� ����ϴ� ���� �� ������. (�̰��� �ε��̴�.)*/
	return 0;
}
