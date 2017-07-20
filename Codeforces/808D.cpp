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
int bSearch(vi v, int x, int l, int r){
	while(l <=r){
		int mid = (l+r)/2;
		if(v[mid] == x){
			return mid;
		}
		else if(v[mid] > x){
			r = mid-1;
		}
		else{
			l = mid+1;
		}
	}
	return -1;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int n;
	cin >> n;
	if(n==1){
		cout << "NO" << endl;
		return 0;
	}
	vi v(n);
	multiset<ll> ms;
	ll sum = 0;
	FOR(i,0,n){
		cin >> v[i];
		sum += v[i];
	}
	//cout << "dawd" <<endl;
	if(sum&1){
		cout << "NO" << endl;
		return 0;
	}
	sum = sum/2;
	//cout << sum << endl;
	ll s = 0;
	bool flag = false;
	vi v1;
	FOR(i,0,n){
		s = s+1ll*v[i];
		//cout <<"S: " <<s << "  ";
		ms.insert(v[i]);
		//cout << "wdada" << endl;
		if(s<sum) continue;
		else if(s == sum){
			flag = true;
			break;
		}
		if(ms.find(s-sum) != ms.end()){
			flag = true;
			break;
		}
	}
	if(flag){
		cout << "YES" << endl;
		return 0;
	}
	flag = false;
	s = 0;
	ms.clear();
	FORD(i,0,n-1){
		s+=1ll*v[i];
		//cout << "S: " << s << "  ";
		ms.insert(v[i]);
		if(s<sum) continue;
		else if(s == sum){
			flag = true;
			break;
		}
		//cout << i << " "<<s-sum << endl;
		if(ms.find(s-sum)!= ms.end()){
			flag = true;
			break;
		}
	}
	if(flag) cout << "YES" << endl;
	else cout << "NO"<< endl;
	return 0;
}