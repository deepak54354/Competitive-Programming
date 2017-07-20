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
	int r,c;
	cin >> r >> c;
	vii vr(r,vi(c)),vr1(r,vi(c));
	vii vc(c,vi(r)),vc1(c,vi(r));
	FOR(i,0,r) FOR(j,0,c){
		cin >> vr[i][j];
		vc1[j][i] = vr[i][j];
	}
	vector<pair<string, int> > ans,ans1;
	FOR(i,0,r){
		int mind = *min_element(all(vr[i]));
		if(mind == 0) continue;
		else{
			FOR(j,0,c) vr[i][j] -= mind;
			FOR(k,0,mind) ans.pb(make_pair("row ",i+1));
		}
	}
	FOR(i,0,c) FOR(j,0,r) vc[i][j]= vr[j][i];
	FOR(i,0,c){
		int mind = *min_element(all(vc[i]));
		if(mind ==0) continue;
		else{
			FOR(j,0,r) vc[i][j]-=mind;
			FOR(k,0,mind) ans.pb(make_pair("col ", i+1));
		}
	}

	FOR(i,0,c){
		int mind = *min_element(all(vc1[i]));
		if(mind ==0) continue;
		else{
			FOR(j,0,r) vc1[i][j]-=mind;
			FOR(k,0,mind) ans1.pb(make_pair("col ", i+1));
		}
	}
	FOR(i,0,r) FOR(j,0,c) vr1[i][j] = vc1[j][i];
	FOR(i,0,r){
		int mind = *min_element(all(vr1[i]));
		if(mind == 0) continue;
		else{
			FOR(j,0,c) vr1[i][j] -= mind;
			FOR(k,0,mind) ans1.pb(make_pair("row ",i+1));
		}
	}
	bool flag = true;
	FOR(i,0,c) FOR(j,0,r) if(vc[i][j] != 0){
		flag = false;break;
	}
	if(!flag) cout << -1 << endl;
	else if(ans.size() <= ans1.size()){
		cout << ans.size() << endl;
		FOR(i,0,ans.size()) cout << ans[i].F << ans[i].S << endl;
	}
	else{
		cout << ans1.size() << endl;
		FOR(i,0,ans1.size()) cout << ans1[i].F << ans1[i].S << endl;
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