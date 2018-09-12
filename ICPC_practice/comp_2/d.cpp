#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int n,k,r;
	cin >> n >> k >> r;
	set<int> s;
	int cam[n+1]={0};
	while(k--){
		int l;
		cin >> l;
		s.insert(l);
		cam[l]=1;
	}
	int j = r;
	int ans=0;
	for(int i = 1, j=r; j <= n; i++,j++)
	{   auto low = s.lower_bound(i);
		if(low == s.end() or *low > j){
			s.insert(j);
			s.insert(j-1);
			ans+=2;
			cam[j]=cam[j-1]=1;
			//cout << i << " " << j << endl;
			continue;
		}
		auto hi = s.upper_bound(*low);
		if(hi == s.end() or *hi > j){
			if(cam[j]==0){
				s.insert(j);
				cam[j]=1;
			}
			else{
				s.insert(j-1);
				cam[j-1]=1;
			}
			ans++;
			//cout << i << " " << j << endl;
		}
	}
	cout << ans << "\n";
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}