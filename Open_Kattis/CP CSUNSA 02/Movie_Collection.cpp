#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int st;
void update(int *arr,int i, int value) {
    while (i<=st) {
        arr[i] += value;
        i += i & -i;
    }
}
int sum(int *arr,int i) {
    int s = 0;
    while (i > 0) {
        s += arr[i];
        i -= i & (-i);
    }
    return s;
}
int* crear(int r, int m){
    st=r+m;
    int *arr=new int[st+1]{0};
    for (int i = r; i < st; i++)
        update(arr,i+1, 1);
    return arr;
}
void test_case(int m, int r, int* arr) {
    int *resul=crear(r,m);
    int *index_tracker=new int[m+1];
    for (int i = 1; i <= m; i++)
        index_tracker[i] = r+i;
    int first = 1;
    for (int i = 0; i < r; i++) {
        if (first)
            first = 0;
        else
            putchar(' ');
        cout<<sum(resul,index_tracker[arr[i]])-1;
        update(resul,index_tracker[arr[i]], -1);
        index_tracker[arr[i]] = r - i;
        update(resul,index_tracker[arr[i]], 1);
    }
    putchar('\n');
    delete resul;
}
int main() {
    int n;
    cin>>n;
    while(n--) {
        int m,r;
        cin>>m>>r;
        int *arr=new int[r];
        for (int i = 0; i < r; i++)
            cin>>arr[i];
        test_case(m,r,arr);
    }
    return 0;
}