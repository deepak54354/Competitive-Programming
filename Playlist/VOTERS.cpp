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

//functions specific to question
const int N=1000100;
//declare question related constants here 
int c[N]={0};
// solution here 
void solve(){
	int n1,n2,n3;
	cin >> n1 >> n2 >> n3;
	int l;
	set<int> s;
	FOR(i,0,n1){
		cin >>l;
		s.insert(l);
		c[l]++;
	}
	FOR(i,0,n2){
		cin >> l;
		s.insert(l);
		c[l]++;
	}
	FOR(i,0,n3){
		cin >>l;
		s.insert(l);
		c[l]++;
	}
	int ans =0;
	vi v;
	for(set<int>::iterator it=s.begin();it!=s.end();it++){
		if(c[*it]>=2){ 
			ans++;
			v.pb(*it);
		}
	}
	cout << ans<< endl;
	if(v.size()>0) FOR(i,0,int(v.size()))cout << v[i] << endl;
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