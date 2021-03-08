#include <stdio.h>
int main() {
	/* int ==정수 (의 자료형)
	int* == 정수의 주소 (의 자료형) */
	int i = 10;
	printf("%p", &i);  //자료형이 d(정수형)이 아닌 p(포인터)
	return 0;
	}
