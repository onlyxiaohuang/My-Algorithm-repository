#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;

int n,m,q;
int a[MAXN],t[MAXN<<2],tag[MAXN<<2];
int opt[MAXN],lef[MAXN],righ[MAXN];
void pushup(int x){
    t[x]=t[x<<1]+t[x<<1|1];
}
void build(int x,int l,int r,int now){
    tag[x]=0;
    if(l==r){
        if(a[l]>now)    t[x]=1;
        else t[x]=0;
        t[x<<1]=t[x<<1|1]=0;//cout<<l<<"-"<<r<<":"<<t[x]<<endl;
        return ;
    }
    int mid=(l+r)>>1;
    build(x<<1,l,mid,now),build(x<<1|1,mid+1,r,now);
    pushup(x); // cout<<l<<"-"<<r<<":"<<t[x]<<endl;
}
void pushdown(int x,int y){
    if(tag[x]==0)    return ;
    if(tag[x]==-1){
        t[x]=0;
        tag[x<<1]=-1; tag[x<<1|1]=-1;
    }
    if(tag[x]==1){
        t[x]=y;
        tag[x<<1]=1; tag[x<<1|1]=1;
    }
    tag[x]=0;
}
void change(int x,int l,int r,int L,int R,int d){
    if(l>r) return ;
    pushdown(x,r-l+1);
    if(l>R||r<L)    return ; 
    if(l>=L&&r<=R){
        tag[x]=d;   pushdown(x,r-l+1); return ;//cout<<l<<"-"<<r<<":"<<t[x]<<endl; 
    }
    //if(l==r)    return ;
    
    int mid=(l+r)>>1;
    change(x<<1,l,mid,L,R,d);   change(x<<1|1,mid+1,r,L,R,d);   
    if(l!=r) pushup(x); //cout<<l<<"-"<<r<<":"<<t[x]<<endl;
    return ;
}
int ask(int x,int l,int r,int L,int R){
    pushdown(x,r-l+1);//cout<<l<<" "<<r<<"&"<<t[x]<<endl;
    if(l>R||r<L)    return 0;
    if(l>=L&&r<=R)  return t[x];
    int mid=(l+r)>>1,ans=ask(x<<1,l,mid,L,R)+ask(x<<1|1,mid+1,r,L,R);
    if(l!=r) pushup(x);
    return ans;    
}



int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)     scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)     scanf("%d%d%d",&opt[i],&lef[i],&righ[i]);
    cin>>q;
    int l=1,r=n;
    while(l<r){
        int mid=(l+r)>>1;
        //cout<<mid<<"*"<<endl;
        build(1,1,n,mid);
        for(int i=1;i<=m;i++){
            int tot=ask(1,1,n,lef[i],righ[i]),len=righ[i]-lef[i]+1;
            //cout<<tot<<" "<<len<<endl;
            if(opt[i]==0){
                change(1,1,n,lef[i],lef[i]+len-tot-1,-1);
                //ask(1,1,n,lef[i],righ[i]);
                change(1,1,n,lef[i]+len-tot,righ[i],1);
                //ask(1,1,n,lef[i],righ[i]);
            }
            else{
                //ask(1,1,n,lef[i],righ[i]);
                change(1,1,n,lef[i],lef[i]+tot-1,1);
                //ask(1,1,n,lef[i],righ[i]);
                change(1,1,n,lef[i]+tot,righ[i],-1);
            }
            //cout<<endl;
        }
        if(ask(1,1,n,q,q)==1)  l=mid+1;
        else r=mid;
    }
    cout<<l<<endl;
    getchar();getchar();
    return 0;
}/*
6 3
1 6 2 5 3 4
0 1 4
1 3 6
0 2 4
2
*/