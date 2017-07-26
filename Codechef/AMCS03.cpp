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
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).begin(),(v).end()
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
int n,k;
vector<double> S,D,f;
double update(double x){
	//cout << "x: " << x << endl;
	FOR(i,0,n){
		f[i] = S[i]*x+D[i];
		//cout << "f[i]: " << f[i] << endl;
	}
	//cout << "-------------------------------" << endl;
	return *max_element(all(f))-*min_element(all(f));
}
void solve(){
	cin >> n >> k;
	S.resize(n);
	D.resize(n);
	f.resize(n);
	FOR(i,0,n){
		cin >> S[i] >> D[i];
	}
	double left = 0,right = 1ll*k;
	while(right-left>eps){
		double m1 = left+(right-left)/3;
		double m2 = right-(right-left)/3;
		double f1 = update(m1);
		double f2 = update(m2);
		if(f2>f1) right = m2;
		else left = m1;
	}
	double ans = min(update(left),update(right));
	cout << fixed << setprecision(6) << ans << endl;
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