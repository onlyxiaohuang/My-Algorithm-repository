#include<bits/stdc++.h>
#define MAXN 500010
#define int long long
using namespace std;

struct Query{
    int l,r,pos,kuai;
}q[MAXN];

int a[MAXN],b[MAXN];
int ans1[MAXN],ans2[MAXN];
bool cmp(Query x,Query y){
    if((x.kuai==y.kuai)&&(x.kuai&1))  return x.r<y.r;
    if((x.kuai==y.kuai)&&(!(x.kuai&1))) return x.r>y.r;
    return x.kuai<y.kuai;
}
int gcd(int x,int y){
    if(y==0)    return x;
    return gcd(y,x%y);
}

signed main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    for(int i=1;i<=m;i++){
        scanf("%lld%lld",&q[i].l,&q[i].r);
        q[i].pos=i; q[i].kuai=q[i].l/sqrt(n)+1;
    }
    sort(q+1,q+1+m,cmp);
    
    int r=0,l=1,ans=0;
    for(int i=1;i<=m;i++){
        while(l>q[i].l) l--,ans+=b[a[l]],b[a[l]]++; 
        while(r<q[i].r) r++,ans+=b[a[r]],b[a[r]]++;
        while(l<q[i].l) b[a[l]]--,ans-=b[a[l]],l++;
        while(r>q[i].r) b[a[r]]--,ans-=b[a[r]],r--;
        ans1[q[i].pos]=ans; ans2[q[i].pos]=q[i].r-q[i].l+1;
        ans2[q[i].pos]=ans2[q[i].pos]*(ans2[q[i].pos]-1)/2;
    }
    
    for(int i=1;i<=m;i++){
        if(ans1[i]==0)  puts("0/1");
        else printf("%lld/%lld\n",ans1[i]/gcd(ans1[i],ans2[i]),ans2[i]/gcd(ans1[i],ans2[i]));
        //cout<<ans1[i]<<endl;
    }

    getchar();getchar();
    return 0;
}