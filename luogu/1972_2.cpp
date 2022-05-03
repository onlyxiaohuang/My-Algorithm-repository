#include<bits/stdc++.h>
#define MAXN 1000100

using namespace std;

struct Query{
    int l,r,pos;
}q[MAXN];

int a[MAXN]; 
int ans[MAXN];

int n,m;
int c[MAXN];
int lowbit(int x){
    return x&(-x);
}
int ask(int x){
    int cnt=0;
    while(x)        cnt+=c[x],x-=lowbit(x);
    return cnt;
}
void add(int x,int val){
    while(x<=n)        c[x]+=val,x+=lowbit(x);
}


int last[MAXN];
bool cmp(Query x,Query y){
    if(x.r==y.r)    return x.l<y.l;
    return x.r<y.r;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)   scanf("%d",&a[i]);
    cin>>m;
    for(int i=1;i<=m;i++)
        scanf("%d%d",&q[i].l,&q[i].r),q[i].pos=i;
    sort(q+1,q+1+m,cmp);
    int R=0;
    for(int i=1;i<=m;i++){
        while(R<q[i].r){
            R++;
            if(!last[a[R]]) add(R,1),last[a[R]]=R;
            else add(last[a[R]],-1),last[a[R]]=R,add(R,1);
        }
        ans[q[i].pos]=ask(R)-ask(q[i].l-1);
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    getchar();getchar();
    return 0;
}