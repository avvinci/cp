// avvinci - April 17 
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
#define siz(x)  (ll)x.size()
#define cnn continue
#define N 100004
const long long infl = 1e18+5;

ll m,n,q,x,y,k,mx =-1,mn=infl,f,val,sz,sm,cnt,ans,t=1,i,j,ind=-1;
ll a[N],dp[N] ,mrk[N];
int b[N/100];
std::vector<int> p;
vector< std::vector<ll > >  v(N);
void seive(){
	int i,j;
	fr(i,2,N/100){
		if(b[i]) cnn;
		for(j=i+i;j<N/100;j += i)
			b[j] =1;
		p.pb(i);
	}
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n;
seive();
dp[0] =1;
fr(i,1,N){
	dp[i] =2*dp[i-1];
	dp[i] %= mod;
}
// ws(siz(p));
fr(i,0,n){
	cin>>a[i];
	t = a[i];

	fr(j,0,siz(p)){

		f = 0 ;
		while(t%p[j] == 0){
			f = 1;
			t /= p[j];
		}

		if(f) v[p[j]].pb(i);

	}
	// ws(t);
	if(t > 1 ){
		v[t].pb(i);
	}


}

fr(i,2,8){

	// 
	fr(j,0, siz(v[i])){
		if(mrk[v[i][j]])
			cnt++;
		mrk[v[i][j]] =1;
	}
	// ws(siz[v]);
	if(siz(v[i])-cnt < 1) cnn;
	ans += (dp[cnt] * dp[siz(v[i]) -cnt] - 1 + mod )%mod; 
	ans %= mod;
ws(siz(v[i]));
ws(cnt);
ws(ans);

}


cout<<(dp[n] - ans - 1 + mod ) %mod;


return 0 ;
}