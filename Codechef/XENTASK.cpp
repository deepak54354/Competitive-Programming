#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define SQR(n) (n*n)
#define MEM(a,val) memset(a,val,sizeof(a))
#define vi vector<int>
#define vii vector< vector<int> >
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define ll long long
#define vll vector<ll>
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
	while(t--){
		int n;
		cin >> n;
		vll X(n),Y(n);
		FOR(i,0,n-1) cin >> X[i];
		FOR(i,0,n-1) cin >> Y[i];
		ll sum1=0,sum2=0;
		for(int i = 0; i < n; i+=2){
			if(i!= n-1) {
				sum1+=X[i]+Y[i+1];
				sum2+=X[i+1]+Y[i];
			}
			else{
				sum1 += X[i];
				sum2+=Y[i];
			}
		}
		cout << min(sum1,sum2) << endl;
	}
	return 0;
}