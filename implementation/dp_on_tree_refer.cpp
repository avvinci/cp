// avvinci -  Winters (12/17)  
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
#define N 100004

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mx = -1,mn = infl ;
ll a[N] , temp[3][11] , dp[N][3][11];
int vis[N] ; 
vector< ll > g[N] ; 

void dfs(int u ){
    vis[u]  = 1; 
    int i , j  ; 
    dp[u][0][0] = k-1 ; 
    dp[u][1][1] = 1 ; 
    dp[u][2][0] = m - k ;  
    for(auto it : g[u] ){
        
        if(vis[it]) continue; 
        dfs(it) ; 
        fr(i,0,3){
            fr(j,0,x+1){
                temp[i][j] = 0  ; 
            }
        }
        fr(i,0,x+1){
            for(j= 0; i+j <= x ; j++){
                temp[0][i+j] +=  ( dp[u][0][i] * (dp[it][0][j] + dp[it][1][j] + dp[it][2][j]) ) %mod ; 
                temp[1][i+j] += (dp[u][1][i] * ( dp[it][0][j])  ) %mod; 
                temp[2][i+j] +=  ( dp[u][2][i] *(dp[it][0][j] + dp[it][2][j])) %mod ;
                temp[0][i+j] %= mod ; 
                temp[1][i+j] %= mod ; 
                temp[2][i+j] %= mod ;  
            }
        }
        fr(i,0,3){
            fr(j,0,x+1){
                dp[u][i][j] = temp[i][j] ; 

            }
        }

    }
}


int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n>>m;
fr(i,0,n-1){
    cin>>x>>y; 
    x-- ; y-- ; 
    g[x].pb(y) ;  
    g[y].pb(x) ;
}
cin>>k>>x ; 
dfs(0) ;

fr(i,0,3){
    fr(j,0,x+1){
        ans += dp[0][i][j] ; 
        ans %= mod;
    }
}

cout<<ans; 

return 0 ;
}