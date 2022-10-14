#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int P;
    while (cin>>P,P!=0){
        cout<<"Printing order for "<<P<<" pages:"<<endl;
        if (P == 1)
            cout<<"Sheet 1, front: Blank, 1"<<endl;
        else{
            int numPages = P/4;
            if (numPages*4 < P)
                ++numPages;
            int numberSkipped = numPages*4 - P;
            for (int i = 0; i < numPages; ++i){
                int frontFirstPage = P - i*2 + numberSkipped;
                int frontSecondPage = i*2 + 1;
                if (frontFirstPage <= P)
                    cout<<"Sheet "<<i+1<<", front: "<<frontFirstPage<<", "<<frontSecondPage<<endl<<"Sheet "<<i+1<<", back : "<<frontSecondPage + 1<<", "<<frontFirstPage - 1<<""<<endl;
                else if (frontFirstPage - 1 <= P)
                    cout<<"Sheet "<<i+1<<", front: Blank, "<<frontSecondPage<<endl<<"Sheet "<<i+1<<", back : "<<frontSecondPage + 1<<", "<<frontFirstPage - 1<<endl;
                else
                    cout<<"Sheet "<<i+1<<", front: Blank, "<<frontSecondPage<<endl<<"Sheet "<<i+1<<", back : "<<frontSecondPage + 1<<", Blank"<<endl;
            }
        }
    }
    return 0;
}