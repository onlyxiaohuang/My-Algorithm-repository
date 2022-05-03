#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;

struct Node{
    int x,y,f,now;
}a[MAXN];

bool cmp1(Node x,Node y){
    return x.x<y.x;
}
bool cmp2(Node x,Node y){
    return x.y<y.y;
}
bool cmp3(Node x,Node y){
    return x.now<y.now;
}

int f(Node x){
    if(!x.f)    return x.now;
    return x.f=f(a[x.f]);
}
void merge(int x,int y){
    int fx=f(a[x]),fy=f(a[y]);
    if(fx==fy)  return ;
    a[fx].f=fy; return ;
}

int main(){

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y),a[i].now=i;
    sort(a+1,a+1+n,cmp1);
    for(int i=1;i<=n;i++)
        if(a[i].x==a[i-1])

}