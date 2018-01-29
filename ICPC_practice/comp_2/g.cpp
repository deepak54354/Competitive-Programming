#include <iostream>
#include <vector>
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
	int n,m;
	cin >> n >> m;
	vector<string> grid(n);
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin >> grid[i];
	}
	for(int i = n-1; i>=0; i--){
		for(int j = 0; j < m; j++){
			if(grid[i][j]=='o'){
				int curry=i,currx=j;
				while(curry+1<n and grid[curry+1][currx] == '.'){
					curry++;
				}
				grid[i][j]='.';
				grid[curry][currx]='o';
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j= 0; j < m; j++){
			cout << grid[i][j];
		}
		cout << "\n";
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