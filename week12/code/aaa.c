#include <stdio.h>
int main()
{
	int a=1;
	char b[1];
	printf("%d",a);
	char b=(char)a;
	printf("%s,%d",b,a);
	return 0;
}
