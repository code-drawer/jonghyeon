#include <iostream>
#include <tuple>
#include <vector>
#include<algorithm>
using namespace std;

int main() {
	vector<int>v = {34,56753,25,146,76};
	cout << find(v.begin(), v.end(), 25) - v.begin() << endl;
	/*iterator�� �ᱹ �������̱⿡ �����Ϳ������� ��޵ȴ�.
	���� ������'-'�� �� ������ ����� ������� ����ϰ� �ȴ�.*/

	return 0;
}