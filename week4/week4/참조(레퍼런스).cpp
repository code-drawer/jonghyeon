#include <stdio.h>
void swap(int& r1, int& r2);   //�Լ����� (�̺��� �Լ�, ���ڴ� ����)
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
