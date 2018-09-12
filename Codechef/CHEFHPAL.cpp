#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

string str[10] = {"","a","ab","aab","aabb","aaabb","aaabbb","aaababb","aaababbb"};
int len[10] =    {0,1,1,2,2,3,3,3,3,3};

void solve(){
	int n,a;
	cin >> n >> a;
	if(n == 1)
		cout << 1 << " " <<  "a" << '\n';
	else if(a == 1){
		cout << n << " ";
		while(n--){
			cout << 'a';
		}
		cout << '\n';
	}
	else if(a > 2){
		cout << 1 << " ";
		string s = "";
		for(int i = 0; i < a; i++){
			s += char('a' + i);
		}

		int l = n/a;
		int g = n%a;
		while(l--)
			cout << s;
		for(int i = 0; i < g; i++)
			cout << s[i];
		cout << '\n';
	}
	else{
		string s = "abbaab";
		if(n < 9){
			cout << len[n] << " " << str[n] << '\n';
		}
		else{
			cout << 4 << " ";
			int l = n/6;
			int g = n%6;
			while(l--)
				cout << s;
			for(int i = 0; i < g; i++)
				cout << s[i];
			cout << '\n';
		}
	}
}


int main(){
	fast_io;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}