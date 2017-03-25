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

using namespace std;

class BadNeighbors {
public:
	int maxDonations(vector <int>);
};

int BadNeighbors::maxDonations(vector <int> donations) {
	int n = donations.size();
	vector<int> dp1(n-1,0);
	vector<int> dp2(n-1,0);
	if(n <=3) return *max_element(donations.begin(),donations.end());
	dp1[0] = donations[0];
	dp1[1] = donations[1];
	dp1[2] = donations[0]+donations[2];
	dp2[0] = donations[1];
	dp2[1] = donations[2];
	dp2[2] = donations[1]+donations[3];
	for(int i = 3; i < n-1; i++){
		dp1[i] = max(dp1[i-2],dp1[i-3]) + donations[i]; 
	}
	for(int i = 4; i<n; i++){
		dp2[i-1] = max(dp2[i-3],dp2[i-4])+donations[i];
	}
	for(int 
	return max(dp1[n-2],dp2[n-2]);
}


//Powered by [KawigiEdit] 2.0!
