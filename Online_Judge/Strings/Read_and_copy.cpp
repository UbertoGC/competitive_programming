#include <iostream>
using namespace std;
int main(){
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		long numero;
		cin >> numero;
		long r_numero = 0;
        long a = numero;
        while (a){
            r_numero *= 10;
            r_numero += a % 10;
            a = a / 10;
        }
		int cont = 0;
		while (r_numero != numero){
			numero += r_numero;
            a = numero;
            r_numero = 0;
            while (a){
                r_numero *= 10;
                r_numero += a % 10;
                a = a / 10;
            }
		    cont++;
		}
		cout << cont << " " << numero << endl;
	}
}