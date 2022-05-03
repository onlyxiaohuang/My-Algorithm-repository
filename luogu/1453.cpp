#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;

int fa[MAXN];
int ask(int x){
    if(fa[x]==x) return x;
    return fa[x]=ask(fa[x]);
}
void merge(int x,int y){
    int fx=ask(x),fy=ask(y);
    if(fx==fy)  return ;
    fa[fx]=fy;   return ;
}

int head[MAXN],nxt[MAXN<<1],to[MAXN<<1],top;
void add(int x,int y){
    nxt[++top]=head[x];head[x]=top;to[top]=y;
}


int n,X,Y;
int p[MAXN],f[MAXN][2];
bool check[MAXN];
void dfs(int x){
    //if(check[x])    return ;
    check[x]=1; f[x][1]=p[x]; f[x][0]=0;
    for(int i=head[x];i;i=nxt[i]){
        if(!check[to[i]]){
            dfs(to[i]); 
            f[x][1]+=f[to[i]][0];
            f[x][0]+=max(f[to[i]][0],f[to[i]][1]);
        }        
    }
}

int main(){
    int x,y;

    cin>>n;
    for(int i=1;i<=n;i++)        scanf("%d",&p[i]),fa[i]=i;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x,&y); x++,y++;
        if(ask(x)==ask(y))  X=x,Y=y;
        else merge(x,y),add(x,y),add(y,x);
    }
    
    dfs(X);
    double ans=f[X][0],k;
    memset(check,0,sizeof(check));
    dfs(Y);
    ans=max(ans,(double)f[Y][0]);
    scanf("%lf",&k);
    printf("%.1lf\n",ans*k);


    getchar();getchar();
    return 0;
}