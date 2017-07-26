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
#define FOR(i,a,b) for(int i = a; i <= b; i++)
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

int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<pii> dolls(n);
		//wi,hi
		FOR(i,0,n-1)
			cin >> dolls[i].F >> dolls[i].S;
		sort(dolls.begin(),dolls.end());
		int ans=0;
		while(!dolls.empty())
		{
			list<int> all;
			all.clear();
			FOR(i,0,dolls.size()-1){
				list<int> current;
				current.pb(i);
				FOR(j,i+1,dolls.size()-1){
					if(dolls[j].F > dolls[current.back()].F && dolls[j].S > dolls[current.back()].S){
						current.pb(j);
					}
				}
				if(current.size() > all.size())
				{
					all.clear();
					all.insert(all.begin(),current.begin(),current.end());
					current.clear();
				}
			}
			ans++;
			while(!all.empty()){
				dolls.erase(dolls.begin()+all.front());
				all.pop_front();
			}
		}
		cout << ans << endl;
	}
	return 0;
}