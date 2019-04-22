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
#define N 1000004
#define B 41
const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mx = -1,mn = infl ;
ll a[N] ,tr[4*N + 5 ][2] , en[4*N] ;

void insert(ll x){

	int i ; 
	vector< int > v ;
	fr(i,0,B){
		v.pb(x%2);
		x /= 2;
	}
	reverse(all(v)) ; 
	 ll node = 0 ;
	fr(i,0,B){
		if(tr[node][v[i]] == 0 ){
			tr[node][v[i]] = t++;
		}
		node = tr[node][v[i]] ; 
	}
	en[node] = 1 ; 
}

ll get(ll x ){
		int i ; 
	vector< int > v ;
	fr(i,0,B){
		v.pb( 1 - x%2);
		x /= 2;
	}
	reverse(all(v)) ; 
	ll re = 0 , node = 0 ;
	fr(i,0,B){
		if(tr[node][v[i]] == 0 ){
			node = tr[node][1 - v[i]]  ;
		}
		else {
			re  += (1LL<<(B-1- i)) ; 
			node = tr[node][v[i]] ; 
		}
		if(node == 0 ) break ;
		// ws(node);

	}
	return re; 
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n>>m;
fr(i,0,n){
	cin>>a[i];
}
fr(i,0,n){
	x = 0 ;
	fr(j,i,n){
	    x ^= a[j] ;
	    if( (j -i ) % 2 == 1 ) 
	        ans = max(ans , x );
		else
	    	insert(x) ; 
	}
}

fr(i,0,m){
	cin>>a[i];
}
// ans = 0 ;
fr(i,0,m){
	x = 0; 
	fr(j,i,m){
	    x ^= a[j] ;
	    if( (j -i ) % 2 == 1 ) 
	        ans = max(ans , x );
	   else
		    ans = max(ans , get(x)); 
// 		ws(ans);
	}
}

cout<<ans;
return 0 ;
}