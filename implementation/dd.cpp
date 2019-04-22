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
// ,dp[20][10][2];
 
// int rec(int ind  ,int st ,int rem ){
//     if(ind == n  ){
//         if(rem == 0 && f && st  )
//             return 1 ; 
 
//     }
// }
 
// int ok(int n ){
//     if(n%6 != 0 ) return 0 ; 
 
// }
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
cin>>t;
while(t--){
    cin>>n ; 
    val = n ; 
    vector< int > v ; 
    while(val > 0 ){
        v.pb(val%10) ; 
        val /= 10 ; 
    }
    reverse(all(v)) ; 
    mx = -1 ; ind = -1; 
    fr(i,0,v.size()){
        val = 0 ; 
        fr(j , 0, v.size()){
            if(j == i ) continue ; 
            val =10*val + v[j] ; 
        }
        // ws(val) ;
        if( (( val%6) == 0 ) && val > mx ){
            mx = val; 
            ind  = i ; 
        } 
        // ws(ind) ; 
    }
    if(mx == - 1) {
        cout<<"-1\n" ;
        continue ; 
    }
    // ws(mx) ; 
    fr(j,0,v.size()){
        if(j == ind ) continue ; 
        cout<<v[j];
    }
    cout<<"\n" ; 
    // f = 1 ; 
    // while(n--){
    //     if(ok(n)){
    //         f = 0 ;
    //         cout<<n<<"\n"; 
    //         break ;
    //     }
    // }
    // if(f){
    //     cout<<"-1\n" ; 
    // }
    // cin>>s ; n = s.size() ; 
    // memset(dp,-1,sizeof(dp)) ; 
    // re = rec(0,0,0) ;
    // f = 1 ; 
    // if(re == 0 ) cout<<"-1\n" ; 
}
 
 
 
 
return 0 ;
} 