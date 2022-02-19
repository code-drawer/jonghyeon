#include "Lib.h"
#include <fstream>

int main() {
	locale::global(locale{ "Korean" });

	/*Lib 베리타스{};
	베리타스.add_user();
	ofstream of{ "./users.txt" };
	of << 베리타스.get_users()[0].userName << endl;*/

	ifstream ifs{ "./users.txt" };
	vector<string> v;
	string temp;
	while (getline(ifs, temp)) {
		cout << temp << endl;
		v.push_back(temp);
	} /*벡터를 쓰는 이유 : 하드에 일일이 접근하기보다는 
	한번에 RAM에 있는 벡터로 옮긴 뒤에 사용하는 것이 더 빠르다. (이것이 로딩이다.)*/
	return 0;
}
