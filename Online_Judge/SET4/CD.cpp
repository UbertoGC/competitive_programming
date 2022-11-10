#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int p[20];
int sumant;
int p2[20];
int resul[20];
int limitc;
int n;
int track_1;
void RC_BU(int track, int obj, int k=0){
    if(obj==0||track==track_1){
        if(sumant>obj){
            for (int i = 0; i < k; i++)
                p2[i]=resul[i];
            limitc=k;
            sumant=obj;
        }
        else if(sumant==obj && k>limitc){
            for (int i = 0; i < k; i++)
                p2[i]=resul[i];
            limitc=k;
        }
    }
    else{
        bool m=false;
        for (int i = track; i < track_1; i++){
            if((obj-p[i])>=0){
                resul[k]=p[i];
                RC_BU(i+1,obj-p[i],k+1);
            }
            else
                m=true;
        }
        if(m){
            if(sumant>obj){
                for (int i = 0; i < k; i++)
                    p2[i]=resul[i];
                limitc=k;
                sumant=obj;
            }
            else if(sumant==obj && k>limitc){
                for (int i = 0; i < k; i++)
                    p2[i]=resul[i];
                limitc=k;
            }
        }
    }
}
int main(){
    while(cin>>n){
        cin>>track_1;
        for (int i = 0; i < track_1; i++){
            cin>>p[i];
        }
        limitc=0;
        sumant=n;
        RC_BU(0,n);
        int resul=0;
        for (int i = 0; i < limitc; i++){
            resul+=p2[i];
            cout<<p2[i]<<" ";
        }
        cout<<"sum:"<<resul<<endl;
    }
    return 0;
}