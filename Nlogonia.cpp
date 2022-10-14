#include <iostream>
using namespace std;
int der[100010],izq[100010];
int main(){
    int S, B;
    while(cin>>S>>B, S>0&&S<=100000&&B>0&&B<=S){
        for (int i = 1; i <= S; i++){
            der[i]=i+1;
            izq[i]=i-1;
        }
        izq[1]=-1;
        der[S]=-1;
        int L,R;
        for (int j = 0; j < B; j++){
            cin>>L>>R;
            izq[der[R]] = izq[L];
            if (izq[L] != -1)
                cout<<izq[L];
            else
                cout<<("*");
            der[izq[L]] = der[R];
            if (der[R] != -1)
                cout<<" "<<der[R]<<endl;
            else
                cout<<" *"<<endl;
        }
        cout<<"-\n";
    }
}