#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main(){
    int N,a,b,c;
    int valor;
    int caso = 0;
    cin>>N;
    while(N--){
        cin >> a >> b >> c;
        vector<int> ruta;
        unordered_map<int,int> posicion;
        for(int i=0;i<=b;i++){
            cin >> valor;
            posicion[valor] = i;
        }
        for(int i=0;i<=c;i++){
            cin >> valor;
            int pos = posicion[valor];
            if(pos != 0){
                auto p = lower_bound(ruta.begin(),ruta.end(),pos);
                if(p == ruta.end()) 
                    ruta.push_back(pos);
                else 
                    *p = pos;
            }
        }
        caso++;
        cout << "Case "<<caso<<": " << ruta.size()+1 << "\n";
    }
}