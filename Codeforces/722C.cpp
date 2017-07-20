/****************************************************************************
*					Author: Deepak Nathani									*
*					hackerrank:- savager									*
*					codeforces:- deepak54354								*
*					Spoj:- deepak54354										*
*					Github:- deeplearning10									*
*****************************************************************************/					


#include <bits/stdc++.h>
using namespace std;

// Math
#define Pi 3.141592653589793
#define eps 1e-9
#define MOD 1000000007
#define SQR(n) ((n)*(n))

// memory 
#define MEM(a,val) memset(a,val,sizeof(a))

// Data types and related macros
#define ll long long
#define ul unsigned long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define vii vector< vector<int> >
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define SS stringstream

//loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)

// I/O
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

//declare question related constants here 


const int N=100010;
// useful functions
template <typename T>
T mod(T a, T b) // calculates a%b, not remainder
{
	T ans;
	if(b == 0)
		return -1;
	else
		ans = (a<0 ? mod(((a%b)+b),b) : a%b);
	return ans;
}
template <typename T>
T fast_exp(T base,T n)
{
  T ans = 1;
  while(n)
  {
    if(n%2==1)
      ans = (ans*base)%MOD;

    base = (base*base)%MOD;
    n = n>>1;
  }
  return ans%MOD;
}

int parent[N];
int rnk[N];
ll sum[N];
ll v[N];
ll maxi=-1;
//functions specific to question
int find(int x){
	if(parent[x]!=x) parent[x]=find(parent[x]);
	return parent[x];
}

void unite(int x,int y){
	int xp=find(x);
	int yp=find(y);
	if(rnk[xp]<rnk[yp]){
		parent[xp]=yp;
		sum[yp]+=sum[xp];
		//if(sum[yp]>maxi) maxi = sum[yp];
	}
	else if(rnk[yp]<rnk[xp]){
		parent[yp]=xp;
		sum[xp]+=sum[yp];
		//if(sum[xp]>maxi) maxi = sum[xp];
	}
	else{
		parent[xp]=yp;
		sum[yp]+=sum[xp];
		//if(sum[yp]>maxi) maxi = sum[yp];
		rnk[yp]++;
	}
}
// solution here 
void solve(){
	int n;
	cin >> n;
	FOR(i,1,n+1) cin >> v[i];
	FOR(i,0,N) parent[i]=i;
	FOR(i,0,N){
		rnk[i]=1;
		sum[i]=-1;
	}
	vll ans;
	ans.pb(0);
	vi q(n);
	//cout << find(15) << endl;
	FOR(i,0,n) cin >> q[i];
	FORD(i,0,n-1){
		int j = q[i];
		sum[j]=v[j];
		if(sum[j-1]!=-1){
			unite(j-1,j);
			//cout <<"j: " << sum[find(j)] << " j-1: " << sum[find(j-1)] << endl;
		}
		if(sum[j+1]!=-1){
			unite(j+1,j);
			//cout <<"j: " << sum[find(j)] << " j+1: " << sum[find(j+1)] << endl;
		}
		//cout <<j << " "<< find(j) << endl;
		if(sum[find(j)]>maxi) maxi = sum[find(j)];
		ans.pb(maxi);
	}
	reverse(all(ans));
	for(int i = 1; i < ans.size(); i++){
		cout << ans[i] << endl;
	}
}

//driver function
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