#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MOD 1000000007
ull fast_exp(int base, int exp) {
    ull res=1;
    while(exp>0) {
       if(exp%2==1) res=(res*base)%MOD;
       base=(base*base)%MOD;
       exp/=2;
    }
    return res%MOD;
}
int main()
{
  int m,n;
  cin >> m >> n;
  ull ans = fast_exp(m,n);
  cout << ans << endl;
}
