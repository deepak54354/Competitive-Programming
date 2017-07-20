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
	int n,m;
	cin >> n >> m;
	char s[n+1];
	char t[m+1];
	scanf("%s%s", s,t);
	//cout << s <<" " << t << endl;
	int j;
	int ans = 1000001;
	int anspos;
	for(int i = 0;i<=m-n; i++){
		int temp = 0;
		int j=i;
		int k =0;
		while(j<=i+n-1){
			if(s[k]!=t[j]) temp++;
			j++;
			k++;
		}
		//cout << temp << endl;
		if(temp<ans){
			ans = temp;
			anspos=i;
		}
	}
	cout << ans << endl;
	int k;
	//cout << anspos << endl;
	for(int i = anspos,k=0;i<anspos+n;i++,k++){
		if(s[k]!=t[i]) cout << k+1 << " ";
	}
	cout << endl;
}
int main()
{
	//fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t=1;
	//cin >> t;
	while(t--){
		solve();
	}
	return 0;
}