#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int k = 1;
	while(1){
		int n;
		cin >> n;
		if(n==0) return;
		if(n<2){
			cout << "Photo " << k << ": ";
			cout << n << " points eliminated" << "\n";
			k++;
			return;
		}
		vector<int> x(n),y(n);
		for(int i = 0; i < n ;i++){
			cin >> x[i] >> y[i];
		}
		int cur,maxPoint,vertical;
		cur=maxPoint=vertical=0;
		map<pair<int,int>, int> slope;
		for(int i =0; i < n;i++){
			cur = vertical=0;
			for(int j = i+1; j < n; j++){
				if(x[i]==x[j]) vertical++;
				else{
					int X = (x[i]-x[j]);
					int Y = (y[i]-y[j]);
					int g = __gcd(X,Y);

					X/=g;
					Y/=g;

					slope[{X,Y}]++;
					cur = max(cur,slope[{X,Y}]);
				}
				cur = max(cur,vertical);
			}
			maxPoint= max(cur+1,maxPoint);
			slope.clear();
		}
		maxPoint=maxPoint>=4?maxPoint:0;
		cout << "Photo " << k << ": ";
		cout << maxPoint << " points eliminated" << "\n";
		k++;
	}
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	solve();
}