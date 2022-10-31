#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
class Fenwick_tree
{
    public:
        Fenwick_tree(){};
        Fenwick_tree(int n) : size(n), arbol(vector<long long>(n)) {}
        void update(int i, ll v) {
            while (i < size) {
                arbol[i] += v;
                i |= (i + 1);
            }
        }
        ll resul(int i, int j){
            return busqueda(j) - busqueda(i-1);
        }
        ll busqueda(int i){
            ll suma=0;
            while (i>=0){
                suma+=arbol[i];
                i = (i & (i + 1)) - 1;
            }
            return suma;
        }
        ~Fenwick_tree(){}
    private:
        vector<long long> arbol;
        int size;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q, gemas[6];
    cin>>n>>q;
    for (int i = 0; i < 6; i++) {
        cin>>gemas[i];
    }
    string a;
    cin>>a;
    Fenwick_tree fenwicks[6];
    for (int i = 0; i < 6; i++) {
        fenwicks[i] = Fenwick_tree(n + 1);
    }
    for (int i = 0; i < n; i++) {
        fenwicks[a[i] - '1'].update(i, 1);
    }
    int f, s, t;
    for (int i = 0; i < q; i++) {
        cin>>f>>s>>t;
        if (f == 1) {
            fenwicks[a[s - 1] - '1'].update(s - 1, -1);
            a[s - 1] = '0' + t;
            fenwicks[a[s - 1] - '1'].update(s - 1, +1);
        }
        else if (f == 2) {
            gemas[s - 1] = t;
        }
        else if (f == 3){
            long long sum = 0;
            for (int j = 0; j < 6; j++) {
                sum += fenwicks[j].resul(s - 1, t - 1) * gemas[j];
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}