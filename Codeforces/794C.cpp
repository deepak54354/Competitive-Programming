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

bool func(const char &a, const char &b){
	return a > b;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	string s1,s2;
	cin >> s1 >> s2;
	int n = s1.size();
	vector<char> ans(n,'?');
	sort(s1.begin(),s1.end());
	sort(s2.rbegin(),s2.rend());
	int i = ceil((double(n))/2)-1,j = floor(n/2)-1;
	//cout << "i: " << i << " j: " << j << endl;
	int p1 = 0,q1 = i;
	int p2 = 0, q2 = j;
	string ans1,ans2;
	ans1 = ans2 = "";
	FOR(k,0,n-1){
		if(k%2){
			if(s2[p2] <= s1[p1]){
				ans2 += s2[q2];
				q2--;
				//cout <<"q2: "<< q2 << endl;
			}
			else{
				ans1 += s2[p2];
				p2++;
			}
		}
		else{
			if(s1[p1] >= s2[p2]){
				//cout << "yolo 2" << k << endl;
				ans2 += s1[q1];
				q1--;
				//cout <<"q1: "<< q1 << endl;	
			}
			else{
				ans1 += s1[p1];
				p1++;
			}
		}
	}
	reverse(ans2.begin(),ans2.end());
	cout << ans1 << ans2<< endl;
	return 0;
}