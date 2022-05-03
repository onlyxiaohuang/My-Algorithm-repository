#include <stdio.h>

int main(){
	/**********Begin**********/
	unsigned short k,a,b;
	scanf("%hu",&k);
	a=k&0xf000,b=k&0x000f;
	a=(a>>12),b=(b<<12); k=k&0x0ff0;
	printf("%hu\n",a|b|k);
    getchar();getchar();
	/**********End**********/
	return 0;
}