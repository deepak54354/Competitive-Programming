#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// loops
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()

#define fast_io ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);


struct node{
	node* edges[26];
	node (){
		for(int i = 0; i < 26; i++){
			this->edges[i]=NULL;
		}
	}
};
node* root = new node;
void insert(string s){
	int i = 0,n = s.size(),j;
	node* trav= root;
	while(i<n){
		j=s[i]-'a';
		if(trav->edges[j]==NULL) trav->edges[j]=new node;
		i++;
		trav=trav->edges[j];
	}
}

string search(string s){
	int i = 0,n = s.size(),j;
	string ans ="";
	node* trav = root;
	while(i<n){
		j = s[i]-'a';
		if(trav->edges[j]==NULL){
			ans+=s[i];
			return ans;
		}
		ans+=s[i];
		trav=trav->edges[j];
		i++;
	}
	return "-1";
}

void solve(){
	int n;
	cin >> n;
	set<string> ans;
	vector<string> bl;
	while(n--){
		char c;string s;
		cin >> c >> s;
		if(c=='+') insert(s);
		else bl.push_back(s);
	}
	for(auto i : bl){
		string q = search(i);
		if(q=="-1"){
			cout << -1 << '\n';
			return;
		}
		ans.insert(q);
	}
	cout << ans.size() << "\n";
	for(auto i : ans){
		cout << i << "\n";
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