#include <iostream>
using namespace std;
int array[26]={0,1,2,3,0,1,2,0,0,2,2,4,5,5,0,1,2,6,2,3,0,1,0,2,0,2};
int main(){
    string m;
    while(cin>>m){
        if(m.size()>0){
            int c=-1;
            if(array[m[0]-'A']!=0){
                c=array[m[0]-'A'];
                cout<<array[m[0]-'A'];
            }
            for (int i = 1; i < m.size(); i++){
                if (array[m[i]-'A'] != 0 && array[m[i]-'A'] != c)
                    cout<<array[m[i]-'A'];
                if (array[m[i]-'A'] == 0)
                    c=-1;
                else 
                    c=array[m[i]-'A'];
            }
            cout<<endl;
        }
    }
    return 0;
}