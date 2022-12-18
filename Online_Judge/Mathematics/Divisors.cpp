#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int l,u;
        double temp,cont;
        int num = 0;
        int numd = 0;
        cin >> l >> u;
        for(int i=l;i<=u;i++){
            temp = pow(i,0.5);
            cont = 0;
            for(int j = 1; j <= temp; j++){
                if(i%j==0){
                    cont++;
                    if(j < temp)
                        cont++;
                }
            }
            if(cont > numd){
                numd = (int)cont;
                num = i;
            }
        }
        cout<<"Between "<<l<<" and "<<u<<", "<<num<<" has a maximum of "<<numd<<" divisors."<<endl;
    }
    return 0;
}