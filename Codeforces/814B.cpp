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
int n;
vi x,y;
bool isvalid(vi v){
	int len = v.size();
	set<int> s;
	FOR(i,0,len) s.insert(v[i]);
	if(len == s.size()) return true;
	return false;
}
void solve(){
	vi per(n,0);
	bool used[n+1] = {false};
	int pos1=-1,pos2=-1;
	int count = 0;
	FOR(i,0,n){
		if(x[i] == y[i]) per[i] = x[i];
		else{
			if(pos1==-1)pos1=i;
			else pos2=i;
			count++;
		}
		used[x[i]] = used[y[i]]= true;
	}
	int g;
	if(count == 1){
		int ava;
		FOR(i,1,n+1  ) if(!used[i]){
			ava = i;
			break;
		}
		FOR(i,0,n){
			if(per[i] == 0) per[i] = ava;
		}
		FOR(i,0,n){
			cout << per[i] << " ";
		}
		return;
	}
	else if(count == 2){
		per[pos1] = x[pos1];per[pos2]=y[pos2];
		if(isvalid(per)){
			FOR(i,0,n){
				cout << per[i] << " ";
			}
			return;
		} 
		per[pos1]=y[pos1];per[pos2]=x[pos2];
	}
	FOR(i,0,n){
		cout << per[i] << " ";
	}
	cout << endl;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	cin >> n;
	x.resize(n);y.resize(n);
	FOR(i,0,n) cin >> x[i];
	FOR(i,0,n) cin >> y[i];
	solve();
	return 0;
}