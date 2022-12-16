#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    string palabra;
    cin >> N;
    while (N--){
        cin >> palabra;
        int maximo = palabra.size();
        int i;
        for (i = 1; i <= maximo; i++){
            if(maximo % i == 0){
                int division = maximo/i;
                int arr[division];
                for (int j = 0; j < division; j++){
                    arr[j] = j*i;
                }
                bool logrado = true;
                for (int k = 0; k < i && logrado; k++){
                    for (int j = 1; j < division && logrado; j++){
                        if(palabra[arr[0]] != palabra[arr[j]])
                            logrado = false;
                        arr[j]++;
                    }
                    arr[0]++;
                }
                if(logrado)
                    break;
            }
        }
        cout<<i<<endl;
        if(N)
            cout<<endl;
    }
    return 0;
}