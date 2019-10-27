#include "dylib.h"
#include <stdio.h>
int main()
{
	int a[5]={12,66,87,4939,-99};
	show(a,5);
	printf("   max=%d\n",max(a,5));
	printf("   sum=%d\n",sum(a,5));
}
