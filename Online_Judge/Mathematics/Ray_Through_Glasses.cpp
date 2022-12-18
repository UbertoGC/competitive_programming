#include <iostream>
#include <queue>
#include <vector>
using namespace std;
void analisis(int nivel,int n, int& cont, bool dir=1){
    if(n == 0){
        cont++;
        return;
    }
    if(nivel!=0){
        if(dir){
            analisis(nivel-1,n-1,cont,0);
        }
        else{
            analisis(nivel-1,n,cont,0);  
        }
    }
    if(nivel!=2){
        if(!dir){
            analisis(nivel+1,n-1,cont,1);
        }
        else{
            analisis(nivel+1,n,cont,1);
        }
    }
}
int main(){
    int n,cont;
    while(cin>>n){
        cont = 0;
        analisis(1,n,cont);
        cout<<cont<<endl;
    }
    return 0;
}