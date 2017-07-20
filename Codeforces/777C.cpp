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
#define pii pait<int,int>
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
struct node{
	int l,r,index;
	bool flag;
};
int main()
{
	//fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int n,m;
	cin >> n >> m;
	int up[n][m];
	int v[n][m];
	FOR(i,0,n-1){
		FOR(j,0,m-1){
			scanf("%d", &v[i][j]);
		}
	}

	FORD(i,0,n-1){
		FOR(j,0,m-1){
			if(i < n-1 && v[i][j] <= v[i+1][j]){
				up[i][j] = up[i+1][j]+1;
			}
			else up[i][j] = 1;
		}
	}
	int maxi[m];
	FOR(i,0,n-1){
		maxi[i] = *max_element(up[i],up[i]+m);
	}
	int k;
	cin >> k;
	FOR(i,0,k-1){
		int l,r;
		cin >> l >> r;
		if(l==r){
			cout << "Yes" << endl;
			continue;
		}
		l--;
		bool yes = false;
		if(maxi[l]>=r-l){
			cout << "Yes" << endl;
			yes = true;
		}
		
		if(!yes) cout << "No" << endl;
	}
}