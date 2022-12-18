#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <bitset>
using namespace std;
#define INF 1e9
int r[105][105];
int f, s, t;
int resultado;
vector<vector<int>> adjunto;
vector<int> p;
int m, w, V;
void operacion(int v, int arista) {
	if (v == s) {
		f = arista;
		return;
	}
    else if (p[v] != -1) {
		operacion(p[v], min(arista, r[p[v]][v]));
		r[p[v]][v] -= f;
		r[v][p[v]] += f;
	}
}

void EKarps() {
	resultado = 0;
	while (1) {
		f = 0;
		bitset<105> visitado;
		visitado.set(s);
		queue<int> q;
		q.push(s);
		p.assign(105, -1);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
				break;
			for (int i = 0; i < (int) adjunto[u].size(); i++) {
				int v = adjunto[u][i];
				if (r[u][v] > 0 && !visitado.test(v)) {
					visitado.set(v);
					q.push(v);
					p[v] = u;
				}
			}
		}
		operacion(t, INF);
		if (f == 0)
			break;
		resultado += f;
	}
}

int main() {
	while (cin >> m >> w, m || w) {
		V = m * 2 - 2;
		memset(r, 0, sizeof r);
		adjunto.assign(V, vector<int>());
		s = 0;
		t = V - 1;
		for (int i = 0; i < m - 2; i++) {
			int id, c, u, v;
			cin >> id >> c;
			id--;
			u = id + id - 1;
			v = u + 1;
			r[u][v] = c;
			adjunto[u].push_back(v);
			adjunto[v].push_back(u);
		}
		for(int i = 0; i < w; i++){
			int id1, id2, c; 
            int a_1, a_2, b_1, b_2;
            cin >> id1 >> id2 >> c;
			id1--;
			id2--;
			if(id1 != 0 && id1 != m - 1){
				a_1 = id1 + id1 - 1;
				b_1 = a_1 + 1;
			}
            else{
				if (id1 == 0)
					a_1 = b_1 = 0;
				else
					a_1 = b_1 = V - 1;
			}
			if(id2 != 0 && id2 != m - 1){
				a_2 = id2 + id2 - 1;
				b_2 = a_2 + 1;
			} 
            else{
				if (id2 == 0)
					a_2 = b_2 = id2;
				else
					a_2 = b_2 = V - 1;
			}
			r[b_1][a_2] = c;
			r[b_2][a_1] = c;
			adjunto[b_1].push_back(a_2);
			adjunto[a_2].push_back(b_1);
			adjunto[b_2].push_back(a_1);
			adjunto[a_1].push_back(b_2);
		}
		EKarps();
		cout << resultado << endl;
	}
	return 0;
}