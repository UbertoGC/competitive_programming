#include <iostream>
using namespace std;
char tablero[100][100];
int main(){
    int t;
    int n;
    int test=0;
    cin>>t;
    while (t--){
        test++;
        cin>>n;
        int boats=0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin>>tablero[i][j];
            }
        }
        int i=0;
        int j=0;
        while (i<n){
            if(tablero[i][j]=='v'){
                j++;
            }
            else if(tablero[i][j]!='.'){
                bool m=false;
                bool det=true;
                if(i<n-1)
                    if(tablero[i+1][j]!='.')
                        det=false;
                if(j<n-1)
                    if(tablero[i][j+1]!='.')
                        det=true;
                if(det){
                    while (j<n&&tablero[i][j]!='.'){
                        if(tablero[i][j]=='x')
                            m=true;
                        tablero[i][j]='v';
                        j++;
                    }
                }
                else{
                    int a_i=i;
                    while (a_i<n&&tablero[a_i][j]!='.'){
                        if(tablero[a_i][j]=='x')
                            m=true;
                        tablero[a_i][j]='v';
                        a_i++;
                    }
                    j++;
                }
                if(m)
                    boats++;
            }
            j++;
            if(j>=n){
                j=0;
                i++;
            }
        }
        cout<<"Case "<<test<<": "<<boats<<endl;
    }
    return 0;
}