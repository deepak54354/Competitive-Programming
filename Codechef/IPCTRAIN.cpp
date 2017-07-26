/****************************************************************************
*                   Author: Deepak Nathani                                  *
*                   hackerrank:- savager                                    *
*                   codeforces:- deepak54354                                *
*                   Spoj:- deepak54354                                      *
*                   Github:- deeplearning10                                 *
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

ll fast_exp(ll base,ll n)
{
  ll ans = 1;
  while(n)
  {
    if(n&1)
      ans = (ans*base)%MOD;

    base = (base*base)%MOD;
    n = n>>1;
  }
  return ans%MOD;
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
const int N=100010;
vector<pair<ll,ll> > v(N);
ll T[N];
//functions specific to question
bool comp(int a,int b){
    return v[a].S > v[b].S;
}
// solution here 
void solve(){
    int n,D;
    cin >> n >> D;
    vii days(D+1);
    v.clear();
    FOR(i,0,N) T[i]=0;
    multiset<int,bool(*)(int,int)> s(comp);
    FOR(i,1,n+1){
        ll d,t,s;
        cin >> d >> t >> s;
        v[i]={t,s};
        T[i]=t;
        days[d].pb(i);
    }
    FOR(i,1,D+1){
        for(auto j : days[i]) s.insert(j);
        if(s.empty()) continue;
        int k = *s.begin();
        s.erase(s.begin());
        v[k].F--;
        if(v[k].F>0)s.insert(k);
    }
    ll sum = 0;
    for(auto e:s){
        sum+= (1ll*v[e].F)*(1ll*v[e].S);
    }
    cout << sum << endl;
}

//driver function
int main()
{
    fast_io;
    //ifstream in_file("file.in");
    //ofstream out_file("file.out");
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}