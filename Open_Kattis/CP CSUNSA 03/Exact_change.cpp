#include<iostream>
using namespace std;
int billetes[100];
int limite_valor;
int limite_cant;
void calculo(int n, int objetivo, int pos=0,int cant=0){
    if(objetivo<=0){
        if(objetivo>limite_valor){
            limite_valor=objetivo;
            limite_cant=cant;
        }
        else if(objetivo==limite_valor){
            if(cant<limite_cant)
                limite_cant=cant;
        }
    }
    else{
        for (int i = pos; i < n; i++)
            calculo(n,objetivo-billetes[i],i+1,cant+1);
    }
}
int main() {
	int t,p,n;
    cin>>t;
    while (t--){
        cin>>p>>n;
        limite_valor=INT16_MIN;
        limite_cant=INT16_MAX;
        for (int i = 0; i < n; i++){
            cin>>billetes[i];
        }
        calculo(n,p);
        cout<<p+(limite_valor*-1)<<" "<<limite_cant<<endl;
    }
}