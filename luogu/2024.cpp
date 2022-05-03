#include<bits/stdc++.h>
#define MAXN 50010
using namespace std;

int f[MAXN],opt[MAXN];
int fi(int x){
    if(x!=f[x]){
        int t=f[x]; f[x]=fi(f[x]); (opt[x]+=opt[t])%=3;
    }
    return f[x];
}

int merge(int x,int y,int val){
    int fx=fi(x),fy=fi(y);
    if(fx==fy){
        if(x==fx&&y==fy){
            if(val==0)  return 0;
            else return 1;
        }   
        if(x==fx){
            if((3-opt[y])%3==val) return 0;
            return 1;
        }
        if(y==fy){
            if(opt[x]==val) return 0;
            return 1;
        }
        if((3+opt[x]-opt[y])%3==val)    return 0;
        return 1;
    }
    f[fx]=f[fy];    opt[fx]=(3-opt[x]+opt[y]+val)%3;
    return 0;
}

int main(){
    int n,m,c,x,y,tmp,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)   f[i]=i;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&c,&x,&y);
        if(x>n||y>n){
            ans++; continue;
        }
        if(x==y&&c==2){
            ans++;  continue;
        }
        ans+=merge(x,y,c-1);
        //cout<<ans<<endl;
        //for(int i=1;i<=n;i++)
        //    cout<<f[i]<<" "<<opt[i]<<endl;
    }
    cout<<ans<<endl;
    
    getchar();getchar();
    return 0;
}
/*
5 5
2 1 5
2 5 2
1 3 4
2 2 4
1 1 4

*/