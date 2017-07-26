
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define pb push_back
#define FOR(i,a,b) for(int i = a; i < b; ++i)


int main()
{
	long long unsigned int n,a,m=0,b,k=0;
	cin>>n>>a>>b;
	b=2*b;
	while(n--)
	{
		cin>>k;
		
		/*if (b==0 and a==0)
		{
			m=m+k;
			continue;
		}
		else if (k==2 and b==1)
		{
			m=m+k;
			continue;
		}
		if (k==1 and a!=0)
		{
			a=a-k;
			//cout<<"k is "<<k<<" a "<<a<<endl;
			continue;
		}
		if (a==0 and b!=0)
		{
			b=b-k;
			//cout<<"k is "<<k<<" b at half"<<b<<endl;
			continue;
		}
		//else m=m+k;
		//n--;*/
		if (k==1 and a!=0)
		{
			a=a-k;
			continue;
		}
		else if (k==1 and a==0 and b!=0)
		{
			b=b-k;
			//cout<<"k is "<<k<<" b at half"<<b<<endl;
			continue;
		}
		else if (k==1 and a==0 and b==0)
		{
			m=m+k;
			continue;
		}
		else if (k==2 and b>1)
		{
			b=b-k;
			//cout<<"k is "<<k<<" b at half"<<b<<endl;
			continue;
		}
		else if (k==2 and (b==1 or b==0))
		{
			m=m+k;
			continue;
		}

		if (n==0) break;
	}


	cout<<m<<endl;
	
	return 0;
}