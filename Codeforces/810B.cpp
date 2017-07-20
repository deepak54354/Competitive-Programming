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
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i > a; i--)
#define ul unsigned long
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif
#define pii pair<int,int>
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
	int n,f;
	cin >> n >> f;
	int l[n],k[n];
	vector<pii> diff(n);
	FOR(i,0,n){
		cin >> l[i] >> k[i];
		diff[i] = make_pair(min(k[i],2*l[i])-min(k[i],l[i]), i);
	}
	sort(diff.rbegin(),diff.rend());
	int j = 0;
	while(f && j < n){
		if((l[diff[j].S] != 0 && k[diff[j].S] != 0))
		{
			l[diff[j].S] *=2;
			//cout << diff[j].S << endl;
			f--;
		}
		j++;
	}
	ll products = 0;
	FOR(i,0,n){
		products+= min(l[i],k[i]);
	}
	cout << products << endl;
	return 0;
}