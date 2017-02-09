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
#define MEM(a,val) memset(a,val,sizeof(a))
//Extra
#define pb push_back
#define SS stringstream
#define Ignore cin.ignore()
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define FORD(i,a,b) for(int i = b; i >= a; i--)
//typedefs
typedef unsigned long long ul;
typedef long long ll;

int main()
{
  int N;
  cin >> N;
  string s;
  cin >> s;
  int mem[26] = {0};
  int numb = 0, zero = 0;
  FOR(i,0,N-1)
    mem[s[i]-'a']++;
  FOR(i,0,25)
  {
    if(mem[i])
      numb += (mem[i]-1);
    else
      zero++;
  }
  cout << (numb <= zero?numb:-1) << endl;
  return 0;
}
