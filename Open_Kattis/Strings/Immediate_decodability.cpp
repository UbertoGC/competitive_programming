#include <iostream>
#include <vector>
using namespace std;
bool procesar(vector<string> &datos){
    bool det = true;
    for (int i = 0; i < datos.size()-1 && det; i++)
        for (int j = i+1; j < datos.size() && det; j++){
            string a = datos[i];
            string b = datos[j];
            if(a.size() != b.size()){
                bool prefijo = true;
                int minimo = min(a.size(),b.size());
                for (int k = 0; k < minimo && prefijo; k++)
                    if(b[k] != a[k])
                        prefijo = false;
                det = !prefijo;
            }
        }
    return det;
}
int main(){
    string linea;
    vector<string> datos;
    int cont=1;
    while (cin>>linea){
        if(linea[0] == '9'){
            cout<<"Set "<<cont;
            if(procesar(datos))
                cout<<" is immediately decodable"<<endl;
            else
                cout<<" is not immediately decodable"<<endl;
            datos.clear();
            cont++;
        }
        else{
            datos.push_back(linea);
        }
    }
    return 0;
}