#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> mapa(2001, vector<int>(2001));
vector<vector<int>> cont_movimiento(2001, vector<int>(2001));
const int movimiento[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m1, m2;
    while (cin >> m1 && m1){
        for (int i = 0; i < 2001; i++){
            fill(mapa[i].begin(),mapa[i].end(),0);
            fill(cont_movimiento[i].begin(), cont_movimiento[i].end(), -1);
        }
        queue<pair<int,int>> ubicaciones;
        for(int i = 0; i < m1; ++i){
            int x;
		    int y;
			cin >> x >> y;
			mapa[x][y] = 1;
            cont_movimiento[x][y] = 0;
			ubicaciones.push({x,y});
		}
		cin >> m2;
		for(int i = 0; i < m2; ++i){
            int x;
		    int y;
			cin >> x >> y;
			mapa[x][y] = 2;
		}
        int distancia = 0;
        while (!ubicaciones.empty()){
            pair<int, int> valores = ubicaciones.front();
			ubicaciones.pop();
            if(mapa[valores.first][valores.second] == 2){
                distancia = cont_movimiento[valores.first][valores.second];
                break;
            }
            for(int i = 0; i < 4; ++i){
                int x = valores.first + movimiento[i][0];
                int y = valores.second + movimiento[i][1];

                if(x < 2000 && x > -1 && y < 2000 && y > -1 && cont_movimiento[x][y] == -1){
                    ubicaciones.push(make_pair(x, y));
                    cont_movimiento[x][y] = cont_movimiento[valores.first][valores.second] + 1;
                }
            }
        }
        cout << distancia << endl;
    }
    return 0;
}