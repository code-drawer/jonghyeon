#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
	string s;
	cin >> s;
	int R;
	cin >> R;
	string p = "";
	for (auto& elem : s) {
		string Re = "";
		for (int i = 0; i < R; i++) {
			Re += elem;
		}
		p += Re;
	}
	cout << p<<endl;

	return 0;
}
