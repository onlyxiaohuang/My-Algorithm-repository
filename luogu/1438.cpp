#include<bits/stdc++.h>
#define MAXN 200010
#define int long long
using namespace std;


int n,m;
int a[MAXN],b[MAXN],t[MAXN<<2],tag[MAXN<<2];
int build(int now,int l,int r){
    if(l>r) return 0;
    if(l==r)    return t[now]=b[l];
    int mid=(l+r)>>1;
    return t[now]=build(now<<1,l,mid)+build(now<<1|1,mid+1,r);
}
void pushdown(int now,int x){
    t[now]+=tag[now]*x;
    tag[now<<1]+=tag[now]; tag[now<<1|1]+=tag[now];
    tag[now]=0;
}
void add(int now,int l,int r,int L,int R,int x){
    pushdown(now,r-l+1);
    if(l>=L&&r<=R){
        tag[now]+=x;    pushdown(now,r-l+1); return ;
    }
    if(r<L||l>R)    return ;
    int mid=(l+r)>>1;
    add(now<<1,l,mid,L,R,x);    add(now<<1|1,mid+1,r,L,R,x);
    t[now]=t[now<<1]+t[now<<1|1];
    //cout<<l<<"-"<<r<<":"<<t[now]<<endl;
}
int ask(int now,int l,int r,int L,int R){
    pushdown(now,r-l+1);
    if(l>=L&&r<=R)  return t[now];
    if(r<L||l>R)    return 0;
    int mid=(l+r)>>1,ans;
    //cout<<l<<"-"<<r<<":"<<t[now]<<endl;
    ans=ask(now<<1,l,mid,L,R)+ask(now<<1|1,mid+1,r,L,R);
    t[now]=t[now<<1]+t[now<<1|1];
    return ans;
}


signed main(){
    int l,r,K,D,p,opt;
    cin>>n>>m;
    for(int i=1;i<=n;i++)   scanf("%lld",&a[i]),b[i]=a[i]-a[i-1];
    build(1,1,n);
    while(m--){
        scanf("%lld",&opt);
        if(opt==1){
            scanf("%lld%lld%lld%lld",&l,&r,&K,&D);
            add(1,1,n,l,l,K);
            if(l!=r)    add(1,1,n,l+1,r,D);
            add(1,1,n,r+1,r+1,-K-(r-l)*D);            
        }
        if(opt==2){
            scanf("%lld",&p);
            printf("%lld\n",ask(1,1,n,1,p));
        }
    }
    getchar();getchar();
    return 0;
}