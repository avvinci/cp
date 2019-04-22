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
#define N 10004

const long long infl = 1e10+5;

ll n,m,k,q,x,y,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;
ll w[N] , dp[102][N] ;
vector< vector< int > > v(102);
ll rec( int ind ,int t ){
	if(t > q ) return infl ;
	if(ind == m ) return  q- t ;
	if(dp[ind][t] != -1) return dp[ind][t] ; 
	ll re = infl ; 
	int i ; 
	fr(i,0,v[ind].size()){
		re = min(re , rec(ind+1 ,t + v[ind][i]));
	}

	dp[ind][t] = re;
	return re; 
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}


cin>>t;
while(t--){
	cin>>n>>m>>q;
	fr(i,0,n){
		cin>>w[i];
	}
	fr(i,0,102) v[i].clear() ;
	
	fr(i,0,n){
		cin>>x;
		v[x-1].pb(w[i]);
	}
	memset(dp,-1,sizeof(dp));
	ans  = rec(0,0) ; 
	if(ans >= infl ) ans =-1 ; 
	cout<<ans<<"\n";
}



return 0 ;
}