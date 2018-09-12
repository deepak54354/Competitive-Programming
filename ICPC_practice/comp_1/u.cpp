#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

long long mod(long long a, long long b){
	if(a < 0) return b+a;
	else if(a >= b) return a%b;
	else return a;
}


int a[110][110];
int b[110][110];
int c[9][2] = {{0,0},{0,1},{1,0},{1,1},{0,-1},{-1,0},{-1,-1},{1,-1},{-1,1}};

void solve(){
	int w,h,t;
	cin >> w >> h >> t;

	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			cin >> a[i][j];
		}
	}

	while(t--){
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				long long  sum = 0;
				for(int k = 0; k < 9; k++){
					sum += 1ll*a[mod(i+c[k][0],h)][mod(j+c[k][1],w)];
				}
				b[i][j] = sum;
			}
		}
		
		for(int i = 0; i < h; i++)
			for(int j = 0; j< w; j++) 
				a[i][j] = b[i][j];
	}

	set<long long> s;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
				s.insert(b[i][j]);
		}
	}

	cout << s.size() << endl;
}

int main(){
	fast_io;
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
}