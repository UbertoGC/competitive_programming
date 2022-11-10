#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int encontrar(vector<int>& d, int a) {
    if(d[a] == -1)
        return a;
    d[a] = encontrar(d, d[a]);
    return d[a];
}
void unir(vector<int>& d, int a, int b) {
    a = encontrar(d, a);
    b = encontrar(d, b);
    if(a == b)
        return;
    d[a] = b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int,int>>> v;
    for(int i = 0; i < m; i++) {
        int n1, n2, w;
        cin >> n1 >> n2 >> w;
        v.push_back({w, {n1,n2}});
    }
    sort(v.begin(), v.end());
    int mejor = 0;
    vector<int> d(n, -1);
    for(auto i : v) {
        if(encontrar(d, i.second.first) != encontrar(d, i.second.second)) {
            unir(d, i.second.first, i.second.second);
            mejor = max(mejor, i.first);
        }
    }
    for(int i = 1; i < d.size(); i++) {
        if(encontrar(d, i-1) != encontrar(d, i)) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    cout << mejor << endl;
}