#include<iostream>
#include <map>
using namespace std;
map<char, char> reverso;
void rellenar(){
    reverso['A'] = 'A'; reverso['E'] = '3'; reverso['H'] = 'H'; reverso['I'] = 'I'; reverso['J'] = 'L';
    reverso['L'] = 'J'; reverso['M'] = 'M'; reverso['O'] = 'O'; reverso['S'] = '2'; reverso['T'] = 'T';
    reverso['U'] = 'U'; reverso['V'] = 'V'; reverso['W'] = 'W'; reverso['X'] = 'X'; reverso['Y'] = 'Y';
    reverso['Z'] = '5'; reverso['1'] = '1'; reverso['2'] = 'S'; reverso['3'] = 'E'; reverso['5'] = 'Z';
    reverso['8'] = '8';
}
bool es_palindromo(string &a){
    int i=0;
    int j=a.size()-1;
    while (i<j){
        if(a[i] != a[j])
            return false;
        i++;
        j--;
    }
    return true;
}
bool es_palabra_espejo(string &a){
    string r_a="";
    for (int i = 0; i < a.size(); i++){
        if(reverso.find(a[i])==reverso.end())
            return false;
        r_a+=reverso[a[i]];
    }
    int i=0;
    int j=a.size()-1;
    while (j>=0){
        if(a[i] != r_a[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int main(){
    string palabra;
    rellenar();
    while (cin>>palabra){
        bool palindromo=es_palindromo(palabra);
        bool palabra_espejo=es_palabra_espejo(palabra);
        if(palindromo && palabra_espejo)
            cout<<palabra<<" -- is a mirrored palindrome."<<endl;
        else if(palindromo)
            cout<<palabra<<" -- is a regular palindrome."<<endl;
        else if(palabra_espejo)
            cout<<palabra<<" -- is a mirrored string."<<endl;
        else
            cout<<palabra<<" -- is not a palindrome."<<endl;
        cout<<endl;
    }
    return 0;
}
