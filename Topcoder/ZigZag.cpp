
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define ll long long
using namespace std;


ll longestZigZag(vector <ll> sequence)
{
	ll len = sequence.size();
	vector<ll> dif(len-1);
	vector<ll> sum(len);
	for(ll i = 0; i < len-1; i++){
		ll k=sequence[i]-sequence[i+1];
		if(k < 0)
			dif[i]=1;
		else if(k >0)
			dif[i]=0;
		else
			dif[i]=-1;
	}
	sum[0]=0;
	sum[1]=1;
	bool flag = false;
	for(ll i =0;i < len-1;i++){
		if(dif[i]!=-1){
			flag = true;
			break;
		}
	}
	if(!flag) return 1;
	for(ll m = 0; m < len-1; m++){
		ll j = m;
		for(ll i = j+1; i < len-1; i++){
			if(dif[i] == 1 - dif[j]){
				sum[i+1] = max(sum[i+1],sum[j+1]+1);
				j=i;
			}
			else
				sum[i+1]=max(sum[i+1],sum[j+1]);
		}
	}
	return *max_element(sum.begin(),sum.end())+1;
}

int main()
{
	ll n;
	cin >> n;
	vector<ll> v(n);
	for (ll i = 0; i < n; ++i)
	{
		/* code */
		cin >> v[i];
	}
	ll ans = longestZigZag(v);
	cout << ans << "\n";
	return 0;
}

//Powered by [KawigiEdit] 2.0!
