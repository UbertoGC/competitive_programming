#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <bitset>
using namespace std;
#define INF 1e9
int p[10010];
int s, t, resultado, n, nc, nf;
pair<int,int> ids[101][101];
int res[10010][10010], tw[10010], distancia[10010];
vector<int> grafo[10010];
bitset<10010> s_arista;
bitset<10010> t_arista;
char mapa[101][101];
void fil_cont(){
    for (int f=0; f<n; f++){
        bool det = 0;
        for (int c=0; c<n; c++){
            if (mapa[f][c] == '.' && !det){
                ids[f][c] = pair<int,int>(nf++, 0);
                det = 1;
            }
            else if (mapa[f][c] == 'X'){
                det=0;
            }
            else{
                ids[f][c] = pair<int,int>(ids[f][c-1].first, 0);
            }
        }
    }
}
void col_cont(){
    for (int c=0; c<n; c++){
        bool det = 0;
        for (int f=0; f<n; f++){
            if (mapa[f][c] == '.' && !det){
                ids[f][c].second = nc++;
                det = 1;
            }
            else if (mapa[f][c] == 'X'){
                det=0;
            } 
            else{
                ids[f][c].second = ids[f-1][c].second;
            }
        }
    }
}
void crear_grafo(){
    for (int f = 0; f<n; f++)
        for (int c =0; c<n; c++){
            if (mapa[f][c] != 'X'){
                int u = ids[f][c].first;
                int v = ids[f][c].second;
                grafo[u].push_back(v);
                grafo[v].push_back(u);
                res[u][v] = 1;
                res[v][u] = 0;
                if (!s_arista[u]){
                    grafo[s].push_back(u);
                    grafo[u].push_back(s);
                    res[s][u] = 1;
                    res[u][s] = 0;
                    s_arista[u]=1;
                }
                if (!t_arista[v]){
                    grafo[v].push_back(t);
                    grafo[t].push_back(v);
                    res[v][t] = 1;
                    res[t][v] = 0;
                    t_arista[v] = 1;
                }
            }            
        }
}
int dinic_dfs(int u, int flow){
    if (u==t) 
        return flow;
    for (int &i = tw[u]; i < (int) grafo[u].size(); i++){
        int v = grafo[u][i];
        if ((res[u][v] > 0) && (distancia[v] == distancia[u] + 1)){
            int df = dinic_dfs(v, min(flow, res[u][v]) );
            if (df > 0){
                res[u][v] -= df; res[v][u] += df;
                return df;
            } 
        }
            
    }
    return 0;
}
bool dinic_bfs(){
    memset(distancia, -1, sizeof distancia);
    distancia[s] = 0;
    queue<int> q; q.push(s);
    while(!q.empty()){
        int u = q.front(); q.pop();
        for (int i = 0; i < grafo[u].size(); i++){
            int v = grafo[u][i];
            if (distancia[v] < 0 && res[u][v])
                distancia[v] = distancia[u] + 1, q.push(v);
        }
    }
    return distancia[t] >= 0;  
}
int f_max(){
    int result = 0;
    while(dinic_bfs()){
        memset(tw, 0, sizeof tw);
        while (int delta = dinic_dfs(s, INF)) 
            result += delta;
    }
    return result;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    while(cin >> n){
        s = 0;
        t = 10009;
        nf = 1;
        nc = 5001;
        for (int i = 0; i <= t; i++) grafo[i].clear();
        s_arista.reset();
        t_arista.reset();
        for (int i=0; i<n; i++) 
            cin >> mapa[i];
        fil_cont();
        col_cont();
        crear_grafo();
        resultado = f_max();
        cout << resultado << endl;
    }
    return 0;
}