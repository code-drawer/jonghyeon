//å �ݳ�

#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

int main() {
	vector<tuple<string, bool>>�������;
	vector<tuple<string, vector<string>>> ȸ�����;

	auto å�߰� = [&]() {
		string temp;
		cin >> temp;
		�������.push_back({ temp, false });
	};         /*�̰��� �����Լ���� ���̴�.
			   �̶�, 'å�߰�'�� �Լ��̸��� �ƴ� �����̸��̹Ƿ�
			   ;�� �������� �ٿ��־�߸� �Ѵ�.*/

	auto ȸ���߰� = [&]() {
		string temp;
		cin >> temp;
		ȸ�����.push_back({ temp, vector<string>{}
									//()�� ���� �ʴ°� ������ ǥ���� �ؼ�
			/*�̰��� ����ִ� �͸����̴�.*/
			});
	};

	auto å���� = [&]() {
		int temp;
		cin >> temp;
		�������.erase(�������.begin()+temp-1);
	};

	auto ȸ������ = [&]() {
		int temp;
		cin >> temp;
		ȸ�����.erase(ȸ�����.begin() + temp - 1);
	};

	å�߰�();
	å�߰�();
	å����();

	auto ���������ȸ = [&]() {
		for (auto& elem : �������) {
			cout << get<0>(elem) << endl;
		}
	};

	���������ȸ();






	ȸ���߰�();
	ȸ���߰�();
	ȸ������();

	auto ȸ�������ȸ = [&]() {
		for (auto& elem : ȸ�����) {
			cout << get<0>(elem) << endl;
		}
	};

	ȸ�������ȸ();




	auto ���Ⱑ�ɸ����ȸ = [&]() {
		for (auto& elem : �������) {
			if (not get<1>(elem))
			cout << get<0>(elem) << endl;
		}
	};

	auto ���� = [&]() {
		ȸ�������ȸ();
		int num;
		cin >> num;
		���Ⱑ�ɸ����ȸ();
		string temp;
		cin >> temp;
		for (auto& elem : �������) {
			if (get<0>(elem) == temp and get<1>(elem) == false) {
				get<1>(elem) = true;
				get<1>(ȸ�����[num - 1]).push_back(temp);
				break;
			}
		}
	};

	����();
	for (auto& elem : ȸ�����) {
		cout << get<0>(elem) << endl;
		for (auto& e : get<1>(elem)) {
			cout << e << " ";
		}
		cout << endl;
	}

	return 0;
}
