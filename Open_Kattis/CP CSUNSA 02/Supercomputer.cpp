#include <bits/stdc++.h>
using namespace std;
class Fenwick_tree
{
    private:
        vector<int> arbol;
        vector<int> valores;
    public:
        Fenwick_tree(int n){
            arbol.assign(n, 0);
            valores.assign(n, 0);
        }
        int busqueda(int i){
            int suma=0;
            while (i>=0){
                suma+=arbol[i];
                i = (i & (i + 1)) - 1;
            }
            return suma;
        }
        int resul(int i, int j){
            return busqueda(j) - busqueda(i);
        }
        void update(int i, int v) {
            valores[i]+=v;
            while (i < arbol.size()) {
                arbol[i] += v;
                i |= (i + 1);
            }
        }
        int obtener(int i){
            return valores[i];
        }
        ~Fenwick_tree(){}
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k,s,t;
    cin>>n>>k;
    char f;
    Fenwick_tree fenwick(n + 1);
    for (int i = 0; i < k; i++){
        cin>>f;
        if(f=='F'){
            cin>>s;
            if (fenwick.obtener(s)) {
                fenwick.update(s, -1);
            }
            else {
                fenwick.update(s, +1);
            }
        }
        else{
            cin>>s>>t;
            cout << fenwick.resul(s - 1, t) << endl;
        }
    }
    return 0;
}