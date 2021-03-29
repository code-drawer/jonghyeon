#include <stdio.h>
int main()
{
	char s[] = "ABCD";
	char* p = "ABCD";
	s[3] ='5';
	printf("%s\n", s);
	printf("%p\n", s);
	printf("%d\n", sizeof(s));
	printf("%d\n", sizeof("ABCD"));
	printf("%d\n", sizeof(NULL));
	if (NULL ==0x0 && 0x0 == (void*)0)  //True
		printf("%s","same");
	return 0;
}