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
	if(base == 0) return 0;
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

ll inv(ll a, ll p){
	return fast_exp(a,p-2,p);
}

ll mod(ll a, ll b){
  ll c = a % b;
  return (c < 0) ? c + b : c;
}

const int N = 2010;
void solve(){
	int a;
	cin >> a;
	ll fact[N];
	fact[0]=1;
	for(int i = 1; i < N; i++)
		fact[i] = mod(1ll*fact[i-1]*i,MOD);
	ll n,k,dp;
	dp = 1; n = k =0;
	cin >> n;
	for(int i = 1;i < a; i++){
		int b;
		cin >> b;
		k = b-1;
		dp = mod(dp*(fact[n+k]%MOD)*(inv(fact[n],MOD)%MOD)*(inv(fact[k],MOD)%MOD),MOD);
		cout << dp << endl;
		n+=b;
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