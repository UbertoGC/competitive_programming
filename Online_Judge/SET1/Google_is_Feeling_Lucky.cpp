#include <iostream>
using namespace std;
int main(){
    int T,n,max;
    string nom;
    string nombres[10];
    cin>>T;
    for (int i = 0; i < T; i++){
        max=1;
        int med=0;
        for (int j = 0; j < 10; j++){
            cin>>nom>>n;            
            if(max<n){
                max=n;
                med=0;
                nombres[med]=nom;
            }
            else if(max==n){
                med++;
                nombres[med]=nom;
            }
        }
        cout<<"Case #"<<i+1<<":"<<"\n";
        for (int j = 0; j <= med; j++){
            cout<<nombres[j]<<"\n";
        }
    }
    return 0;
}