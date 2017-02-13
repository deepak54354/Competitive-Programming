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

class ZigZag {
public:
	int longestZigZag(vector <int>);
};

int ZigZag::longestZigZag(vector <int> sequence) {
	int len = sequence.size();
	vector<int> dif(len-1);
	vector<int> sum(len);
	for(int i = 0; i < len-1; i++){
		int k=sequence[i]-sequence[i+1];
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
	for(int i =0;i < len-1;i++){
		if(dif[i]!=-1){
			flag = true;
			break;
		}
	}
	if(!flag) return 1;
	for(int m = 0; m < len-1; m++){
		int j = m;
		for(int i = j+1; i < len-1; i++){
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


//Powered by [KawigiEdit] 2.0!
