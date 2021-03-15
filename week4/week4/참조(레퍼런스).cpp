#include <stdio.h>
void swap(int& r1, int& r2);   //함수선언 (이변수 함수, 인자는 참조)
int main() {
	int i = 10;
	int j = 20;
	swap(i, j);
	printf("%d\n%d", i, j);
	return 0;
	}
void swap(int& r1, int& r2) {
	int t = r1;
	r1 = r2;
	r2 = t;
	}
