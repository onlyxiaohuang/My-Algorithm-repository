#include<bits/stdc++.h>
using namespace std;

long long a[11],n,k,t;
long long ans=0;
long long now[11];

int main(){

    now[0]=1;
    for(int i=1;i<=10;i++)   now[i]=now[i-1]*10;

    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        memset(a,0,sizeof(a)); ans=0; k++;
        for(int i=1;i<=n;i++)         scanf("%lld",&a[i]);
        for(int i=1;i<=n;i++){
            //while(ans+now[a[i]]<now[a[i+1]]&&k)    ans+=now[a[i]],k--;
            long long cnt=(now[a[i+1]]-1-ans)/now[a[i]];
            k-=cnt; ans+=now[a[i]]*cnt;
            if(k<=0){
                ans+=now[a[i]]*k; k=0; break;
            }
        }
        if(k)   ans+=k*now[a[n]];
        printf("%lld\n",ans);
    }
    //system("pause");
    return 0;
}