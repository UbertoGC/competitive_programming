#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool comparacion(char i, char j){
    if(tolower(i) == tolower(j))
		return i<j;
	return tolower(i) < tolower(j);
}
int main() {
    int T;
    cin >> T;
    string S;
    while (T--) {
        cin.ignore();
        cin >> S;
        sort(S.begin(), S.end(),comparacion);
        cout << S << endl;
        while (next_permutation(S.begin(), S.end(),comparacion)) {
            cout << S << endl;
        }
    }
    return 0;
}