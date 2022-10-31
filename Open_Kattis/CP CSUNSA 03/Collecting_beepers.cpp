#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
	int t,x,y,sx,sy,n;
	cin >> t;
	while(t--) {
		vector<pair<int, int>> points;
		cin >> x >> y;
		cin >> sx >> sy;
		cin >> n;
		while(n--) {
			cin >> x >> y;
			points.push_back(make_pair(x,y));
		}
		sort(points.begin(), points.end());
		int minD = 1e9;
		do {
			int d = 0;
			pair<int, int> curr = make_pair(sx, sy);
			for(auto const &p : points) {
				d += abs(curr.first - p.first);
				d += abs(curr.second - p.second);
				curr = p;
			}
			d += abs(sx - curr.first);
			d += abs(sy - curr.second);
			minD = min(minD, d);
		} while (next_permutation(points.begin(), points.end()));
		cout << minD << endl;
	}
}