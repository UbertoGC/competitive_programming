#include<iostream>
#include<algorithm>
using namespace std;
int LCS(string s1,string s2){
 	int i,j;
 	int lcs[s1.size()+1][s2.size()+1];
 	for(i=0;i<=s1.size();i++){
        for(j=0;j<=s2.size();j++){
            if(i==0 || j==0) {
                lcs[i][j]=0;	  
            }
            else if(s1[i-1]==s2[j-1]){
                lcs[i][j]=lcs[i-1][j-1]+1;
            }
            else {
                lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
            }
        }
    }
	return lcs[s1.size()][s2.size()];
}
int main() {
	string a,b;
	while(getline(cin,a)){
        getline(cin,b);
        cout<<LCS(a,b)<<endl;
	}
    return 0;
}