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
#define fast_io ios_base::sync_with_stdio(false)
#ifdef _WIN32
#  define LLD "%I64d"
#else
#  define LLD "%lld"
#endif
ll fac(int n)
{
	return (n==1 || n==0)? 1 :fac(n-1)*n; 
}
int main()
{
	fast_io;
	string s,s1;
	getline(cin,s);
	getline(cin,s1);
	int len = s.length();
	int cp,cm,cp_,cm_,c_;
	double ans;
	cp = cm = cp_ = cm_ = c_ = 0;
	FOR(i,0,len-1)
	{
		if(s[i] == '+')
			cp++;
		else
			cm++;
		if(s1[i] == '+')
			cp_++;
		else if(s1[i] == '-')
			cm_++;
		else
			c_++;
	}
	//setprecision(9);	
	if(cp_ > cp || cm_ > cm)
		ans = 0.0;
	else if(cp_ == cp && cm_ == cm)
		ans = 1.0;
	else
	{
		int c1=0,c2=0;
		c1 = cp-cp_;
		c2 = cm-cm_;
		double prob = (fac(c_)/(fac(c1)*fac(c2)));
		ans = prob/pow(2,c_);
	}
	cout <<fixed  << setprecision(12)<<  ans << endl;
	return 0;
}