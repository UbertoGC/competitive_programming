#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int g[56][56];
int N;
struct arista{
    int a,  b;
    arista(int x, int y): a(x), b(y){}
};
vector <arista>  ls;
void dfs(int i){
    for(int v = 1; v <= N; v++)
        if(g[i][v]){
            g[i][v]--;
            g[v][i]--;
            dfs(v);
            ls.push_back(arista(i, v));
        }
}
int main(){
    int T;
    int E;
    int x, y;
    int caso = 0;
    int d[56];
    cin>>T;
    while(T--){
        cin>>E;
        N = 0;
        memset(d, 0, sizeof(d));
        memset(g, 0, sizeof(g));
        for(int e = 1; e <= E; e++){
            cin>>x>>y;
            g[x][y]++;
            g[y][x]++;
            d[x]++;
            d[y]++;
            N = max(max(x, y), N);
        }
        bool ruta = false;
        for(int v = 1; v <= N; v++){
            if(d[v] & 1)ruta = true;
            break;
        }
        caso++;
        cout<<"Case #"<<caso<<endl;
        ls.clear();
        if(!ruta ){
            dfs(N);
            if( ls.size() != E || ls[0].b != ls[(int)ls.size()-1].a){
                cout<<"some beads may be lost"<<endl;
            }
            else{
                for(int l = (int)ls.size()-1; l >= 0; l--){
                    cout<<ls[l].a<<" "<< ls[l].b <<endl;
                }
            }
        }
        else{
            cout<<"some beads may be lost"<<endl;
        }
        if(T){
            puts("");
        }
    }
    return 0;
}