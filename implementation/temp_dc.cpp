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

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mx = -1,mn = infl ;
ll a[N] ;
map< P , ll > mp ; 
ll pos[N] ,tr[N]  ; 
map< ll , ll  > num  ;
vector< ll > v ; 

int get( int ind) {
  ll re = 0 ; 
  while( ind > 0 ){
    re += tr[ind] ; 
    ind -= (ind & -ind) ; 
  }
  return re; 
}
void upd( int ind  , int val){
  while(ind < N) {
    tr[ind] += val; 
    ind += (ind & -ind) ; 
  }

}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>n;
fr(i,0,n){
  cin>>a[i] ; 
  if(pos[a[i]] != 0 ) 
      mp[{a[i],num[a[i]]}] = i + 1;
  pos[a[i]] = i +1 ;
  num[a[i]]++ ;  
  v.pb(a[i]) ; 
}
sort(all(v)) ; 
ll pp= 1 , np , prev = -1 ;
while(cnt < n ){
  if(v[cnt] == prev ){
    ind++ ; 
    np = mp[{v[cnt] , ind}] ; 
  }
  else {
    ind = 0 ;
    np = pos[v[cnt]] ; 
  }
  ll temp  =np - pp   -  ( get(max(np, pp ) ) - get(min(np,pp) - 1) ) ; 
  ans += temp ; 
  if(temp == 0 ) ans++;
  upd(np,1 ) ; 
  cnt++;
  // ws(ans);
}

cout<<ans ; 



return 0 ;
}