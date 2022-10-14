#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int>datos;
    int x, contador=0;
    while(cin>>x){
        datos.push_back(x);
        sort(datos.begin(),datos.end());
        if(contador%2==0){
            int mid=(0+contador)/2;
            cout << datos[mid] << endl;
        }
        else{
            int medio_0=(0+contador)/2;
            int medio_1=medio_0+1;
            int val=(datos[medio_0]+datos[medio_1])/2;
            cout << val << endl;
        }
        contador++;
    }
    return 0;
}