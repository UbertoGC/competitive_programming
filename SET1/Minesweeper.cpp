#include <iostream>
using namespace std;
char mapa[100][100];
int main(){
    int m,n;
    int field=1;
    cin>>n>>m;
    while (m!=0&&n!=0){
        if(field!=1)
            cout<<endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin>>mapa[i][j];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++){
                if(mapa[i][j]=='*'){
                    if(i+1<n){
                        if(j+1<m){
                            if(mapa[i+1][j+1]=='.')
                                mapa[i+1][j+1]='1';
                            else if(mapa[i+1][j+1]!='*')
                                mapa[i+1][j+1]++;
                        }
                        if(mapa[i+1][j]=='.')
                            mapa[i+1][j]='1';
                        else if(mapa[i+1][j]!='*')
                            mapa[i+1][j]++;
                        if(j-1>=0){
                            if(mapa[i+1][j-1]=='.')
                                mapa[i+1][j-1]='1';
                            else if(mapa[i+1][j-1]!='*')
                                mapa[i+1][j-1]++;
                        }
                    }
                    if(j+1<m)
                        if(mapa[i][j+1]=='.')
                            mapa[i][j+1]='1';
                        else if(mapa[i][j+1]!='*')
                            mapa[i][j+1]++;
                    if(j-1>=0)
                        if(mapa[i][j-1]=='.')
                            mapa[i][j-1]='1';
                        else if(mapa[i][j-1]!='*')
                            mapa[i][j-1]++;
                    if(i-1>=0){
                        if(j+1<m){
                            if(mapa[i-1][j+1]=='.')
                                mapa[i-1][j+1]='1';
                            else if(mapa[i-1][j+1]!='*')
                                mapa[i-1][j+1]++;
                        }
                        if(mapa[i-1][j]=='.')
                            mapa[i-1][j]='1';
                        else if(mapa[i-1][j]!='*')
                            mapa[i-1][j]++;
                        if(j-1>=0){
                            if(mapa[i-1][j-1]=='.')
                                mapa[i-1][j-1]='1';
                            else if(mapa[i-1][j-1]!='*')
                                mapa[i-1][j-1]++;
                        }
                    }
                }
                else if(mapa[i][j]=='.')
                    mapa[i][j]='0';
                else{continue;}
            }
        cout<<"Field #"<<field<<":"<<endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                cout<<mapa[i][j];
            cout<<endl;
        }
        cin>>n>>m;
        field++;
    }
    return 0;
}