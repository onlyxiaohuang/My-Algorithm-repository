#include<bits/stdc++.h>
#define MAXN 50010
using namespace std;

int a[MAXN];
bool b[MAXN];
int main(){
    bool flag=0;
    int t,n;
    cin>>t;
    while(t--){
        flag=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),b[a[i]]=1;
        for(int i=1;i<=n;i++){
            b[a[i]]=0;
            for(int j=1;j<i;j++)
                if(a[i]*2-a[j]>0&&a[i]*2-a[j]<n&&b[a[i]*2-a[j]]){
                    flag=1;
                    break;
                }
            if(flag)    break;
        }
        if(flag)    printf("Y\n");
        else printf("N\n");
    }
    getchar();  getchar();
    return 0;
}