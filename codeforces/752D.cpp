#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    int t,x,y;
    cin>>t;
    while(t--){
        int ans=0,i=0;
        scanf("%lld%lld",&x,&y);
        if(x>y) printf("%lld\n",x+y);
        else{
            int k=y/x;
            printf("%lld\n",(y+k*x)/2);
        }
    }
    //getchar(); getchar();
    return 0;
}