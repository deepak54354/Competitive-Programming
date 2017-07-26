#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX 1000000000
#define SQR(n) (n*n)
#define MEM(a,val) memset(a,val,sizeof(a))
#define vi vector<int>
#define vii vector< vector<int> >
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
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
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vi p(k+1);
		p[0] = 0;
		FOR(i,1,k)
			cin >> p[i];
		vi b(k+1);
		b[0]= 0;b[1] = p[1];
		bool flag = false;
		FOR(i,2,k){
			b[i] = p[i];
			flag = false;
			int m = MAX,x=i;
			for(int j=0,x = i; j <= x; j++,x--){
				if(b[j] != -1 && b[x] != -1){
					m= min(m,b[j]+b[x]);
					flag = true;
				}
				else if(m == MAX) flag = false;
			}
			if(flag == false) b[i] = -1;
			else b[i] = m;
			//cout << i << " KG-> "<<m <<endl; 
		}
		//if(!flag) cout << -1 << endl;
		cout << b[k] << endl;
	}
	return 0;
}