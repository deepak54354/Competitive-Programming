#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const long long m = 1000000007;

long long mod(long long a){
	if(a >=m) return a-m;
	if(a < 0) return a+m;
	return a;	
}

void solve(){
	int n,q;
	cin >> n >> q;
	vector<long long> a(q+1,0);
	vector<long long> b(n+2,0);
	int type[q+1];
	int l[q+1];
	int r[q+1];
	for(int i = 1; i <=q; i++){
		cin >> type[i] >> l[i] >> r[i];
	}
	long long curr = 1;
	for(int i = q; i>=1; i--){
		if(type[i]==2){
			a[r[i]]=mod(a[r[i]]+curr);
			a[l[i]-1]= mod(a[l[i]-1]-curr);
		}
		curr = mod(curr+a[i-1]);
	}
	a[q]=1;
	for(int i = q-1; i >= 1; i--){
		a[i] = mod(a[i]+a[i+1]);
	}
	for(int i = 1; i <= q; i++){
		if(type[i]==1){
			b[l[i]]=mod(b[l[i]]+a[i]);
			b[r[i]+1]=mod(b[r[i]+1]-a[i]);
		}
	}
	for(int i = 1; i <=n; i++){
		b[i] = mod(b[i]+b[i-1]);
	}
	for(int i = 1; i < n+1; i++){
		cout << mod(b[i]) << " ";
	}
	cout << "\n";
}

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}