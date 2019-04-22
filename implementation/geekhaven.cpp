// avvinci -  sem 8    
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
#define N 1000004

const long long infl = 1e18+5;

ll n,m,k,q,x,y,f,val,t=1,i,j;
ll ind = -1,cnt,sz,sm,ans,mx = -1,mn = infl ;
ll a[N] ;
P tr[N] ; 

ll powmod(ll a ,ll b){
    ll res = 1;
    while(b >0 ){
        if(b&1) {
            res *=a ;
            res %= mod;
        }
        b /= 2; 
        a *= a;
        a %= mod; 
    }
    return res; 
}

void build(int v , int l , int r){
    if(l == r){
        tr[v].fs = a[l] ; 
        tr[v].sc = a[l] ; 
        // ws(a[l]);
        return ; 
    }
    int mid = (l+r)/2; 
    build(2*v,l,mid); 
    build(2*v+1,mid+1,r); 
    tr[v].fs = (tr[2*v].fs * tr[2*v+1].fs)%mod;
    tr[v].fs = (tr[v].fs  * powmod(( __gcd(tr[2*v].fs , tr[2*v+1].fs)),mod-2) )%mod ;  
}

void update(int v ,int l ,int r ,int ind , ll val){
    if(l == r){
        tr[v].fs = val ;
        tr[v].sc = val; 
        a[l] = val; 
        return ; 
    }
    int mid = (l+r)/2 ; 
    if(ind <= mid){
        update(2*v,l,mid,ind,val);
    }
    else
        update(2*v+1,mid+1,r,ind,val) ;
    tr[v].fs = (tr[2*v].fs * tr[2*v+1].fs)%mod;
    tr[v].fs = (tr[v].fs  * powmod(( __gcd(tr[2*v].fs , tr[2*v+1].fs)),mod-2) )%mod ;  

}

P get(int v , int l ,int r , int x ,int y ){
    if(l > y || r < x) {
        return {1,0}  ; 
    }
    if( l >= x && r <= y ){
        // ws(tr[v].fs);

        return tr[v] ; 
    }
    int mid = (l+r)/2 ; 
    P p1= get(2*v,l,mid,x,y); 
    P p2 = get(2*v+1,mid+1,r,x,y) ; 
    P p ;
    p.fs = (p1.fs  * p2.fs)%mod; 
    p.sc =   (p.fs* powmod( (__gcd(p1.sc,p2.sc)),mod-2)  ) %mod ; 
    // ws(p.sc);

    return p ;  
}
int main(){
INP
if (fopen("inp.txt", "r")) {
    freopen("myfile.txt","w",stdout);
    freopen("inp.txt", "r", stdin);
}
ll l, r ;
cin>>n>>q;
fr(i,0,n){
    cin>>a[i] ; 
}
build(1,0,n-1) ; 
while(q--){
    cin>>t; 
    cin>>l>>r; 
    if(t == 1){
        l--;
        update(1,0,n-1,l,r) ; 
    }
    else{
        l--;r--;
        P p  = get(1,0,n-1,l,r) ;
        cout<< (p.fs  ) %mod <<"\n"; 
    }

}



return 0 ;
}