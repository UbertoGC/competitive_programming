#include<iostream>
using namespace std;
int jack[1000000];
int jill[1000000];
int main(){
    int N,M;
    cin>>N>>M;
    while ((N!=0&&M!=0)){
        for (int i = 0; i < N; i++){
            cin>>jack[i];
        }
        for (int i = 0; i < M; i++){
            cin>>jill[i];
        }
        int i1=0,i2=0,cont=0;
        while(i1!=N&&i2!=M){
            if(jack[i1]<jill[i2]){
                i1++;
            }
            else if(jack[i1]==jill[i2]){
                cont++;
                i1++;
                i2++;
            }
            else{
                i2++;
            }
        }
        cout<<cont<<endl;
        cin>>N>>M;
    }
    return 0;
}