// avvinci - sem_7 
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
#define N 201

const long long infl = 1e6+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mx = -1,mn = infl ;
ll a[N];
int b[N] ,c[N] ;
int dp[N][N][651][2];

int  rec(int ind , int num ,int ex ,int st) {
	if(ex > 650 ) ex = 650; 
	if(ind == n || num == k ) return 0 ;
	int &re = dp[ind][num][ex][st] ; 
	if(re != -1 ) return re;
	int nst =st , nex = ex ,ans  = 0 ; 
	if(st == 0 ){
		nex += c[ind];
		ans = min(nex , b[ind]) ; 
		nex -= b[ind]  ;
	}
	else{
		nex += b[ind];
		ans = min(nex,c[ind]) ; 
		nex -= c[ind] ; 
	}

	
	if(nex < 0 ){
		nex *= -1 ; 
		nst = 1 -st ; 
	}

	re = max(rec(ind+1,num,ex,st) , ans + rec(ind+1,num+1, nex , nst )) ; 
	// cout<<ind<<" "<<num<<" "<<ex<<" "<<st<<" \n";
	// ws(re);

	return re ; 


}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n>>k;
memset(dp,-1,sizeof(dp));
sm = 1;
fr(i,0,n){
	cin>>a[i] ;
	x = a[i] ; 
	while(x > 0 && x%5 == 0 ){
		x /= 5 ; b[i]++;
	} 
	while(x > 0 && x % 2 == 0 ){
		x /= 2; 
		c[i]++;
	}
}

cout<<rec(0,0,0,0);

return 0 ; 
}