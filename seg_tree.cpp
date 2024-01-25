//Ram Ram
#include <bits/stdc++.h>
 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
#define ll     long long
#define int    long long int
#define _test  int _TEST; cin>>_TEST; while(_TEST--)
#define ff     first
#define ss     second
#define pb     push_back
#define ppb    pop_back
#define all(x) (x).begin(),(x).end()
#define fr(i,s,e) for(int i=s;i<e;i++)
#define read(x) for(auto &i:x) cin>>i;
#define write(x) for(auto i:x) cout<<i<<" ";
#define input(n) int n; cin>>n;
 
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;//find_by_order,order_of_key


const int N=2e5+10;
int a[N],seg[4*N];


void build(int ind,int tl,int tr){
    if(tl==tr){
        seg[ind]=a[tl];
        return;
    }
    int mid=(tl+tr)/2;
    build(2*ind+1,tl,mid);
    build(2*ind+2,mid+1,tr);
    seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}

int query(int ind,int tl,int tr,int l,int r){
    if(tl>=l && tr<=r) return seg[ind];
    if(l>tr || r<tl) return INT_MAX;
    int mid=(tl+tr)/2;
    return min(query(2*ind+1,tl,mid,l,r),query(2*ind+2,mid+1,tr,l,r));
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //Segment tree is a data structure which is capable of performing range queries in O(logn) time
    //and also perfrom updates in O(logn) time so it is quite useful.
    // we will use devide and conqure approach.

    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++) cin>>a[i];
    build(0,0,n-1);
    while(q--){
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<query(0,0,n-1,l,r)<<"\n";
    }
}