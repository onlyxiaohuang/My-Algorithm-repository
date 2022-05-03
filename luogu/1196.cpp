#include<bits/stdc++.h>
#define MAXN 30010
using namespace std;

int f[MAXN],c[MAXN],size[MAXN];
int swap(int &x,int &y){
    int t=x;x=y;y=t;
}
int fi(int x){
    if(f[x]==x) return x;
    int t=f[x]; f[x]=fi(f[x]); c[x]+=c[t]; 
    return f[x];
}
void merge(int x,int y){
    //if(x<y) swap(x,y);
    int fx=fi(x),fy=fi(y);
    if(fx==fy)  return ;
    f[fx]=fy,c[fx]=size[fy],size[fy]+=size[fx];
}

int main(){
    int t,x,y;
    char d;
    cin>>t;
    for(int i=1;i<=30000;i++)        f[i]=i,size[i]=1;
    while(t--){
        scanf("\n%c %d %d",&d,&x,&y);
        if(d=='M')  merge(x,y);
        if(d=='C'){
            if(fi(x)!=fi(y))    puts("-1");
            else printf("%d\n",abs(c[y]-c[x])-1);
        }
    }
    getchar();getchar();
    return 0;
}