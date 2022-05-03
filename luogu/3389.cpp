#include<bits/stdc++.h>
#define MAXN 110
using namespace std;

int n;
double a[MAXN][MAXN],b[MAXN];

void print(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            printf("%lf ",a[i][j]);
        printf("%lf",b[i]);
        putchar('\n');
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            scanf("%lf",&a[i][j]);
        scanf("%lf",&b[i]);
    }    
    double now;
    for(int i=1;i<=n;i++){
        now=a[i][i];
        if(now==0){
            printf("no solution\n");
            return 0;
        }
        for(int j=1;j<=n;j++)            a[i][j]/=now;
        b[i]/=now;
        
        for(int j=i+1;j<=n;j++){
            now=a[j][i];
            for(int k=1;k<=n;k++)
                a[j][k]-=now*a[i][k];
            b[j]-=now*b[i];
        }
    }

    for(int i=n;i;i--){
        for(int j=i-1;j;j--){
            b[j]-=a[j][i]*b[i];
            a[j][i]=0;
        }
    }
    //print();
    for(int i=1;i<=n;i++)
        printf("%.2lf\n",b[i]);

    getchar();getchar();
    return 0;
}