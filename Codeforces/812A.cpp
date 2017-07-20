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

int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int v[4][4];
	FOR(i,0,4){
		FOR(j,0,4){
			cin >> v[i][j];
		}
	}
	string ans = "NO";
	if(v[0][3] == 1 && (v[0][0]== 1 || v[0][1]== 1 || v[0][2] == 1 || v[1][0] == 1 || v[2][1] == 1 || v[3][2])){
		ans = "YES";
	}
	else if(v[1][3] == 1 && (v[1][0]== 1 || v[1][1]== 1 || v[1][2] == 1 || v[0][2]==1 || v[2][0]== 1 || v[3][1] == 1))
		ans = "YES";
	else if(v[2][3]== 1 && (v[2][0]== 1 || v[2][1]== 1 || v[2][2] == 1 || v[0][1] == 1 || v[1][2] == 1 || v[3][0] == 1))
		ans = "YES";
	else if(v[3][3] ==1  && (v[3][0]== 1 || v[3][1]== 1 || v[3][2] == 1 || v[0][0]==1 || v[1][1]==1 || v[2][2] == 1))
		ans = "YES";
	cout << ans << endl;
	return 0;
}