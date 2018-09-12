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

string  v[3][3][3];

// vector<vector< vector<string> (3,"")> (3)> v(3);

/* reset any variable array */
void reset(){ 
	return;
}

/* solution goes here */ 
void solve(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				cin >> v[i][k][j];
				// cout << s << '\n';
			}
		}
	}

	// for(int i = 0; i < 3; i++){
	// 	for(int j = 0; j < 3; j++){
	// 		for(int k = 0; k < 3; k++){
	// 			cout << v[i][k][j];
	// 			cout << " ";

	// 		}
	// 		cout << '\n';
	// 	}
	// 	cout << "\n\n";
	// }

	int x,y;
	cin >> x >> y;
	x--;y--;

	int x1 = x/3, y1 = y/3;
	int x2 = x%3, y2 = y%3;

	bool flag = false;

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(v[x2][y2][i][j] == '.'){
				v[x2][y2][i][j] = '!';
				flag = true;
			}
		}
	}
	if(flag == false){
		for(int i = 0; i < 3; i++){
			for(int j = 0; j < 3; j++){
				for(int k = 0; k < 3; k++){
					for(int m = 0; m < 3; m++)
					if(v[i][j][k][m] == '.'){
						v[i][j][k][m] = '!';
					}
				}
			}
		}
	}

	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				cout << v[i][k][j];
				cout << " ";

			}
			cout << '\n';
		}
		cout << "\n";
	}

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

