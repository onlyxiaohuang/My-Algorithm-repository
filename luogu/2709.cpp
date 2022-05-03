#include<bits/stdc++.h>
#define MAXN 1000100
using namespace std;

int n,m,k;
int a[MAXN],now[MAXN],ans[MAXN];
struct Query{
    int l,r;
    int pos,num;
}b[MAXN];

bool cmp(Query x,Query y){
    if(x.pos==y.pos){
        if(x.pos&1)        return x.r<y.r;
        else return x.r>y.r;
    }
    return x.pos<y.pos;
}

inline int read(){
    int ans=0;char c=getchar();
    while(c>'9'||c<'0') c=getchar();
    while(c>='0'&&c<='9')   ans=(ans<<3)+(ans<<1)+c-'0',c=getchar();
    return ans;
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++)   a[i]=read();
    cin>>m;
    for(int i=1;i<=m;i++){
        b[i].l=read();b[i].r=read();
        b[i].pos=b[i].l/sqrt(n)+1;
        b[i].num=i;
    }
    sort(b+1,b+1+m,cmp);
    int l=1,r=0,cnt=0;
    for(int i=1;i<=m;i++){//[l,r]
        while(r<b[i].r){
            r++;
            if(now[a[r]]==0)    cnt++;
            now[a[r]]++;
        }         
        while(l>b[i].l){
            l--;
            if(now[a[l]]==0)    cnt++; now[a[l]]++;
        }
        while(l<b[i].l){
            if(now[a[l]]==1)    cnt--;
            now[a[l]]--;    l++;
        }
        while(r>b[i].r){
            if(now[a[r]]==1)    cnt--;
            now[a[r]]--;    r--;
        }
        ans[b[i].num]=cnt;
    }
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    getchar();getchar();
    return 0;
}