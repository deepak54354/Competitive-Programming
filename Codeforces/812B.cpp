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
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(int i = a; i < b; i++)
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
int n,m;
bool check(vector<string> v, int j){
	bool ans = true;
	for(int i = j-1; i >=0; i--){
		FOR(k,0,m+2){
			if(v[i][k] == '1'){
				return false;
			}
		}
	}
	return true;
}
int main()
{
	fast_io;
	//ifstream in_file("file.in");
	//ofstream out_file("file.out");
	cin >> n >> m;
	vector<string> v(n);
	int time = 0;
	FOR(i,0,n){
		cin >> v[i];
	}
	bool flag =false;
	FOR(i,0,n){
		FOR(j,1,m+1){
			if(v[i][j] == '1'){
				flag = true;
				break;
			}
		}
	}
	if(!flag){
		cout << 0 << endl;
		return 0;
	}
	int curr = 0;
	int floor = n-1;
	while(floor >=0 ){
		if(curr == 0){
			FOR(j,curr+1,m+1){
				if(v[floor][j] == '1'){
					time += j-curr;
					curr = j;
					j = curr;
					v[floor][j] = '0';
					//cout << "fdsf" << endl;
				}
			}
		}
		else{
			FORD(j,0,curr-1){
				if(v[floor][j] == '1'){
					time += curr - j;
					curr = j;
					j = curr;
					v[floor][j] = '0';
				}
			}
		}
		if(floor == 0) break;
		if(check(v,floor) == true){
			break;
		}
		int dis_left = curr-0;
		int dis_right = m+1-curr;
		if(dis_right > dis_left){
			time+= dis_left;
			curr = 0;
			floor--;
			time++;
		}
		else if(dis_left > dis_right){
			time += dis_right;
			curr = m+1;
			floor--;
			time++;
		}
		else{
			floor--;
			int index;
			FOR(j,0,m+1){
				if(v[floor][j] == '1'){
					index = j;
					break;
				}
			}
			if(index-0 > m+1-index)
				curr = m+1;
			else curr = 0;
			time+= dis_right;
			time++;
		}
		//cout << "time: " << time << endl;
		//cout << floor << " " << curr << endl;
	}
	cout << time << endl;
	return 0;
}