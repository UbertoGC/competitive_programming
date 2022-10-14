#include <iostream>
using namespace std;
int main(){
    int m,n,r=0;
    char p;
    while(cin>>m>>n,m!=0&&n!=0){
        if (m==1||n==1)
            r=max(m,n);
        else if (m==2||n==2)
            r=4*int(max(m,n)/4)+2*min(2,max(m,n)%4);
        else
            r=(m*n+1)/2;
        cout<<r<<" knights may be placed on a "<<m<<" row "<<n<<" column board."<<endl;
    }
    return 0;
}