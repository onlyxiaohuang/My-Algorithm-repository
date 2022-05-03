#include<bits/stdc++.h>
using namespace std;

int a[110];
string s;

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        cin>>s;
        if(s[0]==s[s.length()-1])   cout<<s<<endl;
        else s[0]=s[s.length()-1],cout<<s<<endl;

    }
  //  system("pause");
    return 0;
}