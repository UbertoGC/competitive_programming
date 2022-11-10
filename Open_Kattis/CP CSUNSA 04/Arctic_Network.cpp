#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
struct arista{
    int punto_1, punto_2;
    double distancia;
};
int encontrar(vector<int>& d, int a){
    if(d[a] == -1)
        return a;
    d[a] = encontrar(d,d[a]);
    return d[a];
}
void unir(vector<int>& d, int a, int b){
    a = encontrar(d,a);
    b = encontrar(d,b);
    if(a == b)
        return;
    d[a] = b;
}
bool cmp(arista primero, arista segundo){
    return primero.distancia < segundo.distancia;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, s, p;
    cin >> n;
    while (n--){
        cin >> s >> p;
        vector<pair<int,int>> puntos(p);
        for (int i = 0; i < p; i++){
            cin >> puntos[i].first >>puntos[i].second;
        }
        vector<arista> aristas;
        for (int i = 0; i < p; i++){
            for (int j = i+1; j < p; j++){
                double d = sqrt(pow(puntos[i].first - puntos[j].first, 2) + pow(puntos[i].second - puntos[j].second, 2));
                arista nuevo;
                nuevo.punto_1 = i;
                nuevo.punto_2 = j;
                nuevo.distancia = d;
                aristas.push_back(nuevo);
            }
        }
        sort(aristas.begin(),aristas.end(),cmp);
        vector<int> desunir(p,-1);
        vector<double> mantener;
        for (auto i : aristas){
            if(encontrar(desunir,i.punto_1) != encontrar(desunir,i.punto_2)){
                unir(desunir, i.punto_1, i.punto_2);
                mantener.push_back(i.distancia);
            }
        }
        for (int i = 1; i < s; i++){
            mantener.pop_back();
        }
        cout << fixed;
        cout.precision(2);
        cout << mantener.back() << endl;
    }
    return 0;
}