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
string next_string(string s){
	string ans = "";
	int len = s.size();
	bool f = false;
	while(len){
		if(f) ans+=s[len-1];
		else if(s[len-1] <'z'){
			ans += (s[len-1]+1);
			f = true;
		}
		else if(s[len-1]=='z'){
			ans+='a';
		}
		len--;
	}
	bool flag = true;
	FOR(i,0,ans.size()){
		if(ans[i]!='a'){
			flag = false;
			break;
		}
	}
	if(flag) ans+='a';
	reverse(ans.begin(),ans.end());
	return ans;
}
void solve(){
	int n,k;
	cin >> n >> k;
	vector<string> v(n-k+2);
	FOR(i,1,n-k+2){
		string s;
		cin >> v[i];
	}
	vector<string> names(n+1);
	names[1] ="a";
	FOR(i,2,n+1){
		names[i] = next_string(names[i-1]);
		// cout << names[i] << endl;
	}
	FOR(i,1,n-k+2){
		if(v[i] == "NO"){
			names[i+k-1] = names[i];
		}
	}
	FOR(i,1,n+1) 
	{
		names[i][0] = static_cast<char>(toupper(names[i][0]));
		cout << names[i] << " ";
	}
	cout << endl;
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