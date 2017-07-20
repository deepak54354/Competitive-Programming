#include <bits/stdc++.h>
using namespace std;
#define N (int)(1e5+10)
int n;
bool a[N];
int tree[N<<1];
int lazy[N<<1];
void build(int node, int start, int end){
    if(start==end){
        tree[node]=a[start];
    }
    else{
        int mid = (start+end)>>1;
        build(node<<1,start,mid);
        build(node<<1|1,mid+1,end);
        tree[node]=tree[node<<1]+tree[node<<1|1];
    }
}
void modify(int node,int start, int end, int l, int r, int val){
    if(start>r || end<l || start>end) return;
    if(lazy[node]!=0){
        tree[node]+=(r-l+1)*lazy[node];
        if(start!=end){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>=l && end<=r){
        tree[node]+=(r-l+1)*val;
        if(start!=end){
            lazy[node<<1]+=val;
            lazy[node<<1|1]+=val;
        }
        return;
    }
    int mid = (start+end)/2;
    modify(node<<1,start,mid,l,r,val);
    modify(node<<1|1,mid+1,end,l,r,val);
    tree[node]=tree[node<<1]+tree[node<<1|1];
}
int query(int node, int start, int end, int l, int r){
    if(start>r ||end<l||start>end) return 0;
     if(lazy[node]!=0){
        tree[node]+=(r-l+1)*lazy[node];
        if(start!=end){
            lazy[node<<1]+=lazy[node];
            lazy[node<<1|1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(start>=l&&end<=r) return tree[node];
    int mid=(start+end)/2;
    int p1 = query(node<<1,start,mid,l,r);
    int p2 =query(node<<1|1,mid+1,end,l,r);
    return p1+p2;
}

int main()
{
    cin >> n;
    for(int i=0;i<2*n;i++) lazy[i]=0;
    for(int i = 0; i < n; i++){
        int l;
        cin >> l;
        a[i]=l&1;
    }
    build(1,0,n-1);
    int q;
    cin >> q;
    while(q--){
        int Q,x,y;
        cin >> Q >> x>>y;
        if(Q==0) modify(1,0,n-1,x,x,y);
        else if(Q==1) cout << (y-x+1)-query(1,0,n-1,x,y) << endl;
        else cout << query(1,0,n-1,x,y) << endl;
    }
    return 0;
}
