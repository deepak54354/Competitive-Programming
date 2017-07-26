#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define SQR(n) ((n)*(n))
#define MEM(a,val) memset(a,val,sizeof(a))
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector< vector<int> >
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define ul unsigned long
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

ll mod(ll a, ll b) // calculates a%b, not remainder
{
	ll ans;
	if(b == 0)
		return -1;
	else
	{
		ans = (a<0 ? mod(((a%b)+b),b) : a%b);
	}
	return ans;
}
string extract(string s){
	int l = s.size();
	string ans = "";
	FOR(i,0,l){
		if(s[i]=='(')
			break;
		else ans+=s[i];
	}
	return ans;
}
map<string, set<int> > m;
int ext(string s){
	int k = s.size();
	int ans = 0;
	if(s[k-1] == ')'){
		FOR(i,0,k){
			if(s[i] == '('){
				i++;
				while(i < k-1){
					ans = ans*10 +(s[i]-'0');
					i++;
				}
			}
		}
	};
	return ans;
}
int create(string s){
	if(m.find(s) == m.end()){
		m[s].insert(0);
	}
	int k;
	auto it = m[s].begin();
	k = *it;
	m[s].erase(it);
	if(m[s].empty()){
		m[s].insert(k+1);
	}
	//cout << ans << endl;
	return k;
}

void del(string s){
	string h = extract(s);
	m[h].insert(ext(s));
}

void rnm(string s1, string s2){
	del(s1);
	int t = create(s2);
	cout << "r " << s1 << " -> " << s2;
	if(t == 0){
		cout << endl;
		return;
	}
	cout << "(" << t <<")" << endl;
}

int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int q;
	cin >> q;
	map<string, int>m;
	while(q--){
		string comm,name1,name2;
		cin >> comm;
		if(comm == "crt"){
			cin >> name1;
			int t = create(name1);
			cout << "+ " << name1;
			if(t == 0){
				cout << endl;
				continue;
			}
			cout << "(" << t <<")" << endl;
		}	
		else if(comm == "del"){
			cin >> name1;
			cout << "- " << name1 << endl;
			del(name1);
		}
		else{
			cin >> name1 >> name2;
			rnm(name1,name2);
		}
	}
	return 0;
}