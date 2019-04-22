// avvinci - summer_17 home
// #include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long int , long long int> P;

#define mod 1000000007 
#define pb push_back
#define mk make_pair
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define all(container) container.begin(),container.end()
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define sz(x)  (ll)x.size()
#define N 14

const long long infl = 1e18+5;

ll n,m,k,q,x,y,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;
ll a[N][N] ,dp[8500][N] ;

ll rec(int mask  , int prev ){
    int z = (1<<n)-1 ; 
    if(mask == z) return 0 ; 
    if(dp[mask][prev] != -1 ) return dp[mask][prev] ; 
    ll re = infl;
    int i ; 
    //   ws(mask) ;
    // ws(prev);
    fr(i,1,n+1){
        // cout<<(mask & (1<<(i-1)))<<"\n";
        int v = mask & (1<<(i-1)); 
        if(i != prev &&  v == 0  ){
            // ws(i);
            
            v = mask | (1<<(i-1));
            if(i == 1  && v != z ) continue; 
            re = min(re, a[prev][i] + rec( v  , i) );
        }
    }
    // ws(mask);
    // ws(re);
    dp[mask][prev] = re;
    return re ;
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>t;
while(t--){
    cin>>n;
    fr(i,1,n+1){
        fr(j,1,n+1){
            cin>>a[i][j] ;
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,1)<<"\n";
}

return 0 ;
}