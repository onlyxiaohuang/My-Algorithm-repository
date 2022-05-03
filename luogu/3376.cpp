#include<bits/stdc++.h>
#define MAXN 10100
#define MAXM 100100
#define int long long
using namespace std;

int n,m,s,t;
int top=1;
int head[MAXN],cur[MAXN],nxt[MAXM<<1],to[MAXM<<1],v[MAXM<<1];
void add(int x,int y,int w){
    nxt[++top]=head[x]; to[top]=y; head[x]=top; v[top]=w;
    nxt[++top]=head[y]; to[top]=x; head[y]=top; v[top]=0;
}

int dep[MAXN];
bool bfs(){
    queue <int> q;
    q.push(s); 
    for(int i=1;i<=n;i++)   cur[i]=head[i],dep[i]=0;
    dep[s]=1;
    while(!q.empty()){
        int now=q.front();q.pop();
        for(int i=head[now];i;i=nxt[i]){
            if(dep[to[i]]==0&&v[i])
                dep[to[i]]=dep[now]+1,q.push(to[i]);
        }
    }
    if(dep[t]!=0)   return 1;
    return 0;
}
int dfs(int x,int f){
    int now=0,flow=0;
    if(x==t||f==0)    return f;
    
    for(int &i=cur[x];i;i=nxt[i]){
        //printf("%lld  %lld:%lld,%lld\n",x,to[i],dep[x],dep[to[i]]);
        if(dep[to[i]]==dep[x]+1&&(now=dfs(to[i],min(v[i],f)))>0){
            v[i]-=now; v[i&1]+=now;
            f-=now; flow+=now; 
            if(f==0)    break;
        }
    }
    return flow;
}
int dinic(){
    int f=0;
    while(bfs())        f+=dfs(s,2147483647);
    return f;
}


signed main(){
    int x,y,w;
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        scanf("%lld%lld%lld",&x,&y,&w);
        add(x,y,w);
    }
    printf("%lld\n",dinic());
    getchar();getchar();
    return 0;

}