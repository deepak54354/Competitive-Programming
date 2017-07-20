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
#define rall(v) (v).begin(),(v).end()
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
	string s;
	cin >> s;
	int hh,mm;
	hh = (s[0]-'0')*10 + (s[1]-'0');
	mm = (s[3]-'0')*10 + (s[4]-'0');
	int hh1 = hh;
	int mm1 = mm;
	//string ft = s;
	bool flag = false;
	while(1){

		if(hh1/10 == 0 && mm1/10 == 0){
			if(hh1 ==0 && mm1 == 0) flag = true;
		}
		else if(hh1/10 == 0){
			if(mm1 == hh1*10) flag = true;
		}
		else if(mm1/10 == 0){
			if(hh1 == mm1*10) flag = true;
		}
		else{
			if(hh1 == (mm1%10)*10 + (mm1/10)) flag = true;
		}
		if(flag){
			//cout << (hh1-hh+24)%24 << endl;
			int ans = ((hh1-hh+24)%24)*60 + mm1-mm;
			cout << ans << endl;
			break;
		}
		//cout << hh1 << " " << mm1 << endl;
		mm1++;
		if(mm1 == 60){
			mm1 = 0;
			hh1++;
			if(hh1 == 24) hh1 =0;
		}
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