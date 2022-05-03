#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;

int head[MAXN],nxt[MAXN<<1],to[MAXN<<1],top;
void add(int x,int y){
    nxt[++top]=head[x]; to[top]=y;  head[x]=top;
}

int n,m;
int a[MAXN],f[MAXN];
bool check[MAXN];

int fa(int x){
    if(!f[x])   return x;
    return f[x]=fa(f[x]);
}
void merge(int x,int y){
    int fx=fa(x),fy=fa(y);
    f[fx]=fy;   return ;
}

int main(){
    int x,y;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        scanf("%d%d",&x,&y),add(x,y),add(y,x);
    
    int now=0; 
//cout<<endl;
    for(int i=n;i;i--){
        check[i]=1; now++;
        for(int j=head[i];j;j=nxt[j])
            if(check[to[j]]&&fa(i)!=fa(to[j])){
                now--;  merge(i,to[j]);// cout<<i<<" "<<to[j]<<endl;
            }
        a[i]=now; 
    }
    for(int i=2;i<=n;i++)
        printf("%d\n",a[i]);
    cout<<0<<endl;
    getchar();getchar();
    return 0;
}