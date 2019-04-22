// avvinci
// #include"prettyprint.hpp"
#include<bits/stdc++.h>
using namespace std;

typedef pair<long long int , long long int> P;
#define mod 1000000007 
#define MOD 1000000007
#define all(container) container.begin(),container.end()
#define tr(container,it) for(typeof(container.begin()) it = container.begin();it!=container.end();it++)
#define pb push_back
#define CLR(arr) memset(arr, 0, sizeof(arr))
#define mk make_pair
#define present(container,x) ((container).find(x) != (container).end())
#define inf 3234567891
//#define infl LLONG_MAX
#define fs first
#define sc second
#define ll long long int
#define fr(it,st,en) for(it=st;it<en;it++)
#define INP ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ws(x) cout << #x << " = " << x << endl
#define siz size()
#define N 1003
const long long infl = 1e12+5;

ll m,n,pp,q,x,y ,cn,k,tmp1,tmp,mx =0 ,mn,f,val,sz,sm,cnt,ans,t=1,i,j,ind,ci;

ll dp[N][N][2],h[N],d[N];
char a[N][N];

ll solve(int ind , int len ,int st){
	if(ind == m ){
		if(len >= x)
			return 0 ;
		else
			return 987654321;
	}
	
	if(dp[ind][len][st] != -1)
		return dp[ind][len][st] ;
	ll re;
	 if(st == 0 ){
	 	if(len < x)
	 		re = d[ind] + solve(ind+1,len+1,st);
	 	else if(len >=x  && len < y){
	 		re =  min( d[ind] + solve(ind+1,len+1,st) , h[ind] + solve(ind+1,1,1));

	 	}
	 	else
	 		re= h[ind] + solve(ind+1,1,1);
	 }
	 else{
	 		if(len < x){
	 			re = h[ind] + solve(ind+1,len+1,st);
	 		}
	 		else if(len>= x && len <y){
	 			re = min(h[ind]+ solve(ind+1,len+1,st) , d[ind]+ solve(ind+1,1,0));
	 		}
	 		else
	 			re = d[ind] + solve(ind+1,1,0);

	 }



		dp[ind][len][st]  = re;
		return re; 
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>n>>m>>x>>y;
fr(i,0,n){
	fr(j,0,m){
		cin>>a[i][j];
	}
}
fr(i,0,m+2){
	fr(j,0,m+2){
		dp[i][j][0] = -1;
		dp[i][j][1] = -1;
	}
}

fr(i,0,m){
	fr(j,0,n){
		if(a[j][i] == '.')
			h[i]++;
		else
			d[i]++;
	}
	// ws(h[i]);
}
ans  =min( solve(0,0,0) ,solve(0,0,1));

cout<<ans;

return 0 ;
}