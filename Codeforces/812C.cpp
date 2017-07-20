#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
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
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(ll i = a; i < b; i++)
#define FORD(i,a,b) for(ll i = b; i >= a; i--)
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

ll n,s;
vll price;
ll cost = 0;
void update(ll k, vll v){
	for(ll i= 0; i < n; i++){
		price[i] = v[i]*1LL+((i+1)*k)*1LL;		
	}
}
ll possible(ll k, vll v){
	update(k,v);
	sort(price.begin(),price.end());
	ll c = 0*1LL;
	FOR(i,0,k) c += price[i]*1LL;
	if(c > s) return -1;
	else return c; 
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	cin >> n >> s;
	vll v(n);
	FOR(i,0,n) cin >> v[i];
	price.resize(n);
	ll left = 0; ll right = n;
	while(left<=right){
		ll mid = left+(right-left)/2;
		ll c = possible(mid,v)*1LL;
		if(c != -1){
			left = mid+1;
			cost = c;
		}
		else right = mid-1;
	}
	cout << right << " " << cost << endl;
	return 0;
}