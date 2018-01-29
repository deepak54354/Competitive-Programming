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

ll fast_exp(ll base,ll n, ll M)
{
	ll ans = 1;
	while(n)
	{
		if(n%2==1)
		ans = (ans*base)%M;
		base = (base*base)%M;
		n = n>>1;
	}
	return ans%M;
}

//splits a string according to a given delimiter
template<typename Out>
void split(const string &s, char delim, Out result) {
	SS ss;
	ss.str(s);
	string item;
	while (getline(ss, item, delim)) {
		*(result++) = item;
	}
}

vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, back_inserter(elems));
	return elems;
}
//function ends

//declare question related constants here 
struct node{
	int start,end,happy;
};
const int N = 3000010;
vector<node> v(N);
vector<ll> table(N,0);
//functions specific to question
bool compare(node& a, node& b){
	return (a.end < b.end);
}
int b_search(int ind){
	int l = 0,r = ind-1;
	while(l<=r){
		int mid = (l+r)/2;
		if(v[mid].end <= v[ind].start){
			if(v[mid+1].end <= v[ind].start) l = mid+1;
			else return mid;
		}
		else r = mid-1;
	}
	return -1;
}
// solution here 
void solve(){
	int n;
	cin >> n;
	FOR(i,0,n){
		cin >> v[i].start >> v[i].happy >> v[i].end;
		v[i].end+=v[i].start;
	}
	sort(v.begin(),v.begin()+n,compare);
	table[0]=1ll*v[0].happy;
	ll ans = 0;
	FOR(i,1,n){
		ll inprof=1ll*v[i].happy;
		int l = b_search(i);
		if(l!=-1){
			inprof+=table[l];
		}
		table[i]=max(inprof,table[i-1]);
	}
	cout << table[n-1] << endl;
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