#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
bool con[100][100];
int C[100][100];
int R[100][100];
int F[100][100];
bool visitado[100];
int flujo[100];
int conexion[100];
int BFS(int s,int t,int n){
	memset(visitado,false,sizeof(visitado));
	std::queue<int> Q;
	visitado[s]=true,conexion[s]=s,flujo[s]=2e9;
	Q.push(s);
	while(!Q.empty()){
		int i=Q.front();	Q.pop();
		for(int j=0;j<n;j++){
			if(R[i][j]>0&&!visitado[j]){
				visitado[j]=true;
				conexion[j]=i;
				if( flujo[i]>R[i][j] )
					flujo[j]=R[i][j];
				else
					flujo[j]=flujo[i];
				if(j==t)
					return flujo[t];
				else
					Q.push(j);
			}
		}
	}
	return 0;
}
int main(){
	int n;
	int caso = 0;
	while(cin>>n,n){
		memset(C,0,sizeof(C));
		int s,t,c;
		cin >> s >> t >> c;
		for(int i = 1;i < c+1; i++){
			int x,y,z;
			cin >> x >> y >> z;
			C[x-1][y-1] = C[y-1][x-1] += z;
		}
		int resultado;
        int f;
        s--;
        t--;
        memset(F,0,sizeof(F));
        memcpy(R,C,sizeof(C));
        for(resultado = 0; f=BFS(s,t,n) ; resultado+=f){
            for(int i = conexion[t],j = t; i != j ; j = i,i = conexion[i] ){
                F[i][j]+=f;
                F[j][i]-=F[i][j];
                R[i][j]=C[i][j]-F[i][j];
                R[j][i]=C[j][i]-F[j][i];
            }
        }
        caso++;
		cout<<"Network "<<caso<<endl;
		cout<<"The bandwidth is "<<resultado<<"."<<endl<<endl;
	}
	return 0;
}