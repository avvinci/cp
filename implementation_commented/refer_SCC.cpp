// avvinci -  sem 8    
// #include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long,long long > P;

#define mod 1000000007 
#define pb emplace_back
#define fs first
#define sc second
#define ll long long 
#define fr(it,st,en) for(it=st;it<en;it++)
#define all(container) container.begin(),container.end()
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl;
#define N 1000004

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t,i,j;
ll ind,cnt,sm,ans,mx,mn;
ll a[N] ,vis[N] ,sz[N] ,b[N];

stack< ll > st ;  
vector< ll > g[N], gr[N] ; // input graph  and reverse graph 
vector< ll > vu, v[N], vans ; 
set< ll > gn[N] ; // graph of SCC


/* DFS on reverse graph to find Strongly connected components ----------------------------*/
void dfs1(int u ){
	if(vis[u] == 2) return; 
	vis[u] = 2; 
	v[cnt].pb(u) ; 
	for(auto it : gr[u])
		dfs1(it);
}


/* DFS on input graph and push to stack at the end -----------------------------------*/
void dfs(int u){
	if(vis[u] ) return ; 
	vis[u] =1;
	for(auto it: g[u]) {
		dfs(it) ;
	}
	st.push(u) ; 
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
 /* input  -------------------------------------------------------*/ 
ll h;
cin>>n>>m>>h;
fr(i,0,n) cin>>a[i] ; 
fr(i,0,m){
	cin>>x>>y ;
	x-- ; y-- ; 
	if(a[x] == (a[y] + 1 )%h ) {
		g[y].pb(x);
		gr[x].pb(y);
	}
	if( a[y] == (a[x]+1)%h){
		g[x].pb(y);
		gr[y].pb(x) ; 
	}
}


 /* SCC  -------------------------------------------------------*/ 
fr(i,0,n){
	if(vis[i]) continue;
	dfs(i); 
}

while(!st.empty()){
	ll  u = st.top() ; 
	st.pop() ; 
	if(vis[u] == 2) continue;
	cnt++ ; 
	dfs1(u) ;

	fr(i,0,v[cnt].size()) 
		b[v[cnt][i]] = cnt ;  
	sz[cnt] = v[cnt].size() ; 
}

/* creating graph of SCC, where each SCC is a single node --------------------*/
fr(i,0,n){
	for(auto it : g[i]){
		if(b[it] == b[i]) continue;
		gn[b[i]].insert(b[it]) ; 
	}
}


/* calculating answer ----------------------------------------------------*/
ans = infl ; 
fr(i,1,cnt+1){
	if(gn[i].empty()){
		if(ans > sz[i]){
			ans = sz[i] ;
			vans = v[i] ; 
		}
	}
}
if(ans == infl  ){
	cout<<n<<"\n" ; 
	fr(i,1,n+1) cout<< i <<" " ; 
	return 0 ; 
}

/* printing answers----------------------------------------------------------*/
cout<<vans.size()<<"\n"; 
fr(i,0,vans.size()) 
	cout<<vans[i]+1<<" " ; 

return 0 ;

}