#include <iostream>
#include <vector>
#include <list>
using namespace std;
struct Rooted_Tree
{
    int m=0;
    bool revisado=false;
    vector<int>hijos;
};
Rooted_Tree arbol[10000];
int main(){
    int n;
    int cont=0;
    while(cin>>n,n&&(cont<10)){
        int v,d,h;
        bool es_hijo[n]{0};
        for (int j = 0; j < n; j++){
            cin>>v;
            v--;
            cin>>arbol[v].m;
            cin>>d;
            arbol[v].hijos.clear();
            arbol[v].revisado=false;
            for (int k = 0; k < d; k++){
                cin>>h;
                h--;
                arbol[v].hijos.push_back(h);
                es_hijo[h]=true;
            }
        }
        list<int>cola;
        for (int i = 0; i < n; i++){
            if(!es_hijo[i]){
                cola.push_back(i);
            }
        }
        int movimiento=0;
        while(!cola.empty()){
            int pri=cola.front();
            if (arbol[pri].hijos.size() == 0){
                arbol[pri].m=arbol[pri].m-1;
                arbol[pri].revisado=true;
                movimiento+= abs(arbol[pri].m);
                cola.erase(cola.begin());
            }
            else{
                bool d=true;
                int med=0;
                for (int j = 0; j < arbol[pri].hijos.size(); j++){
                    if(!(arbol[arbol[pri].hijos[j]].revisado)){
                        d=false;
                        cola.push_front(arbol[pri].hijos[j]);
                    }
                    else{
                        med+=arbol[arbol[pri].hijos[j]].m;
                    }
                }
                if(d){
                    arbol[pri].m=(med + arbol[pri].m - 1);
                    movimiento+=abs(arbol[pri].m);
                    arbol[pri].revisado=true;
                    cola.erase(cola.begin());
                }
            }
        }
        cout<<movimiento<<endl;
        cont++;
    }
    return 0;
}