#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;

int a[MAXN];

int main(){
    int n,x,y;
    cin>>n;
    for(int i=1;i<n;i++)
        scanf("%d%d",&x,&y),a[x]++,a[y]++;
    for(int i=1;i<=n;i++)
        if(a[i]==n-1){
            printf("Yes\n");
            return 0;
        }
    printf("No\n");
    return 0;
}