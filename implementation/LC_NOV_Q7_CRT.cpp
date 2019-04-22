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
 
ll n,m,k,q,p,f,val,t=1,i,j;
ll ind = -1,sz,sm,ans,mx = -1,mn = infl ;
ll a[N][31] ,x[N*21] , y[N*21] ,pr[N][31] , b[N] ,mdv[N][31] ,cnt[N][31] ,pwm[31][N] , invpp[31];
 
 ll powmod(ll a ,ll b ){
    ll res = 1 ;
    while( b > 0 ){
        if(b&1) {
            res *= a;
            res %= p;
        }
        a *=a ; 
        a %=p ;
        b /= 2 ; 
    }
    return res ; 
}
ll modinv(ll a, ll m)
{
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }
    if (x1 < 0)
       x1 += m0;
    return x1;
}

int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
 
cin>>t;
while(t--){

    cin>>n>>p>>q;
    vector< ll >  vp , num ; 
    ll p_copy = p ; 

    fr(i,2,N) {
        if( p %i == 0 ) {
            vp.pb(i) ;
            ll  p1 = 1  ; 
            while(p > 1 && p % i == 0 ){
                p /= i ;
                p1 *= i ; 
            }
            num.pb(p1) ;
        } 
    }

    if(p > 1 ){
        vp.pb(p) ;
        num.pb(p) ; 
    }
    // ws(vp);
    // ws(num);
    ll M = num.size() ; 
    p = p_copy ; 
    ll tmp ; 
    fr(i,0,n){
        cin>>tmp ;
        fr(j,0,M){
            a[i][j] = tmp ; 
            cnt[i][j] = 0 ; 
        }
    } 

    fr(i ,0 , n ){
        fr(j,0,M){
            if(i > 0 )
                cnt[i][j] = cnt[i-1][j] ; 
            if(a[i][j] % vp[j]  == 0 ) {
                ll v = a[i][j] ; 
                while(v > 1  && v % vp[j] == 0 ) {
                    v /= vp[j] ; 
                    cnt[i][j]++ ; 
                } 
                a[i][j] = v ; 
            }
        }
    }

    fr(j,0,M)
        pr[0][j] = a[0][j]%p ; 

    fr(i,1,n) {
        fr(j,0,M){
            pr[i][j] = (a[i][j]%p)* pr[i-1][j] ; 
            pr[i][j] %=  p ; 
        }
    }

    // fr(j,0,M){
    //     pwm[j][0]  = 1 ; 
    //     ll tmp = vp[j] ,en = 0  ; 
    //     while(tmp < 1e9 + 100 ){
    //         tmp *= vp[j] ; 
    //         en++ ;
    //     }
    //     fr(i,1,N*en){ ///////////////////////////////////////////////////////////// ---- --------------------------EDIT
    //         pwm[j][i] = vp[j] * pwm[j][i-1] ;
    //         pwm[j][i] %= p ; 
    //     }
    // }

    // fr(i,0,n){
    //     fr(j,0,M){
    //         mdv[i][j] =  modinv( pr[i][j] , num[j] )  ;
    //         // cout<<pr[i][j] << " " << mdv[i][j]<<" \n"; 
    //     }
    // }
    fr( j ,0 , M ){
        ll pp = p / num[j] ; 
        invpp[j] = modinv(pp , num[j]) ; 
    }
    fr(i,0,q/64 + 2) {
        cin>>b[i] ; 
    }
    ll pans =0 , ans = 0; 
    fr(i,0,q){
 
        if(i%64 == 0 ){
            x[i] = b[i/64] + pans ;    
            y[i] = b[i/64 + 1] + pans ;  
        }
        else{
            x[i] = x[i-1] + pans ; 
            y[i] = y[i-1]  + pans; 
        }
 
        x[i] %= n ; 
        y[i] %= n ;
        if(x[i] > y[i] ) swap(x[i],y[i]) ;  
        vector< ll > rem ; 
        fr(j ,0 , M ){
            if(x[i] == 0 ) 
                ans = pr[y[i]][j] * powmod( vp[j], cnt[y[i]][j]) ; 
                // ans = pr[y[i]][j] * pwm[j][cnt[y[i]][j]] ;
            else{
                ans = (( pr[y[i]][j] * powmod( vp[j], cnt[y[i]][j] - cnt[x[i]-1][j] )  )%p ) * (modinv(pr[x[i]-1][j] ,num[j])) ; 
                // ans = (( pr[y[i]][j] * pwm[j][cnt[y[i]][j] - cnt[x[i]-1][j]]  )%p ) * (mdv[x[i]-1][j]) ; 
            }
            ans %= num[j] ; 
            rem.pb(ans) ; 
        }
        // ws(rem);
        ll result  = 0 ; 
        fr(j , 0 , M ){
            ll pp = p / num[j] ; 
            result +=  ( ( rem[j] *  invpp[j])%p )  * pp ;
            result %= p ;  

        }
        result %= p ;  
        // cout<<x[i]<<" "<<y[i]<<" "<<result<<"\n" ; 
        pans = (result + 1)%p ;   
 
    }
    cout<<pans<<"\n";
 
    }   
return 0 ;
} 