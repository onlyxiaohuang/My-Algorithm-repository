#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;

pair<int,int> a[MAXN];

void solve(int l,int r){
    
}

int main(){
    int n,m,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].first);
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        a[x].second=i;
    }

    getchar();getchar();
    return 0;
}