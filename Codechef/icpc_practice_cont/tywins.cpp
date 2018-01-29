#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define ll long long

const int N = 100010; // define n as number of nodes, so size of array can be 2*n;

vector<ll> adj[N];
ll BEGIN[2*N];// denotes BEGINing of v's subtree
ll END[2*N]; // denotes ENDing index of v's subtree
ll discover[2*N]; // array on which you have to built segment tree
ll pos[2*N]; // position of a node in discover array
vector<bool> used(N,0);

//segment tree to find sum of a range with poll updates

struct node		//modify this as per questions requirements
{
	ll val;
};

ll aa[N];
node T[4 *N];
node identity;	//set this such that merge(a, identity) = a and merge(identity, b) = b

ll cnt = -1; // for 0-indexed indexing of arrays
void dfs(ll i){
	used[i]=1;
	discover[++cnt]=i;
	pos[i]=cnt;
	BEGIN[i]=cnt;
	for(ll j = 0; j < adj[i].size(); j++){
		if(!used[adj[i][j]]){
			dfs(adj[i][j]);
		}
	}
	END[i]=cnt;
}

inline ll c1(ll n) { return (n << 1); }
inline ll c2(ll n) { return (n << 1)|1; }

void init(node &a, ll val)
{
	a.val = val;
}

node merge(node &a, node &b)
{
	//handle condition for identity seperately
	
	node res;
	res.val = a.val +b.val;
	return res;
}

void build(ll curr, ll st, ll END)
{
	if(st == END)
	{
		init(T[curr], aa[discover[st]]);
		return;
	}
	
	ll mid = st +END >> 1;
	
	build(c1(curr), st, mid);
	build(c2(curr), mid +1, END);
	
	T[curr] = merge(T[c1(curr)], T[c2(curr)]);
}

void update(ll curr, ll st, ll END, ll idx, ll value)
{
	if(st == END)
	{
		init(T[curr], value);
		return;
	}
	
	ll mid = st + END >> 1;
	
	if(idx <= mid)
		update(c1(curr), st, mid, idx, value);
	
	else
		update(c2(curr), mid +1, END, idx, value);
	
	T[curr] = merge(T[c1(curr)], T[c2(curr)]);		
}

node query(ll curr, ll st, ll END, ll l, ll r)
{
	if(st > END || r < st || END < l)
		return identity;
	
	if(l <= st && END <= r)
		return T[curr];
	
	ll mid = st +END >> 1;
	
	node q1 = query(c1(curr), st, mid, l, r);
	node q2 = query(c2(curr), mid +1, END, l, r);
	
	return merge(q1, q2);
}

void solve(){
	identity.val = 0;
	ll n,m;
	cin >> n >> m;
	for(ll i = 0; i < n; i++)
		cin >> aa[i];

	for(ll i = 0; i < n-1; i++){
		ll x,y;
		cin >> x >> y;
		x--;y--;
		adj[x].push_back(y);
      	adj[y].push_back(x);
	}

	dfs(0);

	build(1, 0, n-1);
	while(m--){
		char c;
		cin >> c;
		if(c == 'U'){
			ll s,x;
			cin >> s >> x;
			s--;
			update(1,0,n-1,pos[s],x);
		}
		else{
			int s;
			cin >> s;
			s--;
			cout << query(1,0,n-1,BEGIN[s],END[s]).val << "\n";
		}
	}
}

int main(){
	fast_io;
	ll t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}