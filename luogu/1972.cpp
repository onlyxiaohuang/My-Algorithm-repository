#include<bits/stdc++.h>
#define int long long
#define MAXN 1000100
using namespace std;

int n,m,k;
int a[MAXN],now[MAXN],ans[MAXN];
struct Query{
    int l,r;
    int pos,num;
}b[MAXN];

bool cmp(Query x,Query y){
    if(x.pos==y.pos)    return x.r<y.r;
    return x.pos<y.pos;
}

signed main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld",&b[i].l,&b[i].r);
        b[i].pos=b[i].l/sqrt(n)+1;
        b[i].num=i;
    }
    sort(b+1,b+1+m,cmp);
    int l=1,r=0,cnt=0;
    for(int i=1;i<=m;i++){//[l,r]
        while(r<b[i].r){
            r++; cnt+=now[a[r]]*2+1; now[a[r]]++;
        }         
        while(l>b[i].l){
            l--; cnt+=now[a[l]]*2+1; now[a[l]]++;
        }
        while(l<b[i].l){
            cnt-=now[a[l]]*2-1; now[a[l]]--;    l++;
        }
        while(r>b[i].r){
            cnt-=now[a[r]]*2-1; now[a[r]]--;    r--;
        }
        ans[b[i].num]=cnt;
    }
    for(int i=1;i<=m;i++)
        printf("%lld\n",ans[i]);
    //printf("%d\n",sizeof('\0'));
    getchar();getchar();
    return 0;
}