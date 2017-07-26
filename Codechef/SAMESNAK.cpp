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
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i > a; i--)
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
bool horizontal(int s1[2][2]){
	if(s1[0][1]== s1[1][1]) return true;
	return false;
}
bool vertical(int s[2][2]){
	if(s[0][0] == s[1][0]) return true;
	return false;
}
int same(int s1[2][2], int s2[2][2]){
	if(horizontal(s1) && horizontal(s2)){
		if(s1[0][1] == s2[0][1]) return 1;
	}
	else if(vertical(s1) && vertical(s2)){
		if(s1[0][0] == s2[0][0]) return 2;
	}
	return 0;
}
/*void hnormalise(int** s){
	if(s[0][0] > s[1][0]){
		swap(s[0][0],s[1][0]);
		swap(s[0][1],s[1][1]);
	}
}
void vnormalise(int** s){
	if(s[0][1] > s[1][1]){
		swap(s[0][1],s[1][1]);
		swap(s[0][0],s[1][0]);
	}
}*/
bool solve(int s1[2][2], int s2[2][2]){
	int h = same(s1,s2);
	if(h == 1){
		if(s1[0][0] > s1[1][0]){
			swap(s1[0][0],s1[1][0]);
			swap(s1[0][1],s1[1][1]);
		}
		if(s2[0][0] > s2[1][0]){
			swap(s2[0][0],s2[1][0]);
			swap(s2[0][1],s2[1][1]);
		}
		return (s1[0][0] <= s2[1][0] && s2[0][0] <= s1[1][0]);
	}
	else if(h == 2){
		if(s1[0][1] > s1[1][1]){
			swap(s1[0][1],s1[1][1]);
			swap(s1[0][0],s1[1][0]);
		}
		if(s2[0][1] > s2[1][1]){
			swap(s2[0][1],s2[1][1]);
			swap(s2[0][0],s2[1][0]);
		}
		return (s1[0][1] <= s2[1][1] && s2[0][1] <= s1[1][1]);
	}
	else{
		return ((s1[0][0]==s2[0][0] && s1[0][1]==s2[0][1]) || (s1[0][0]==s2[1][0] && s1[0][1]==s2[1][1]) || (s1[1][0]==s2[0][0] && s1[1][1]==s2[0][1]) || (s1[1][0]==s2[1][0] && s1[1][1]==s2[1][1]));	
	}
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int t;
	cin >> t;
	while(t--){
		bool yes = false;
		int s1[2][2],s2[2][2];
		FOR(i,0,2){
			FOR(j,0,2)
				cin >> s1[i][j];
		}
		FOR(i,0,2){
			FOR(j,0,2)
				cin >> s2[i][j];
		}
		cout << (solve(s1,s2)?"yes":"no") << endl;
	}
	return 0;
}