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
int n,c;
bool poss(vi v, int x){
	int cow = 1;
	int lastpos = v[0];
	FOR(i,1,n){
		if(v[i]-lastpos>=x){
			cow++;
			lastpos = v[i];
		}
		if(cow == c) return 1;
	}
	return 0;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t;
	cin >>t;
	while(t--){
		cin >> n >> c;
		vi v(n);
		FOR(i,0,n) cin >> v[i];
		sort(v.begin(),v.end());
		int start= 0,end = v[n-1]-v[0]+1;
		//cout << end << endl;
		while(end-start>1){
			int mid = (start+end)>>1;
			//cout << start << " "<< end<<endl;
			if(poss(v,mid)){
				start = mid;
			}
			else end = mid;
		}
		cout << start << endl;
	} 
	return 0;
}