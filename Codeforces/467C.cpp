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
#define FOR(i,a,b) for(int i = a; i <= b; i++)
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
int* v;
int n,m,k;
ll knapsack(ll* arr,ll** O,int wt, int x){
	if(x < 0 || wt <= 0) return 0;
	//cout << "YOOLA" << endl; 
	if(O[x][wt] > MIN)
		return O[x][wt];
	else{
		O[x][wt] = max(arr[x]+knapsack(arr,O,wt-1,x-m), knapsack(arr,O,wt,x-1));
	} 
	return O[x][wt];
}
ll solve(int* v){
	int index;
	int l = n;
	ll* arr = new ll[l-m+1];
	arr[0] = 0;
	FOR(i,0,m-1){
		arr[0] += v[i];
	}
	FOR(i,m,l-1){
		arr[i-m+1] = arr[i-m]-v[i-m]+v[i];
	}
	ll** O = new ll*[l-m+1];
	FOR(i,0,l-m) O[i] = new ll[k+1];
	FOR(i,0,l-m) 
		FOR(j,0,k)
			O[i][j] = MIN;
	FOR(i,0,l-m) O[i][0] = 0;
	return knapsack(arr,O,k,l-m);
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	cin >> n >> m >> k;
	v = new int[n];
	FOR(i,0,n-1) cin >> v[i];
	ll ans = 0; 
	ans = solve(v);
	cout << ans << endl;
	return 0;
}