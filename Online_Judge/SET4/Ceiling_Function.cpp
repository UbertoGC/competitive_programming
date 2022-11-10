#include <iostream>
#include <queue>
using namespace std;

int ceiling[50][20];
int hijoder[50][20];
int hijoizq[50][20];
int mediador[50];
int n,k;
int main(){
    while (scanf("%d %d", &n, &k) == 2){
        int cont = 0;
        int m;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < k; j++){
                scanf("%d", &ceiling[i][j]);
                hijoder[i][j] = -1;
                hijoizq[i][j] = -1;
                if(j != 0){
                    m = 0;
                    while(1){
                        if(ceiling[i][m] > ceiling[i][j]){
                            if(hijoizq[i][m] == -1){
                                hijoizq[i][m] = j;
                                break;
                            }
                            else{
                                m = hijoizq[i][m];
                            }
                        }
                        else if(ceiling[i][m] < ceiling[i][j]){
                            if(hijoder[i][m] == -1){
                                hijoder[i][m] = j;
                                break;
                            }
                            else
                                m = hijoder[i][m];
                        }
                    }
                }
            }
            if(cont == 0){
                mediador[0] = i;
                cont++;
            }
            else{
                bool det = true;
                for (int z = 0; z < cont; z++){
                    queue<int> col;
                    queue<int> col1;
                    det=true;
                    col.push(0);
                    col1.push(0);
                    while (!col.empty() || !col1.empty()){
                        bool izq = false, der = false;
                        int indice = col.front();
                        int indice1 = col1.front();
                        col.pop();
                        col1.pop();
                        if((hijoder[i][indice] != -1 && hijoder[mediador[z]][indice1] != -1) ||
                            (hijoder[i][indice] == -1 && hijoder[mediador[z]][indice1] == -1)){
                            der = true;
                        }
                        else{
                            der = false;
                        }
                        if((hijoizq[i][indice] != -1 && hijoizq[mediador[z]][indice1] != -1) ||
                            (hijoizq[i][indice] == -1 && hijoizq[mediador[z]][indice1] == -1)){
                            izq = true;
                        }
                        else{
                            izq = false;
                        }
                        if(der && izq){
                            if(hijoder[i][indice] != -1){
                                col.push(hijoder[i][indice]);
                                col1.push(hijoder[mediador[z]][indice1]);
                            }
                            if(hijoizq[i][indice] != -1){
                                col.push(hijoizq[i][indice]);
                                col1.push(hijoizq[mediador[z]][indice1]);
                            }
                        }
                        else{
                            det=false;
                            break;
                        }
                    }
                    if(det){
                        break;
                    }
                }
                if(!det){
                    mediador[cont] = i;
                    cont++;
                }
            }
        }
        printf("%d\n", cont);
    }
    return 0;
}