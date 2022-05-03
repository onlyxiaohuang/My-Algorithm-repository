#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;

set < vector<int> > s;
vector <int> t;

int main(){
    int n,x,m;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&m);
        t.clear();
        for(int j=1;j<=m;j++){
            scanf("%d",&x);
            t.push_back(x);
        } 
        s.insert(t);
    }
    cout<<s.size()<<endl;
    getchar();getchar();
    return 0;
}