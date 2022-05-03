#include<bits/stdc++.h>
#define MAXN 2000100
using namespace std;

struct Heap{
    private:
    int top,a[MAXN];
    inline void allocate(int val){        a[++top]=val;    }
    inline void pushup(int x){
        if(x==1)    return ;
        if(a[x]<a[x>>1])    swap(a[x],a[x>>1]),pushup(x>>1);
    }

    inline void pushdown(int x){
        if((x<<1)>top)  return ;
        if((x<<1|1)>top){
            if(a[x<<1]<a[x])   swap(a[x],a[x<<1]);    return ;
        }
        int now=(a[x<<1]<=a[x<<1|1]?(x<<1):(x<<1|1));
        if(a[now]<a[x]) swap(a[now],a[x]),pushdown(now);
    }

    public:
    inline int min_val(){ return a[1]; }
    inline void insert(int val){  allocate(val); pushup(top);   }
    inline void del(){  swap(a[1],a[top]); a[top--]=0; pushdown(1);    }
}Q;

int main(){
    int n,op,x;
    cin>>n;
    while(n--){
        scanf("%d",&op);
        if(op==1)   scanf("%d",&x),Q.insert(x);
        if(op==2)   printf("%d\n",Q.min_val());
        if(op==3) Q.del();
    }
    getchar();getchar();
    return 0;
} 