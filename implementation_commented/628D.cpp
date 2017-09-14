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
#define N 2004

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,d,ans,mx = -1,mn = infl ;

string a , b ;
ll dp[N][N][2] ; 
ll rec(int ind ,int rem ,int st){

	if(ind == n+1 ){
		if(rem == 0 ) return 1;
		return 0 ; 
	}
	//st = 1 means ,current prefix is greater than 'a' 
	// st = 0 , means current prefix equals 'a'
	// rem stores modulus
	// ind is index of string (1-indexing)

	ll &re = dp[ind][rem][st] ; 
	if(re != -1) return re ;
	re = 0 ; 
	int i ,x = a[ind-1] -'0'; 

	if(ind & 1 ){

		int ss = 0  ; 
		if(st == 0 ) ss = x ; //choosing start index based on state , if st is 0 , we can't start from lower numbers

		fr(i,ss,10){
			if(i == d ) continue ;  // d not allowed on odd positions

			if( i > x ) 
				re += rec(ind+1 , (rem*10 + i)%m ,1) ;  // since i > x then we are in state  1 
			else
				re +=  rec(ind+1 , (rem*10 + i)%m , st) ; 
			re %= mod; 
		}

	}
	else{
		// only d allowed on even positions 
		if(st == 1 || d > x) 
			re += rec(ind+1 , (rem * 10 + d)%m ,1 ) ;  // since d > x then we are in state  1 
		else if(d == x  && st == 0  )
			re += rec(ind+1 , (rem * 10 + d)%m ,st) ;  
	}
	re %= mod;
	return re; 
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>m>>d;
cin>>a>>b;
n= a.size();

int sh =  1 ; // sh is 1 if 'b' is d-magic 

// check 'b' is d-magic or not
//-------------------------------------- ---------------- 
fr(i,0,b.size()){
	if(i%2 == 0 && b[i] -'0' == d ) sh = 0 ;
	else  if( i %2 == 1 && b[i] - '0' != d ) sh = 0 ; 
	sz = sz * 10 + b[i] - '0' ; 
	sz %= m ; 
}
if(sz != 0 ) sh = 0 ; 
//-------------------------------------------------------

memset(dp,-1,sizeof(dp)) ; 
ll val1 = rec(1,0,0) ;  // val1 stores all numbers greater than 'a' that are d-magic  (one indexing used )    
a = b ;
memset(dp,-1,sizeof(dp)) ; 
ll val2 = rec(1,0,0); // val2 stores all numbers greater than 'b' that are d-magic  

cout<< (val1 - val2 + sh  + mod ) %mod;



return 0 ;
}
