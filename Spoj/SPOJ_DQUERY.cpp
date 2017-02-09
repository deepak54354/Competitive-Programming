#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define SQR(n) (n*n)
#define MEM(a,val) memset(a,val,sizeof(a))
#define vi vector<int>
#define vii vector< vector<int> >
#define pii pair<int,int>
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
vi cnt(1000005,0);
int n;
int answer = 0;
typedef struct node
{
	int L,R,i;
}node;
void add(int position,int* v)
{
	cnt[v[position]]++;
	if(cnt[v[position]] == 1) answer++;
} 
void remove(int position,int* v)
{
	cnt[v[position]]--;
	if(cnt[v[position]] == 0) answer--;
}
bool comp(node &a,node &b)
{
	int sq = sqrt(n);
	if((a.L/sq) == (b.L/sq))
		return a.R < b.R;
	else
		return a.L < b.L;
}
int main()
{
	//fast_io;
	cin >> n;
	int* v = new int[n];
	FOR(i,0,n-1)
		cin >> v[i];
	int qe;
	cin >> qe;
	int ans[qe];
	node q[qe];
	FOR(i,0,qe-1)
	{
		scanf("%d%d",&q[i].L,&q[i].R);
		q[i].L--;q[i].R--;
		q[i].i = i;
	}
	sort(q,q+qe,comp);
	int currentL = 0;
	int currentR = 0;
	FOR(i,0,qe-1)
	{
		while(currentL > q[i].L)
		{
			add(currentL-1,v);
			currentL--;
		}
		while(currentR <= q[i].R)
		{
			add(currentR,v);
			currentR++;
		}
		while(currentL < q[i].L)
		{
			remove(currentL,v);
			currentL++;
		}
		while(currentR > q[i].R+1)
		{
			remove(currentR-1,v);
			currentR--;
		}
		ans[q[i].i] = answer;
	}
	FOR(i,0,qe-1)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}
