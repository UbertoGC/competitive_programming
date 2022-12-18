#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N, M;
vector<int> a[400];
vector<int> b[400];
int unir[400];
int marca[400];
int mat[400];
bool included[40][10];
int n_fila;
int m_fila;
int dfs(int i) {
    if (i < 0) return 1;
    for (int j : a[i]) {
        if (!marca[j]++ && dfs(mat[j]))
            return unir[mat[j] = i] = 1;
    }
    return 0;
}
void marcar(){
    memset(unir, 0, sizeof unir);
    memset(mat, -1, sizeof mat);
    memset(marca, 0, sizeof marca);
    for (int i = 0; i < N; i++) {
        for (int j : a[i]) {
            if (mat[j] < 0) {
                unir[mat[j] = i] = 1;
                break;
            }
        }
    }
    for (int i = 0; i < N; ++i){
        if(!unir[i] && dfs(i)) 
            memset(marca, 0, sizeof marca);
    }
    for (int i = 0; i < N; ++i){
        if(!unir[i]) 
            dfs(i);
    }
}
int arista_cont() {
    marcar();
    int cont = 0;
    for (int i = 0; i < M; ++i) {
        if (mat[i] >= 0 || b[i].size()) {
            cont++;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (!unir[i] && a[i].size()) {
            cont++;
        }
    }
    return cont;
}
int obtener_indice(int r, int c) {
    bool isN = (r + c) % 2 == 0;
    return r * (isN ? n_fila : m_fila) + c / 2;
}
vector<pair<int,int>> cambios = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int main() {
    int T;
    cin >> T;
    while (T--) {
        int fila, columna;
        cin >> fila >> columna;
        n_fila = columna / 2 + 1;
        m_fila = columna / 2 + 1;
        N = n_fila * fila;
        M = m_fila * fila;
        for (int i = 0; i < N; ++i)
            a[i].clear();
        for (int i = 0; i < M; ++i)
            b[i].clear();
        string l;
        for (int f = 0; f < fila; ++f) {
            cin >> l;
            for (int c = 0; c < columna; ++c) {
                included[f][c] = (l[c] == '*');
            }
        }
        int cont = 0;
        for (int f = 0; f < fila; ++f) {
            for (int c = 0; c < columna; ++c) {
                if (included[f][c]){
                    bool det = (f + c) % 2 == 0;
                    int index = obtener_indice(f, c);
                    vector<int>* current = b + index;
                    if(det)
                        current = a + index;
                    int beside = 0;
                    for (auto i : cambios) {
                        int nueva_fil = f + i.first;
                        int nueva_col = c + i.second;
                        if (nueva_fil >= 0 && nueva_fil < fila && nueva_col >= 0 && nueva_col < columna && included[nueva_fil][nueva_col]) {
                            current->push_back(obtener_indice(nueva_fil, nueva_col));
                            ++beside;
                        }
                    }
                    if (beside == 0)
                        cont++;
                }
            }
        }
        cont += arista_cont();
        cout << cont << endl;
    }
}