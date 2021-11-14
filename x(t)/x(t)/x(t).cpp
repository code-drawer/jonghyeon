#include <iostream>
#include <corecrt_math_defines.h>
using std::cin;
using std::cout;
using std::endl;


double X(int N, double t) {
	double x = 0;  //x(t)는 실수
	for (double n = 1; n <= N; n += 2) {  // 1/n이 double이어야 한다.
		x += (1 / n) * sin(n * M_PI * t); // M_PI는 원주율, sin은 호도각 기준
	}
	x *= 4 / M_PI;

	return x;
}

int main() {
	cout << "N값 입력" << endl;
	int N;
	cin >> N;
	for (double t = 0; t <= 2; t += 0.005) {
		cout << X(N,t) << endl;
	}

	return 0;
}
