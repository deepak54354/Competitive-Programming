#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long

bool comp(pair<ll,int>& a, pair<ll,int>& b){
	int c = a.first/a.second,d = b.first/b.second;
	//cout << c << " " << d << endl;
	if(c==d) return a.second > b.second;
	return  c<d;
}
int main(){
	vector<pair<ll,int> > v(4);
	ll a,b,c,d,L;
	cin >> a >> b >> c >> d >> L;
	L*=100;
	int number;
	v[0]={a*100,25};v[1]={b*100,50};v[2]={c*100,100};v[3]={d*100,200};
	sort(v.begin(),v.end(),comp);
	ll ans = 0;
	int i = 0;
	//cout << v[3].second << " "<<v[2].second << endl;
	while(L and i <4){
		number = L/v[i].second;
		L-=number*v[i].second;
		ans+=1ll*v[i].first*number/100;
		i++;
		//cout << ans << endl;
	}
	cout << ans << "\n";
}