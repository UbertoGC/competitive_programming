#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int r,c;
    cin >> r >> c;
    char mapa[r][c];
    queue<pair<int,int>> Joe;
    queue<pair<int,int>> fuego;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> mapa[i][j];
            if(mapa[i][j] == 'J'){
                Joe.push({i,j});
            }
            else if (mapa[i][j] == 'F'){
                fuego.push({i,j});
            }
        }
    }
    int cont = 0;
    bool detener = false;
    while(!Joe.empty()){
        int m = Joe.size();
        while (m--){
            int x=Joe.front().first;
            int y=Joe.front().second;
            Joe.pop();
            if(mapa[x][y] != 'F'){
                if(y == 0 || x == 0 || x == r-1 || y == c-1){
                    cont++;
                    detener = true;
                    break;
                }
                else{
                    if(mapa[x+1][y] == '.'){
                        Joe.push({x+1,y});
                        mapa[x+1][y] = 'J';
                    }
                    if(mapa[x-1][y] == '.'){
                        Joe.push({x-1,y});
                        mapa[x-1][y] = 'J';
                    }
                    if(mapa[x][y+1] == '.'){
                        Joe.push({x,y+1});
                        mapa[x][y+1] = 'J';
                    }
                    if(mapa[x][y-1] == '.'){
                        Joe.push({x,y-1});
                        mapa[x][y-1] = 'J';
                    }
                }
            }
        }
        if(detener)
            break;
        m = fuego.size();
        while (m--){
            int x = fuego.front().first;
            int y = fuego.front().second;
            fuego.pop();
            if(x+1 < r && (mapa[x+1][y] == '.'|| mapa[x+1][y] == 'J')){
                fuego.push({x+1,y});
                mapa[x+1][y] = 'F';
            }
            if(x-1 >= 0 && (mapa[x-1][y] == '.'|| mapa[x-1][y] == 'J')){
                fuego.push({x-1,y});
                mapa[x-1][y] = 'F';
            }
            if(y+1 < c && (mapa[x][y+1] == '.'|| mapa[x][y+1] == 'J')){
                fuego.push({x,y+1});
                mapa[x][y+1] = 'F';
            }
            if(y-1 >= 0 && (mapa[x][y-1] == '.'|| mapa[x][y-1] == 'J')){
                fuego.push({x,y-1});
                mapa[x][y-1] = 'F';
            }
        }
        cont++;
    }
    if(detener)
        cout << cont << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}