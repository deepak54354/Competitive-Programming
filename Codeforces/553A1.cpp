#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
const ll MOD = 1e9+7;
ll fast_exp(ll base,ll n, ll M)
{
	ll ans = 1;
	while(n)
	{
		if(n%2==1)
		ans = (ans*base)%M;
		base = (base*base)%M;
		n = n>>1;
	}
	return ans%M;
}

ll mod(ll a, ll b){
	if(a<0) return mod(a+b,b);
	else if(a >= b) return a%b;
	else return a;
}

const int N = 2010;
ll ncr[N][N];

void solve(){
	int a;
	cin >> a;

// precompute ncr 
	for(int i = 0; i< N; i++){
		for(int j = 0; j <=i; j++){
			if(j==0 or j == i)
				ncr[i][j] = 1;
			else if(j == 1)
				ncr[i][j] = i;
			else
				ncr[i][j] = mod(ncr[i-1][j-1] + ncr[i-1][j],MOD);
		}
	}
	ll dp,n,k;
	dp = 1;n = k = 0;
	cin >> n;
	for(int i = 1; i < a; i++){
		int b;
		cin >> b;
		k = b-1;
		// cout << n+k-1 << " " << k-1 << " " << ncr[n+k-1][k-1] << endl;
		dp = mod(dp*ncr[n+k][k],MOD);
		n += b;
		// cout << dp << endl;
	}
	cout << dp << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}