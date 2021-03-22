#include <stdio.h>
int main()
{
	int x = 1;
	int y = 2;
	int& r = x;
	r = y;
	y = 3;
	printf("%d", r);
	return 0;
}