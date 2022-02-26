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
		v.push_back(temp.substr(current + 1, temp.size() - current - 2));
		v.push_back(temp.substr(temp.size() - 1, 1));
		베리타스.get_books().emplace_back(v[0], v[1], v[2][0] != '0' ? true : false);
		// 베리타스.get_books().emplace_back(v[0], v[1], [=] { if (v[2][0] != '0') return true; else return false; }() );
	}
	ifs.close();

	return 0;
}
