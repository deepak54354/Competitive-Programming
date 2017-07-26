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

//declare question related constants here 
const int N = 100010;
// solution here
int H,n;
int A[N]; 
bool flag = false;
void solve(){
	cin >> n >> H;
	FOR(i,0,n) cin >> A[i];
	int x;int point = 0;
	while(cin >> x){
		if(x==0){
			break;
		}
		else if(x==1){
			if(point !=0) point--;
		}
		else if(x==2){
			if(point!=n-1) point++;
		}
		else if(x==3){
			if(!flag && A[point]>0){
				flag = true;
				A[point]--;
			}
		}
		else{
			if(flag && A[point] <H){
				flag = false;
				A[point]++;
			}
		}
	}
	FOR(i,0,n) cout << A[i] << " ";
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