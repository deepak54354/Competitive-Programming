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

//declare question related constants here 

const int N=100010;

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
struct  node{
	int c[3];
	node(){
		c[0]=c[1]=c[2]=0;
	}
};

int A[N]={0};
node t[N<<2]=node ();
int lazy[N<<2];
int n,q;
//functions specific to question
node combine(node a, node b){
	node res;
	FOR(i,0,3) res.c[i]=a.c[i]+b.c[i];
	return res;
}
void build(int id,int s,int e){
	if(s==e){
		t[id].c[A[s]%3]++;
		//cout << "id: " << id << " " << t[id].c[0] << endl;
		return;
	}
	else{
		int mid =(s+e)/2;
		build(id<<1,s,mid);
		build(id<<1|1,mid+1,e);
		t[id]=combine(t[id<<1],t[id<<1|1]);
		//cout << "id: " << id << " " << t[id].c[0] << endl;
	}
}

void update(int id,int s,int e, int l, int r){
	if(s>e) return;
	if(lazy[id]!=0){
		int j = lazy[id];
		node res;
		FOR(i,0,3){
			res.c[i]=t[id].c[mod(i-j,3)];
		}
		t[id]=res;
		if(s!=e){
			lazy[id<<1]+=lazy[id];
			lazy[id<<1|1]+=lazy[id];
		}
		lazy[id]=0;
	}
	if(s > r || e < l ) return;
	if(s>=l&&e<=r){
		node res;
		FOR(i,0,3){
			res.c[i]=t[id].c[mod(i-1,3)];
		}
		t[id]=res;
		if(s!=e){
			lazy[id<<1]++;
			lazy[id<<1|1]++;
		}
		return;
	}
	
	int mid = (s+e)/2;
	update(id<<1,s,mid,l,r);
	update(id<<1|1,mid+1,e,l,r);
	t[id]=combine(t[id<<1],t[id<<1|1]);
}

int query(int id,int s, int e, int l, int r){
	if(s>e || s>r || e<l) return 0;
	if(lazy[id]!=0){
		int j = lazy[id];
		node res;
		FOR(i,0,3){
			res.c[i]=t[id].c[mod(i-j,3)];
		}
		t[id]=res;
		if(s!=e){
			lazy[id<<1]+=lazy[id];
			lazy[id<<1|1]+=lazy[id];
		}
		lazy[id]=0;
	}
	if(s>=l && e <=r){
		return t[id].c[0];
	}
	else{
		int mid=(s+e)/2;
		int p1 = query(id<<1,s,mid,l,r);
		int p2=query(id<<1|1,mid+1,e,l,r);
		return p1+p2;
	}
}
// solution here 
void solve(){
	scanf("%d%d",&n,&q);
	build(1,0,n-1);
	while(q--){
		int w,x,y;
		scanf("%d%d%d",&w,&x,&y);
		if(w==0){
			update(1,0,n-1,x,y);
		}
		else{
			cout << query(1,0,n-1,x,y)<<endl;
		}
		/*cout << "q: " << q << endl;
		FOR(i,0,2*n){
			cout << "i: " <<i << " ";
			FOR(j,0,3){
				cout << t[i].c[j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
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