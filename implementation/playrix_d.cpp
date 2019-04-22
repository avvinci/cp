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
#define N 100004
#define B 41
#define M 1000004


const long long infl = 1e8+5;

ll n,q,x,y,mx =-1,mn=infl,f,val,sz,cnt,ans,t=1,i,j,ind=-1;
ll a ,b , h,w ,p[N] ,dp[B][M];
// int rec(int ind , int num){

// 	if(ind == n+1 ) return infl ;
// 	if(dp[ind][num ] != -1) return dp[ind][num]; 
// 	ll i  ,x = h, y = w , val = num ,r;
// 	fr(i,0,ind){
// 		r = val%2 ; 
// 		if(r == 1) x *= p[i] ;
// 		else  y *= p[i];
// 		val /= 2;
// 	} 

// 	if(x >= a && y >> b ) return 0 ; 
// 	ll re ;
// 	re = min ( rec(ind+1, num|(1<<ind) ) ,rec(ind+1, num ) );  
// 	dp[ind][num] = re;
// 	return re;
// }
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cout<<(1<<17);
// cin>>a>>b>>h>>w>>n;

// fr(i,0,n ){
// 	cin>>p[i];
// }
// sort(all(p[i]), greater<ll>()); 

// ans  = rec(0,0);
// if(ans >= infl ) 
// 	ans  = -1;
// cout<<ans ; 

return 0 ;
}