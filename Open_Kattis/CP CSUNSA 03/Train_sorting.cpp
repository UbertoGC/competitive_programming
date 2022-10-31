#include <iostream>
#include <deque>
using namespace std;
template <class T>
int LIS(deque<T>& v) {
    if(v.size() == 0) return {};
    deque<int> p(v.size(), -1);
    deque<int> t(v.size(), 0);
    int lis = 1;
    for(int i = 1; i < v.size(); i++) {
        if(v[i] <= v[t[0]]) {
            t[0] = i;
        }
        else if(v[i] > v[t[lis - 1]]) {
            p[i] = t[lis - 1];
            t[lis++] = i;
        }
        else {
            int l = -1;
            int r = lis - 1;
            while(r - l > 1) {
                int m = l + (r - l) / 2;
                if(v[t[m]] >= v[i]) r = m;
                else l = m;
            }
            p[i] = t[r - 1];
            t[r] = i;
        }
    }
    deque<int> ans;
    for(int i = t[lis - 1]; i >= 0; i = p[i]) {
        ans.push_back(i);
    }
    return ans.size();
}
int main(){
    int n,alfa;
    cin>>n;
    int del=0;
    deque<int> datos(n);
    for (int i = 0; i < n; i++){
        cin>>datos[i];
    }
    int ans = 0;
    while(datos.size() > 0) {
        int centro = datos.front();
        datos.pop_front();

        deque<pair<int,int>> d1;
        deque<pair<int,int>> d2;

        for(auto i : datos) {
            if(i > centro) {
                int sz = d1.size();
                pair<int, int> del;
                del.first=i;
                del.second=sz;
                d1.push_back(del);
            }
        }
        for(auto i : datos) {
            if(i < centro) {
                int sz = d2.size();
                pair<int, int> del;
                del.first=-i;
                del.second=-sz;
                d2.push_back(del);
            }
        }
        ans = max(ans,int(1 + LIS(d1) + LIS(d2)));
    }

    cout << ans << endl;
}