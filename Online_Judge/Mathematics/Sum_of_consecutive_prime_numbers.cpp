#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
vector<ll>primos;
bool visitado[10050];
void numeros_primos(){
    primos.push_back(2);
    for (ll i = 4; i < 10021; i += 2){
        visitado[i] = true;
    }
    for (ll i = 3; i < 10021; i += 2){
        if (!visitado[i]){
            primos.push_back(i);
            for (ll j = i*i; j < 10021; j += 2*i){
                visitado[j] = true;
            }
        }
    }
}
int main(){
    numeros_primos();
    ll n;
    ll suma,a;
    while(cin >> n, n){
        a = 0;
        for (ll i = 0; primos[i] < n+1; i++){
            suma = primos[i];
            for (ll j = i+1; suma < n; j++){
                suma += primos[j];
            }
            if(suma == n){
                a++;
            }
        }
        printf("%lld\n",a);
    }
    return 0;
}