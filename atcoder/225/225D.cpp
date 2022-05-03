#include<bits/stdc++.h>
#define MAXN 100010
using namespace std;

struct edge{
    int head[MAXN],to[MAXN],top,tmp[MAXN];
    void add(int x,int y){
        head[x]=++top;    to[top]=y; tmp[top]=x;
    }
    void del(int x,int y){
        int now=head[x];
        head[x]=to[now]=tmp[now]=0;
    }
}a,b;

void check(){
    for(int i=1;i<=a.top;i++)
        cout<<a.to[i]<<" "<<a.tmp[i]<<endl;
    for(int i=1;i<=b.top;i++)
        cout<<b.to[i]<<" "<<b.tmp[i]<<endl;
}


int main(){
    int n,q,x,y,opt;
    cin>>n>>q;
    while(q--){
        scanf("%d",&opt);
        if(opt==1){
            scanf("%d%d",&x,&y);
            a.add(x,y); b.add(y,x);
        }
        if(opt==2){
            scanf("%d%d",&x,&y);
            a.del(x,y); b.del(y,x);
        }
        if(opt==3){
            //check();
            //for(int i=1;i<=n;i++)                cout<<a.head[i]<<" "<<b.head[i]<<" ";
            scanf("%d",&x); 
            int now=0; 
            if(b.head[x]) {
                now=b.head[x];  
                while(b.head[b.to[now]])    now=b.head[b.to[now]];
                now=b.to[now];now=a.head[now];
            }
            else if(a.head[x]) now=a.head[x];
            else{
                printf("1 %d\n",x);
                continue;
            }
            int cnt=now,ans=1;
            while(a.to[cnt])    ans++,cnt=a.head[a.to[cnt]];
            printf("%d %d ",ans,a.tmp[now]);
            while(a.to[now])    printf("%d ",a.to[now]),now=a.head[a.to[now]];
            putchar('\n'); //cout<<x<<"*"<<now<<endl;
        }
    }
    //getchar();getchar();
    return 0;
}