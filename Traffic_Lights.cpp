#include<cstdio>
#include<vector>
using namespace std;
bool allLightsOn(vector<int> &v, int time){
	bool result = false;
	int changeOrange = 0;
	int hits = 0;
	for(int i = 0; i < v.size(); ++i){
		if(time % (v[i]*2) < (v[i] - 5))
			++hits;
		if(time > v[i])
				changeOrange++;
	}
	if(hits == v.size() && changeOrange > 0) result = true;
	return result;
}
int main(){
	int x, y, z;
	while(scanf("%d%d%d", &x, &y, &z) == 3 && (x || y || z)){
		vector<int> lights;
		lights.push_back(x);
		lights.push_back(y);
		while(z != 0){
			lights.push_back(z);
			scanf("%d", &z);
		}
		bool found = false;
		int time = 0;
		for(int i = 1; i <= 18000 && !found; ++i){
			if(allLightsOn(lights, i)){
				found = true;
				time = i;
			}
		}
		if(found){
			int hours = time / 3600;
			time %= 3600;
			int minutes = time / 60;
			time %= 60;
			int seconds = time;
			printf("%02d:%02d:%02d\n", hours, minutes, seconds);
		}
		else
			printf("Signals fail to synchronise in 5 hours\n");
	}
	return 0;
}