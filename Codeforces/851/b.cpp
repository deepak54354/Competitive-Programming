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

void solve(){
	long long ax,ay,bx,by,cx,cy;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	long long f = ax*ax - cx*cx + ay*ay -cy*cy - 2*(bx*(ax-cx) + by*(ay-cy));
	bool slope = (ay-by)*(bx-cx) == (by-cy)*(ax-bx); // checking if slopea are equal
	//bool area = ax*(by-cy) + bx*(cy-ay) + cx*(ay-by)>0; // checking if area of triangel ABC is zero, if zero then collinear
	if(f==0 and !slope) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}