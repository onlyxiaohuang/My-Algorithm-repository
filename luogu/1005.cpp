#include<bits/stdc++.h>
#define MAXN 100
using namespace std;

int f[MAXN][MAXN][MAXN];
int c[MAXN][MAXN];

int n,m;
int cal(int x){
    int ans=0;
    if(m==1)    return c[x][1];
    for(int i=1;i<=m;i++){
        for(int len=m-1;len;len--)
            for(int beg=1;beg<=m;beg++)
                
    }
}

int main(){

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&c[i][j]);
    
}