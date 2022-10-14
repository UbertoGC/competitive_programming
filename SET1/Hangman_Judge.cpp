#include <iostream>
using namespace std;
int main(){
    int ronda,strikes;
    string objetivo,respuesta;
    while(cin>>ronda,ronda!=-1){
        cin>>objetivo>>respuesta;
        strikes=0;
        cout<<"Round "<<ronda<<endl;
        for (int i = 0; i < respuesta.size(); i++){   
            bool encontrado=false;
            for (int j = 0; j < objetivo.size(); j++){
                if(respuesta[i]==objetivo[j]){
                    encontrado=true;
                    objetivo.erase(j,1);
                    j--;
                }
            }
            if(!encontrado)
                strikes++;
            if(strikes==7){
                cout<<"You lose."<<endl;
                break;
            }
            if(objetivo.empty()){
                cout<<"You win."<<endl;
                break;
            }
            if(i==respuesta.size()-1)
                cout<<"You chickened out."<<endl;
        }
    }
    return 0;
}