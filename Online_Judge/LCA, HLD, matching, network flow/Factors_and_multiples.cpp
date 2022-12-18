#include <iostream>
#include <vector>
using namespace std;
vector<int> puntos;
vector<bool> visitado;
vector<vector<int>> adjunto;

int Calc(int l) {
	if (visitado[l])
		return 0;
	visitado[l] = 1;
	for (int j = 0; j < (int) adjunto[l].size(); j++) {
		int r = adjunto[l][j];
		if (puntos[r] == -1 || Calc(puntos[r])) {
			puntos[r] = l;
			return 1;
		}
	}
	return 0;
}

int main() {
	int T;
    int caso = 0;
	int n, m;
    int valor, v_l;
	int a[105], b[105];
	cin>>T;
	while (T--) {
		cin>>n;
		for (int i = 0; i < n; i++) {
			cin>>a[i];
		}
		cin>>m;
		for (int i = 0; i < m; i++) {
			cin>>b[i];
		}
		valor = n + m;
		v_l = n;
		adjunto.assign(valor, vector<int>());
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] != 0){
					if (b[j] == 0 || b[j] % a[i] == 0)
						adjunto[i].push_back(j + n);
				} 
                else if(a[i] == 0 && b[j] == 0){
					adjunto[i].push_back(j + n);
				}
			}
		}
		int MCBM = 0;
		puntos.assign(valor, -1);
		for (int l = 0; l < v_l; l++) {
			visitado.assign(v_l, 0);
			MCBM += Calc(l);
		}
        caso++;
        cout<<"Case "<<caso<<": "<<MCBM<<endl;
	}
	return 0;
}