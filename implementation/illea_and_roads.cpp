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
#define N 310
const long long infl = 1e18+5;

ll m,n,p,q,x,y ,cn,k,tmp1,tmp,mx =0 ,f,val,sz,cnt,ans,t=1,ii,jj;
ll	dp[310][310],dp2[310][310],a[310],b[310],c[310];
ll  rec( int ind ,int len ){

	if(ind == n+1 ){
		if(len < k )
			return infl;
		return 0;
	}
	
	if(dp2[ind][len] != -1)
		return dp2[ind][len];

	ll re = infl ,i ;
	re = rec(ind+1 ,len);

	fr(i,0, n-ind +1){

		ll v1 = infl ;
		if(dp[ind][ind+i] !=infl )
			v1  = rec(ind+i+1, len+i+1);
		if(v1 != infl  ){
			re =  min(v1 + dp[ind][ind+i] ,re);
		}
		
	}
	dp2[ind][len] = re;
	return re;


}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>n>>m>>k;
int i,j;
fr(i,0,N){
	
	fr(j,0,N){
		dp[i][j] =infl;
		dp2[i][j] = -1;
	}
	
}
fr(i,0,m){
	cin>>a[i]>>b[i]>>c[i];
	dp[a[i]][b[i]] = min(c[i],dp[a[i]][b[i]]);
}

fr(i,1,n+1){
	fr(j,1,n+1){
		dp[j][i] = min(dp[j][i], dp[j-1][i]);
	}
}

ll re = infl;
re  = rec(1,0);
if(re == infl)
	cout<<"-1";
else 
	cout<<re;
return 0;







// fr(x,1,n+1){

// 	for(i=x;i>=1;i--){
// 		dp2[x][x-i+1] = dp2[x-1][x-i+1];
// 		fr(j,1,x)
// 		dp2[x][x-i+1] = min(dp2[x][x-i+1] ,dp2[x-1][x-j] +  dp[i][x]);

// 	}

// }
// ws(dp2);


}
