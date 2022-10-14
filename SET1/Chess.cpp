#include <iostream>
using namespace std;
int main(){
    int t,m,n,r=0;
    char p;
    cin>>t;
    while(t!=0){
        cin>>p>>m>>n;
        if(p=='k'){
            r=(((m+1)/2)*((n +1)/2))+((m/2)*(n/2));
        }
        else if(p=='Q'||p=='r'){
            r=min(m,n);
        }
        else if(p=='K'){
            r=((m+1)/2)*((n+1)/2);
        }
        cout<<r<<endl;
        t--;
    }
    return 0;
}