#include <iostream>
#include <cstring>
using namespace std;
struct Matrix{
    int A[2][2];
    Matrix(){}
    Matrix operator * (Matrix B){
        Matrix C;
        memset(C.A,0,sizeof C.A);
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k < 2; k++)
                    C.A[i][j] += A[i][k] * B.A[k][j];
                C.A[i][j] %= 10000;
            }
        }
        return C;
    }
    Matrix pow(int n){
        Matrix ret,aux = *this;
        ret.A[0][0] = 1;
        ret.A[0][1] = 0;
        ret.A[1][0] = 0;
        ret.A[1][1] = 1;
        while(n){
            if(n & 1) ret = ret * aux;
            aux = aux * aux;
            n >>= 1;
        }
        return ret;
    }
};
int main(){
    Matrix M,P;
    M.A[0][0] = 1;
    M.A[0][1] = 1;
    M.A[1][0] = 1;
    M.A[1][1] = 0;
    int T;
    int a,b;
    int n,m;
    cin >> T;
    while(T--){
        cin >> a >> b,
        cin >> n >> m;
        int resultado = a;
        if(n > 0){
            P = M.pow(n - 1);
            resultado = P.A[0][0] * b + P.A[0][1] * a;
        }
        switch (m){
        case 1:
            resultado %= 10;
            break;
        case 2:
            resultado %= 100;
            break;
        case 3:
            resultado %= 1000;
            break;
        case 4:
            resultado %= 10000;
            break;
        }
        cout << resultado << endl;
    }
    return 0;
}