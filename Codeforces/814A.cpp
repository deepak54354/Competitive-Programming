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
vi x,y;
bool is_incre(vi v){
	bool yes = true;
	FOR(i,1,v.size()){
		if(v[i] <= v[i-1]){
			yes = false;
			break;
		}
	}
	//cout << yes << endl;
	return yes;
}
void solve(){
	sort(y.rbegin(),y.rend());
	int j = 0;
	FOR(i,0,n){
		if(x[i] == 0){
			x[i] = y[j];
			j++;
		}
	}
	if(is_incre(x)) cout << "No" << endl;
	else cout << "Yes" << endl;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	cin >> n >> k;
	x.resize(n);y.resize(k);
	FOR(i,0,n) cin >> x[i];
	FOR(i,0,k) cin >> y[i];
	solve();
	return 0;
}