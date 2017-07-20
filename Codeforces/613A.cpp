#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MOD 1000000007
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
#define pdd   pair<double,double>
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
pdd center;
double maxd = -1, mind = DBL_MAX;
double dis(pdd b){
	return sqrt((pow(center.F-b.F,2))+pow(center.S-b.S,2));
}
void update(pdd a,pdd b){
	maxd = max(maxd,max(dis(a),dis(b)));
	pdd m1,m2;
	FOR(i,0,100){
		m1.F = a.F + (b.F-a.F)/3; m1.S = a.S + (b.S-a.S)/3;
		m2.F = b.F - (b.F-a.F)/3; m2.S = b.S - (b.S-a.S)/3;
		if(dis(m1)<=dis(m2))
			b = m2;
		else a = m1;
	}
	mind = min(mind,dis(a));
}
void solve(){
	int n;
	cin >> n;
	cin >> center.F >> center.S;
	vector<pdd > points(n);
	FOR(i,0,n){
		cin >> points[i].F >> points[i].S;
	}
	update(points[0],points[n-1]);
	FOR(i,1,n){
		update(points[i-1],points[i]);
	}
	cout << fixed << setprecision(18)<<Pi*(pow(maxd,2)-pow(mind,2)) << endl;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t=1;
	//cin >>t;
	while(t--){
		solve();
	}
	return 0;
}