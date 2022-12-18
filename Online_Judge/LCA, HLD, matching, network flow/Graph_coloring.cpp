#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int grafo[101][101];
int mt[101];
int tmp[101];
int resultados[101];
int L_max;
int cant[101];
int n, m;
void DFS(int punto, int a, int b) {
    if(a + b == n || punto == n+1) { 
        if(a > L_max) {
            L_max = a;
            for(int i = 0; i < L_max; i++)
                resultados[i] = tmp[i];
        }
        return;
    }  
    if(cant[punto] == 0) {
        int n_b = b;
        int r[n];
        int idx = 0;
        for(int i = 0; i < mt[punto]; i++) {
            if(cant[grafo[punto][i]] == 0) {
                cant[grafo[punto][i]] = 1;
                n_b++;
                r[idx++] = grafo[punto][i];
            }
        }
        tmp[a] = punto;
        DFS(punto + 1, a + 1, n_b);
        for(int i = 0; i < idx; i++)
            cant[r[i]] = 0;
    }
    DFS(punto + 1, a, b + (!cant[punto]));
}
int main() {
    int T;
    int i, x, y;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        memset(mt, 0, sizeof(mt));
        memset(cant, 0, sizeof(mt));
        for(i = 0; i < m; i++) {
            cin >> x >> y;
            grafo[x][mt[x]++] = y;
            grafo[y][mt[y]++] = x;
        }
        L_max = 0;
        DFS(1, 0, 0);
        cout << L_max << endl;
        for(i = 0; i < L_max-1; i++)
            cout << resultados[i] << " ";
        cout << resultados[i] << endl;
    }
    return 0;
}