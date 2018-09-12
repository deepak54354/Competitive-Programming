#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 
#define ll long long
 
//segment tree to find sum of a range with point updates
const int N = 600010;
struct node		//modify this as per questions requirements
{
	ll smf;
	ll sf;
	ll sme;
	ll se;
	ll ans;
	ll cnt;
};
 
vector<char> v(N,'s');
node T[4 *N];
node identity;	//set this such that merge(a, identity) = a and merge(identity, b) = b
 
inline int c1(int n) { return (n << 1); }
inline int c2(int n) { return (n << 1)|1; }
 
void init(node &a, char val)
{
	if(val == 's'){
		a.smf = 1;
		a.sf = 1;
		a.se = 1;
		a.sme = 1;
		a.ans = 0;
		a.cnt = 1; 
	}
	else if(val == 'm'){
		a.smf = 1;
		a.sf = 0;
		a.se = 0;
		a.sme = 1;
		a.ans = 1;
		a.cnt = 1;
	}
	else{
		a.smf = a.sf = a.se = a.sme = a.ans = 0;
		a.cnt = 1;
	}
}
 
node merge(node &a, node &b)
{
	//handle condition for identity seperately
	node c;
	if(a.sme == -1){
		c.smf = b.smf;
		c.sf = b.sf;
		c.sme = b.sme;
		c.se = b.se;
		c.ans = b.ans;
		c.cnt = b.cnt;
		return c;
	}
	if(b.sme == -1){
		c.smf = a.smf;
		c.sf = a.sf;
		c.sme = a.sme;
		c.se = a.se;
		c.ans = a.ans;
		c.cnt = a.cnt;
		return c;
	}
	//both full
	if(a.smf == a.cnt and b.smf == b.cnt){
		c.smf = a.smf + b.smf;
		c.sme = b.sme + a.sme;
	}
	//left full
	else if(a.smf == a.cnt){
		c.smf = a.smf+b.smf;
		c.sme = b.sme;
	}
	//right full
	else if(b.smf == b.cnt){
		c.smf = a.smf;
		c.sme = b.smf+a.sme;
	}
	else{
		c.smf = a.smf;
		c.sme = b.sme;		
	}

	if(a.sf == a.cnt and b.sf == b.cnt){
		c.sf = a.sf + b.sf;
		c.se = b.se + a.se;
	}
	else if(a.sf == a.cnt){
		c.sf = a.sf + b.sf;
		c.se = b.se;
	}
	else if(b.sf == b.cnt){
		c.sf = a.sf;
		c.se = b.sf + a.se;
	}
	else{
		c.sf = a.sf;
		c.se = b.se;
	}

	c.ans = a.ans + b.ans + (a.sme*b.smf - a.se*b.sf);
	c.cnt = a.cnt+b.cnt;
 
	return c;
}
 
void build(int curr, int st, int end)
{
	if(st == end)
	{
		init(T[curr], v[st]);
		return;
	}
	
	int mid = st +end >> 1;
	
	build(c1(curr), st, mid);
	build(c2(curr), mid +1, end);
	
	T[curr] = merge(T[c1(curr)], T[c2(curr)]);
	// cout << c1(curr) << "-> " << T[c1(curr)].smf << " " << T[c1(curr)].sf << " " << T[c1(curr)].sf << " " << T[c1(curr)].se << " " << T[c1(curr)].ans << " " << T[c1(curr)].cnt << '\n';
	// cout << c2(curr) << "-> " << T[c2(curr)].smf << " " << T[c2(curr)].sf << " " << T[c2(curr)].sf << " " << T[c2(curr)].se << " " << T[c2(curr)].ans << " " << T[c2(curr)].cnt << '\n';
 
	// cout << curr << "-> " << T[curr].smf << " " << T[curr].sf << " " << T[curr].sf << " " << T[curr].se << " " << T[curr].ans << " " << T[curr].cnt << '\n';
 
}
 
void update(int curr, int st, int end, int idx, char value)
{
	if(st == end)
	{
		init(T[curr], value);
		return;
	}
	
	int mid = st +end >> 1;
	
	if(idx <= mid)
		update(c1(curr), st, mid, idx, value);
	
	else
		update(c2(curr), mid +1, end, idx, value);
	
	T[curr] = merge(T[c1(curr)], T[c2(curr)]);
	// cout << c1(curr) << "-> " << T[c1(curr)].smf << " " << T[c1(curr)].sf << " " << T[c1(curr)].se << " " << T[c1(curr)].sme << " " << T[c1(curr)].ans << " " << T[c1(curr)].cnt << '\n';
	// cout << c2(curr) << "-> " << T[c2(curr)].smf << " " << T[c2(curr)].sf << " " << T[c2(curr)].se << " " << T[c2(curr)].sme << " " << T[c2(curr)].ans << " " << T[c2(curr)].cnt << '\n';
 
	// cout << curr << "-> " << T[curr].smf << " " << T[curr].sf << " " << T[curr].se << " " << T[curr].sme << " " << T[curr].ans << " " << T[curr].cnt << '\n';
 		
}
 
node query(int curr, int st, int end, int l, int r)
{
	if(st > end || r < st || end < l)
		return identity;
	
	if(l <= st && end <= r)
		return T[curr];
	
	int mid = st +end >> 1;
	
	node q1 = query(c1(curr), st, mid, l, r);
	node q2 = query(c2(curr), mid +1, end, l, r);

	// cout << c1(curr) << "-> " << q1.smf << " " << q1.sf << " " << q1.se << " " << q1.sme << " " << q1.ans << " " << q1.cnt << '\n';
	// cout << c2(curr) << "-> " << q2.smf << " " << q2.sf << " " << q2.se << " " << q2.sme << " " << q2.ans << " " << q2.cnt << '\n';
 	
	node q =  merge(q1, q2);

	// cout << curr << "-> " << q.smf << " " << q.sf << " " << q.se << " " << q.sme << " " << q.ans << " " << q.cnt << '\n';
	return q;
}
void solve(){
	identity.ans = 0;
	identity.sme = identity.se = identity.smf = identity.sf = -1;
 
	int n,q,L,R;
	cin >> n >> q >> L >> R;
	
 //    for(int i = 0; i < n; i++){
 //    	v[i] = 's';
	// }
 
	build(1,0,n-1);
 
	while(q--){
		int type,x,y;
		cin >> type >> x >> y;
		if(type==1){
			if(y >= L and y <= R)
				v[x-1] = 'm';
			else if(y < L)
				v[x-1] = 's';
			else
				v[x-1] = 'l';
			update(1,0,n-1,x-1,v[x-1]);
		}
 
		else{
			node f = query(1,0,n-1,x-1,y-1);
			cout << f.ans << '\n';
		}
	}
}
 
int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}   
