#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define SQR(n) (n*n)
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
#define FOR(i,a,b) for(int i = a; i <= b; i++)
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
	int n;
	cin >> n;
	string s,m;
	cin >> s >> m;
	bool check1[n] = {false},check2[n] = {false};
	sort(m.begin(),m.end());
	//cout << m[0] << endl;
	int mini=0,maxi=0;
	FOR(i,0,n-1){
		bool flag1 = false,flag2 = false;
		FOR(j,0,n-1){
			if(m[j] >= s[i] && !check1[j]){
				check1[j] = true;
				flag1 = true;
				break;
			}
		}
		if(!flag1){
			mini++;
			//cout << "Yippee mini " << i << endl;
		}
		FOR(j,0,n-1){
			if(m[j] > s[i] && !check2[j]){
				check2[j] = true;
				flag2 = true;
				break;
			}
		}
		if(flag2){
			maxi++;
			//cout << "Yippee maxi " <<i<<endl;
		}
	}
	cout << mini << endl << maxi << endl;
	return 0;
}