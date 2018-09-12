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
vi let(26,0);
//functions specific to question

// solution here 
void solve(){
    string good;
    cin >>good;
    for(auto i:good) let[i-'a']=1;
    string s;cin>>s;
    int n;cin >> n;
    string pre,suf;
    pre =suf="";
    int i=0;
    bool star=true;
    while(i<s.size() && s[i]!='*'){
        pre+=s[i];i++;
    }
    if(i==s.size()) star=false;
    i++;
    while(i<s.size()){
        suf+=s[i];i++;
    }
    while(n--){
        string k;
        cin >>k;
        int i=0,j=0;
        bool flag = true;
        if(k.size()<pre.size()+suf.size()){
            cout << "NO" << endl;
            continue;
        }
        while(i<pre.size() and j<k.size()){
            if(pre[i]==k[j]){
                i++;j++;
            }
            else if(pre[i]=='?' and let[k[j]-'a']==1){
                i++;j++;
            }
            else{
                flag=false;
                break;
            }
        }
        //cout << "1" << endl;
        if(j<k.size() and suf.size()==0 and !star){
            cout << "NO" << endl;
            continue;
        }
        if(!flag){
            cout << "NO" << endl;
            continue;
        }
        i=suf.size()-1;j=k.size()-1;
        while(i>=0){
            if(suf[i]==k[j]){
                i--;j--;
            }
            else if(suf[i]=='?' and let[k[j]-'a']==1){
                i--;j--;
            }
            else{
                flag=false;
                break;
            }
        }
        //cout << "2" << endl;
        if(!flag){
            cout << "NO" << endl;
            continue;
        }
        i=pre.size();
        j=i+k.size()-pre.size()-suf.size()-1;
        //cout << i << " " << j << endl;
        while(i<=j){
            if(let[k[i]-'a']==1){
                //cout << k[i] << endl;
                flag=false;
                break;
            }
            i++;
        }
        //cout << "3" << endl;
        if(!flag)
            cout << "NO" << endl;
        else cout << "YES" << endl;
    }
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