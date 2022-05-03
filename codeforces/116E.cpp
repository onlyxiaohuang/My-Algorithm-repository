#include<bits/stdc++.h>
#define MOD 998244353
#define MAXN 550
#define int long long
using namespace std;

int C[MAXN][MAXN];
int f[MAXN][MAXN];



int ksm(int n,int k){
    int ans=1;
    while(k){
        if(k&1) (ans*=n)%=MOD;
        (n*=n)%=MOD;  k>>=1;
//        cout<<k<<endl;
    }
    return ans;
}

int dfs(int n,int k){
    if(f[n][k]) return f[n][k];
//    if(n==1)    return 0;
    if(k<=0)    return 0;
//    cout<<n<<k<<endl;
    int ans=0;
    ans+=ksm(min(k,n-1),n);
    for(int i=2;i<=n;i++)
        (ans+=((C[n][i]*ksm(n-1,n-i))%MOD*dfs(i,k-n+1))%MOD)%=MOD;
    return f[n][k]=ans;
}

signed main(){
    int n,x;
    cin>>n>>x;
    C[0][0]=1;
    for(int i=1;i<=n;i++){
        C[i][0]=1;
        for(int j=1;j<=i;j++)      C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
    }
    cout<<dfs(n,x)<<endl;
   // getchar();getchar();
    return 0;
}