#include<bits/stdc++.h>
#define MAXN 200010
#define int long long
using namespace std;

int n;
int t[MAXN],f[MAXN];
vector <int> a[MAXN];
bool check[MAXN];

signed main(){
    int m,x;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&t[i]);
        scanf("%lld",&m);
        while(m--)
            scanf("%lld",&x),a[i].push_back(x);
        
        f[i]+=t[i];
    }
    cout<<f[n]<<endl;
    getchar();getchar();
    return 0;
}