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

int v[26] = {0};
/* reset any variable array */
void reset(){ 
	return;
}

int shock = 0;
int shock_need = 0;
/* solution goes here */ 
void solve(){
	bool need = true;
	int n;
	cin >> n;

	bool flag = false;

	REP(i,n){
		// db(i);
		char c;string s;
		cin >> c >> s;
		if(i == n-1)
			break;
		if(c == '!'){
			if(flag){
				int temp[26];
				REP(j,s.size()){
					temp[s[j]-'a'] = 1;
				}
				REP(j,26){
					if(v[j] == 1 and temp[j] == 1){
						v[j] = 1;
					}
					else{
						v[j] = -1;
					}				
				}
			}
			else{
				REP(j,s.size()){
					v[s[j]-'a'] = 1;
				}
			}
			if(need)
				shock_need++;
			shock++;
			flag = true;
		}
		else if(c == '.'){
			REP(j,s.size()){
				v[s[j]-'a'] = -1;
			}
		}
		else if(c == '?'){
			if(need)
				shock_need++;
			shock++;

			v[s[0]-'a'] = -1;
		}
		int count = 0;
		REP(m,26){
			if(v[m] == 1)
				count++;
		}
		if(count == 1)
			need =false;
		// db(shock_need);
		// db(shock);
		// db(need);
		// db(count);

	}
	cout << shock - shock_need << '\n';
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

