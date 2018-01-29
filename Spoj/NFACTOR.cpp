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
const int N=int(1e6+10);
vi sf(N,-1);
vector<bool> prime(N,1);
vii v(11);
//functions specific to question
void seive(){
    prime[0]=prime[1]=sf[0]=0;
    sf[1]=1; 
    for(int i = 2; i*i <=N; i++){
        if(prime[i]){
            for(int j=i*i;j<=N;j+=i){
                prime[j]=false;
                if(sf[j]==-1) sf[j]=i;
            }
        }
    }
    for(int i =2; i<=N;i++) if(prime[i]) sf[i]=i; 
}
int count(ll n){
    ll num = n;
    ll ans=0;
    while(num>1){
        ll div=sf[num];
        //cout << n << "-> " << endl; 
        ans++;
        while(num%div==0){
            num /= div;
        }
    }
    return ans;
}
// solution here 
void solve(){
	ll a,b,n;
    cin >> a >> b >> n;
    int ans =upper_bound(all(v[n]),b)-lower_bound(all(v[n]),a);
    cout << ans << endl;
}

//driver function
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
    int t;
    cin >> t;
    seive();
    v[0].pb(1);
    for(int i=2;i<N;i++){
        //cout << i << endl;
        v[count(1ll*i)].pb(i);
    }
    //cout << "y" << endl;
	while(t--){
		solve();
	}
	return 0;
}