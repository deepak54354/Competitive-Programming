#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1010;

vector<int> parent[N];
vector<int> child[N];

vector<int> iskiller(N,0);

int n;

void solve(){
	cin >> n;
	while(1){
		char x,y;
		cin >> x >> y;
		if(x == 'B'){
			int v;
			while(scanf("%d", &v) != EOF){
				while(parent)
			}
		}
		else{
			int c = x-'0';
			int p = y-'0';
			parent[c].push_back(y);
			child[p].push_back(x);
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