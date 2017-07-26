#include <bits/stdc++.h>
using namespace std;

int *a;
int *tree;
void build(int node,int start,int end){
    if(start==end){
        tree[node]=a[start];
        return;
    }
    
    //divide range
    int mid = (start+end)/2;
    //recurse on left child
    build(2*node,start,mid);
    //recurse on right child
    build(2*node+1,mid+1,end);
    //merging logic
    tree[node]= min(tree[2*node],tree[2*node+1]);
}
void update(int node, int start, int end, int idx, int val){
    if(idx<start || idx>end||start>end) return;
    if(start ==end){
        a[idx]=val;
        tree[node]=val;
        return;
    }
    int mid = (start+end)/2;
    update(2*node,start,mid,idx,val);
    update(2*node+1,mid+1,end,idx,val);
    tree[node]=min(tree[2*node],tree[2*node+1]);
}
int query(int node, int start, int end, int l,int r){
    if(l >end || r<start || start > end) return 10000000;
    if(l<=start && r >=end){
        return tree[node];
    }
        int mid = (start+end)/2;
        int p1 = query(2*node,start,mid,l,r);
        int p2 = query(2*node+1,mid+1,end,l,r);
        return min(p1,p2);
}
int main()
{
    int n,q;
    cin >> n >>q;
    a = new int[n+1];
    tree = new int[2*n+10];
    for(int i =0; i <=n-1;i++) cin >> a[i];
    build(1,0,n-1);
    //cout << "sda" << endl;
    while(q--){
        char c;
        int x,y;
        cin >> c >> x >> y;
        if(c=='u') update(1,0,n-1,x-1,y);
        else cout << query(1,0,n-1,x-1,y-1) << endl;
    }
    return 0;
}
