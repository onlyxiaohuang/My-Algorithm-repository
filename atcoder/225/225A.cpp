#include<bits/stdc++.h>
using namespace std;

string s;
int main(){
    cin>>s;
    if(s[0]==s[1]&&s[1]==s[2])
        printf("1\n");
    else if(s[0]==s[1]||s[1]==s[2]||s[0]==s[2])
        printf("3\n");
    else printf("6\n");
    return 0;
}