#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n,m;
    int a,b;
    cin >> n >> m;
    int top[n]{0};
    vector<vector<int>> down(n);
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        down[a-1].push_back(b-1);
        top[b-1]++;
    }
    queue<int> valores;
    vector<int> resultado;
    for (int i = 0; i < n; i++){
        if(top[i] == 0)
            valores.push(i);
    }
    while (!valores.empty()){
        int d = valores.front();
        valores.pop();
        resultado.push_back(d+1);
        for (int j = 0; j < down[d].size(); j++){
            top[down[d][j]]--;
            if(top[down[d][j]] == 0){
                valores.push(down[d][j]);
            }
        }
    }
    if(resultado.size() < n){
        cout << "IMPOSSIBLE\n";
    }
    else{
        for (int i = 0; i < resultado.size(); i++){
            cout << resultado[i] << endl;
        }
    }
    return 0;
}