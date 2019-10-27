#include "dylib.h"
#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
int main()
{
	int a[5]={12,66,87,4939,-99};
	void *hd;
	char *error;
	void (*f1)();
	int (*f2)(),(*f3)();
	hd=dlopen("../dynamiclib/libdylib.so",RTLD_LAZY);
	if(!hd){
			fprntf(stderr,"%s\n",dlerror());
			exit(1);
	}
	f1=dlsym(hd,"show");
	if((error=dlerror())!=NULL){
			fprntf(stderr,"%s\n",dlerror());
			exit(1);
	}
	f2=dlsym(hd,"max");
	if((error=dlerror())!=NULL){
			fprntf(stderr,"%s\n",dlerror());
			exit(1);
	}
	f3=dlsym(hd,"sum");
	if((error=dlerror())!=NULL{
			fprntf(stderr,"%s\n",dlerror());
			exit(1);
	}
	f1(a,5);
	printf("    max=%d\n",f2(a,5));
	printf("    sum=%d\n",f3(a,5));
	if(dlclose(hd<0)){
			fprntf(stderr,"%s\n",dlerror());
			exit(1);
	}
	return 0;
}
