#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
bool jolly(bool a[],int n){
    while(--n)
        if(!a[n])
            return 0;
    return 1;
}
int main(){
    int n,a,b;
    bool jollys[3000];
    while(cin>>n){
        memset(jollys,0,sizeof(bool)*n);
        cin>>a;
        for(int i=1;i<n;++i){
            cin>>b;
            a=abs(a-b);
            if(a<n)
                jollys[a]=1;
            a=b;
        }
        if(jolly(jollys,n))
            cout<<"jolly"<<endl;
        else
            cout<<"Not jolly"<<endl;
    }
    return 0;
}