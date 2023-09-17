//Ram Ram
#include <bits/stdc++.h>
/*


SPARSE TABLE for static range queries for non invertible operations




*/
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

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;//find_by_order,order_of_key

const int MAX_N=2e5+10;
const int LOG=17;
int a[MAX_N];
int m[MAX_N][LOG];

int query(int l,int r){
  int len=r-l+1;
  int k=__lg(len);
  return min(m[l][k],m[r-(1<<k)+1][k]);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,q;
    cin>>n>>q;
    fr(i,0,n){
      cin>>a[i];
      m[i][0]=a[i];
    }
    //preprocessing O(N*LOGN)
    for(int j=1;j<LOG;j++){
      for(int i=0;i+(1<<j)-1<n;i++){
        m[i][j]=min(m[i][j-1],m[i+(1<<(j-1))][j-1]);
      }
    }
    while(q--){
      int l,r;
      cin>>l>>r;
      cout<<query(l-1,r-1)<<"\n";
    }
}
