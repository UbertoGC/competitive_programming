#include<iostream>
using namespace std;
int main(){
    int L;
    string operacion;
    while (cin>>L,L>0){
        int punt=1;
        for (int j = 1; j <=L-1; j++){
            cin>>operacion;
            if(operacion[0]=='-'){
                if(operacion[1]=='z'){
                    if(punt==1)
                        punt=6;
                    else if(punt==2)
                        punt=5;
                    else if(punt==5)
                        punt=1;
                    else if(punt==6)
                        punt=2;
                }  
                else{
                    if(punt==1)
                        punt=4;
                    else if(punt==2)
                        punt=3;
                    else if(punt==3)
                        punt=1;
                    else if(punt==4)
                        punt=2;
                }
            }
            else if(operacion[0]=='+'){
                if(operacion[1]=='y'){
                    if(punt==1)
                        punt=3;
                    else if(punt==2)
                        punt=4;
                    else if(punt==3)
                        punt=2;
                    else if(punt==4)
                        punt=1;
                }
                else{
                    if(punt==1)
                        punt=5;
                    else if(punt==2)
                        punt=6;
                    else if(punt==5)
                        punt=2;
                    else if(punt==6)
                        punt=1;
                }
            }
            else{};
        }
        switch (punt){
        case 1:
            cout<<"+x"<<endl;
            break;
        case 2:
            cout<<"-x"<<endl;
            break;
        case 3:
            cout<<"+y"<<endl;
            break;
        case 4:
            cout<<"-y"<<endl;
            break;
        case 5:
            cout<<"+z"<<endl;
            break;
        default:
            cout<<"-z"<<endl;
            break;
        }
    }
    return 0;
}