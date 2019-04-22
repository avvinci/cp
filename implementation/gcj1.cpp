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
#define N 104

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mx = -1,mn = infl ;
ll dp[N][N][N][2] ;
string s ; 
vector< char >v ;

ll rec(int ind ,int l ,int r , int st ){
  if(ind == n+1 ) return 0 ; 

  int i , j ; 
  ll re = infl ; 
  if(dp[ind][l][r][st] != -1) return dp[ind][l][r][st] ; 
  
  re = 1 +  rec(ind+1 , l, r ,0 )  ;
  
  fr(i,ind,n+1){
    if( l + i - ind <= r && v[i] == v[l+i-ind] ){
       re = min ( re , 1 +  rec(i + 1, l, r , 0 ) ) ;
    }
    else break ;
  }
  if(st == 0 ) {
    fr(i,1,ind){
      fr(j,i,ind){
        re = min(re ,1 + rec(ind ,i ,j , 1)) ; 
      }
    }

  }
  dp[ind][l][r][st] =re; 
   return re;

}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>t;
sz = t ;
while(t--){
  cin>>s;
  n = s.size() ; 
  v.clear();
  v.pb('.') ; 
  memset(dp,-1,sizeof(dp))  ;
  fr(i,0,s.size()) {
    v.pb(s[i]) ; 
  }
  cout<< "Case #"<<sz-t<<": "<<rec(1, 0 , 0 , 0  )<<"\n" ; 

}



return 0 ;
}