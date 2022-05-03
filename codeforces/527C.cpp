#include<bits/stdc++.h>
#define int long long
using namespace std;

struct Lines{
    multiset <int> len,pos;
}H,V;

void check(){
    putchar('\n');
    multiset<int>::iterator it=H.len.begin();
    while(it!=H.len.end())  printf("%d ",*it),++it; putchar('\n');
    it=V.len.begin();
    while(it!=V.len.end())  printf("%d ",*it),++it; putchar('\n');   putchar('\n'); 
    it=H.pos.begin();
    while(it!=H.pos.end())  printf("%d ",*it),++it; putchar('\n');
    it=V.pos.begin();
    while(it!=V.pos.end())  printf("%d ",*it),++it; putchar('\n');  putchar('\n'); 

}

int w,h;

signed main(){
    int n,x,p,q;
    char opt;

    cin>>w>>h>>n;
    H.pos.insert(h); H.pos.insert(0);   H.len.insert(h);
    V.pos.insert(w); V.pos.insert(0);   V.len.insert(w);   
    while(n--){
        scanf("\n%c %lld",&opt,&x);
        //cout<<opt<<endl;
        if(opt=='H'){
            multiset <int> :: iterator it=H.pos.upper_bound(x);
            p=*it; it--; q=*it; //
            H.len.erase(H.len.find(p-q)); //H.len.erase(it);
            H.len.insert(p-x);  H.len.insert(x-q); H.pos.insert(x);
        }
        if(opt=='V'){
            multiset <int> :: iterator it=V.pos.upper_bound(x);
            p=*it; it--; q=*it;
            V.len.erase(V.len.find(p-q));//cout<<p<<" *"<<q<<endl; V.len.erase(it);
            V.len.insert(p-x);  V.len.insert(x-q); V.pos.insert(x);            
        }
        multiset <int> :: iterator it1=H.len.end(),it2=V.len.end();
        //check();
        it1--; it2--;
        printf("%lld\n",(*it2)*(*it1));
    }
    getchar();getchar();
    return 0;
}