#include <iostream>
using namespace std;
int main(){
    int T,amp,fre;
    string resul[] = {"", "1", "22", "333", "4444", "55555", "666666", "7777777", "88888888", "999999999"};
    cin>>T;
    while (T!=0){
        cin>>amp>>fre;
        if(amp>=9){
            while(fre){
                int j=1;
                for (; j < amp; j++){
                    cout<<resul[j]<<endl;
                }
                for (; j >0; j--){
                    cout<<resul[j]<<endl;
                }
                if(fre!=1)
                    cout<<endl;
                fre--;
            }
            if(T!=1)
                cout<<endl;
        }
        T--;
    }
    return 0;
}