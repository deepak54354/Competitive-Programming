#include <bits/stdc++.h>

using namespace std;

//math
#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)

//pairs
#define ff first
#define ss second
#define mp make_pair

//array
#define CLR(a) memset(a, 0, sizeof(a))
#define MEM(a,val) memset(a,val,sizeof(a))

//Extra
#define pb push_back
#define SS stringstream
#define Ignore cin.ignore()
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)

typedef unsigned long long ul;
typedef long long ll;

using namespace std;
int main()
{
  string s = "";
  string s1;
  for(int i = 1; i <= 370; i++)
  {
    SS convert;
    convert << i;
    s1 = convert.str();
    s = s+s1;
  }
  int n;
  cin >> n;
  cout << s[n-1] << endl;
}
