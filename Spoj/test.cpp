/*
  Template by Siddhartha Mishra(sid_m97)
*/
#include <bits/stdc++.h>
 
using namespace std;
 
#define inf 1e9
#define eps 1e-9
const double pi = acos(-1.0);
#define MOD 1000000007
 
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
 
#define ll long long
#define vi vector<int>
#define vf vector<float>
#define vs vector<string>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii>
#define vll vector<pll>
#define mpii map<int,int>
#define seti set<int>
#define mseti multiset<int>
 
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
 
#define loop(i, a, b, x) for(ll i = a;i <b; i += x)
#define f(i,a,b) loop(i,a,b,1)
#define rep(i,n) f(i,0,n)
#define repv(i,a) rep(i,a.size()) 
#define loopr(i,a,b,x) for(ll i = a; i>=b;i--)
#define fr(i,a,b) loopr(i,a,b,1)
#define repr(i,n) fr(i,n-1,0)
#define repvr(i,a) repr(i,a.size())
#define mem(a,b) memset(a, (b), sizeof(a))
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define SORT(v) sort(v.begin(),v.end());
#define inc(A, B, C)  A <= B && B <= C
 
/* important functions */
template <typename T>
T mod(T a, T b)
{ return (a%b+b)%b; }
 
template <typename T>
T xdiv(T a, T b)
{
  if(a%b == 0) return a/b;
  else return a/b + 1;
}
 
template <typename T>
T gcd(T a, T b) {
  T r, i;
  while(b!=0){
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}
 
template <typename T>
T fast_exp(T base, T exp ,T mod=MOD) {
    T res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%mod;
       base=(base*base)%mod;
       exp/=2;
    }
    return res%mod;
}
template <typename T>
void prvec(T a){
  rep(i,a.size()) cout<<a[i]<<" ";
  cout<<endl;
}
/* Declare variables here*/
ll T;
 
 
/* user define functions specific to problem */
 
 
 
 
/* solve here */
void solve()
{
  ll m,k;
  cin>>m>>k;
  vl p(m);
  rep(i,m)cin>>p[i];
  ll lo = *max_element(all(p));
  ll hi = accumulate(all(p),0);
  vl slash(m);
  ll slcount;
  while(lo < hi)
  {
    std::fill(slash.begin(), slash.end(), 0);
    ll mid = lo + (hi-lo)/2;
    slcount= 0;
    ll req = 1, curr = 0;
    rep(i,m){
      if(curr + p[i] <= mid){
        curr += p[i];
      }
      else {
        ++req;
        if(slcount < k-1){
          slash[i] = 1;
          slcount++;
        }
        curr = p[i];
      }
    }
 
    if(req <= k)
      hi = mid;
    else
      lo = mid+1;
  }
  slcount = (k - 1 - slcount);
  rep(i,m)
  {
    if(slash[i]) {
      cout<<"/ ";
    }
    else if(i != 0 && slcount > 0) {
      cout<<"/ ";
      slcount--;
    }
    cout<<p[i]<<" ";  
 
  }
  cout<<endl;
}
 
void solver(int test)
{
  if(test) {
    cin>>T;
    rep(i,T) {solve();}
    return;
  }
  solve();
}
 
 
/* main function */
 
int main() 
{
  std::ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
 
  solver(1);
 
  return 0;
}