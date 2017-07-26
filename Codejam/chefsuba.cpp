#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <vector>
#include <sstream>
#include <utility> // for pair
#define REP(i,n) for(ll i=0;i<(n);i++)
#define FOR(i,a,b,c) for(int i=a;i<b;i += c)
#define FORd(i,a,b,c) for(int i=a;i>=b;i -=c)
#define vi vector<ll>
#define vii vector<vector<ll> >
#define ll long long int //range -> –9,223,372,036,854,775,808 to 9,223,372,036,854,775,807
#define ui unsigned int // range -> 0 to 4,294,967,295
#define ull unsigned long long
using namespace std;
bool sortdes(const pair<int,int> &a,const pair<int,int> &b){
    if(a.first >b.first)return true;
    else if(a.first == b.first && a.second < b.second)return true;
    else return false;
}

int main(){
	int n,k,p;
	cin >> n >> k >> p;
	vector <int> ans(n,-1);
	bool a[2*n];
	int count1 =0;
	
	REP(i,n){
		cin >> a[i];
		a[n+i]=a[i];
		if(a[i]==1)count1++;
	
	}

	pair <int,int> swa[n];
	int f =0;
	int c = 0;
	FOR(j,0,n,1){
		if(f == 0){
			FOR(l,0,k,1){
				c+=a[l];
			}
			f =1;	
		}
		else{
			c = c - a[j-1] + a[j+k-1];
		}
		swa[j].first = c;
		swa[j].second = j;
	} 
	sort(swa,swa+n,sortdes);

	int start = 0;
	string s;
	cin >> s;

	FOR(i,0,p,1){
		if(s[i]=='!'){
			if(start==0) start = n-1;
			else start--;
		}
		else if(s[i]=='?'){
			if(k>=n){
				cout << count1 << endl;
			}
			else if(ans[start] == -1){
				int x = 0;
				while(x<n){
					if(swa[x].second+k-1<n){
						if(start>swa[x].second && start<= swa[x].second +k-1)x++;
						else break;
					}
					else{
						if((start>swa[x].second && start <= n-1)|| (start <= (swa[x].second+k-1)%n))x++;
						else break;
					}	
				}
				cout << swa[x].first<<endl;
				ans[start] = swa[x].first;

			}
			else {
				cout << ans[start]<<endl;
			}
		}
	}

	return 0;
}