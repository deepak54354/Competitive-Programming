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
	int n,m,k;
	cin >> n >> m >>k;
	int x = 1;
	bool direction = 1;
	int i = 1, j = 1;
	vector<vector<pii > > v(k+1);
	v[1].pb(make_pair(1,1));
	while(x<=k-1){
		if(v[x].size()==2){
			x++;
		}
		if(direction){
			if(i+1>n){
				j = j+1;
				direction = 0;
			}
			else{
				i++;
			}
			v[x].pb(make_pair(i,j));
		}
		else{
			if(i-1<1){
				j++;direction=1;
			}
			else{
				i--;
			}
			v[x].pb(make_pair(i,j));
		}
	}
	while(1){
		if(direction){
			if(i+1>n){
				if(j==m)
					break;
				j = j+1;
				direction = 0;
			}
			else{
				i++;
			}
			v[k].pb(make_pair(i,j));
		}
		else{
			if(i-1<1){
				if(j==m) 
					break;
				j++;direction=1;
			}
			else{
				i--;
			}
			v[k].pb(make_pair(i,j));
		}
	}
	FOR(i,1,k+1){
		cout << v[i].size() << " ";
		FOR(j,0,v[i].size()) cout << v[i][j].F << " " << v[i][j].S << " ";
		cout << endl;
	}
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