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
vi cntl(100003,0),cntr(100003,0),cntt(100003,0),cntb(100003,0);
int n,m,d;
void solve(){
	int cl,cb,cr,ct;
	cin >> d >> n >> m;
	vi x1(d+1),x2(d+1),y1(d+1),y2(d+1);
	FOR(i,1,d+1){
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		cntl[min(x1[i],x2[i])]++;
		cntr[max(x1[i],x2[i])]++;
		cntt[min(y1[i],y2[i])]++;
		cntb[max(y1[i],y2[i])]++;
	}
	FOR(i,1,100003){
		cntl[i]+=cntl[i-1];
		cntt[i]+=cntt[i-1];
	}
	FORD(i,1,100001){
		cntb[i]+=cntb[i+1];
		cntr[i]+=cntr[i+1];
	}
	cin >> cl >> cr >> ct >> cb;
	vector< pair<pii,pii> > cnt(d); // cnt.F.F =l,cnt.F.S = r,cnt.S.F =t,cnt.S.S=b
	FOR(i,1,d+1){
		cnt[i-1].F.F = cntl[max(x1[i],x2[i])-1]-(x1[i]!=x2[i]);
		//cout << cnt[i].F.F << " ";
		cnt[i-1].F.S = cntr[min(x1[i],x2[i])+1]-(x1[i]!=x2[i]);
		//cout << cnt[i].F.S<<" ";
		cnt[i-1].S.F = cntt[max(y1[i],y2[i])-1]-(y1[i]!=y2[i]);
		//cout << cnt[i].S.F<<" ";
		cnt[i-1].S.S = cntb[min(y1[i],y2[i])+1]-(y1[i]!=y2[i]);
		//cout <<cnt[i].S.S<<endl;
	}
	pair<pii,pii> target = {{cl,cr},{ct,cb}};
	if(find(all(cnt),target) != cnt.end()){
		cout << distance(cnt.begin(),find(all(cnt),target))+1<< endl;
	}
	else cout << -1 << endl;
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