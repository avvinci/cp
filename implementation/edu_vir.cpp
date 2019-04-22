// avvinci - sem_7 
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
#define N 1000004

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mx = -1,mn = infl ;
ll a[N] ,dp[N][11][2];
vector< ll > g[N] ;
// ll dfs(int u , int p ){

//     dp[u][0] = 1 ; 
//     dp[u][1] = m-1 ; 
//     for(auto it : g[u]){
//         if(it == p ) continue ; 
//             dfs(it,u) ; 
//     }

//     ll sm = 1 , rg = 1; 
//     for(auto it : g[u]){
//         if(it == p ) continue ; 
//         sm *= dp[it][1] ;
//         sm %= mod; 
//         rg *= (dp[it][1] + dp[it][0]) ; 
//         rg %= mod; 
//     }
//     rg -= sm ; 
//     rg += mod ; 
//     rg %= mod ;
//     dp[u][1] = rg * (k-1) ;
//     dp[u][1] %= mod;
//     dp[u][1] += sm * (m-1) ;
//     dp[u][1] %= mod ;
//     dp[u][0] = sm  ; 
// }
ll dfs(int u , int c , int st , int p ){
    if(dp[u][c][st] !=  -1) return dp[u][c][st] ; 
    ll re = 0 ;
    // ws(u);
    if(g[u].size() == 1 ){
        if(u == 1) {
            return m ; 
        }
        if(st == 1  ){
            return (k-1) ;
        }
        if(st == 0 ){
            if(c == x ) return (m-1) ; 
            else if( k <= 1) return (m-1) ;
                return (m) ;
        }
    }
    for(auto it : g[u]){
        if(it == p ) continue ; 
        if(c == x ){
            if(st){
                re += (k-1) * dfs(it,c,0,u) ; 
            }
            else{
                re += (m-1) * dfs(it , c, 0 , u ) ;
            }
        }
        else{
            if(st){
                re += (k-1)*dfs(it,c,0,u) ; 
            }
            else{
                re += (m-1)*dfs(it,c,0,u) ;
                re %= mod;  
                re += dfs(it,c+1,1,u) ; 
            }
        }
        re %= mod;
    }
    re %= mod ;
    dp[u][c][st] = re;
    ws(u);
    ws(st);
    ws(re);
    return re ; 
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cout<<"1000\n";
fr(i,10,1021) cout<<i<<"\n" ; 
// cin>>n>>m;
// fr(i,0,n-1){
//     cin>>x>>y;
//     g[x].pb(y) ; 
//     g[y].pb(x) ; 
// }
// cin>>k>>x ; 
// memset(dp,-1,sizeof(dp)) ; 
// dfs(1,0,0,0);
// fr(i,0,x+1){
//     if(dp[1][i][0] != -1)
//     ans += dp[1][i][0];
//     if(dp[1][i][1] != -1 )
//     ans += dp[1][i][1] ; 
// }
// // ws(dp[1][0]);
// // ans = (dp[1][0]  + dp[1][1]) ; 
// // ans %= mod; 
// cout<< ans; 

return 0 ;
}