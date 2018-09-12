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

//functions specific to question

// solution here 
void solve(){
	int n;
	double w;
	cin >> n >> w;
	double prob = 1.0;
	double safe_am=0.0;
	double exp=0.0;
	FOR(i,0,n){
		string s;
		double pi,v;

		cin >> s >> pi >> v;
		//if correct
		//double temp= prob*pi*log(1+ v/w);
		if(i==n-1) exp+= prob*pi*log(1+v/w);
		//if incorrect
		exp += prob*(1-pi)*log(1+safe_am/w);
		if(s=="safe"){
			safe_am=v;
		}
		prob*=pi;
	}
	cout << exp << endl;
	double l = 0.0,r = 1000000.0;
	int cont = 0;
	double ans;
	while(cont <=1000 and l <=r){
		double mid = (l+r)/2.0;
		double comp=log(1+mid/w);
		if(comp-exp > 0 and comp-exp <= eps) ans = mid;
		else if(comp<exp) l = mid;
		else r = mid;
		cont++;
	}
	ans = l;
	ans = floor(ans*100+0.5)/100;
	cout << setprecision(2) << fixed << ans << endl; 	
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