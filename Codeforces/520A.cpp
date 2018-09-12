/* * * * * * * * * * * * * * * * *
	Created By: Deepak Nathani
*	Last Updated: 23/12/2017     *
	You will win or you'll learn
* * * * * * * * * * * * * * * *	*/

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

#define db(x) cout << "->" << #x << ':' << x << '\n';
#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define fastio	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

#define ll long long

// Functions
inline bool eq(double a, double b) { return fabs(a-b) < 1e-9; }
template<typename T> T gcd(T a, T b) { return(b?__gcd(a,b):a); } // a is larger
template<typename T> T lcm(T a, T b) { return(a*(b/gcd(a,b))); }
template <typename T> T mod(T a, T m) { T c = a%m; return (c<0)?c+m:c; }
template<typename T> T mulMod(T a, T b, T m) { return mod((mod(a,m)*mod(b,m)),m);}
template<typename T>T power(T e, T n, T m){ T x=1,p=e; while(n){ if(n&1)x=(x*p)%m; p=mul(p,p,m);n>>=1; } return x;}

// Constants
const int INF = (1 << 29);

/* reset any variable array */
void reset(){ 
	return;
}

/* solution goes here */ 
void solve(){
	bool ans[26] = {0};

	int n;
	cin >> n;

	string s;
	cin >> s;

	REP(i,n){
		s[i] = tolower(s[i]);
		ans[s[i]-'a']++;
	}

	REP(i,26){
		if(ans[i] == 0){
			cout << "NO" << '\n';
			return;
		}
	}
	cout << "YES" << '\n';
}

int main(){
	fastio;
	int t;
	// cin >> t;
	t = 1;
	while(t--){
		reset();
		solve();
	}
}

