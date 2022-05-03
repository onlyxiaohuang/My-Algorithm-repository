#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,t,x;
    cin>>t;
    while(t--){
        int k=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&x);
            k=max(k,x-i);
        }
        printf("%d\n",k);
    }
    getchar();getchar();
    return 0;
}