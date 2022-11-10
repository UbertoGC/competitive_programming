#include <iostream>
using namespace std;
int arr[12];
int guard[6];
void conversor(int k,int &k_real, int min=0){
    if(k<6){
        for (int i = min; i <k_real; i++){
            guard[k]=arr[i];
            conversor(k+1,k_real,i+1);
        }
    }
    else{
        for (int i = 0; i < k; i++){
            cout<<guard[i];
            if(i<k-1)
                cout<<" ";
            else{
                cout<<endl;
            }
        }
    }
}
int main(){
    int k;
    bool primero=true;
    while (cin>>k, k!=0){
        if(!primero){
            cout<<endl;
        }
        primero=false;
        for (int i = 0; i < k; i++){
            cin>>arr[i];
        }
        conversor(0,k);
    }
    return 0;
}