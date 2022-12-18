#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9
vector<vector<int>> adjunto;
vector<int> puntos, distancia;
int V, V_l;
bool bfs() {
	queue<int> cola;
	for (int i = 1; i <= V_l; i++) {
		if (puntos[i] == 0) {
			distancia[i] = 0;
			cola.push(i);
		}
        else
			distancia[i] = INF;
	}
	distancia[0] = INF;
	while (!cola.empty()) {
		int u = cola.front();
		cola.pop();
		if (u != 0) {
			for (int i = 0; i < adjunto[u].size(); i++) {
				int v = adjunto[u][i];
				if (distancia[puntos[v]] == INF) {
					distancia[puntos[v]] = distancia[u] + 1;
					cola.push(puntos[v]);
				}
			}
		}
	}
	return (distancia[0] != INF);
}
bool dfs(int u) {
	if (u != 0) {
		for (int i = 0; i < adjunto[u].size(); i++) {
			int v = adjunto[u][i];
			if (distancia[puntos[v]] == distancia[u] + 1) {
				if (dfs(puntos[v])) {
					puntos[v] = u;
					puntos[u] = v;
					return true;
				}
			}
		}
		distancia[u] = INF;
		return false;
	}
	return true;
}
int hopkarp() {
	puntos.assign(V, 0);
	distancia.assign(V, 0);
	int m = 0;
    int i;
	while (bfs())
		for (i = 1; i <= V_l; i++)
			if (puntos[i] == 0 && dfs(i))
				m++;
	return m;
}
int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	int N, nueces;
    int caso = 0;
	int f, b;
	cin >> N;
	while (N--) {
		cin >> b >> nueces;
		V = b + nueces + 1;
		V_l = b;
		adjunto.assign(V, vector<int>());
		for (int i = 1; i <= b; i++) {
			for (int n = 1; n <= nueces; n++) {
				cin >> f;
				if (f)
					adjunto[i].push_back(n + b);
			}
		}
		int MCBM = hopkarp();
        caso++;
		cout<<"Case "<<caso<<": "<<"a maximum of "<<MCBM<<" nuts and bolts "<<"can be fitted together"<<endl;
	}
	return 0;
}