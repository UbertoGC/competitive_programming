#include <iostream>
using namespace std;
int main(){
    int T,n,v,x;
    int mov[100];
    string op;
    cin>>T;
    if(T>100)
        return 0;
    for (int i = 0; i < T; i++){
        x=0;
        cin>>n;
        if(1<=n&&n<=100){
            for (int j = 0; j < n; j++){
                cin>>op;
                if(op=="LEFT"){s
                    x--;
                    mov[j]=-1;
                }
                else if (op=="RIGHT"){
                    x++;
                    mov[j]=1;
                }
                else{
                    cin>>op>>v;
                    x+=mov[v-1];
                    mov[j]=mov[v-1];
                }
            }
            cout<<x<<endl;
        }       
    }
    return 0;
}