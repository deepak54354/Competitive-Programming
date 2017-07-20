#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MOD (ll)(1e9 + 7)
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector< vector<int> >
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define ul unsigned long
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif
ll mod(ll a, ll b) // calculates a%b, not remainder
{
	ll ans;
	if(b == 0)
		return -1;
	else
	{
		ans = (a<0 ? mod(((a%b)+b),b) : a%b);
	}
	return ans;
}
vi minprime(5000010,0);
void sieve(ll N)
{
  bool prime[N+1];
  for(ll i = 0; i < N+1; i++)
    prime[i] = true;
  prime[0]=false;
  prime[1]=false;
  ll end = sqrt(N);
  for(ll i = 2; i < end; i++)
  {
    if(prime[i])
    {
      for(int j = i*i; j <N; j += i){
      	prime[j] = false;
      	if(minprime[j]==0) minprime[j]=i;
      }
    }
  }
  for(int i = 2; i < N; i++){
  	if(prime[i]) minprime[i]=i;
  }
}
ll fast_exp(ll base,ll n)
{
  ll ans = 1;
  while(n)
  {
    if(n%2==1)
      ans = (ans*base)%MOD;

    base = (base*base)%MOD;
    n = n>>1;
  }
  return ans%MOD;
}
ll pre(ll i){
	ll tempans = 0;
	while(i>1){
		ll m = minprime[i];
		tempans += (i*(m-1))/2;
		i/=m;
	}
	return tempans;
}
void solve(){
	ll p,l,r;
	ll ans = 0;
	cin >> p >> l >> r;
	sieve((ll)5e6+8);
	for(ll i = r; i >=l;i--){
		ans=(ans*p + pre(i))%MOD;
		//cout << i << " "<<pre(i) << endl;
	}
	cout << ans << endl;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t=1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}