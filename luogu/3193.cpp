#include<bits/stdc++.h>
using namespace std;

char s[30];
//int f[MAXN][30];
int fail[30];

int n,m,K;
struct matrix{
    int a[31][31];
    void print(){
        for(int i=0;i<=m;i++){
            for(int j=0;j<=m;j++)
                printf("%d ",a[i][j]);
            putchar('\n');
        }
    }
    void init(){
        for(int i=0;i<=m;i++)
            for(int j=0;j<=m;j++)
                a[i][j]=0;

        for(int i=0;i<=m;i++)
            a[i][i]=1;
    }
}g,f;
matrix mul(matrix x,matrix y){
    matrix ans; //x.print();y.print();
    for(int i=0;i<=m;i++)
        for(int j=0;j<=m;j++)
            ans.a[i][j]=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++)
            for(int k=0;k<m;k++){
                //cout<<i<<" "<<j<<" "<<k<<endl;
                //cout<<ans.a[0][0]<<endl;
                //cout<<x.a[i][j]<<endl;
                ///cout<<y.a[k][j]<<endl;
                (ans.a[i][j]+=(x.a[i][k])*(y.a[k][j]))%=K;
                //cout<<ans.a[i][j]<<endl;
            }
    }
    //cout<<K<<endl;
    return ans;
}
matrix ksm(matrix x,int y){
    matrix ans,cnt=x;   ans.init(); 
    while(y){
        //ans.print(); cnt.print();
        if(y&1) ans=mul(ans,cnt);
        y>>=1; cnt=mul(cnt,cnt);
    }
    return ans;
}

int main(){
    cin>>n>>m>>K;
    scanf("%s",s+1);

    int j=0;
    for(int i=2;i<=m;i++){
        while(s[j+1]!=s[i]&&j) j=fail[j];
        if(s[j+1]==s[i])    j++;
        fail[i]=j;
    }

    for(int i=0;i<m;i++){
        for(int j='0';j<='9';j++){
            int now=i;
            while(s[now+1]!=j&&now)  now=fail[now];
            if(s[now+1]==j)  now++;
            g.a[i][now]++;    //cout<<i<<" "<<now<<" "<<g[i][now]<<endl;
        }
    }

    /*f[0][0]=1;
    for(int i=1;i<=n;i++)
        for(int j=0;j<m;j++)
            for(int p=0;p<m;p++)
                (f[i][j]+=f[i-1][p]*g[p][j])%=k;
    */
    //for(int i=1;)
    f.a[0][0]=1;
    g=ksm(g,n); f=mul(f,g); 
    int ans=0;
    for(int i=0;i<m;i++)
        ans=(ans+f.a[0][i])%K;
    cout<<ans<<endl;

    getchar();getchar();
    return 0;
}