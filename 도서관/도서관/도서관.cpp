//책 반납

#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
	vector<tuple<string, bool>>도서목록;
	vector<tuple<string, vector<string>>> 회원목록;

	auto 책추가 = [&]() {
		string temp;
		cin >> temp;
		도서목록.push_back({ temp, false });
	};         /*이것은 람다함수라는 것이다.
			   이때, '책추가'는 함수이름이 아닌 변수이름이므로
			   ;을 마지막에 붙여주어야만 한다.*/

	auto 회원추가 = [&]() {
		string temp;
		cin >> temp;
		회원목록.push_back({ temp, vector<string>{}
									//()를 쓰지 않는건 중의적 표현의 해소
			/*이것은 비어있는 익명벡터이다.*/
			});
	};

	auto 책삭제 = [&]() {
		int temp;
		cin >> temp;
		도서목록.erase(도서목록.begin()+temp-1);
	};

	auto 회원삭제 = [&]() {
		int temp;
		cin >> temp;
		회원목록.erase(회원목록.begin() + temp - 1);
	};

	책추가();
	책추가();
	책삭제();

	auto 도서목록조회 = [&]() {
		for (auto& elem : 도서목록) {
			cout << get<0>(elem) << endl;
		}
	};

	도서목록조회();






	회원추가();
	회원추가();
	회원삭제();

	auto 회원목록조회 = [&]() {
		for (auto& elem : 회원목록) {
			cout << get<0>(elem) << endl;
		}
	};

	회원목록조회();




	auto 대출가능목록조회 = [&]() {
		for (auto& elem : 도서목록) {
			if (not get<1>(elem))
			cout << get<0>(elem) << endl;
		}
	};

	auto 대출 = [&]() {
		회원목록조회();
		int num;
		cin >> num;
		대출가능목록조회();
		string temp;
		cin >> temp;
		for (auto& elem : 도서목록) {
			if (get<0>(elem) == temp and get<1>(elem) == false) {
				get<1>(elem) = true;
				get<1>(회원목록[num - 1]).push_back(temp);
				break;
			}
		}
	};

	대출();
	for (auto& elem : 회원목록) {
		cout << get<0>(elem) << endl;
		for (auto& e : get<1>(elem)) {
			cout << e << " ";
		}
		cout << endl;
	}

	return 0;
}
