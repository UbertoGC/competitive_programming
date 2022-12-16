#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define MAX  5009
vector <int> conecciones[MAX];
int T[MAX],  L[MAX];
bool visitado[MAX];
int M[MAX][13];
int N, Q;
void maching_maximum(int a){
    int b;
    queue <int> q;
    q.push(a);
    visitado[a] = true;
    while(!q.empty()){
        a = q.front();
        q.pop();
        for(int i = 0; i < conecciones[a].size(); i++){
            b = conecciones[a][i];
            if(visitado[b] == false){
                T[b] = a;
                L[b]  = L[a] + 1;
                visitado[b] = true;
                q.push(b);
            }
        }
    }
}
int LCA(int a, int b){
    if(L[a] < L[b])
        swap(a, b);
    int logaritmo = log2(L[a]);
    for(int i = logaritmo; i >= 0; i--)
        if(L[a] - (1 << i) >= L[b])
            a = M[a][i];
    if(a == b)
        return a;
    for(int i = logaritmo; i >= 0; i--)
        if(M[a][i] != -1 && M[a][i] != M[b][i]){
            a = M[a][i];
            b = M[b][i];
        }
    return T[a];
}
int kthNode(int c, int level){
    int logaritmo = log2(L[c]);
    for(int i = logaritmo; i >= 0; i--)
        if(L[c] - (1 << i) >= level)
            c = M[c][i];
    return c;
}
int main() {
    int a, b, lca, respuesta;
    while(scanf("%d", &N) && N){
        for(int  i = 1; i < N; i++){
            scanf("%d %d", &a, &b);
            conecciones[a].push_back(b);
            conecciones[b].push_back(a);
        }
        //Se reinicia todo el algoritmo
        for (int i = 0; i < MAX; i++){
            T[i] = -1;
            visitado[i] = false;
            for (int j = 0; j < 13; j++)
                M[i][j] = -1;
        }
        L[1] = 0;
        maching_maximum(1);
        for(int i = 1; i <= N; i++)
            M[i][0] = T[i];
        for(int j = 1; (1 << j) < N; j++)
            for(int i = 1; i <= N; i++)
                if(M[i][j-1] != -1)
                    M[i][j] = M[M[i][j-1]][j-1];
        scanf("%d", &Q);
        while(Q--){
            scanf("%d %d", &a, &b);
            lca = LCA(a, b);
            int dist = L[b] + L[a] - 2*L[lca];
            if(dist & 1){
                if(L[a] > L[b])
                    respuesta = kthNode(a, L[a] -  dist/2 );
                else
                    respuesta = kthNode(b, L[b] - dist/2 );
                printf("The fleas jump forever between %d and %d.\n", min(respuesta, T[respuesta]), max(respuesta, T[respuesta]));
            }
            else{
                if(L[a] > L[b])
                    respuesta = kthNode(a, L[a] - dist/2);
                else
                    respuesta = kthNode(b, L[b] - dist/2);
                printf("The fleas meet at %d.\n",respuesta);
            }
        }
        for(int i = 1; i <= N; i++)
            conecciones[i].clear();
    }
	return 0;
}