#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
#include <unordered_map>
using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] == -1) {
        return a;
    }
    d[a] = find(d, d[a]);
    return d[a];
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);
    if(a == b)
        return;
    d[a] = b;
}

void dfs1(vector<vector<int>>& down, unordered_set<int>& vis, stack<int>& r, int curr) {
    vis.insert(curr);
    for(auto i : down[curr]) {
        if(vis.count(i) == 0) {
            vis.insert(i);
            dfs1(down, vis, r, i);
        }
    }
    r.push(curr);
}

void dfs2(vector<vector<int>>& top, unordered_set<int>& vis, stack<int>& r, vector<int>& dis, int curr) {
    for(auto i : top[curr]) {
        if(vis.count(i) == 0) {
            join(dis, curr, i);
            vis.insert(i);
            dfs2(top, vis, r, dis, i);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cases;
    cin >> cases;

    while(cases--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> down(n);
        vector<vector<int>> top(n);
        vector<pair<int, int>> aristas;
        for(int i = 0; i < m; i++) {
            int n1, n2;
            cin >> n1 >> n2;
            n1--;
            n2--;
            down[n1].push_back(n2);
            top[n2].push_back(n1);
            aristas.push_back({n1, n2});
        }


        unordered_set<int> vis;
        stack<int> reciente;
        for(int i = 0; i < n; i++) {
            if(vis.count(i) > 0) {
                continue;
            }
            dfs1(down, vis, reciente, i);
        }

        vector<int> dis(n, -1);
        unordered_map<int, int> deg;

        vis.clear();
        while(!reciente.empty()) {
            int d = reciente.top();
            reciente.pop();
            vis.insert(d);
            dfs2(top, vis, reciente, dis, d);
        }

        for(int i = 0; i < dis.size(); i++) {
            deg[find(dis, i)] = 0;
        }

        for(auto i : aristas) {
            if(find(dis, i.first) != find(dis, i.second)) {
                deg[find(dis, i.second)]++;
            }
        }

        int total = 0;
        for(auto i : deg) {
            if(i.second == 0) {
                total++;
            }
        }

        cout << total << endl;
    }
}