#include<bits/stdc++.h>
#define int long long
using namespace std;

int b[10010][8];

signed main(){
    bool ans=0;
    int n,m,x,y;
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%lld",&b[i][j]);
    
    x=(b[1][1]-1)/7; y=(b[1][1]-1)%7+1;
    //cout<<x<<" "<<y<<endl;
    if(y+m>8){
        printf("No\n");
        return 0;
    }
    
    for(int i=x;i<x+n;i++)
        for(int j=y;j<y+m;j++)
            if(b[i+1-x][j+1-y]!=i*7+j){
                ans=1;
                break;
            }
    
    if(ans) printf("No\n");
    else printf("Yes\n");
    //getchar();getchar();
    return 0;
}