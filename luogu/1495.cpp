#include<stdio.h>
#define MAXN 11
//冒泡升序排序 ，程序的输入为 int类型数组 和数组长度 
//请在此处编辑您的代码
/**********  Begin  **********/


void reverseOrder(int a[ ],int n){
	//请在此处编辑您的代码
	/**********  Begin  **********/
	int *p=a,*q=a+n-1;
    while(p<q){
        int t=*p; *p=*q; *q=t;
        p++; q--;
    }
	/**********  End  **********/
}
#define SIZE 100
int main()
{
	/**********  Begin  **********/
	int a[SIZE],i,k,n;
    scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	reverseOrder(a,n);
	for(k=0;k<n;k++){
		printf("%d ",a[k]);	
	}
    getchar();getchar();
	/**********   End   **********/
	return 0; 
}
