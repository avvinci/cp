// avvinci
//#include"prettyprint.hpp"
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
#define sz size()
#define N 300005
const long long infl = 1e18+5;

ll m,n,q,cn,i,j,k,w,pos,tmp1,sz,mx =-1,tmp,mx1 = -1,val,sm,a,b,c,d,mn = infl ,cnt=1,k1,ans,p,x;
//vector< vector< int > > g(N);
//ll cons[N][N] ,dp[N][N][11];
double d1;
//string s,t;
 ll powmod( ll  a1 , ll p1 ){
 	ll  res  = 1 ;
 	a1  = (a1+mod)%mod;
 	while(p1 > 0 ){
 		if(p1 & 1){
 			res = res*a1 ;
 			res %=mod;
 		}
 		a1 = a1*a1;
 		a1 %=mod;
 		p1 /=2;
 	}
 	return res;


 }


int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>a>>b>>n>>x;

if(a == 1){
	cout<< (x + (n%mod)*b%mod)  %mod ;
}
else{
	ll  v1  = powmod(a,n);
	ll v2  = powmod(a-1,mod-2);
	 ans = v1*x%MOD + b*((v1-1+MOD)%MOD)%MOD*v2%MOD;
    
  // cout << ans%MOD << "\n";
	cout<<( v1*x%mod + ((b * (v1-1+mod )%mod )%mod) *v2%mod)%mod<<endl; 
	cout<<((powmod(a,n)*x)%mod +(b*((((powmod(a,n) -1 + mod) %mod) * powmod(a-1,mod-2) )%mod) ) %mod ) %mod; 
}


return 0;
}