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
#define N 5004

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mx = -1,mn = infl ;
ll a[N] ,pre[N];

ll nc2( ll u ){
  ll re  = u*(u-1) ; 
  re /= 2;
  return re; 
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}

cin>>t;
sz = t; 
while(t--){
  cin>>n;
  map< ll , ll > mp ; 
  set< ll > s ; 
  fr(i,0,n){
    cin>>a[i] ; 
    mp[a[i]]++ ; 
    s.insert(a[i]) ; 
  }
  vector< ll > v ; 
  ll tot = 0 ; 
  cnt = 0 ;
  memset(pre,0,sizeof(pre)) ; 

  for(auto it : s) {
    if(mp[it] > 1) {
      v.pb(it) ; 
      tot +=  nc2 (mp[it] ); 
      pre[cnt] = tot;  
      cnt++;
    }
  }

  ans = 0 ;  
  for(auto it : s ){
    val = mp[it] ;
    x = val *(val-1) * (val-2) ;
    x /= 6 ; 
    for(auto it1 : s ){
      if(it1 == it ) continue ; 
      if(it1 - it < 2 * it )
          ans += x*(mp[it1]) ; 
    }

  }
  // ws(ans);
     ll temp =  0  , d = v.size();
    for(auto it1 : s) {

      for(auto it2 : s ){
        if(it2 <= it1  ) continue ; 
        
        ll low  = 0 , high = d - 1, mid, ind = -1 ; 
        while(low <= high){
          mid = (low + high )/ 2 ; 
          if(2* v[mid] > it2 - it1){
            high = mid - 1; 
            ind = mid ; 
          }
          else{
            low = mid +1 ; 
          }
        }

        if(ind == -1  ) continue ; 
        // ws(ind);
        // ws(it1);
        ll sh =0 ,sh1 = 0  ; 
        if(mp[it1] > 1 && it1 >= v[ind] ) sh += nc2( mp[it1] )  ; 
        if(mp[it2] > 1 && it2 >= v[ind] ) sh += nc2 ( mp[it2] );

        if(ind > 0 ) sh1 = pre[ind-1] ; 

        ans +=  mp[it1] * mp[it2] * ( tot - sh - sh1 ) ; 
        // ws(tot - sh -sh1);
        // ws(sh);
        // ws(sh1);
        // ws(tot);


      }
    }



  cout<<"Case #"<<sz-t<<": "<<ans<<"\n" ; 

}



return 0 ;
}