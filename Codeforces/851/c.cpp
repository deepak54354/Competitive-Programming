#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int n;
	cin >> n;
	if(n > 12){
		cout << 0 << endl;
		return;
	}
	int a[n+1][5];
	for(int i = 0 ; i < n ; i++){
		for(int j = 0; j < 5; j++){
			cin >> a[i][j];
		}
	}
	vector<int> v;
	for(int i = 0; i < n; i++)
	{
		bool flag = true;
		for(int j = 0; j<n; j++)
		{
			if(j == i) continue;
			for(int k = 0; k < n; k++)
			{
				if(k == i or k == j) continue;
				long long dot=0.0;
				for(int m = 0; m < 5; m++)
				{
					dot += (a[i][m]-a[j][m])*(a[i][m]-a[k][m]);
				}
				if(dot > 0)
				{
					flag = false;
					break;
				}
			}
		}
		if(flag) v.push_back(i+1);
	}
	cout << v.size() << "\n";
	for(auto i : v) cout << i << '\n';
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}