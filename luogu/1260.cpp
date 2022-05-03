#include<bits/stdc++.h>
#define MAXN 1010
#define MAXM 5010
#define MAX 1000000000
using namespace std;

int n,m;
int head[MAXN],nxt[MAXM<<1],to[MAXM<<1],val[MAXM<<1],top;
void add(int x,int y,int v){
    nxt[++top]=head[x],to[top]=y,val[top]=v,head[x]=top;
}

int now[MAXN],check[MAXN];
queue <int> q;
bool Spfa(){
    for(int i=1;i<=n;i++)        now[i]=MAX;
    memset(check,0,sizeof(check));
    q.push(n+1); now[n+1]=0;
    while(!q.empty()){
        int x=q.front();  q.pop();
        check[x]++;
        if(check[x]==n)   return 0;
        for(int j=head[x];j;j=nxt[j]){
            if(now[x]+val[j]<now[to[j]])
                now[to[j]]=now[x]+val[j],q.push(to[j]);
        }
    }
    return 1;
}

int main(){
    int x,y,v;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&v);        add(y,x,v);
    }
    for(int i=1;i<=n;i++)        add(n+1,i,0);
    if(!Spfa()){
        printf("NO SOLUTION\n");
        return 0;
    }
 //   for(int i=1;i<=n;i++)
 //       if(now[i]==MAX) now[i]=0;

    int mi=MAX;
    for(int i=1;i<=n;i++)   mi=min(mi,now[i]);
    for(int i=1;i<=n;i++)   printf("%d\n",now[i]-mi);
    

    //getchar();getchar();
    return 0;

}