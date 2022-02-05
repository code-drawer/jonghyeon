#include <iostream>
#include <tuple>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int>v = {34,56753,25,146,76};
	cout << find(v.begin(), v.end(), 25) - v.begin() << endl;
	/*iterator도 결국 포인터이기에 포인터연산으로 취급된다.
	따라서 연산자'-'가 그 사이의 대상이 몇개인지를 계산하게 된다.*/

	return 0;
}