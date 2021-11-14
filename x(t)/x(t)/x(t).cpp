#include <iostream>
#include <corecrt_math_defines.h>
using std::cin;
using std::cout;
using std::endl;


double X(int N, double t) {
	double x = 0;  //x(t)�� �Ǽ�
	for (double n = 1; n <= N; n += 2) {  // 1/n�� double�̾�� �Ѵ�.
		x += (1 / n) * sin(n * M_PI * t); // M_PI�� ������, sin�� ȣ���� ����
	}
	x *= 4 / M_PI;

	return x;
}

int main() {
	cout << "N�� �Է�" << endl;
	int N;
	cin >> N;
	for (double t = 0; t <= 2; t += 0.005) {
		cout << X(N,t) << endl;
	}

	return 0;
}
