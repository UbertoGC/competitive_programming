#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> contar_letras(string p){
    vector<int> contador_de_letras(26,0);
    for (string::const_iterator iter = p.begin(); iter != p.end(); ++iter)
        contador_de_letras[tolower(*iter) - 'a']++;
    return contador_de_letras;
}
bool igualdad(const vector<int>& first, const vector<int>& second){
    for (int i = 0; i < 26; ++i)
        if (first[i] != second[i])
            return false;
    return true;
}
int main(){
    string p;
    vector<string> palabras;
    vector<vector<int> > contador_de_letras;
    while (cin >> p, p != "#"){
        palabras.push_back(p);
        contador_de_letras.push_back(contar_letras(p));
    }
    vector<bool> es_anagrama(palabras.size(), true);
    for (int i = 0; i < palabras.size(); ++i)
        if (es_anagrama[i])
            for (int j = i + 1; j < palabras.size(); ++j)
                if (igualdad(contador_de_letras[i], contador_de_letras[j])){
                    es_anagrama[i] = false;
                    es_anagrama[j] = false;
                }
    vector<string> anagramas_resultado;
    for (int i = 0; i < palabras.size(); ++i)
        if (es_anagrama[i])
            anagramas_resultado.push_back(palabras[i]);
    sort(anagramas_resultado.begin(), anagramas_resultado.end());
    for (int i = 0; i < anagramas_resultado.size(); ++i)
        cout << anagramas_resultado[i] << '\n';
}