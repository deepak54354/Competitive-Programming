#include <iostream>
#include <set>
using namespace std;

// Data Types
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

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
	int n,k;
	cin >> n >> k;
	ll curr=0, ans = 0;
	multiset<ll> s;
	for (int i = 0; i < k; ++i)
	{
		ll h;
		cin >> h;
		s.insert(h);
	}
	int j = k;
	while(j<n){
		ll h=*(s.begin());
		//cout << h << endl;
		curr += h;
		ans+=curr;
		s.erase(s.begin());
		cin >> h;
		s.insert(h);
		j++;
	}
	for(auto i: s){
		curr+=i;
		ans+=curr;
	}
	cout << ans << "\n";
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}