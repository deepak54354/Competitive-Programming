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

int mod(int a, int b) // calculates a%b, not remainder
{
	int ans;
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
	//fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int n,p,k;
	cin >> n >> k>> p;
	bool A[n];
	FOR(i,0,n-1) cin >> A[i];
	int end = n-1;
	string q; cin >> q;
	list<int> current;
	int curr= 0, curr_prev = 0;
	if(n <= k)
	{
		int sum = 0;
		FOR(i,0,n-1)
			sum+=A[i];
		FOR(i,0,p-1)
		{
			if(q[i] == '?') cout << sum << endl;
		}
		return 0;
	}
	FOR(i,0,n-k)
	{
		if(i == 0)
		{
			FOR(j,0,k-1) 
				curr += A[j];
		}
		else
			curr = curr_prev - A[i-1] + A[i+k-1];
		curr_prev = curr;
		current.push_back(curr);
	}
	int pre = k-1;
	int maxi = *max_element(current.begin(),current.end());
	int index = distance(current.begin(),max_element(current.begin(),current.end()));
	FOR(i,0,p-1)
	{
		if(q[i] == '?')
			cout << maxi << endl;
		else
		{
			int f = current.front();
			current.pop_back();
			current.push_front(f+A[end]-A[pre]);
			if(index == n-k)
			{
				maxi = *max_element(current.begin(),current.end());
	        	index = distance(current.begin(),max_element(current.begin(),current.end()));	
			}
			else
			{
				if(current.front() >= maxi)
				{
					maxi = current.front();
					index = 0;
				}
				else index++;
			}
			if(end == 0) end = n-1;
			else end--;
			if(pre == 0) pre = n-1;
			else pre--;
		}
	}
	return 0;
}