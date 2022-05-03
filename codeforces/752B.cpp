#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;

int a[MAXN];

int main(){
    int n,t;
    cin>>t;
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        if(n%2==0){
            printf("YES\n");
            continue;
        }
        bool ans=0;
        for(int i=1;i<=n;i++)
            if(a[i]<=a[i-1]){
                ans=1;  break;
            }
        if(ans)
            printf("YES\n");
        else printf("NO\n");
    }
    //getchar();  getchar();
    return 0;
}