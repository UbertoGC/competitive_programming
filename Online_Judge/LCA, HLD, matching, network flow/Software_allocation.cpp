#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 100000000000ll
int comienzo = 26;
int s_1 = 36;
int s_2 = 37;
int cant_puntos = 38;
typedef long long ll;
struct arista {
    int u, v, i;
    ll c;
    bool r;
    arista(int uu = 0, int vv = 0, ll cc = 0, int ii = 0, bool rr = false) :
        u(uu), v(vv), c(cc), i(ii), r(rr) {}
};
vector<arista> aristas[40];
int ant[40];
void anadir_arista(int u, int v, ll c) {
    aristas[u].push_back(arista(u, v, c, aristas[v].size(), false));
    aristas[v].push_back(arista(v, u, 0, aristas[u].size()-1, true));
}
ll augment(int s, int t, int n) {
    queue<int> q;
    for (int i = 0; i < n; i++) 
        ant[i] = -1;
    ant[s] = -2;
    q.push(s);
    while (!q.empty() && ant[t] == -1) {
        int indice = q.front();
        q.pop();
        for (int i = 0; i < aristas[indice].size(); ++i) {
            arista arist = aristas[indice][i];
            if (ant[arist.v] == -1 && arist.c > 0) {
                ant[arist.v] = arist.i;
                q.push(arist.v);
            }
        }
    }
    if (ant[t] == -1) 
        return 0;
    ll val = INF;
    int v = t;
    while (v != s) {
        int u = aristas[v][ant[v]].v;
        val = min(val, aristas[u][aristas[v][ant[v]].i].c);
        v = u;
    }
    v = t;
    while (v != s) {
        int u = aristas[v][ant[v]].v;
        aristas[v][ant[v]].c += val;
        aristas[u][aristas[v][ant[v]].i].c -= val;
        v = u;
    }
    return val;
}

ll acumulacion(int s, int t, int n) {
    ll flow = 0, aug;
    while ((aug = augment(s, t, n))){
        flow += aug;
    }
    return flow;
}
int ParseLine(const string &l){
    int a = l[0] - 'A';
    int n = l[1] - '0';
    anadir_arista(s_1, a, n);
    for (int i = 3; l[i] != ';'; i++){
        anadir_arista(a, comienzo + l[i] - '0', 1);
    }
    return n;
}

int main(){
    string line;
    while (getline(cin, line)){
        for (int i = 0; i <= s_2; i++)
            aristas[i].clear();
        for (int i = comienzo; i < s_1; i++)
            anadir_arista(i, s_2, 1);
        int cont = ParseLine(line);
        while (getline(cin, line) && line != ""){
            cont += ParseLine(line);
        }
        int flujo_max = acumulacion(s_1, s_2, cant_puntos);
        if (cont != flujo_max){
            cout << "!" <<endl;
        }
        else{
            for (int i = 0; i < 10; ++i){
                int c_1 = i + comienzo;
                if (aristas[c_1][0].c){
                    cout << '_';
                }
                else{
                    int i;
                    for (i = 1; !aristas[c_1][i].c; i++);
                    cout << (char)('A' + aristas[c_1][i].v);
                }
            }
            cout << endl;
        }
    }
}