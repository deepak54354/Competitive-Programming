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
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vi a1(n+1),a2(n+1,0);
		FOR(i,1,n) a1[i] = i;
		if(k == 0){
			a2 = a1;
		}
		else if(k==1 && n > 1 && n%2 == 0){
			for(int i = 1; i <=n-1; i+=2){
				//cout << "yolo" << endl;
				a2[i] = a1[i+1];
				a2[i+1] = a1[i];
			}
		}
		else if(n == 2*k){
			for(int i = 1; i <= n-k; i++){
				a2[i] = a1[i+k];
				a2[i+k] = a1[i];
			}
		}
		else if(n < 2*k || n == 2*k+1){
			cout << "-1" << endl;
			continue;
		}
		else{
			bool flag = true;
			FOR(i,1,n){
				if(i-k > 0 && a2[i-k] == 0) 
					a2[i-k] = a1[i];
				else if(i+k <=n && a2[i+k] == 0) a2[i+k] = a1[i];
				else{
					cout << "-1" << endl;
					flag = false;
					break;
				}
			}
			if(!flag) continue;
		}
		FOR(i,1,n){
			cout << a2[i] << " ";
		}
		cout << endl;
	}
	return 0;
}