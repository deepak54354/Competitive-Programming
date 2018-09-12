#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define int2 long long

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int2 n;
	cin >> n;

	int2 k = n/2;

	vector<int2> v(n);
	multiset<int2> toS;
	multiset<int2> toNS;

	int2 moves = 0;

	int2 nums = 0;

	for(int2 i = 0; i < n; i++){
		cin >> v[i];
		int2 sq = floor(sqrt(double(v[i])));
		if(sq*sq == v[i]){
			nums++;
			if(v[i] == 0)
				toNS.insert(2);
			else
				toNS.insert(1);
		}
		else{
			toS.insert(min(v[i]-sq*sq, (sq+1)*(sq+1)-v[i]));
		}
	}

	if(nums == k){
		cout << 0 << '\n';
		return;
	}

	else if(nums < k){
		int m = k-nums;
		int i = 0;
		for(auto j: toS){
			if(i >= m)
				break;
			moves += j;
			i++;
		}
	}
	else{
		int i = 0;
		int m = nums-k;
		for(auto j: toNS){
			if(i >= m)
				break;
			moves+=j;
			i++;
		}
	}
	cout << moves << '\n';
}	

int main(){
	fast_io;
	int2 t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}