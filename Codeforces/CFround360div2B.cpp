#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  string n;
  getline(cin,n);
  string ans = n;
  reverse(n.begin(),n.end());
  ans += n;
  cout << ans << endl;
}
