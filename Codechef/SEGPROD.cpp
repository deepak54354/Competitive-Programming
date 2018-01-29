#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long

int modInverse(int a, int m)
{
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;
 
    if (m == 1)
      return 0;
 
    while (a > 1)
    {
        // q is quotient
        q = a / m;
 
        t = m;
 
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
 
        t = x0;
 
        x0 = x1 - q * x0;
 
        x1 = t;
    }
 
    // Make x1 positive
    if (x1 < 0)
       x1 += m0;
 
    return x1;
}

void solve(){
	ll n,p,q;
	cin >> n >> p >> q;
	vector<ll> v(n+1);
	vector<ll> inv(n+1);
	vector<int> l(q+1),r(q+1);
	inv[0] = 1;
	v[0] = 1;

	vector<ll> b(q/64 + 2);
	for(int i = 1; i <= n; i++){
		cin >> v[i];
		v[i] = (v[i]*v[i-1])%p;
		inv[i] = modInverse(v[i],p);
	}
	int len = b.size();

	for(int i = 0; i < len ; i++){
		cin >> b[i];
	}
	ll xi = 0;

	for(int i = 0; i < q; i++){
		int x,y;
		if(i%64 == 0){
			x = (b[i/64] + xi)%n;
			y = (b[i/64+ 1] + xi)%n;
			l[i] = min(x,y);
			r[i] = max(x,y);
		}
		else{
			x = (l[i-1] + xi)%n;
			y = (r[i-1] + xi)%n;
			l[i] = min(x,y);
			r[i] = max(x,y);
		}

		ll a = v[r[i]+1];
		ll b = inv[l[i]];

		xi = ((a)*(b) + 1)%p;
	}
	cout << xi << '\n';
}

int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}