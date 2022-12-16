#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct nivelador{
    int nivel;
    int rebotes;
    bool dir;
};
int main(){
    int n,cont;
    while(cin>>n){
        cont = 0;
        queue<nivelador> medio;
        nivelador primero;
        primero.nivel = 1;
        primero.rebotes = n;
        primero.dir = true;
        medio.push(primero);
        while(!medio.empty()){
            nivelador a = medio.front();
            medio.pop();
            if(a.rebotes == 0){
                cont++;
            }
            else{
                if(a.nivel!=0){
                    nivelador b;
                    b.nivel=a.nivel-1;
                    b.dir=false;
                    b.rebotes=a.rebotes;
                    if(a.dir){
                        b.rebotes--;
                    }
                    medio.push(b);
                }
                if(a.nivel!=2){
                    nivelador b;
                    b.nivel=a.nivel+1;
                    b.dir=true;
                    b.rebotes=a.rebotes;
                    if(!a.dir){
                        b.rebotes--;
                    }
                    medio.push(b);
                }
            }
        }
        cout<<cont<<endl;
    }
    return 0;
}