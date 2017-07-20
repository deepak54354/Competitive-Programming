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
#define F firsat
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
void solve(){
	int n;
	cin >> n;
	vi v;
	int r = 1;
	ll reorder = 0;
	stack<int> st;
	FORD(i,1,n) st.push(i);
	FOR(i,0,2*n){
		string s;
		cin >> s;
		if(s=="add"){
			int c;
			cin >> c;
			v.pb(c);
		}
		else{
			int sz = v.size();
			if(sz==0){
				st.pop();
			}
			else if(sz!=0 && r==v[sz-1]){
				st.pop();
				v.erase(v.end()-1);
			}
			else if(sz!=0 && r != v[sz-1]){
				//cout << r << " " << v[sz-1] << endl;
				reorder++;
				//cout << "v[last]: " << v[v.size()-1];
				v.clear();
			}
			r++;
		}
	}
	cout << reorder << endl;	
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