#include <bits/stdc++.h>
using namespace std;

#define Pi 3.141592653589793
#define eps 1e-9
#define MAX int(1e9)
#define MIN int(-1e9)
#define SQR(n) (n*n)
#define MEM(a,val) memset(a,val,sizeof(a))
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vii vector< vector<int> >
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define all(v) ((v).begin(),(v).end())
#define FOR(i,a,b) for(int i = a; i <= b; i++)
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
int n;
vi DFS(vii adj, int v){
    vector<bool> visited(n,false);
    vi color(n,-1);
    vi parent(n,-1);
    color[v] = 1;

    stack<int> s;
    s.push(v);

    while(!s.empty()){
        int cur = s.top();
        s.pop();

        if(!visited[cur]) visited[cur] = true;
        int c = 1,y = color[cur],x;
        if(parent[cur] == -1) x = color[cur];
        else x = color[parent[cur]];
        for(vi::iterator it = adj[cur].begin(); it != adj[cur].end(); it++){
            if(!visited[*it]){
                s.push(*it);
                parent[*it] = cur;
                while(color[*it] == -1){
                    if(c != x && c != y) color[*it] = c;
                    c++;
                }
            }
        }
    }
    return color;
}
int main()
{
    fast_io;
    //ifstream in_file("file.in");
    //ofstream out_file("file.out");
    cin >> n;
    vi v(1,-1);
    vii adj(n,v);
    FOR(i,0,n-2){
        int a,b;
        cin >> a >> b;
        a--;b--;
        if(adj[a][0]== -1) adj[a].pop_back();
        if(adj[b][0]== -1) adj[b].pop_back();
        adj[a].pb(b),adj[b].pb(a);
    }
    vi color = DFS(adj,0);
    cout << *max_element(color.begin(),color.end()) << endl;
    FOR(i,0,n-1){
        cout << color[i] << " ";
    }
    cout << endl;
    return 0;
}