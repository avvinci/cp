// avvinci - march 17 
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

#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define siz size()
#define N 100004
const long long infl = 1e18+5;

ll m,n,p,q,x,y,k,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;
ll a[N] ,dp[N][2];
vector< vector < ll > > g(N); 

void dfs(int ver, int par = 0){
	if(a[ver] == 0 ){
		dp[ver][0] = 1;
		dp[ver][1] = 0 ;
	}
	else{
		dp[ver][0] = 0;
		dp[ver][1] = 1;
	}
	
	for(auto &it : g[ver]){
		if(it == par) continue;
		dfs(it,ver);

		dp[ver][0] += dp[ver][0] * dp[it][0];
		dp[ver][1] += dp[ver][1] * dp[it][0];
		dp[ver][1] += dp[ver][0] * dp[it][1]; 

	}
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n;


fr(i,2,n+1){
	cin>>p;
	g[p].pb(i);
	g[i].pb(p);
} 

fr(i,1,n+1){
	cin>>a[i];
}

dfs(1);
cout<<dp[1][1];
return 0 ;
}
