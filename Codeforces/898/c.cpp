#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

bool isSuff(string a, string b){
	if(a.size() > b.size())
		return false;
	bool flag = true;

	int i = a.size()-1, j = b.size()-1;

	while(i >=0){
		if(a[i] != b[j]){
			flag = false;
			break;
		}
		i--;j--;
	}

	return flag;
}

void solve(){
	int n;
	cin >> n;

	map<string, vector<string> > my;
	set<string> names;

	for(int i = 0; i < n; i++){
		string s;
		int k;
		cin >> s >> k;
		names.insert(s);
		vector<string> v;
		for(int j = 0; j < k; j++)
		{
			string phone;
			cin >> phone;

			my[s].push_back(phone);
		}
	}	
	cout << names.size() << '\n';
	for(auto i: names){
		cout << i << ' ';
		int s = my[i].size();
		set<string> temp;
		for(int j = 0; j < s; j++){
			bool flag = true;
			for(int k = 0; k < s; k++){
				if(my[i][j] == my[i][k])
					continue;
				if(isSuff(my[i][j],my[i][k])){
					flag = false;
					break;
				}
			}
			if(flag)
				temp.insert(my[i][j]);
		}
		cout << temp.size() << ' ';
		for(auto j: temp)
			cout << j << ' ';
		cout << '\n';
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