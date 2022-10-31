#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
typedef long long ll;
struct doll
{
    ll width;
    ll height;
};
bool comparar(const doll&d1,const doll&d2){
    if(d1.width==d2.width){
        return d1.height>d2.height;
    }
    return d1.width<d2.width;
}
int main(){
    int t;
    cin>>t;
    while (t--){
        int m;
        cin>>m;
        vector<doll> munecas(m);
        for (int i=0; i<m;i++){
            cin>>munecas[i].width>>munecas[i].height;
        }
        sort(munecas.begin(),munecas.end(),comparar);
        int k=0;
        deque<int> ord;
        for (int i = 0; i < m; i++){
            int pos=lower_bound(ord.begin(),ord.end(),munecas[i].height)-ord.begin();
            if(pos==0){
                ord.push_front(munecas[i].height);
            }
            else{
                ord[pos-1]=munecas[i].height;
            }
        }
        cout<<ord.size()<<endl;
    }
    return 0;
}