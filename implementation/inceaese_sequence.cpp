// avvinci - summer_17  home
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
#define N 2004

const long long infl = 1e18+5;

ll n,m,q,x,y,mx =-1,mn=infl,f,val,sz,cnt,ans,t=1,i,j,ind=-1;
ll a[N] ,dp[N][N],h;
ll rec(int ind ,int open){

	if(open < 0  ) return  0 ; 

	// if(ind == n ){
	// 	if(open == 0 ) return 1;
	// 	return 0 ; 
	// }

	if(dp[ind][open] != -1 ) return dp[ind][open] ; 

	ll re = 0 ; 

	if(a[ind] + open == h ) {

		re +=  rec(ind+1 , open ) ; 
		re %= mod ; 
		
		re += open * rec(ind+ 1, open -1 ) ; 
		re %= mod ; 

	}
	else if  (a[ind] + open == h - 1) {
		re +=  rec(ind+1, open +1) ; 
		re %= mod ;

		re +=  rec(ind+1, open) ; 
		re %= mod ;  
	}
	else
		return 0  ;



	re += 2 * rec(ind+1, open) ; 
	re %= mod ; 

	re += 2 * rec(ind+1 , open + 1) ; 
	re %= mod ; 
	
	re += open * rec(ind+ 1, open -1 ) ; 
	re %= mod ; 

	dp[ind][open] = re;
	return re;

}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
memset(dp,-1,sizeof(dp));
cin>>n>>h;
fr(i,0,n) cin>>a[i];
cout << rec(n-1,0) ; 




return 0 ;
}