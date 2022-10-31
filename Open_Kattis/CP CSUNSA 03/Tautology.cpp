#include <iostream>
#include <vector>
using namespace std;
int pos=0;
string m;
vector<int> cont;
bool det=true;
bool delimitador[26];
bool analizador(){
    bool a;
    bool b;
    switch (m[pos]){
    case 'K':
        pos++;
        a=analizador();
        pos++;
        b=analizador();
        return(a && b);
        break;
    case 'A':
        pos++;
        a=analizador();
        pos++;
        b=analizador();
        return(a || b);
        break;
    case 'N':
        pos++;
        a=analizador();
        return(!a);
        break;
    case 'C':
        pos++;
        a=analizador();
        pos++;
        b=analizador();
        return((!a) || b);
        break;
    case 'E':
        pos++;
        a=analizador();
        pos++;
        b=analizador();
        return(a == b);
        break;
    default:
        return delimitador[m[pos]-'a'];
        break;
    }
}
void cantidades(int m){
    for (int i = 1; i >=0; i--){
        delimitador[cont[m]-'a']=i;
        if(m!=0){
            cantidades(m-1);
        }
        else{
            pos=0;
            det=det && analizador();
        }
    }
}
int main(){
    while(cin>>m,m[0]!='0'){
        cont.clear();
        for (int i = 0; i < m.size(); i++){
            if((m[i]>='a' && m[i]<='z') && !(delimitador[m[i]-'a'])){
                cont.push_back(m[i]);
                delimitador[m[i]-'a']=true;
            }
        }
        det=true;
        cantidades(cont.size()-1);
        for (int i = 0; i < cont.size(); i++)
            delimitador[cont[i]-'a']=false;
        if(det)
            cout<<"tautology"<<endl;
        else
            cout<<"not"<<endl;
    }
    return 0;
}