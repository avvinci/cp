// avvinci
// march 17 home
// #include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;
typedef pair<long long int , long long int> P;
#define mod 1000000007 
#define all(container) container.begin(),container.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin();it!=container.end();it++)
#define pb push_back
#define CLR(arr) memset(arr, 0, sizeof(arr))
#define mk make_pair
#define present(container,x) ((container).find(x) != (container).end())
//#define infl LLONG_MAX
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define siz size()
#define N 3004
const long long infl = 1e18+5;

ll m,n,p,q,x,y ,cn,k,tmp1,tmp,mx =-1 ,mn=infl,f,sz,sm,cnt,fans,t=1,i,j,ind = -1,ci;
ll a[N] ,c[N],ans,d,u,v;
vector< vector<int > >  g(N);

void dfs(int ver , int par ,int val ,int ind){
	// ws(ver);
	// ws(val);
	// ws(a[ver]);
	if( (a[ver] < val) || ((a[ver]-val ) > d ) ) {
		c[ver] = 0 ;
		return;}
	if(a[ver] == val  && ver < ind) {
		c[ver] = 0;
		return;
	}
// ws(ver);

	for(auto &it :g[ver])
	{
		

		if(it == par) continue;
		dfs(it,ver,val, ind);
		c[ver] *= (c[it]+1) ;
		c[ver] %= mod;
	
		
	}

	

}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>d>>n;
fr(i,1,n+1){
	cin>>a[i];
	c[i]=1;
} 
fr(i,0,n-1){
	cin>>u>>v;
	g[u].pb(v);
	g[v].pb(u);
}

fr(i,1,n+1){
	ans = 1;
	dfs(i,0,a[i],i );
	// ws(c[i]);
	fans += c[i];
	fans %= mod;
	fr(j,1,n+1)
		c[j] =1;

}

cout<<fans;
return 0 ;
}
