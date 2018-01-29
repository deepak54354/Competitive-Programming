#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Math
#define Pi 3.141592653589793
#define eps 1e-9
#define MOD 1000000007
#define SQR(n) ((n)*(n))
// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1010;
vector<int> v(N);
int n;
bool vis[N]={false};
bool check(double m,int c){
	int count = 0;
	for(int i = 1; i < N; i++) vis[i]=false;
	for(int i = 1; i <= n; i++ ){
		if(v[i]-c == 1ll*m*(i-1)){
			vis[i]=true;
			count++;
		}
	}

	if(count == n) return false;
	if(count == n-1) return true;

	int pos1;
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			pos1=i;
			break;
		}
	}

	for(int i = pos1+1; i<=n; i++){
		if(!vis[i]){
			if(abs((double)(v[i]-v[pos1])/(i-pos1) - m) > eps) return false;
		}
	}
	return true;
}
void solve(){
	//int n;
	cin >> n;
	//vector<int> v(n);
	for(int i =1; i <= n; i++) cin >> v[i];
	bool ans = false;
	ans |= check(1.0*(v[2]-v[1]), v[1]);
	ans |= check(1.0*(v[3]-v[2]), 2*v[2]-v[3]);
	ans |= check(0.5*(v[3]-v[1]), v[1]);
	cout << (ans?"yes":"no") << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}