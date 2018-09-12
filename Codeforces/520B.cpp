#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


void solve(){
	int n,m;
	cin >> n >> m;
	vector<int> vis(2*max(m,n),-1);
	queue<int> q;
	q.push(n);
	vis[n]=0;
	while(!q.empty()){
		int top = q.front();
		q.pop();
		if(top == m)
			break;
		if(top < m and vis[2*top]==-1){
			vis[2*top] = 1+vis[top];
			q.push(2*top);
		}
		if(top-1 > 0  and vis[top-1] == -1){
			vis[top-1] = 1+vis[top];
			q.push(top-1);  
		}
	}
	cout << vis[m] << endl;

}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}