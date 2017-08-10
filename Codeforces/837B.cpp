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
const int N = 110;
char grid[N][N];
bool col[3]={0};
int n,m;
//r==0.G==1.B==2;
//functions specific to question
bool horizontal(){
	int x= n/3;
	int i,j;
	i = j = 0;
	char c1= grid[i][j];
	char c=c1;
	while(i < x){
		j=0;
		while(j<m){
			if(grid[i][j]==c) j++;
			else{
				return false;
			}
		}
		i++;
	}
	i = x; j = 0;
	char c2 = grid[i][j];
	if(c2==c1) return false;
	c=c2;
	while(i < 2*x){
		j=0;
		while(j<m){
			if(grid[i][j]==c) j++;
			else{
				return false;
			}
		}
		i++;
	}
	i = 2*x; j = 0;
	char c3 = grid[i][j];
	if(c3== c1 || c3==c2) return false;
	c=c3;
	while(i < 3*x){
		j=0;
		while(j<m){
			if(grid[i][j]==c) j++;
			else{
				return false;
			}
		}
		i++;
	}
	return true;
}
bool vertical(){
	int x = m/3;
	int i,j;
	i = j = 0;
	char c1 = grid[i][j];
	char c =c1;
	while(i<n){
		j=0;
		while(j<x){
			if(grid[i][j]==c)j++;
			else{
				//cout << 1 << endl;
				return false;
			}
		}
		i++;
	}
	i = 0;j = x;
	char c2 = grid[i][j];
	c=c2;
	if(c2==c1) return false;
	while(i<n){
		j=x;
		while(j<2*x){
			if(grid[i][j]==c)j++;
			else{
				//cout << 2 << endl;
				return false;
			}
		}
		i++;
	}
	i = 0; j = 2*x;
	c=grid[i][j];
	if(c==c2 or c==c1) return false;
	while(i<n){
		j=2*x;
		while(j<3*x){
			if(grid[i][j]==c)j++;
			else{
				//cout << 3 << endl;
				return false;
			}
		}
		i++;
	}
	return true;
}
// solution here 
void solve(){
	cin >> n >> m;
	FOR(i,0,n){
		FOR(j,0,m) cin >> grid[i][j];
	}
	if(n%3==0 && m%3==0){
		//cout << horizontal() << " " <<vertical() << endl;
		cout << (horizontal() or vertical() ? "YES" : "NO") << endl;
	}
	else if(n%3==0){
		cout << (horizontal()?"YES":"NO") << endl;
	}
	else if(m%3==0){
		cout << (vertical()?"YES":"NO") << endl;
	}
	else cout << "NO" << endl;
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