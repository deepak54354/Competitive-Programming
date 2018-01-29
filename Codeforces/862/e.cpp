#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int n,m,q;
	cin >> n >> m >> q;
	vector<int> a(n+1),b(m+1);
	long long suma = 0,sumb = 0;
	vector<long long> range(m-n+1,0);
	for(int i = 1; i <= n;i++){
		cin >> a[i];
		suma += (2*(i&1)-1)*a[i];
	}
	for (int i = 1; i <= m; i++) cin >> b[i];

	for(int i = 1; i <= n; i++){
		range[0] += ((-2*(i&1)+1)*b[i]);
	}
	for(int j = 1; j <=m-n; j++){
		range[j] = -range[j-1] - b[j] + (1-2*(n&1))*b[n+j];
		// cout << range[j] << " ";
	}
	// cout << suma << endl;
	sort(all(range));
	auto lo = lower_bound(all(range),-suma);
	long long ans = abs(suma + range[lo-range.begin()]);
	if(lo-range.begin()!=0){
		ans = min(ans, abs(suma+ range[lo-range.begin()-1]));
	}
	cout << ans << "\n";
	while(q--){
		int l,r,x;
		cin >> l >> r >> x;
		if((r-l+1)&1){
			suma += 1ll*(2*(l&1)-1)*x; 
		}
		auto lo = lower_bound(all(range),-suma);
		long long ans = abs(suma + range[lo-range.begin()]);
		if(lo-range.begin()!=0){
			ans = min(ans, abs(suma+ range[lo-range.begin()-1]));
		}
		cout << ans << "\n";
	}
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}