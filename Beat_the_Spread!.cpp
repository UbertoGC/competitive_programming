#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int t,s,d,x,y;
	cin>>t;
	while(t--){
		cin>>s>>d;
		x=(s+d)/2;
		y=s-x;
		if (((s+d)%2!=0)||(x+y!=s)||(abs(x-y)!=d)||x<0||y<0)
			cout<<"impossible"<<endl;
		else
			cout<<max(x, y)<<" "<<min(x, y)<<endl;
	}
	return 0;
}