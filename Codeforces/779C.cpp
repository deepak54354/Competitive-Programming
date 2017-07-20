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
bool func(const pii &a, const pii &b){
	return a.F-a.S < b.F-b.S;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int n,k;
	cin >> n >> k;
	vector<pii > now,after;
	int no[n];
	int af[n];
	FOR(i,0,n){
		cin >> no[i];
	}
	FOR(j,0,n){
		cin >> af[j];
	}
	//cout << "yolo" << endl;
	FOR(i,0,n){
		if(af[i] >= no[i]) now.pb(make_pair(no[i],af[i]));
		else after.pb(make_pair(no[i],af[i]));
	}
	ll money = 0;
	if(now.size()>=k){
		FOR(i,0,now.size()) money += now[i].F;
		FOR(i,0,after.size()) money += after[i].S;
	}
	else{
		//cout << now.size()<< endl;
		sort(after.begin(),after.end(),func);
		FOR(i,0,now.size()){
			//cout << "yolo" << endl;
			money += now[i].F;
		}
		// /cout << "yolo" << endl;
		FOR(i,0,k-now.size()){
			money+=after[i].F;
		}
		FOR(i,k-now.size(),after.size()) money+= after[i].S;
	}
	cout << money << endl;
	return 0;
}