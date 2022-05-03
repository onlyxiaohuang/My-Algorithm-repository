#include<bits/stdc++.h>
#define int long long
#define MAXN 1000100
using namespace std;

int n,fail[MAXN];
char s[MAXN];


signed main(){
    scanf("%lld",&n);
    scanf("%s",s+1);
    int j=0;
    for(int i=2;i<=n;i++){
        while(j&&s[j+1]!=s[i])  j=fail[j];
        if(s[j+1]==s[i])    j++;
        fail[i]=j;
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        j=i;
        while(fail[j])  j=fail[j];
        if(fail[i])    fail[i]=j;
        ans+=i-j;
    }
    cout<<ans<<endl;
    getchar();getchar();
    return 0;
}