#include <iostream>
using namespace std; 
int T[1000005];
void KMP(string & n){
    int tamano = n.size();
    T[0] = -1;
    T[1] = 0;
    int posicion = 2;
    int i = 0;
    while (posicion < tamano){
        if (n[posicion - 1] == n[i]){
            i++;
            T[posicion] = i;
            posicion++;
        }
        else if (i > 0){
            i = T[i];
        }
        else{
            T[posicion] = 0;
            posicion++;
        }
    }
}
int main(){
    string n;
    while (cin >> n, n[0]!='.'){
        KMP(n);
        int inicio = n.size() - 1;
        int final = T[inicio];
        if (final != -1 && n[final] != n[inicio])
            final = min(0, final - 1);
        int longitud = inicio - final;
        cout << (n.size() / longitud) << '\n';
    }
    return 0;
}