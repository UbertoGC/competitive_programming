#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    int c, l, n;
    cin>>c;
    while(c--){
        cin>>l>>n;
        int a[n], minimo=0;
        int valor_minimo=l, valor_maximo=0;
        for (int i = 0; i < n; i++){
            cin>>a[i];
            valor_maximo=max(a[i],valor_maximo);
            valor_minimo=min(a[i],valor_minimo);
            minimo=max(minimo,min(a[i],l-a[i]));
        }
        int maximo=max(valor_maximo,l-valor_minimo);
        cout<<minimo<<" "<<maximo<<endl;
    }
    return 0;
}