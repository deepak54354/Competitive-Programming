#include <iostream>
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
	char e;int a=-1,b=-1,r;
	for(int i=0; i < 5; i++){
		char c;
		cin >> c;
		if(isdigit(c)){
			if(a==-1) a=c-'0';
			else if(b==-1) b=c-'0';
			else r=c-'0';
		}
		if(c!='=') e = c;
	}
	if(a+b==r) cout <<"YES" << "\n";
	else cout << "NO" << "\n";
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}