#include<bits/stdc++.h>
using namespace std;

unsigned long long now=0,ans=0,k,n,t;

int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(k>n) k=n;
        now=1; ans=0;
        if(k==1){
            cout<<n-1<<endl;
            continue;
        }
        while(now<k)    now*=2,ans++;
        if(n>now) ans+=(n-now-1)/k+1;
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}