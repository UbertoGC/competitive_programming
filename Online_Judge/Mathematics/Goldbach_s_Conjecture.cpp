#include<iostream>
using namespace std;
int m[1000000]{0};
int p[100000];
int Pt = 0;
int main(){
	int n;
	for(int i = 3; i < 1000000; i += 2) 
		if(m[i] == 0) {
			p[Pt++] = i;
			for(int j = 3; i*j < 1000000; j += 2)
				m[i*j] = 1;
		}
	while(cin >> n, n) {
		int x, y;
		bool det = false;
		for(int i = 0; i < Pt; i++) {
			x = p[i], y = n-p[i];
			if(x > y)	break;
			if(m[x] == 0 && m[y] == 0) {
				cout << n << " = " << x << " + " << y << endl;
				det = true;
				break;
			}
		}
		if(!det)
			puts("Goldbach's conjecture is wrong.");
	}
    return 0;
}