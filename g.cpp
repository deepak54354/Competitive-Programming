#include<bits/stdc++.h>
using namespace std;

int main()
 {
    //code
    int t;
    cin >> t;
     
    while(t--){
        int n,k;
        cin >> n >> k;
        
        vector<int> v(n);
        multiset<int> my;
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        
        for(int i = 0; i < k; i++)
            my.insert(v[i]);
        cout << *(my.end()) << ' ';
        
        for(int i = k; i < n; i++){
           // cout << v[i-k] << ' ' << v[i] << '\n';
           // cout << *my.find(v[i-k]) << '\n';
            my.erase(my.find(v[i-k]));
            my.insert(v[i]);
           // for(auto it : my)
               // cout << it << ' ';
           // cout << '\n';
            cout << *(my.end()) << ' ';
        }
        cout << '\n';
    }
    return 0;
}