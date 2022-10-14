#include <iostream>
using namespace std;
char dic[10][4]={{'.','*','*','*'},{'*','.','.','.'},{'*','.','*','.'},{'*','*','.','.'},{'*','*','.','*'},
{'*','.','.','*'},{'*','*','*','.'},{'*','*','*','*'},{'*','.','*','*'},{'.','*','*','.'}};
char braille[100][6];
char texto[100];
void braille_a_texto(int d){
    for (int i = 0; i < d; i++){
        if(braille[i][1]=='*'){
            if(braille[i][0]=='*'){
                if(braille[i][2]=='*'){
                    if(braille[i][3]=='*')
                        cout<<7;
                    else
                        cout<<6;
                }
                else{
                    if(braille[i][3]=='*')
                        cout<<4;
                    else
                        cout<<3;
                }
            }
            else{
                if(braille[i][3]=='*')
                    cout<<0;
                else
                    cout<<9;
            }
        }
        else{
            if(braille[i][2]=='*'){
                if(braille[i][3]=='*')
                    cout<<8;
                else
                    cout<<2;
            }
            else{
                if(braille[i][3]=='*')
                    cout<<5;
                else
                    cout<<1;
            }
        }
    }
    cout<<endl;
}
void texto_a_braille(int d){
    for (int k = 0; k < 5; k+=2){
        for (int i = 0; i < d; i++){
            if(k<4)
                cout<<dic[texto[i]-48][k]<<dic[texto[i]-48][k+1]<<"";
            else
                cout<<"..";
            if(i!=d-1)
                cout<<" ";
        }
        cout<<endl;
    }   
}
int main(){
    int D;
    char L;
    while(cin>>D){
        if(D==0)
            continue;
        cin>>L;
        if(L=='S'){
            for (int i = 0; i < D; i++)
                cin>>texto[i];
            texto_a_braille(D);
        }
        else{
            for (int j = 0; j < 5; j+=2){
                for (int i = 0; i < D; i++)
                    cin>>braille[i][j]>>braille[i][j+1];
            }
            braille_a_texto(D);
        }
    }
    return 0;
}