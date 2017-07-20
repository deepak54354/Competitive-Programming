#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)
#define MEM(a,val) memset(a,val,sizeof(a))
#define vi vector<int>
#define vii vector< vector<int> >
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) (v.begin(),v.end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
#define ll long long
#define ul unsigned long
#define READ freopen("input.txt", "r", stdin);
#define WRITE freopen("output.txt", "w", stdout);
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif

int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int nb,nc,ns,ab,as,ac,pb,pc,ps;
	ll r;
	ab=as=ac = 0;
	string s;
	cin >> s;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;
	FOR(i,0,s.length()-1)
	{
		if(s[i] == 'B')
			ab++;
		else if(s[i] == 'S')
			as++;
		else
			ac++;
	}
	ll mini = 0,maxi = 10000000000000;
	while(mini+1 < maxi)
	{
		ll middle = (mini+maxi)/2;
		ll cost = max((ll)0,(as*middle-ns)*ps) + max((ll)0,(ac*middle-nc)*pc) + max((ll)0,(ab*middle-nb)*pb);
		if(cost <= r)
		{
			mini = middle;
		}
		else 
		{
			maxi = middle;
		}
	}
	cout << mini << endl;
	return 0;
}