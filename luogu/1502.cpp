#include<bits/stdc++.h>
#define MAXN 1010
#define mid ((l+r)>>1)
using namespace std;

struct Lines{
    int x,y,h,val;
}l[MAXN<<1];

int n,W,H;
int a[MAXN<<1],top;

bool cmp(Lines x,Lines y){
    if(x.h==y.h)    return x.val>y.val;
    return x.h<y.h;
}

int t[MAXN<<2],tag[MAXN<<2];
void pushup(int x){
    t[x]=max(t[x<<1],t[x<<1|1]);
}
void pushdown(int x){
    if(!tag[x]) return ;
    t[x]+=tag[x];   tag[x<<1]+=tag[x]; tag[x<<1|1]+=tag[x]; tag[x]=0;
}
void change(int x,int l,int r,int L,int R,int val){
    pushdown(x);
    if(l>R||r<L)    return ;
    if(l>=L&&r<=R){
        tag[x]+=val;    pushdown(x);    
        return ;
    }
    //if(l==r)    return ;
    //cout<<x<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<endl;
    change(x<<1,l,mid,L,R,val);    change(x<<1|1,mid+1,r,L,R,val);  pushup(x);
    return ;
}


int main(){
    int T;
    cin>>T;
    while(T--){

        int x,y,li;
        scanf("%d%d%d",&n,&W,&H);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&x,&y,&li);
            l[(i<<1)-1].x=x;    l[(i<<1)-1].y=x+W-1;    l[(i<<1)-1].val=li;     l[(i<<1)-1].h=y;
            l[i<<1].x=x; l[i<<1].y=x+W-1; l[i<<1].val=-li; l[i<<1].h=y+H-1;
            a[(i<<1)-1]=x-W+1; a[i<<1]=x+W-1;
        }


        sort(a+1,a+1+2*n);
        top=unique(a+1,a+1+2*n)-a-1;
        //cout<<top<<endl;
        sort(l+1,l+1+2*n,cmp);
        
        int ans=0;
        for(int i=1;i<=2*n;i++){
            x=lower_bound(a+1,a+1+top,l[i].x)-a;
            y=lower_bound(a+1,a+1+top,l[i].y)-a;
            //cout<<x<<" "<<y<<" "<<l[i].val<<endl;
            change(1,1,top,x,y,l[i].val);   ans=max(ans,t[1]);    
        }
        cout<<ans<<endl;
    }
    getchar();getchar();
    return 0;
}