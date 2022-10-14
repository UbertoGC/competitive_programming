#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main() {
	int n, c;
	cin>>n;
	map<vector<int>, int> frecuencias;
	for (int i = 0; i < n; i++) {
		vector<int> estudiante;
		for (int j = 0; j < 5; j++) {
			cin >> c;
			estudiante.push_back(c);
		}
		sort(estudiante.begin(), estudiante.end());
		frecuencias[estudiante]++;
	}
	int maximo = 0;
	for (auto combinacion : frecuencias) 
		maximo = max(combinacion.second, maximo);
	int total = 0;
	for (auto combinacion : frecuencias) 
		total = total+(combinacion.second == maximo ? maximo : 0);
	cout<<total<<endl;
	return 0;
}