#include <iostream>
#include <algorithm>
using namespace std;
int precios[10005];
int main(){
    int n;
    int obj;
    int a;
    int b;
    while(scanf("%d",&n)!=EOF){
        for (int i = 0; i < n; i++){
            cin>>precios[i];
        }
        sort(precios,precios+n);
        cin>>obj;
        int minimo=1000001;
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                if(precios[i]+precios[j]==obj){
                    if(minimo>(precios[j]-precios[i])){
                        a=precios[i];
                        b=precios[j];
                    }
                }
            }
        }
        cout<<"Peter should buy books whose prices are "<<a<<" and "<<b<<"."<<endl;
        cout<<endl;
    }
    return 0;
}