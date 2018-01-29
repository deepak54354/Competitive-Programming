#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int dis(int x1,int y1,int x2,int y2){
	return ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}
void solve(){
	int r,d;
	cin >> r >> d;
	int out,in;
	out = r,in= r-d;
	int n;
	cin >> n;
	int ans=0;
	for(int i = 0; i < n; i++){
		int x,y,r1;
		cin >> x >> y >>r1;
		double dist = dis(0,0,x,y);
		bool cond1= dist <= (out-r1)*(out-r1);
		bool cond2 = dist >= (in+r1)*(in+r1);
		bool cond3 = (x*x + y*y - out*out)<=0;
		bool cond4 = (x*x+y*y-in*in)>=0;
		if(cond1 and cond2 and cond3 and cond4){
			ans++;
			//cout << i << endl;
		}
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