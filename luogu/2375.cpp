#include<bits/stdc++.h>
#define MAXN 1000100
#define MOD 1000000007
using namespace std;

int t;
int fail[MAXN],num[MAXN],ans[MAXN];
char s[MAXN];
int main(){
    cin>>t;
    while(t--){
        scanf("%s",s+1);

        int j=0,n=strlen(s+1); ans[1]=1;
        for(int i=2;i<=n;i++){
            while(j&&s[j+1]!=s[i])  j=fail[j];
            if(s[j+1]==s[i])    j++;
            fail[i]=j; ans[i]=ans[j]+1;
        }

        long long num=1; j=0;
        for(int i=2;i<=n;i++){
            while(j&&s[j+1]!=s[i])    j=fail[j];
            if(s[j+1]==s[i])    j++;
            while(j*2>i)    j=fail[j];
           (num*=(ans[j]+1))%=MOD;
        }
        //num*=ans[1]
        cout<<num<<endl;
        memset(fail,0,sizeof(fail));
    }
    getchar();getchar();
    return 0;
}