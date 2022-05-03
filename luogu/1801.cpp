#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;

struct Node{
    int ori,now,pri;
}a[MAXN];

bool dmp(Node x,Node y){
    return x.ori<y.ori;
}
bool dmp2(Node x,Node y){
    return x.pri<y.pri;
}

int b[MAXN],C[MAXN];
inline int lowbit(int x){ return x&(-x);  }
void add(int pos,int x){
    if(pos>=MAXN||pos==0)   return ;
    C[pos]+=x;  add(pos+lowbit(pos),x);
    return ;
}
int ask(int pos){
    if(pos==0)  return 0;
    return ask(pos-lowbit(pos))+C[pos];
}
int query(int l,int r,int pos){
    int mid;
    while(l<r){
        mid=(l+r)>>1;
        if(ask(mid)<pos)    l=mid;
        else r=mid+1;
    }
    return mid;
}

int main(){
    
    int n,m,x,p=0;
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i].ori),a[i].pri=i;
    sort(a+1,a+1+n,dmp);
    for(int i=1;i<=n;i++)    a[i].now=i;
    sort(a+1,a+1+n,dmp2);
    
    for(int i=1;i<=m;i++)        scanf("%d",&b[i]);
    for(int i=1;i<=m;i++){
        p++;
        for(int j=b[i-1]+1;j<=b[i];j++)       add(a[j].now,1);
        printf("%d\n",query(1,n,p));
    }
    system("pause");
    return 0;
}