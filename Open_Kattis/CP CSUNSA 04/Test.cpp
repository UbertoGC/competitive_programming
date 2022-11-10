#include <iostream>
#include <vector>
#include <tuple>
#include <functional>
#include <algorithm>
#include <sstream>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(int T=0;;T++){
        int n,l,u,v;
        cin>>l;
        if(!l)break;
        vector<int> m(128);
        vector<tuple<int,int>> e;
        n=0;
        for(int i=0;i<l;i++){
            vector<int> x;
            char c;
            for(int j=0;j<5;j++){
                cin>>c;
                if(!m[c])m[c]=++n;
                x.push_back(m[c]-1);
            }
            cin>>c;
            if(!m[c])m[c]=++n;
            u=m[c]-1;
            for(int v:x)
                if(u!=v)e.emplace_back(u,v);
        }
        vector<int> r(n);
        for(int i=0;i<128;i++)
            if(m[i])
                r[m[i]-1]=i;
        vector<vector<int>> g(n),h(n),c;
        for(tuple<int,int> x:e){
            tie(u,v)=x;
            g[u].push_back(v);
            h[v].push_back(u);
        }
        vector<int> a,s(n),t(n);
        function<void(int)> dfs1=[&](int i){
            s[i]=1;
            for(int j:g[i])
                if(!s[j])dfs1(j);
            a.push_back(i);
        };
        for(int i=0;i<n;i++)
            if(!s[i])dfs1(i);
        reverse(a.begin(),a.end());
        function<void(int)> dfs2=[&](int i){
            t[i]=1;
            c.back().push_back(i);
            for(int j:h[i])
                if(!t[j])dfs2(j);
        };
        for(int i=0;i<a.size();i++)
            if(!t[a[i]]){
                c.push_back(vector<int>());
                dfs2(a[i]);
            }
        vector<string> q;
        for(vector<int>&x:c){
            vector<int> p;
            for(int i:x)
                p.push_back(r[i]);
            sort(p.begin(),p.end());
            stringstream o;
            for(int i=0;i<p.size();i++){
                o<<char(p[i]);
                if(i<p.size()-1)o<<" ";
            }
            q.push_back(o.str());
        }
        sort(q.begin(),q.end());
        if(T)
            cout<<"\n";
        for(auto &s:q)
            cout<<s<<"\n";
    }
}