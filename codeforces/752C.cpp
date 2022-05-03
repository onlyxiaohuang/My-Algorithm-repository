#include<bits/stdc++.h>
#define MAXN 100010
#define M 1000000000
#define int long long
using namespace std;

int a[MAXN];

int gcd(int x,int y){
    if(!y)  return x;
    return gcd(y,x%y);
}

int lcm(int x,int y){
    return x/gcd(x,y)*y;
}

signed main(){
    int t,n;
    cin>>t;
    while(t--){
        bool ans=0;
        int now=1;
        scanf("%lld",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++){
            now=lcm(now,i+1);
            if(a[i]%now==0){
                ans=1;
                break;
            }
            if(now>M)   break;
        }
        if(!ans) printf("YES\n");
        else printf("NO\n");
    }
    //getchar();getchar();
    return 0;
}