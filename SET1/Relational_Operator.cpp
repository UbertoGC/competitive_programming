#include <iostream>
using namespace std;
int main(){
    int r,a,b;
    cin>>r;
    while(r!=0){
        cin>>a>>b;
        if(a<b)
            cout<<"<";
        else if(a>b)
            cout<<">";
        else
            cout<<"=";
        cout<<'\n';
        r--;
    }
    return 0;
}