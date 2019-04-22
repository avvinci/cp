#include<bits/stdc++.h>
using namespace std;

typedef pair<long long int , long long int> P;
#define mod 1000000007
#define all(container) container.begin(),container.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin();it!=container.end();it++)
#define sz(a) int((a).size())
#define pb push_back
#define CLR(arr) memset(arr, 0, sizeof(arr))
#define mk make_pair
#define present(container,x) ((container).find(x) != (container).end())
#define inf 123456789123456
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define NL cout<<"\n";  
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define KM 100000
#define what_is(x) cout << #x << " = " << x << endl
// ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
// ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
#define N 123456
// struct sort_pred {
//     bool operator()(const std::pair<V,int> &left, const std::pair<V,int> &right) {
//         return left.second < right.second;
//     }  };

// bool compare(P a, P b){ return ((a.first) <  (b.first) ); }
//ll ord[123456],a[123456],f[123456],p[123456],s[123456];
// // ll find (ll u ){
// //     if(p[u]!=u)
// //         return(find(p[u]));
// //     return u;
// // }
// void  merge (ll u, ll v){
//     ll y = find(u);
//     ll yy = find(v);
//     p[yy] = y;
//     s[y] = s[yy] + s[y];
// }
// std::priority_queue<P, std::vector< P >, decltype(&compare)> pq(&compare);

ll i,j, n,col[N],sz[N],cnt[N],b[N];
vector< ll > g[N];
void setsize(ll u,ll par){
    sz[u]=1;
    for(auto &it:g[u]){
        if(it== par)    continue;
        setsize(it,u);
        sz[u] +=sz[it];
    }
    
}
void dfs( ll u ,ll par, ll keep){
    ll mx =-1,ind =-1;
    for(auto &it:g[u]){
        if(sz[it] > mx){
            mx= sz[it];
            ind = mx;
        }
    }
     for(auto &it:g[u]){
        if(it== par || it== ind)    continue;
        dfs(it,u,0);
    }
    if(ind!=-1){
         dfs(ind , u , 1);
         b[ind] =1;
    }
    add(u,par,1);
    
    
    if(ind!=-1){
         b[ind] =0;
    }
    if(keep == 0 )
        add(u,par,-1);
    
}
int main(){
INP
cin>>n;
fr(i,0,n)   cin>>col[i];
ll u ,v;
fr(i,0,n-1){
    cin>>u>>v;
    u--;v--;
    g[u].pb(v);
    g[v].pb(u);
}
setsize(0,-1);
dfs(0,-1,0);

return 0;
}
