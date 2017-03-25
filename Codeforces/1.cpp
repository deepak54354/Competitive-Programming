#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
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


int func(int n,int arr[],int answer[])
{

	if(n == 0)
	{
		answer[n] =1 ;
		return 1;
	}
	if(answer[n] != -1 && answer[n] != 0)
		return answer[n];

	else
	{
		int temp[n];
		int counter = 0;
		for(int i = 0;i<=n-1;i++)
		{
			if(abs(arr[n]) > abs(arr[i]) && ((arr[i] < 0 && arr[n] >0) || (arr[i] > 0 && arr[n] < 0) ))
			{
				temp[counter++] = func(i,arr,answer) + 1;
			}
			else
			{
				temp[counter++] = func(i,arr,answer);
			}


		}
		//cout<<"check"<<temp[0];

		int x = *max_element(temp,temp+n);
		//cout<<x<<endl;
		answer[n] = x;
		return x;
	}


}

int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	int n ;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	int answer[n];
	for(int i = 0; i < n; i++) answer[i] = -1;

	cout<<func(n-1,a,answer) << endl;


	return 0;
}