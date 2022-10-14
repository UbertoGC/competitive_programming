#include <iostream>
using namespace std;
int main(){
    int N,B,H,W;
    int preciomin;
    while(cin>>N>>B>>H>>W){
        preciomin=B+1;
        for (int i = 0; i < H; i++){
            int precios;
            int camas,camasd=0;
            cin>>precios;
            for (int j = 0; j < W; j++){
                cin>>camas;
                camasd=max(camas,camasd);
            }
            if(N<=camasd && N*precios<preciomin)
                preciomin=N*precios;
        }
        if(preciomin!=B+1)
            cout<<preciomin<<endl;
        else
            cout<<"stay home"<<endl;
    }
    return 0;
}