#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<tuple<string, bool>>�������;
	vector<tuple<string, vector<string>>> ȸ�����;

	auto å�߰� = [&]() {
		cout << "�߰� �� å�� �Է��Ͻÿ�" << endl;
		string temp;
		cin >> temp;
		�������.push_back({ temp, false });
	};         /*�̰��� �����Լ���� ���̴�.
			   �̶�, 'å�߰�'�� �Լ��̸��� �ƴ� �����̸��̹Ƿ�
			   ;�� �������� �ٿ��־�߸� �Ѵ�.*/

	auto ȸ���߰� = [&]() {
		cout << "�߰� �� ȸ���� �Է��Ͻÿ�" << endl;
		string temp;
		cin >> temp;
		ȸ�����.push_back({ temp, vector<string>{}
									//()�� ���� �ʴ°� ������ ǥ���� �ؼ�
			/*�̰��� ����ִ� �͸����̴�.*/
			});
	};

	auto å���� = [&]() {
		cout << "���° å�� �����Ͻðڽ��ϱ�" << endl;
		int temp;
		cin >> temp;
		�������.erase(�������.begin()+temp-1);
	};

	auto ȸ������ = [&]() {
		cout << "���° ȸ���� �����Ͻðڽ��ϱ�" << endl;
		int temp;
		cin >> temp;
		ȸ�����.erase(ȸ�����.begin() + temp - 1);
	};

	å�߰�();
	å�߰�();
	å����();

	auto ���������ȸ = [&]() {
		cout << "�������" << endl;
		for (auto& elem : �������) {
			cout << get<0>(elem) << endl;
		}
	};

	���������ȸ();






	ȸ���߰�();
	ȸ���߰�();
	ȸ������();

	auto ȸ�������ȸ = [&]() {
		cout << "ȸ�����" << endl;
		for (auto& elem : ȸ�����) {
			cout << get<0>(elem) << endl;
		}
	};

	ȸ�������ȸ();




	auto ���Ⱑ�ɸ����ȸ = [&]() {
		cout << "���� ���� ���" << endl;
		for (auto& elem : �������) {
			if (not get<1>(elem))
			cout << get<0>(elem) << endl;
		}
	};

	auto ���� = [&]() {
		ȸ�������ȸ();
		cout << "����� ���° ȸ���Դϱ�" << endl;
		int num;
		cin >> num;
		���Ⱑ�ɸ����ȸ();
		cout << "������ å�� �Է��Ͻÿ�" << endl;
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

	auto �ݳ� = [&]() {
		string id;
		string temp;
		cout << "ȸ���̸��� �Է��Ͻÿ�" << endl;
		cin >> id;
		cout << "�ݳ� �� å�� �Է��Ͻÿ�" << endl;
		cin >> temp;


		for (auto& elem : �������) {
			if (get<0>(elem) == temp and get<1>(elem) == true) {
				get<1>(elem) = false;
				break;
			}
		}

		for (auto& elem : ȸ�����) {
			if (get<0>(elem) == id) {
				auto& v = get<1>(elem);
				/*'&'�� �������ν� get<1>(elem)�� �ܼ� �����ϴ°� �ƴ϶�
				�� ��ü�� �����ϰ� �ȴ�.*/
				auto i = find(v.begin(), v.end(), temp) - v.begin();
				v.erase(v.begin() + i);
				break;
			}
		}
	};

	�ݳ�();

	return 0;
}

