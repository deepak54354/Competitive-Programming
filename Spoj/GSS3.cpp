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
#define N 50010
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
	ll sum,maxsum,prefixsum,suffixsum;
	node(){
		maxsum=prefixsum=suffixsum= -1e12;
		sum=0;
	}
	node(ll a){
		sum=prefixsum=suffixsum=maxsum=a;
	}
};
int n,m;
ll A[N];
node tree[N<<1];
node combine(node a, node b){
	node res;
	res.sum=a.sum+b.sum;
	res.maxsum=max(max(a.maxsum,b.maxsum),a.suffixsum+b.prefixsum);
	res.prefixsum=max(a.prefixsum,a.sum+b.prefixsum);
	res.suffixsum=max(b.suffixsum,b.sum+a.suffixsum);
	return res;
}
void build(){
	for(int i=n-1;i>0;i--) tree[i]=combine(tree[i<<1],tree[i<<1|1]);
}
void modify(int p, ll x){
	for(tree[p+=n]=node (x);p>>=1;) tree[p]=combine(tree[p<<1],tree[p<<1|1]);
}
ll query(int l,int r){
	node resl,resr;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1){
		if(l&1) resl=combine(resl,tree[l++]);
		if(r&1) resr=combine(tree[--r],resr);
	}
	return (combine(resl,resr)).maxsum;
}
void solve(){
	cin >>n;
	FOR(i,0,n){
		cin >> A[i];
		tree[i+n]= node (A[i]);
	}
	build();
	cin >> m;
	while(m--){
		int t,x,y;
		cin >> t >> x >> y;
		if(t==0){
			modify(x-1,1ll*y);
		}
		else{
			cout << query(x-1,y) << endl;
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