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

//declare question related constants here 
#define N 1<<17
int t[2*(N)+10];
int v[(N)+10];
int n,m;
//functions specific to question
void build(int node,int s,int e){
	//if(s>e) return;
	if(s==e){
		t[node]=v[s];
		return;
	}
	else{
		int mid =(s+e)/2;
		build(node<<1,s,mid);
		build(node<<1|1,mid+1,e);
		int level =n-int(log2(node));
		if(level&1){
			t[node]=(t[node<<1]|t[node<<1|1]);
		}
		else t[node]=(t[node<<1]^t[node<<1|1]);
	}
}

void modify(int node,int s,int e,int p,int x){
	if(s>p || e < p || s>e) return;
	if(s==e){
		v[s]=x;
		t[node]=x;	
	}
	else{
		int mid =(s+e)/2;
		modify(node<<1,s,mid,p,x);
		modify(node<<1|1,mid+1,e,p,x);
		int level =n-int(log2(node));
		if(level&1) t[node]=(t[node<<1]|t[node<<1|1]);
		else t[node]=(t[node<<1]^t[node<<1|1]);
	}
}
// solution here 
void solve(){
	cin >> n >> m;
	int n1=1<<n;
	FOR(i,0,n1){
		cin >> v[i];
	}
	build(1,0,n1-1);
	while(m--){
		int x,y;
		cin >> x >>y;
		modify(1,0,n1-1,--x,y);
		cout << t[1] << endl;
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