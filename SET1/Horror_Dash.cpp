#include <iostream>
using namespace std;
int main(){
    int T,m,n,t_3;
    cin>>T;
    if(T>50)
        return 0;
    for (int i = 0; i < T; i++){
        m=1;
        cin>>n;
        if(n<=100&&1<=n){
            for (int j = 0; j < n; j++){
                cin>>t_3;
                if(m<t_3&&t_3<=10000){
                    m=t_3;
                }
            }
            cout<<"Case "<<i+1<<": "<<m<<endl;
        }
        
    }
    return 0;
}