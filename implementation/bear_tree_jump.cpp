// avvinci
// march 17 
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
#define N 200004
const long long infl = 1e18+5;

ll m,n,p,q,x,y ,cn,k,tmp1,tmp,mx =-1 ,mn=infl,f,val,sm,cnt,ans,t=1,i,j,ind = -1,ci;
ll a[N][6] ,sz[N] ;
vector< vector < ll > > g(N); 
ll u , v ; 
void dfs(int ver ,int par){
	sz[ver] = 1;
	int i , j;

	for(auto &it : g[ver]){
		if(it == par) continue;
		dfs(it,ver);
		sz[ver] += sz[it];
		sm += sz[it]*(n-sz[it]);
		fr(i,0,k){
			fr(j,0,k){
				a[ver][ (i+j+1) % k] += a[ver][j] * a[it][i];
			}
		}
		cout<<"it  = "<<it<<" "<<ver<<"\n";
		fr(i,0,k){
			
			a[ver][(i+1)% k] += a[it][i];
			 ws(a[ver][i]);
		}
		// a[ver][1]++;

		

	}
	ws(ver);
	a[ver][0]++;
	fr(i,0,k){
			// a[v/er][(i+1)%k] += a[it][i];
			ws(a[ver][i]);
		}
		cout<<"..\n";


}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>n>>k;

fr(i,0,n-1){
	cin>>u>>v;
	g[u].pb(v);
	g[v].pb(u);
} 

dfs(1,0); 
ws(sm);
fr(i,1,k){
	cnt = 0;
	fr(j,0,n){
		cnt += a[j][i];
	}
	// ws(cnt);
	sm += (k-i)*cnt;
}
ws(sm);
cout<<sm/k ;
return 0 ;
}
