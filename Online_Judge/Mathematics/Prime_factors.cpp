#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
int main(){
    vector<int> primos(4792);
    vector<bool> isPrime(46340, true);
    primos[0] = 2;
    int pos = 1;
    int n;
    for (ll i = 3; i < 46340; i += 2){
        if (isPrime[i]){
            for (ll j = i * i; j < 46340; j += i){
                isPrime[j] = false;
            }
            primos[pos] = i;
            pos++;
        }
    }
    while (cin >> n, n){
        cout << n << " =";
        bool ocurrencia = false;
        if (n < 0){
            n *= -1;
            cout << " -1";
            ocurrencia = true;
        }
        else if (n == 1){
            cout << " 1";
        }
        for (int pos = 0; primos[pos] * primos[pos] <= n && pos < 4792; ++pos){
            while ((n % primos[pos]) == 0){
                if (ocurrencia){
                    cout<< " x ";
                }
                else{
                    cout << " ";
                }
                cout << primos[pos];
                ocurrencia = true;
                n /= primos[pos];
            }
        }
        if (n > 1){
            if (ocurrencia){
                cout << " x ";
            }
            else{
                cout << " ";
            }
            cout << n;
        }
        cout<<endl;
    }
}